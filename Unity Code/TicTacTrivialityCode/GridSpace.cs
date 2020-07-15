using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GridSpace : MonoBehaviour {

    public Button button;
    public Text buttonText;
    public GameObject cardPanel;

    private GameController gameController;

    public void SetGameControllerReference (GameController controller)
    {
        gameController = controller;
    }

    public void ActivateQuestion()
    {
        gameController.SetBoardInteractable(false);
        gameController.cardPanel.SetActive(true);

        gameController.AskQuestion();
    }

    public void SetSpace()
    {
        buttonText.text = gameController.GetPlayerSide();
        button.interactable = false;
        cardPanel.SetActive(false);
        gameController.AddMoveCounter();
    }
}
