using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Player2 : MonoBehaviour {

    // Public variables
    public float movementSpeed;                             // Determines how fast the player can move
    public float jumpSpeed;                                 // Determines the speed of the jump for the player
    public float jumpFallSpeed;                             // Determines the speed the player can fall when in the air
    public float lowJumpSpeed;                              // Determines the speed the player can fall during a low jump
    public int scrap;                                       // Determines how much scrap the player has
    public int health;                                      // Determines how much health the player has
    public LayerMask groundLayer;                           // Determines what layer the player will be able to jump from
    public Text scrapText;                                  // References the text element on Player 2's UI
    public Slider healthSlider;                             // Reference to Player 2's health slider
    public Slider rollSlider;                               // Reference to Player 2's roll slider
    public Player player1Script;                            // Reference to Player1's script
    public Car carScript;                                   // Reference to the car script

    // Private variables
    Rigidbody2D rb2D;                                       // References the 2D rigidbody of the player
    BoxCollider2D bc2D;                                     // References the 2D boxcollider of the player
    float movementInputHorizontal;                          // Holds the value for how far the player wants to move horizontally
    bool jumpReady = true;                                  // Determines if the player is ready to jump again
    bool rollReady = true;                                  // Determines if the player is ready to roll again
    bool dead = false;                                      // Determines if the player is dead
    Vector2 movement;                                       // Holds the vector2 for the new value of the players position when moving
    GameObject spanner;                                     // References the spanner gameobject
    Animator gameController;                                // References the animation controller for the player
    //Transform spannerTransform;
    //Transform spannerNewTransform;

    private void Awake()
    {
        rb2D = GetComponent<Rigidbody2D>();
        bc2D = GetComponent<BoxCollider2D>();
        gameController = GetComponent<Animator>();

        scrapText.text = "Scrap: " + scrap;
        healthSlider.value = health;
        rollSlider.value = 5f;

        spanner = this.gameObject.transform.GetChild(1).gameObject;
        //spannerTransform = spanner.transform;
        //spannerNewTransform = this.gameObject.transform.GetChild(3);
    }

    private void Update()
    {
        movementInputHorizontal = Input.GetAxis("HorizontalLeftJoy2");
        //movementInputHorizontal = Input.GetAxis("Horizontal2");
        movement = new Vector2(movementInputHorizontal, 0f);

        // With no if statement, you have to adjust the gravity scale. With it, you don't, but you can't run and jump
        //if (movementInputHorizontal != 0)
        //{
        rb2D.velocity = movement * movementSpeed;
        //}
        gameController.SetFloat("speed", movementInputHorizontal);

        // Allows the player to jump if they hit the Jump2/AButton2 button
        if (Input.GetButtonDown("AButton2"))
        //if (Input.GetButtonDown("Jump2"))
        {
            Jump();
        }
        // Makes the player fall faster as they are decending from a jump
        if (rb2D.velocity.y < 0)
        {
            rb2D.velocity += Vector2.up * Physics2D.gravity.y * (jumpFallSpeed - 1) * Time.deltaTime;
        }
        else if (rb2D.velocity.y > 0 && !Input.GetButton("Jump"))
        {
            rb2D.velocity += Vector2.up * Physics2D.gravity.y * (lowJumpSpeed - 1) * Time.deltaTime;
        }

        // If the user hits the swing button, they will swing the spanner
        if (Input.GetKeyDown("s"))
        {
            StartCoroutine(SwingSpanner());
        }

        // If the user hits the roll button and their bar is filled, they will become invisible
        if (Input.GetKeyDown("q") && Time.time > 5f && rollReady)
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

        // FOR TESTING ONLY. DECREASES THE PLAYERS HEALTH
        if (Input.GetKeyDown("2"))
        {
            healthSlider.value -= 1;
            if (healthSlider.value <= 0 && !dead)
            {
                gameController.SetBool("dead", true);
                dead = true;
            }
        }
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
            scrap += 10;
            player1Script.ammo += 10;
            player1Script.ammoText.text = "Ammo: " + player1Script.ammo;
            scrapText.text = "Scrap: " + scrap;
        }
        // Destroys the player if they enter the door of the car
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

    // Allows the player to swing their spanner
    IEnumerator SwingSpanner()
    {
        spanner.SetActive(true);
        yield return new WaitForSeconds(2);
        spanner.SetActive(false);
        /*
        float timer = 0f;
        float rotationTimer = 2f;
        spanner.SetActive(true);
        Debug.Log(spannerTransform.rotation.z);
        while (timer < rotationTimer)
        {
            timer += Time.deltaTime;
            spanner.transform.rotation = Quaternion.Lerp(spannerTransform.rotation, spannerNewTransform.rotation, 1 - (rotationTimer - timer) / rotationTimer);
            yield return 0;
        }
        spanner.SetActive(false);
        spanner.transform.rotation = spannerTransform.rotation;
        yield break;*/
    }
}
