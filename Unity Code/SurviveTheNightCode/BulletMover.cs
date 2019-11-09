using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BulletMover : MonoBehaviour {

    public float speed;                         // Determines how fast the bullet will travel
    private int lifespan = 2;                   // Determines how long the bullet will last before being destroyed
    Rigidbody2D rb2D;                           // References the 2D rigidbody of the bullet

    void Start()
    {
        // Grabs the rigidbody then shoots the bullet to the right
        rb2D = GetComponent<Rigidbody2D>();
        rb2D.velocity = transform.right * speed;
    }

    void Update()
    {
        // Destroyes the bullet after a set amount of time
        Destroy(this.gameObject, lifespan);
    }
}
