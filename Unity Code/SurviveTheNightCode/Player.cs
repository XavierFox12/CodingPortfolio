using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Player : MonoBehaviour {

    // Public variables
    public float movementSpeed;                             // Determines how fast the player can move
    //public float rollTimer;                                 // Timer to determine if the player can roll
    public int ammo;                                        // Determines how much ammo the player has
    public int health;                                      // Determines how much health the player has
    public int playerNumber;                                // Determines if the user is either player 1 or 2
    public float jumpSpeed;                                 // Determines the speed of the jump for the player
    public float jumpFallSpeed;                             // Determines the speed the player can fall when in the air
    public float lowJumpSpeed;                              // Determines the speed the player can fall during a low jump
    public Transform shotSpawn;                             // Where the bullet will be fired from
    public GameObject bullet;                               // Holds the prefab for the bullet
    public LayerMask groundLayer;                           // Determines what layer the player will be able to jump from
    public Text ammoText;                                   // References the text element on Player 1's UI
    public Slider healthSlider;                             // Reference to Player 1's health slider
    public Slider rollSlider;                               // Reference to Player 1's roll slider
    public Player2 player2Script;                           // Reference to Player2's script
    public Car carScript;                                   // Reference to the car script

    // Private variables
    Rigidbody2D rb2D;                                       // References the 2D rigidbody of the player
    BoxCollider2D bc2D;                                     // References the 2D boxcollider of the player
    float movementInputHorizontal;                          // Holds the value for how far the player wants to move horizontally
    float fireRate = .25f;                                  // Holds the fire rate for the gun
    float nextFire = .5f;                                   // Holds the value for how long the player has to wait before they can fire the gun again
    bool jumpReady = true;                                  // Determines if the player is ready to jump again
    bool rollReady = true;                                  // Determines if the player is ready to roll again
    bool dead = false;                                      // Determines if the player is dead or not
    Vector2 movement;                                       // Holds the vector2 for the new value of the players position when moving
    Animator gameController;                                // References the animation controller for the player

    private void Awake()
    {
        rb2D = GetComponent<Rigidbody2D>();
        bc2D = GetComponent<BoxCollider2D>();
        gameController = GetComponent<Animator>();
        ammoText.text = "Ammo: " + ammo;
        healthSlider.value = health;
        rollSlider.value = 5f;
    }

    private void Update()
    {
        movementInputHorizontal = Input.GetAxis("HorizontalLeftJoy");
        //movementInputHorizontal = Input.GetAxis("Horizontal1");
        movement = new Vector2(movementInputHorizontal, 0f);

        // With no if statement, you have to adjust the gravity scale. With it, you don't, but you can't run and jump
        //if (movementInputHorizontal != 0)
        //{
            rb2D.velocity = movement * movementSpeed;
        //}
        gameController.SetFloat("speed", movementInputHorizontal);
        if (Input.GetButtonDown("AButton"))
        //if (Input.GetButtonDown("Jump"))
        {
            Jump();
        }
        // Makes the player fall faster if they are still in the air
        if (rb2D.velocity.y < 0)
        {
            rb2D.velocity += Vector2.up * Physics2D.gravity.y * (jumpFallSpeed - 1) * Time.deltaTime;
        }
        else if (rb2D.velocity.y > 0 && !Input.GetButton("Jump"))
        {
            rb2D.velocity += Vector2.up * Physics2D.gravity.y * (lowJumpSpeed - 1) * Time.deltaTime;
        }
        // Fires the gun if the Fire1/B button is hit
        if (Input.GetButton("BButton") && Time.time > nextFire && ammo > 0)
        //if (Input.GetButton("Fire1") && Time.time > nextFire && ammo > 0)
        {
            GunFire();
        }
        // FOR TESING ONLY. DECREASES THE PLAYERS HEALTH EVERY TIME THE 1 BUTTON IS HIT
        if (Input.GetKeyDown("1"))
        {
            healthSlider.value -= 1;
            if (healthSlider.value <= 0 && !dead)
            {
                gameController.SetBool("dead", true);
                dead = true;
            }
        }
        // Allows the player to roll if they hit the r/X button
        if(Input.GetButton("XButton"))
        //if(Input.GetKeyDown("r") && Time.time > 5f && rollReady)
        {
            StartCoroutine(Invisibility());
        }
        else
        {
            rollSlider.value += Time.deltaTime;
            if (rollSlider.value == 5f)
            {
                rollReady = true;
            }
        }
    }

    // Spawns a bullet in front of the player if they hit the fire button
    void GunFire()
    {
        nextFire = Time.time + fireRate;
        Instantiate(bullet, shotSpawn.position, shotSpawn.rotation);
        --ammo;
        --player2Script.scrap;
        ammoText.text = "Ammo: " + ammo;
        player2Script.scrapText.text = "Scrap: " + player2Script.scrap;
    }

    // Allows the player to jump if they are on a ground surface
    void Jump()
    {
        if (!IsGrounded())
        {
            return;
        }
        else
        {
            rb2D.velocity = Vector2.up * jumpSpeed;
            jumpReady = false;
        }
    }

    // Checks to see if the player is on the ground
    bool IsGrounded()
    {
        RaycastHit2D hit = Physics2D.Raycast(transform.position, Vector2.down, .5f, groundLayer);
        if (hit.collider != null)
        {
            return true;
        }
        return false;
    }

    void OnTriggerEnter2D(Collider2D other)
    {
        // If the player hits a piece of scrap both scrap and ammo increase
        if (other.gameObject.CompareTag("Scrap"))
        {
            other.gameObject.SetActive(false);
            ammo += 10;
            player2Script.scrap += 10;
            ammoText.text = "Ammo: " + ammo;
            player2Script.scrapText.text = "Scrap: " + player2Script.scrap;
        }
        // Destroys the player if they enter through the door of the car
        else if (other.gameObject.CompareTag("Door"))
        {
            carScript.CheckCar();
            Destroy(this.gameObject);
        }
    }

        // Makes the player invisible if they get hit or hit the roll button
        IEnumerator Invisibility()
    {
        bc2D.enabled = false;
        print("INVISIBLE");
        rollSlider.value = 0f;
        rollReady = false;
        gameController.SetBool("roll", true);
        yield return new WaitForSeconds(2);
        gameController.SetBool("roll", false);
        bc2D.enabled = true;
        print("NOT INVISIBLE");
    }
}
