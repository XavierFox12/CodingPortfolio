/*********************************************************************
 * Created by: Xavier Fox
 * Script Name: DarknessMovement.cs
 * Game Name: Fleeing Night
 * Last Modified: 14 March, 2017
 *********************************************************************/

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DarknessMovement : MonoBehaviour {

    public float speed;                 // Sets the speed of the darkness
    private Rigidbody2D rb;             // Reference to the 2D rigidbody of the darkness

	void Start () {
        // Gets the component of the 2D rigidbody of the darkness
        rb = GetComponent<Rigidbody2D>();

        // Moves the darkness slowly from the left side of the screen to the right
        rb.velocity = transform.right * speed;
    }
}
