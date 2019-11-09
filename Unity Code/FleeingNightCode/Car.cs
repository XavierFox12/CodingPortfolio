/*********************************************************************
 * Created by: Xavier Fox
 * Script Name: Car.cs
 * Game Name: Fleeing Night
 * Last Modified: 27 April, 2017
 *********************************************************************/

using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using UnityEngine.SceneManagement;

public class Car : MonoBehaviour
{
    // Public variables
    public float speed;                             // Sets the speed of the car
    public float gas;                               // Determines the amount of gas the car has
    public Animator animator;                       // Reference to the animator on the car
    public Slider healthSlider;                     // Reference to the health slider on the car
    public Slider gasSlider;                        // Reference to the gas slider on the car
    public cameraMovement cameraScript;             // Reference to the camera script
    public Text winOrLoseText;                      // Reference to the win and lose text
    public GameObject FrontShot;                    // Holds the gameobject of where the shot from the front will be fired
    public GameObject BackShot;                     // Holds the gameobject of where the shot from the back will be fired
    public static GameObject Player1;               // Static variable for the player1 gameobject that gets initialized when the player exits the car
    public static GameObject Player2;               // Static variable for the player2 gameobject that gets initialized when the player exits the car
    public GameObject Player1Prefab;                // Reference to the player1 prefab
    public GameObject Player2Prefab;                // Reference to the player2 prefab
    public Transform ShotSpawn;                     // Position of where the front shot will spawn
    public Transform ShotSpawn2;                    // Position of where the back shot will spawn
    public Transform ShotSpawn3;                    // Position of where the top shot will spawn
    public Transform ShotSpawn4;                    // Position of where the bottom shot will spawn
    public Transform PlayerSpawn;                   // Position of where player1 spawns
    public Transform PlayerSpawn2;                  // Position of where player2 spawns
    public int health;                              // Controls the amount of health the car has
    public float fireRate;                          // Determines the fire rate of the car

    // Private variables
    private int playerCountStop;                    // Determines if all players are in the car or out of the car
    private int playersInCar;                       // Determines how many players are in the car
    private float nextFire;                         // Determines how long the car has to wait before it can shoot again
    private int ammo = 1000;                        // Controls the amount of ammo the car has
    private int tmpAmmo;                            // Temporary variable that holds the amount of ammo the car has
    private Rigidbody2D rb2d;                       // Reference to the 2D rigidbody
    private RigidbodyConstraints2D constraints;     // Reference to the constraints on the 2D rigidbody

    void Start()
    {
        // Gets the 2D rigidbody component and sets the text and int values
        // to their default values
        rb2d = GetComponent<Rigidbody2D>();
        winOrLoseText.text = "";
        playerCountStop = 0;
        playersInCar = 2;
    }

    void Update()
    {
        // Fires the shot up if the up arrow is pressed
        if (Input.GetKeyDown(KeyCode.UpArrow) && Time.time > nextFire && ammo > 0)
        {
            nextFire = Time.time + fireRate;
            Instantiate(FrontShot, ShotSpawn3.position, ShotSpawn3.rotation);
            --ammo;
        }
        // Fires the shot down if the down arrow is pressed
        else if (Input.GetKeyDown(KeyCode.DownArrow) && Time.time > nextFire && ammo > 0)
        {
            nextFire = Time.time + fireRate;
            Instantiate(FrontShot, ShotSpawn4.position, ShotSpawn4.rotation);
            --ammo;
        }
        // Fires the shot forward if the right arrow is pressed
        else if (Input.GetKeyDown(KeyCode.RightArrow) && Time.time > nextFire && ammo > 0)
        {
            nextFire = Time.time + fireRate;
            Instantiate(FrontShot, ShotSpawn.position, ShotSpawn.rotation);
            --ammo;
        }
        // Fires the shot backwards if the left arrow is pressed
        if (Input.GetKeyDown(KeyCode.LeftArrow) && Time.time > nextFire && ammo > 0)
        {
            nextFire = Time.time + fireRate;
            Instantiate(BackShot, ShotSpawn2.position, ShotSpawn2.rotation);
            --ammo;
        }
        // Calls the ExitCar function if the player hits the spacebar
        if ((Input.GetKeyDown(KeyCode.Space) || health <= 0 || gas <= 0) && playerCountStop == 0)
        {
            ExitCar();
        }
        // If both players are still in the car and there is still gas left, the cars
        // gas will slowly decrease
        else if (gas > 0 && playerCountStop == 0)
        {
            gas -= Time.deltaTime;
            gasSlider.value = gas;
            Debug.Log(gas);
        }
    }

    void FixedUpdate()
    {
        // Moves the car Vertically and Horizontally depending on what keys the user hits
        float moveHorizontal = Input.GetAxis("Horizontal");
        float moveVertical = Input.GetAxis("Vertical");
        Vector2 movement = new Vector2(moveHorizontal, moveVertical);
        rb2d.velocity = movement * speed;

        // Sets the car animation to always be facing forward
        animator.SetBool("movingForward", true);
        animator.SetBool("movingBackward", false);
        animator.SetBool("idle", false);
        animator.SetBool("emptyIdle", false);
    }

    void OnTriggerEnter2D(Collider2D other)
    {
        // If the car hits an object that is ammo, the ammo is set to
        // false and the cars ammo is increased by 10
        if (other.gameObject.CompareTag("Ammo"))
        {
            other.gameObject.SetActive(false);
            ammo += 10;
        }
        // If the car comes into contact with an enemy, the enemy is destroyed
        // and the cars health is decreased by 1
        else if (other.gameObject.CompareTag("Enemy"))
        {
            Destroy(other.gameObject);
            --health;
            healthSlider.value = health;
        }

        // If the car hits the wall of darkness, then the cars health
        // instantly goes to 0, and the players health to go to 0 if
        // they are both in the car
        else if (other.gameObject.CompareTag("Wall"))
        {
            health = 0;

            // If both players are in the car, then the title screen scene is loaded
            if (playerCountStop == 0)
            {
                SceneManager.LoadScene("titleScreen");
            }
            healthSlider.value = health;
            Destroy(this.gameObject);
        }
        // If the player reaches the finish line, it will call the YouWin function
        else if (other.gameObject.CompareTag("Finish"))
        {
            YouWin();
        }
    }

    // Displays You Win when the player crosses the Finish Line
    void YouWin()
    {
        Debug.Log("You Win");
        winOrLoseText.text = "You Win";
        SceneManager.LoadScene("titleScreen");
    }

    // Checks to see if both the players are in the car
    public void CheckCar()
    {
        ++playersInCar;

        // If both players are in the car, then the cars constrains are unfrozen
        // and is free to move around again
        if (playersInCar >= 2)
        {
            Debug.Log("Players are in the Car");
            cameraScript.TrackCar(this.gameObject);
            rb2d.constraints &= ~RigidbodyConstraints2D.FreezeAll;
            rb2d.constraints = RigidbodyConstraints2D.FreezeRotation;
            playerCountStop = 0;
            ammo = tmpAmmo;
        }
    }

    // Sets the car values if the players have exited the car
    public void ExitCar()
    {
        // Stores the cars ammo in the tmp variable and clears the ammo variable
        tmpAmmo = ammo;
        ammo = 0;

        // Spawns the players in their spawn positions, sets the camera script to track the players,
        // and stops the camera script from tracking the car
        Player1 = Instantiate(Player1Prefab, PlayerSpawn.position, PlayerSpawn.rotation);
        Player2 = Instantiate(Player2Prefab, PlayerSpawn2.position, PlayerSpawn2.rotation);
        Player1.GetComponent<playerMovement>().cameraScript = cameraScript;
        Player2.GetComponent<playerMovement>().cameraScript = cameraScript;
        cameraScript.UnTrackCar(this.gameObject);
        cameraScript.TrackPlayer(Player1);
        cameraScript.TrackPlayer(Player2);

        // Increases the amount needed for players in the car, sets the amount of players in the car
        // to 0 and freezes all 2D rigidbody constraints to prevent the car from moving from its position
        playerCountStop++;
        playersInCar = 0;
        rb2d.constraints = RigidbodyConstraints2D.FreezeAll;

        // Sets the cars animation to be in an idle animation
        animator.SetBool("movingForward", false);
        animator.SetBool("movingBackward", false);
        animator.SetBool("idle", false);
        animator.SetBool("emptyIdle", true);
    }

    // Adds 10 to the cars gas value if the player picks up gas
    public void AddGas()
    {
        gas += 10f;
        gasSlider.value = gas;
        Debug.Log(gas);
    }

    // Adds 5 to the cars health if the player decided to spend scrap on car health
    public void AddHealth()
    {
        health = health + 5;
        healthSlider.value = health;
        Debug.Log(health);
    }
}
