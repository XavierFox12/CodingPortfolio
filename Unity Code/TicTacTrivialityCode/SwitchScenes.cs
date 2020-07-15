using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class SwitchScenes : MonoBehaviour {
    public GameObject mainMenu;
    public GameObject credits;
    public GameObject options;
    public Slider aiSlider;
    private static float computerLevel = 1;

    public void LoadGame(int aiLevel)
    {
        Debug.Log("AI Level: " + computerLevel);
        if (aiLevel > 0)
        {
            GameController.enableAI = true;
            //GameController.aiLevel = aiLevel;
            GameController.aiLevel = Mathf.RoundToInt(computerLevel);
        }
        else
        {
            GameController.enableAI = false;
        }
        SceneManager.LoadScene("XaviersScene");
    }

    public void QuitGame()
    {
        Application.Quit();
    }

    public void CreditsMenu()
    {
        mainMenu.SetActive(false);
        credits.SetActive(true);
        options.SetActive(false);
    }

    public void OptionsMenu()
    {
        mainMenu.SetActive(false);
        credits.SetActive(false);
        options.SetActive(true);
    }

    public void MainMenu()
    {
        mainMenu.SetActive(true);
        credits.SetActive(false);
        options.SetActive(false);
    }

    public void SetAILevel()
    {
        computerLevel = aiSlider.value;
        Debug.Log("AI Level pt.2: " + computerLevel);
    }
}
