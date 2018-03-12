/*********************************************************************
 * Created by: Xavier Fox
 * Script Name: playerMovement.cs
 * Game Name: Fleeing Night
 * Last Modified: 27 April, 2017
 *********************************************************************/

using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class playerMovement : MonoBehaviour
{
    // Public variables
    public int playerNumber = 1;                // Determines what player this script belongs to
    public GameObject shot;                     // The shot gameobject that allows the player to shoot forward
    public GameObject backShot;                 // The backShot gameobject that allows the player to shoot back
    public Transform shotSpawn;                 // The shot spawn, which is where the shot will spawn from the front
    public Transform shotSpawn2;                // The shot spawn, which is where the shot will spawn from the back
    public Slider healthSlider;                 // Controller for the players health
    public Text winText;                        // The text that displays "You Win" if the player reaches the end
    public cameraMovement cameraScript;         // The camera script that will keep its eye on the player
    public GameManager gameManagerScript;       // The game manager, which will determine if the game is over for the player
    public Car carScript;                       // The car script that will be called if the player picks up scrap or gas
    public float speed = 10f;                   // Controls the speed of the player
    public int health = 10;                     // Controls the health of the player
    public Animator animator;                   // Controls the animator for the player movements
    public Animator gunAnimator;                // Controls the animator for the players guns

    // Private variables
    private string fire;                        // Determines if the player shooting is 1 or 2
    private string movementVertical;            // Allows the player to move vertically
    private string movementHorizontal;          // Allows the player to move horizontally
    private Rigidbody2D rb;                     // Grabs the 2d rigidbody off the player
    private SpriteRenderer spriteR;             // Grabs the sprite renderer off the player
    private float movementInputHorizontal;      // Controls the input for moving horizontally
    private float movementInputVertical;        // Controls the input for moving vertically
    private float nextFire;                     // Determines how long the player has to wait before they can shoot again
    private float fireRate;                     // Determines the fire rate of the players
    private int ammo = 1000;                    // Controls the amount of ammo the player has
    private int inventory;                      // Controls what is in the players inventory


    void Awake()
    {
        // Gets the components for the 2D rigidbody and sprite renderer
        rb = GetComponent<Rigidbody2D>();
        spriteR = GetComponent<SpriteRenderer>();

        // Sets the variables for moving vertically and horizontally to whatever
        // the players numbers are
        movementHorizontal = "Horizontal" + playerNumber;
        movementVertical = "Vertical" + playerNumber;
        fire = "Fire" + playerNumber;

        // Freezes the rotation on the player to prevent the player spinning,
        // setting the text to be empty, and sets the fire rate to .5
        rb.constraints = RigidbodyConstraints2D.FreezeRotation;
        winText.text = "";
        fireRate = .5f;
    }

    void Start()
    {
        // Sets the players health to be at the max, and also sets the slider
        // to be full as well
        health = 10;
        healthSlider.value = health;
    }

    void Update()
    {
        // Sets the float variables to be the axis of the player moving horizontally
        // or vertically
        movementInputHorizontal = Input.GetAxis(movementHorizontal);
        movementInputVertical = Input.GetAxis(movementVertical);

        // If player1 hits the H key, and if enough time has passed, and if they have
        // enough ammo, they can shoot their gun in front of them
        if (Input.GetKeyDown(KeyCode.H) && Time.time > nextFire && ammo > 0 && playerNumber == 1)
        {
            nextFire = Time.time + fireRate;
            Instantiate(shot, shotSpawn.position, shotSpawn.rotation);
            --ammo;
        }

        // If player1 hits the H key, and if enough time has passed, and if they have
        // enough ammo, they can shoot their gun behind them
        if (Input.GetKeyDown(KeyCode.G) && Time.time > nextFire && ammo > 0 && playerNumber == 1)
        {
            nextFire = Time.time + fireRate;
            Instantiate(backShot, shotSpawn2.position, shotSpawn.rotation);
            --ammo;
        }

        // If player2 hits the H key, and if enough time has passed, and if they have
        // enough ammo, they can shoot their gun in front of them
        if (Input.GetKeyDown(KeyCode.Period) && Time.time > nextFire && ammo > 0 && playerNumber == 2)
        {
            nextFire = Time.time + fireRate;
            Instantiate(shot, shotSpawn.position, shotSpawn.rotation);
            --ammo;
        }

        // If player2 hits the H key, and if enough time has passed, and if they have
        // enough ammo, they can shoot their gun behind them
        if (Input.GetKeyDown(KeyCode.Comma) && Time.time > nextFire && ammo > 0 && playerNumber == 2)
        {
            nextFire = Time.time + fireRate;
            Instantiate(backShot, shotSpawn2.position, shotSpawn.rotation);
            --ammo;
        }

        // If the players health reaches 0 they player gameobject is destroyed, and the
        // camera stops tracking that player
        if (health < 0)
        {
            gameManagerScript.PlayerDeathCount();
            healthSlider.value = health;
            cameraScript.UnTrackPlayer(this.gameObject);
            Destroy(this.gameObject);
        }

        // If the 2 key or E key is hit, and if the player has scrap in their inventory,
        // the player can add health to the car
        if ((Input.GetKeyDown(KeyCode.Keypad2) || Input.GetKeyDown(KeyCode.E)) && inventory > 0)
        {
            carScript.AddHealth();
            --inventory;
        }

        // If the 1 key or Q key is hit, and if the player has scrap in their inventory,
        // the player can add ammo for their gun
        if ((Input.GetKeyDown(KeyCode.Keypad1) || Input.GetKeyDown(KeyCode.Q)) && inventory > 0)
        {
            ammo += 10;
            --inventory;
            Debug.Log(ammo);
        }

        // Makes player2's animation face the right if the right arrow key was hit
        if (Input.GetKeyDown(KeyCode.RightArrow) && playerNumber == 2)
        {
            animator.SetBool("turnBack", false);
            animator.SetBool("turnFront", false);
            animator.SetBool("turnLeft", false);
            animator.SetBool("turnRight", true);
            gunAnimator.SetBool("gunLeft", false);
            gunAnimator.SetBool("gunRight", true);
            gunAnimator.SetBool("gunIdle", false);
        }
        // Makes player2's animation face the left if the left arrow key was hit
        else if (Input.GetKeyDown(KeyCode.LeftArrow) && playerNumber == 2)
        {
            animator.SetBool("turnBack", false);
            animator.SetBool("turnFront", false);
            animator.SetBool("turnLeft", true);
            animator.SetBool("turnRight", false);
            gunAnimator.SetBool("gunLeft", true);
            gunAnimator.SetBool("gunRight", false);
            gunAnimator.SetBool("gunIdle", false);
        }
        // Makes player2's animation face back if the up arrow key was hit
        else if (Input.GetKeyDown(KeyCode.UpArrow) && playerNumber == 2)
        {
            animator.SetBool("turnBack", true);
            animator.SetBool("turnFront", false);
            animator.SetBool("turnLeft", false);
            animator.SetBool("turnRight", false);
            gunAnimator.SetBool("gunLeft", false);
            gunAnimator.SetBool("gunRight", false);
            gunAnimator.SetBool("gunIdle", true);
        }
        // Makes player2's animation face forward if the down arrow key was hit
        else if (Input.GetKeyDown(KeyCode.DownArrow) && playerNumber == 2)
        {
            animator.SetBool("turnBack", false);
            animator.SetBool("turnFront", true);
            animator.SetBool("turnLeft", false);
            animator.SetBool("turnRight", false);
            gunAnimator.SetBool("gunLeft", false);
            gunAnimator.SetBool("gunRight", false);
            gunAnimator.SetBool("gunIdle", true);
        }
        // Makes player1's animation face right if the D key was hit
        else if (Input.GetKeyDown(KeyCode.D) && playerNumber == 1)
        {
            animator.SetBool("turnBack", false);
            animator.SetBool("turnFront", false);
            animator.SetBool("turnLeft", false);
            animator.SetBool("turnRight", true);
            gunAnimator.SetBool("gunLeft", false);
            gunAnimator.SetBool("gunRight", true);
            gunAnimator.SetBool("gunIdle", false);
        }
        // Makes player1's animation face the left if the A key was hit
        else if (Input.GetKeyDown(KeyCode.A) && playerNumber == 1)
        {
            animator.SetBool("turnBack", false);
            animator.SetBool("turnFront", false);
            animator.SetBool("turnLeft", true);
            animator.SetBool("turnRight", false);
            gunAnimator.SetBool("gunLeft", true);
            gunAnimator.SetBool("gunRight", false);
            gunAnimator.SetBool("gunIdle", false);
        }
        // Makes player1's animation face back if the W key was hit
        else if (Input.GetKeyDown(KeyCode.W) && playerNumber == 1)
        {
            animator.SetBool("turnBack", true);
            animator.SetBool("turnFront", false);
            animator.SetBool("turnLeft", false);
            animator.SetBool("turnRight", false);
            gunAnimator.SetBool("gunLeft", false);
            gunAnimator.SetBool("gunRight", false);
            gunAnimator.SetBool("gunIdle", true);
        }
        // Makes player1's animation face forward if the S key was hit
        else if (Input.GetKeyDown(KeyCode.S) && playerNumber == 1)
        {
            animator.SetBool("turnBack", false);
            animator.SetBool("turnFront", true);
            animator.SetBool("turnLeft", false);
            animator.SetBool("turnRight", false);
            gunAnimator.SetBool("gunLeft", false);
            gunAnimator.SetBool("gunRight", false);
            gunAnimator.SetBool("gunIdle", true);
        }
    }

    void FixedUpdate()
    {
        // Allows the player to move depending on the values of their
        // vertical and horizontal values
        Vector2 movement = new Vector2(movementInputHorizontal, movementInputVertical);
        rb.velocity = movement * speed;
    }

    void OnTriggerEnter2D(Collider2D other)
    {
        // If the player hits an object that is ammo, the ammo is set to
        // false and the players ammo is increased by 10
        if (other.gameObject.CompareTag("Ammo"))
        {
            other.gameObject.SetActive(false);
            ammo += 10;
        }
        // If the player hits an object that is scrap, the scrap is set to
        // false and players scrap in increased by 1
        else if (other.gameObject.CompareTag("Scrap"))
        {
            other.gameObject.SetActive(false);
            ++inventory;
            Debug.Log("scrap +1");
        }
        // If the player hits an object that is gas, the gas object is set to
        // false and the cars gas is increased
        else if (other.gameObject.CompareTag("Gas"))
        {
            carScript.AddGas();
            other.gameObject.SetActive(false);
        }
        // If the player comes into contact with an enemy, the enemy is destroyed
        // and the players health is decreased by 1
        else if (other.gameObject.CompareTag("Enemy"))
        {
            other.gameObject.SetActive(false);
            --health;
            healthSlider.value = health;
        }
        // If the player hits the wall of darkness, then the players health
        // instantly goes to 0, which causes the camera to stop tracking
        // the player, and destroys the gameobject
        else if (other.gameObject.CompareTag("Wall"))
        {
            health = 0;
            gameManagerScript.PlayerDeathCount();
            healthSlider.value = health;
            cameraScript.UnTrackPlayer(this.gameObject);
            SceneManager.LoadScene("titleScreen");
            Destroy(this.gameObject);
        }
        // If the player reaches the finish line, it will call the YouWin function
        else if (other.gameObject.CompareTag("Finish"))
        {
            YouWin();
        }
    }

    void OnTriggerStay2D(Collider2D other)
    {
        // Determines if the player is standing in door area of the car
        if (other.gameObject.CompareTag("Door"))
        {
            // If the player hits the right or left shift key, then the camera stops
            // tracking the player, the gameobject gets destroyed, and the player enters
            // the car and waits to see if both he and the other player are in the car
            if (Input.GetKeyDown(KeyCode.RightShift) || Input.GetKeyDown(KeyCode.LeftShift))
            {
                other.transform.parent.GetComponent<Car>().CheckCar();
                cameraScript.UnTrackPlayer(this.gameObject);
                Destroy(this.gameObject);
            }
        }
    }

    // Displays you win in the console and loads the title screen
    void YouWin()
    {
        Debug.Log("You Win");
        SceneManager.LoadScene("titleScreen");
    }
}