using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Car : MonoBehaviour {

    public float speed;                     // Determines the speed of the car
    public float health;                    // Holds how much Health the car has
    public Slider healthSlider;             // References the health slider
    public GameObject bullet;               // Holds the prefab for the bullet
    public GameObject bluePlayer;           // Reference to the blue player gameobject
    public GameObject redPlayer;            // Reference to the red player gameobject
    public Player player1Script;            // Reference to Player1's script
    public Player2 player2Script;           // Reference to Player2's script
    public Transform shotSpawn;             // Where the bullet will be fired from
    public Transform blueSpawn;             // Reference to where the blue player spawns
    public Transform redSpawn;              // Reference to where the red player spawns

    float moveHorizontal;                   // Holds the value for how far the car wants to move horizontally
    float fireRate = .25f;                  // Holds the fire rate for the gun
    float nextFire = .5f;                   // Holds the value for how long the player has to wait before they can fire the gun again
    Vector2 movement;                       // Holds the vector2 for the new position of the car
    Rigidbody2D rb2d;                       // References the 2D rigidbody of the car
    BoxCollider2D bc2d;                     // Reference to the 2D boxcolider on the car
    int playerCount;                        // Counts how many players are in the car
    bool moveCar;                           // Determines if the car can move or not

    private void Start()
    {
        // Grabs the 2D rigidbody of the car
        rb2d = GetComponent<Rigidbody2D>();
        bc2d = GetComponent<BoxCollider2D>();
        //bc2d.enabled = true;
        healthSlider.value = health;
        playerCount = 0;
    }

    private void Update()
    {
        // Determines if the car is allowed to move
        if(moveCar)
        {
            // Determines how far the car will move horizontally
            //moveHorizontal = Input.GetAxis("Horizontal");
            moveHorizontal = Input.GetAxis("HorizontalLeftJoy");
            movement = new Vector2(moveHorizontal, 0f);
            rb2d.velocity = movement * speed;

            // Determines if the car has no health
            if (health > 0f)
            {
                // Slowly degenerates the cars health system
                health -= Time.deltaTime;
                healthSlider.value = health;
            }
            // Determines if the user has hit the Fire/B button
            if (Input.GetButton("BButton") && Time.time > nextFire && player1Script.ammo > 0)
            //if (Input.GetButton("Fire1") && Time.time > nextFire && player1Script.ammo > 0)
            {
                // Fires the gun on the car
                GunFire();
            }
            // Determines if the user has hit the jump/A button
            if(Input.GetButton("AButton"))
            //if (Input.GetButtonDown("Jump"))
            {
                // Ejects player 1 and 2 out of the car
                Instantiate(redPlayer, redSpawn.position, redSpawn.rotation);
                Instantiate(bluePlayer, blueSpawn.position, blueSpawn.rotation);
                playerCount = 0;
                moveCar = false;
                //bc2d.enabled = false;
            }
        }
    }

    // Spawns a bullet in front of the player if they hit the fire button
    void GunFire()
    {
        nextFire = Time.time + fireRate;
        Instantiate(bullet, shotSpawn.position, shotSpawn.rotation);
        --player1Script.ammo;
        --player2Script.scrap;
        player1Script.ammoText.text = "Ammo: " + player1Script.ammo;
        player2Script.scrapText.text = "Scrap: " + player2Script.scrap;
    }

    // Checks to see if both players are in the car or not
    public void CheckCar()
    {
        ++playerCount;

        // Allows the car to move if both players are in the car
        if (playerCount == 2 && !moveCar)
        {
            moveCar = true;
            //bc2d.enabled = true;
        }
    }
}
