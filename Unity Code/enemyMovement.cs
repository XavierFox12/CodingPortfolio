/*********************************************************************
 * Created by: Xavier Fox
 * Script Name: enemyMovement.cs
 * Game Name: Fleeing Night
 * Last Modified: 24 April, 2017
 *********************************************************************/

using UnityEngine;
using System.Collections;

public class enemyMovement : MonoBehaviour
{
    // Public variables
	public Transform target1, target2, target3;                     // Holds the transform values for the 3 targets that the enemies are chasing
    public int moveSpeed;                                           // The speed of the enemy 
	public int rotationSpeed;                                       // The rotation speed of the enemy

    // Private variables
    private int carHealth, player1Health, player2Health;            // Holds the health of the two players and the car
	private GameObject car;                                         // Reference to the car gameobject
	private GameObject player1;                                     // Reference to the player1 gameobject
    private GameObject player2;                                     // Reference to the player2 gameobject
	private Transform myTransform;                                  // Holds the transform of the enemy

	void Awake() {
        // Sets myTransform to enemies starting position transform
		myTransform = transform;
	}

	void Start () {
        // Sets the targets transfrom to be where the players and car are located
        car = GameObject.FindGameObjectWithTag ("Car");
        Debug.Log(car == null);
        Debug.Log(player1 == null);
		target1 = car.transform;
		target2 = player1.transform;
        target3 = player2.transform;
	}

	void Update () {
        // Gets the cars health component
        carHealth = car.GetComponent<Car>().health;

        // The enemy is able to track player1 based on where he is on the screen and stops
        // following him if his health reaches 0
        if (Car.Player1 != null)
        {
            player1Health = Car.Player1.GetComponent<playerMovement>().health;
            Vector3 dir = target2.position - myTransform.position;
            dir.z = 0.0f;
            if (dir != Vector3.zero)
            {
                myTransform.rotation = Quaternion.Slerp(myTransform.rotation, Quaternion.FromToRotation(Vector3.right, dir), rotationSpeed * Time.deltaTime);
            }

            myTransform.position += (target2.position - myTransform.position).normalized * moveSpeed * Time.deltaTime;
            if (transform.position.x > target2.transform.position.x)
            {
                transform.localRotation = Quaternion.Euler(0f, 180f, 0f);
            }
            else if (transform.position.x < target2.transform.position.x)
            {
                transform.localRotation = Quaternion.Euler(0f, 0f, 0f);
            }
        }
        if (Car.Player2 != null)
        {
            player2Health = Car.Player2.GetComponent<playerMovement>().health;
        }

        // The enemy is able to track the car based on where the car is located on the screen
        // and stops following the car if the cars health is 0
        if (carHealth > 0)
        {
            Vector3 dir = target1.position - myTransform.position;
            dir.z = 0.0f;
            if (dir != Vector3.zero)
            {
                myTransform.rotation = Quaternion.Slerp(myTransform.rotation, Quaternion.FromToRotation(Vector3.right, dir), rotationSpeed * Time.deltaTime);
            }

            myTransform.position += (target1.position - myTransform.position).normalized * moveSpeed * Time.deltaTime;
            if (transform.position.x > target1.transform.position.x)
            {
                transform.localRotation = Quaternion.Euler(0f, 180f, 0f);
            }
            else if (transform.position.x < target1.transform.position.x)
            {
                transform.localRotation = Quaternion.Euler(0f, 0f, 0f);
            }
        }



        // The enemy is able to track player2 based on where he is on the screen and stops
        // following him if his health reaches 0
        if (player2Health > 0)
        {
            Vector3 dir = target3.position - myTransform.position;
            dir.z = 0.0f;
            if (dir != Vector3.zero)
            {
                myTransform.rotation = Quaternion.Slerp(myTransform.rotation, Quaternion.FromToRotation(Vector3.right, dir), rotationSpeed * Time.deltaTime);
            }

            myTransform.position += (target3.position - myTransform.position).normalized * moveSpeed * Time.deltaTime;
            if (transform.position.x > target3.transform.position.x)
            {
                transform.localRotation = Quaternion.Euler(0f, 180f, 0f);
            }
            else if (transform.position.x < target3.transform.position.x)
            {
                transform.localRotation = Quaternion.Euler(0f, 0f, 0f);
            }
        }
    }
}
