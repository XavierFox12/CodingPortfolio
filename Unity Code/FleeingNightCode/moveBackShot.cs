/*********************************************************************
 * Created by: Xavier Fox
 * Script Name: moveBackShot.cs
 * Game Name: Fleeing Night
 * Last Modified: 9 February, 2017
 *********************************************************************/

using UnityEngine;
using System.Collections;

public class moveBackShot : MonoBehaviour {
	public float speed;                 // Determines the speed that the bullet can travel
	private int lifespan = 2;           // Determines how long the bullet will last before it is destroyed
	Rigidbody2D rb;                     // Reference to the 2D rigidbody

	void Start () {
        // Gets the 2D rigidbody component from the bullet
		rb = GetComponent<Rigidbody2D>();

        // Forces the bullet to move to the left of the screen or behend the player
		rb.velocity = transform.right * -speed;
	}

	void Update ()
	{
        // Destroys the bullet after the amount of lifespan it has, which is 2 seconds
		Destroy(this.gameObject, lifespan);
	}

	void OnTriggerEnter2D(Collider2D other)
	{
        // If the bullet hits an object thats an enemy, it will destroy the enemy and the bullet
		if (other.gameObject.CompareTag("Enemy"))
		{
            Destroy(other.gameObject);
			Destroy(this.gameObject);
		}
        // If the bullet hits a cactus object, it will destroy the cactus and the bullet
        else if (other.gameObject.CompareTag("Cacti"))
        {
            Destroy(other.gameObject);
            Destroy(this.gameObject);
        }
        // If the bullet hits any object that has a tag that is breakable, it will destroy that object and the bullet
        else if (other.gameObject.CompareTag("Breakable"))
        {
            Destroy(other.gameObject);
            Destroy(this.gameObject);
        }
    }
}
