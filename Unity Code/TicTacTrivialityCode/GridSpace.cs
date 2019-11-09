using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GridSpace : MonoBehaviour {

    public Button button;                               // Reference to the grid spaces button
    public Text buttonText;                             // Reference to the grid spaces text
    public GameObject cardPanel;                        // Refernce to the card game object that displays the question

    private GameController gameController;              // Refernce to the GameController script

    // Sets the gameController variable to script object that is being passed in
    public void SetGameControllerReference (GameController controller)
    {
        gameController = controller;
    }

    // Displays the question card on the screen to display the question
    public void ActivateQuestion()
    {
        gameController.SetBoardInteractable(false);
        gameController.cardPanel.SetActive(true);

        gameController.AskQuestion();
    }

    // Sets the Grid space to the user who got the question correct
    public void SetSpace()
    {
        buttonText.text = gameController.GetPlayerSide();
        button.interactable = false;
        cardPanel.SetActive(false);
        gameController.AddMoveCounter();
    }
}
