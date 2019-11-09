using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CaveMusic : MonoBehaviour {

    public AudioSource mainTheme;               // Reference to the audio source for the main theme
    AudioSource caveTheme;                      // Reference to the audio source for the cave theme

    void Start() {
        // Gets the audio source for the cave theme
        caveTheme = GetComponent<AudioSource>();
    }


    void OnTriggerEnter2D(Collider2D other)
    {
        // Determines if either player 1 or 2 has entered the cave
        if (other.gameObject.CompareTag("Player"))
        {
            // Enables the cave music and disables the main theme
            mainTheme.enabled = false;
            caveTheme.enabled = true;
        }
    }

    void OnTriggerExit2D(Collider2D other)
    {
        // Determines if either player 1 or 2 has exited the cave
        if (other.gameObject.CompareTag("Player"))
        {
            // Disables the cave music and enables the main theme
            caveTheme.enabled = false;
            mainTheme.enabled = true;
        }
    }
}
