/*********************************************************************
 * Created by: Xavier Fox
 * Script Name: GameManager.cs
 * Game Name: Fleeing Night
 * Last Modified: 24 April, 2017
 *********************************************************************/

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    public Text gameOverText;                   // Reference to the game over text
    public GameObject enemy;                    // Holds the enemy gameobject
    public Transform enemySpawn1;               // Holds the first transform of where the enemy spawns
    public Transform enemySpawn2;               // Holds the second transform of where the enemy spawns
    public float spawnWait;                     // The wait time before another enemy can spawn
    private int playerDeathCount;               // Counter for how many players have died

    void Start()
    {
        // Begins the coroutine to continuously spawn the enemies, sets the
        // death count to 0, and the game over text to be empty
        StartCoroutine(SpawnEnemies());
        playerDeathCount = 0;
        gameOverText.text = "";
    }

    // Coroutine to continuously spawn the enemies
    IEnumerator SpawnEnemies()
    {
        // Loop that goes on until the end of the game
        while (true)
        {
            // Changes the position of the two spawners
            Vector2 spawnPosition1 = new Vector2(enemySpawn1.position.x, Random.Range(-enemySpawn1.position.y, enemySpawn1.position.y));
            Vector2 spawnPosition2 = new Vector2(enemySpawn2.position.x, Random.Range(-enemySpawn2.position.y, enemySpawn2.position.y));
            Quaternion spawnRotation = Quaternion.identity;

            // Spawns the enemies in the spawn locations and waits for how long
            // the spawn wait time is and then starts the loop at the beginning
            Instantiate(enemy, spawnPosition1, spawnRotation);
            Instantiate(enemy, spawnPosition2, spawnRotation);
            yield return new WaitForSeconds(spawnWait);
        }
    }

    // Increases the player death count, and if the count has reaced 2,
    // then the game is over
    public void PlayerDeathCount()
    {
        ++playerDeathCount;
        if (playerDeathCount >= 2)
        {
            GameOver();
        }
    }

    // Prints a message to the console and loads the title screen scene
    void GameOver()
    {
        Debug.Log("Game Over");
        SceneManager.LoadScene("titleScreen");
    }
}