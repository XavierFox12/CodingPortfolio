using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

// Class that determines the players panel, text, and button
[System.Serializable]
public class Player
{
	public Image panel;
	public Text text;
	public Button button;
}

// Class that gives both a panel and its text color
[System.Serializable]
public class PlayerColor
{
	public Color panelColor;
	public Color textColor;
}

public class GameController : MonoBehaviour {

    // Public variables
    public Text[] buttonList;                       // Reference to the text on all the buttons on the grid
    public GameObject gameOverPanel;                // Reference to the Game Over panel
    public Text gameOverText;                       // Reference to the Game Over text
    public GameObject restartButton;                // Reference to the Restart button

    public Player playerX;                          // Reference to the player class for X
    public Player playerO;                          // Reference to the player class for O
    public PlayerColor activePlayerColor;           // Reference to the playerColor class to determine the colors for being active
    public PlayerColor inactivePlayerColor;         // Reference to the playerColor class to determine the colors for being inactive
    public GameObject startInfo;                    // Reference to the Start info, which tells the player to pick a side, and asks if they want to play again
    public Text category1;                          // Reference to the first categories text
    public Text category2;                          // Reference to the second categories text
    public Text category3;                          // Reference to the third categories text
    public GameObject cardPanel;                    // Reference to the card panel which contains question the the player picked
    public Text questionText;                       // Reference to the question text on the card
    public Text answerAText;                        // Reference to the answer A's text
    public Text answerBText;                        // Reference to the answer B's text
    public Text answerCText;                        // Reference to the answer C's text

    // Private Variables
    private string playerSide;                      // String that holds if player is either X or O
    private int category;                           // Integer that determines what category the player picked
    private int moveCount;                          // Integer that determines how many moves have been made between the two players
    private int questionNumber = 0;                 // Integer that determines what question number will be displayed to the user
    private int buttonNumber = 0;                   // Integer that determines what button the player picked on the board
    private int randomNumber;                       // Integer that holds a random number to determine what question will be given
    private bool answerA = false;                   // Determines if the player picked answer A
    private bool answerB = false;                   // Determines if the player picked answer B
    private bool answerC = false;                   // Determines if the player picked answer C
    private bool questionAnswered = false;          // Determines if the player actually answered the question
    private bool level1Selected = false;            // Determines if a level 1 question was selected
    private bool level2Selected = false;            // Determines if a level 2 question was selected
    private bool level3Selected = false;            // Determines if a level 3 question was selected
    private Questions questionsScript;              // Reference to the Questions script

    // These variables are used to determine if any of the 9 buttons were hit
    private bool setButtons = false;
    private bool setButtons1 = false;
    private bool setButtons2 = false;
    private bool setButtons3 = false;
    private bool setButtons4 = false;
    private bool setButtons5 = false;
    private bool setButtons6 = false;
    private bool setButtons7 = false;
    private bool setButtons8 = false;

    // Sets the categories, gets the reference on the buttons, and disables everything
    private void Awake()
    {
        questionsScript = GetComponent<Questions>();
        moveCount = 0;
        SetGameControllerReferenceOnButtons();
        gameOverPanel.SetActive(false);
        restartButton.SetActive(false);

        questionsScript.ChooseCategories();
        category1.text = questionsScript.randomCategory1.categoryName.ToString();
        category2.text = questionsScript.randomCategory2.categoryName.ToString();
        category3.text = questionsScript.randomCategory3.categoryName.ToString();
    }

    private void Update()
    {
        // Determines if the user hit the "q" key, which will take them back to the title screen
        if (Input.GetKeyDown("q"))
        {
            SceneManager.LoadScene("TitleScreen");
        }
    }

    // Sets the reference on each button on the grid
    void SetGameControllerReferenceOnButtons()
    {
        for (int i = 0; i < buttonList.Length; i++)
        {
            buttonList[i].GetComponentInParent<GridSpace>().SetGameControllerReference(this);
        }
    }

    // Determines who goes first depending on if X or O was chosen at the start
    public void SetStartingSide(string startingSide)
    {
        playerSide = startingSide;
        if (playerSide == "X")
        {
            SetPlayerColors(playerX, playerO);
        } else
        {
            SetPlayerColors(playerO, playerX);
        }

        StartGame();
    }

    // Sets the game board to be active
    void StartGame()
    {
        SetBoardInteractable(true);
        SetPlayerButtons(false);
        startInfo.SetActive(false);
    }

    // Determines whose turn it is
    public string GetPlayerSide()
    {
        return playerSide;
    }

    // Changes the players sides from X to O or vice versa
    void ChangeSides()
    {
        playerSide = (playerSide == "X") ? "O" : "X";
        if (playerSide == "X")
        {
            SetPlayerColors(playerX, playerO);
        }
        else
        {
            SetPlayerColors(playerO, playerX);
        }

    }

    // Sets the players colors to be active if it is there turn
    void SetPlayerColors(Player newPlayer, Player oldPlayer)
    {
        newPlayer.panel.color = activePlayerColor.panelColor;
        newPlayer.text.color = activePlayerColor.textColor;
        oldPlayer.panel.color = inactivePlayerColor.panelColor;
        oldPlayer.text.color = inactivePlayerColor.textColor;
    }

    // Adds to the move count
    public void AddMoveCounter()
    {
        moveCount++;
    }

    // Determines if the player won or tied. If not, it switches to the next player
    public void EndTurn()
    {
        //moveCount++;

        // The first 3 if statements determine if there is a horizontal match
        if (buttonList[0].text == playerSide && buttonList[1].text == playerSide && buttonList[2].text == playerSide)
        {
            GameOver(playerSide);
        }
        else if (buttonList[3].text == playerSide && buttonList[4].text == playerSide && buttonList[5].text == playerSide)
        {
            GameOver(playerSide);
        }
        else if (buttonList[6].text == playerSide && buttonList[7].text == playerSide && buttonList[8].text == playerSide)
        {
            GameOver(playerSide);
        }
        // The next 3 if statements determine if there is a vertical match
        else if (buttonList[0].text == playerSide && buttonList[3].text == playerSide && buttonList[6].text == playerSide)
        {
            GameOver(playerSide);
        }
        else if (buttonList[1].text == playerSide && buttonList[4].text == playerSide && buttonList[7].text == playerSide)
        {
            GameOver(playerSide);
        }
        else if (buttonList[2].text == playerSide && buttonList[5].text == playerSide && buttonList[8].text == playerSide)
        {
            GameOver(playerSide);
        }
        // The next 2 if statements determine if there is a diagonal match
        else if (buttonList[0].text == playerSide && buttonList[4].text == playerSide && buttonList[8].text == playerSide)
        {
            GameOver(playerSide);
        }
        else if (buttonList[2].text == playerSide && buttonList[4].text == playerSide && buttonList[6].text == playerSide)
        {
            GameOver(playerSide);
        }
        // Determines if there is a draw
        else if (moveCount >= 9)
        {
            GameOver("draw");
        }
        else
        {
            ChangeSides();
        }
    }

    // Sets the text to the winning player or sets it to a tie
    void GameOver(string winningPlayer)
    {
        SetBoardInteractable(false);

        if (winningPlayer == "draw")
        {
            SetGameOverText("It's a Draw!");
            SetPlayerColorsInactive();
        }
        else
        {
            SetGameOverText(winningPlayer + " Wins!");
        }
        restartButton.SetActive(true);
    }

    // Displays who won or if it was a draw
    void SetGameOverText(string value)
    {
        gameOverPanel.SetActive(true);
        gameOverText.text = value;
    }

    // Restarts the game, by making all the squares blank, and interactable again.
    // Also it chooses the categories at random again
    public void RestartGame()
    {
        // Resets the buttons and colors back to the beginning
        moveCount = 0;
        gameOverPanel.SetActive(false);
        restartButton.SetActive(false);
        SetPlayerButtons(true);
        SetPlayerColorsInactive();
        startInfo.SetActive(true);
        SetBoardInteractable(false);

        // Loops through and sets all of the squares blank
        for (int i = 0; i < buttonList.Length; i++)
        {
            buttonList[i].text = "";
            buttonList[i].GetComponentInParent<GridSpace>().cardPanel.SetActive(true);
        }

        // Picks 3 new random categories
        questionsScript.ChooseCategories();
        category1.text = questionsScript.randomCategory1.categoryName.ToString();
        category2.text = questionsScript.randomCategory2.categoryName.ToString();
        category3.text = questionsScript.randomCategory3.categoryName.ToString();
    }

    // Sets the buttons on the board to be interactable or inactive
    public void SetBoardInteractable(bool toggle)
    {
        for (int i = 0; i < buttonList.Length; i++)
        {
            if (buttonList[i].text == "" || buttonList[i].text == "")
                buttonList[i].GetComponentInParent<Button>().interactable = toggle;
        }
    }

    // Allows the X and O to be chosen at the start of the game
    void SetPlayerButtons(bool toggle)
    {
        playerX.button.interactable = toggle;
        playerO.button.interactable = toggle;
    }

    // Sets the players colors to be inactive
    void SetPlayerColorsInactive()
    {
        playerX.panel.color = inactivePlayerColor.panelColor;
        playerX.text.color = inactivePlayerColor.textColor;
        playerO.panel.color = inactivePlayerColor.panelColor;
        playerO.text.color = inactivePlayerColor.textColor;
    }

    // Determines if the button of answer A was hit
    public void SetAnswerA()
    {
        answerA = true;
    }

    // Determines if the button of answer B was hit
    public void SetAnswerB()
    {
        answerB = true;
    }

    // Determines if the button of answer C was hit
    public void SetAnswerC()
    {
        answerC = true;
    }

    // These next 9 functions determine if the grid buttons were hit
    public void SetButton()
    {
        setButtons = true;
    }

    public void SetButton1()
    {
        setButtons1 = true;
    }

    public void SetButton2()
    {
        setButtons2 = true;
    }

    public void SetButton3()
    {
        setButtons3 = true;
    }

    public void SetButton4()
    {
        setButtons4 = true;
    }

    public void SetButton5()
    {
        setButtons5 = true;
    }

    public void SetButton6()
    {
        setButtons6 = true;
    }

    public void SetButton7()
    {
        setButtons7 = true;
    }

    public void SetButton8()
    {
        setButtons8 = true;
    }

    // Displays the question and the answers on the card
    public void AskQuestion()
    {
        // Generates a random number to help choose a random question from a category
        randomNumber = Random.Range(0, 5);

        // Determines if any of the buttons in the first column/category were selected
        if (setButtons == true || setButtons3 == true || setButtons6 == true)
        {
            category = 1;
            // Displays the level 1 question if this button was selected
            if (setButtons == true)
            {
                questionText.text = questionsScript.randomCategory1.level1[randomNumber].question;
                answerAText.text = questionsScript.randomCategory1.level1[randomNumber].answerA;
                answerBText.text = questionsScript.randomCategory1.level1[randomNumber].answerB;
                answerCText.text = questionsScript.randomCategory1.level1[randomNumber].answerC;
                questionNumber = 0;
                buttonNumber = 0;
                setButtons = false;
                level1Selected = true;
            }
            // Displays the level 2 question if this button was selected
            else if (setButtons3 == true)
            {
                questionText.text = questionsScript.randomCategory1.level2[randomNumber].question;
                answerAText.text = questionsScript.randomCategory1.level2[randomNumber].answerA;
                answerBText.text = questionsScript.randomCategory1.level2[randomNumber].answerB;
                answerCText.text = questionsScript.randomCategory1.level2[randomNumber].answerC;
                questionNumber = 1;
                buttonNumber = 3;
                setButtons3 = false;
                level2Selected = true;
            }
            // Displays the level 3 question if this button was selected
            else if (setButtons6 == true)
            {
                questionText.text = questionsScript.randomCategory1.level3[randomNumber].question;
                answerAText.text = questionsScript.randomCategory1.level3[randomNumber].answerA;
                answerBText.text = questionsScript.randomCategory1.level3[randomNumber].answerB;
                answerCText.text = questionsScript.randomCategory1.level3[randomNumber].answerC;
                questionNumber = 2;
                buttonNumber = 6;
                setButtons6 = false;
                level3Selected = true;
            }
        }
        // Determines if any of the buttons in the second column/category were selected
        else if (setButtons1 == true || setButtons4 == true || setButtons7 == true)
        {
            category = 2;
            // Displays the level 1 question if this button was selected
            if (setButtons1 == true)
            {
                questionText.text = questionsScript.randomCategory2.level1[randomNumber].question;
                answerAText.text = questionsScript.randomCategory2.level1[randomNumber].answerA;
                answerBText.text = questionsScript.randomCategory2.level1[randomNumber].answerB;
                answerCText.text = questionsScript.randomCategory2.level1[randomNumber].answerC;
                questionNumber = 0;
                buttonNumber = 1;
                setButtons1 = false;
                level1Selected = true;
            }
            // Displays the level 2 question if this button was selected
            else if (setButtons4 == true)
            {
                questionText.text = questionsScript.randomCategory2.level2[randomNumber].question;
                answerAText.text = questionsScript.randomCategory2.level2[randomNumber].answerA;
                answerBText.text = questionsScript.randomCategory2.level2[randomNumber].answerB;
                answerCText.text = questionsScript.randomCategory2.level2[randomNumber].answerC;
                questionNumber = 1;
                buttonNumber = 4;
                setButtons4 = false;
                level2Selected = true;
            }
            // Displays the level 3 question if this button was selected
            else if (setButtons7 == true)
            {
                questionText.text = questionsScript.randomCategory2.level3[randomNumber].question;
                answerAText.text = questionsScript.randomCategory2.level3[randomNumber].answerA;
                answerBText.text = questionsScript.randomCategory2.level3[randomNumber].answerB;
                answerCText.text = questionsScript.randomCategory2.level3[randomNumber].answerC;
                questionNumber = 2;
                buttonNumber = 7;
                setButtons7 = false;
                level3Selected = true;
            }
        }
        // Determines if any of the buttons in the third column/category were selected
        else if (setButtons2 == true || setButtons5 == true || setButtons8 == true)
        {
            category = 3;
            // Displays the level 1 question if this button was selected
            if (setButtons2 == true)
            {
                questionText.text = questionsScript.randomCategory3.level1[randomNumber].question;
                answerAText.text = questionsScript.randomCategory3.level1[randomNumber].answerA;
                answerBText.text = questionsScript.randomCategory3.level1[randomNumber].answerB;
                answerCText.text = questionsScript.randomCategory3.level1[randomNumber].answerC;
                questionNumber = 0;
                buttonNumber = 2;
                setButtons2 = false;
                level1Selected = true;
            }
            // Displays the level 2 question if this button was selected
            else if (setButtons5 == true)
            {
                questionText.text = questionsScript.randomCategory3.level2[randomNumber].question;
                answerAText.text = questionsScript.randomCategory3.level2[randomNumber].answerA;
                answerBText.text = questionsScript.randomCategory3.level2[randomNumber].answerB;
                answerCText.text = questionsScript.randomCategory3.level2[randomNumber].answerC;
                questionNumber = 1;
                buttonNumber = 5;
                setButtons5 = false;
                level2Selected = true;
            }
            // Displays the level 3 question if this button was selected
            else if (setButtons8 == true)
            {
                questionText.text = questionsScript.randomCategory3.level3[randomNumber].question;
                answerAText.text = questionsScript.randomCategory3.level3[randomNumber].answerA;
                answerBText.text = questionsScript.randomCategory3.level3[randomNumber].answerB;
                answerCText.text = questionsScript.randomCategory3.level3[randomNumber].answerC;
                questionNumber = 2;
                buttonNumber = 8;
                setButtons8 = false;
                level3Selected = true;
            }
        }
    }

    // Activates when an answer button is clicked
    public void AnsweredQuestion()
    {
        questionAnswered = false;

        // Determines if the question answered was in the first category
        if (category == 1)
        {
            // Determines if the question has been answered
            if (!questionAnswered)
            {
                // Determines if the answer A was selected
                if (answerA == true)
                {
                    // Sets the grid space to the players marker if the A answer was correct
                    if ((questionsScript.randomCategory1.level1[randomNumber].answer == Questions.Answer.A && level1Selected) || (questionsScript.randomCategory1.level2[randomNumber].answer == Questions.Answer.A && level2Selected) ||
                        (questionsScript.randomCategory1.level3[randomNumber].answer == Questions.Answer.A && level3Selected))
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();

                    questionAnswered = true;
                }
                // Determines if the answer B was selected
                else if (answerB == true)
                {
                    // Sets the grid space to the players marker if the B answer was correct
                    if ((questionsScript.randomCategory1.level1[randomNumber].answer == Questions.Answer.B && level1Selected) || (questionsScript.randomCategory1.level2[randomNumber].answer == Questions.Answer.B && level2Selected) ||
                        (questionsScript.randomCategory1.level3[randomNumber].answer == Questions.Answer.B && level3Selected))
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();

                    questionAnswered = true;
                }
                // Determines if the answer C was selected
                else if (answerC == true)
                {
                    // Sets the grid space to the players marker if the C answer was correct
                    if ((questionsScript.randomCategory1.level1[randomNumber].answer == Questions.Answer.C && level1Selected) || (questionsScript.randomCategory1.level2[randomNumber].answer == Questions.Answer.C && level2Selected) ||
                        (questionsScript.randomCategory1.level3[randomNumber].answer == Questions.Answer.C && level3Selected))
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();

                    questionAnswered = true;
                }
            }
        }
        // Determines if the question answered was in the second category
        else if (category == 2)
        {
            // Determines if the question has been answered
            if (!questionAnswered)
            {
                // Determines if the answer A was selected
                if (answerA == true)
                {
                    // Sets the grid space to the players marker if the A answer was correct
                    if ((questionsScript.randomCategory2.level1[randomNumber].answer == Questions.Answer.A && level1Selected) || (questionsScript.randomCategory2.level2[randomNumber].answer == Questions.Answer.A && level2Selected) || 
                        (questionsScript.randomCategory2.level3[randomNumber].answer == Questions.Answer.A && level3Selected))
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();

                    questionAnswered = true;
                }
                // Determines if the answer B was selected
                else if (answerB == true)
                {
                    // Sets the grid space to the players marker if the B answer was correct
                    if ((questionsScript.randomCategory2.level1[randomNumber].answer == Questions.Answer.B && level1Selected) || (questionsScript.randomCategory2.level2[randomNumber].answer == Questions.Answer.B && level2Selected) ||
                        (questionsScript.randomCategory2.level3[randomNumber].answer == Questions.Answer.B && level3Selected))
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();

                    questionAnswered = true;
                }
                // Determines if the answer C was selected
                else if (answerC == true)
                {
                    // Sets the grid space to the players marker if the C answer was correct
                    if ((questionsScript.randomCategory2.level1[randomNumber].answer == Questions.Answer.C && level1Selected) || (questionsScript.randomCategory2.level2[randomNumber].answer == Questions.Answer.C && level2Selected) ||
                        (questionsScript.randomCategory2.level3[randomNumber].answer == Questions.Answer.C && level3Selected))
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();

                    questionAnswered = true;
                }
            }
        }
        // Determines if the question answered was in the third category
        else if (category == 3)
        {
            // Determines if the question has been answered
            if (!questionAnswered)
            {
                // Determines if the answer A was selected
                if (answerA == true)
                {
                    // Sets the grid space to the players marker if the A answer was correct
                    if ((questionsScript.randomCategory3.level1[randomNumber].answer == Questions.Answer.A && level1Selected) || (questionsScript.randomCategory3.level2[randomNumber].answer == Questions.Answer.A && level2Selected) ||
                        (questionsScript.randomCategory3.level3[randomNumber].answer == Questions.Answer.A && level3Selected))
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();

                    questionAnswered = true;
                }
                // Determines if the answer B was selected
                else if (answerB == true)
                {
                    // Sets the grid space to the players marker if the B answer was correct
                    if ((questionsScript.randomCategory3.level1[randomNumber].answer == Questions.Answer.B && level1Selected) || (questionsScript.randomCategory3.level2[randomNumber].answer == Questions.Answer.B && level2Selected) ||
                        (questionsScript.randomCategory3.level3[randomNumber].answer == Questions.Answer.B && level3Selected))
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();

                    questionAnswered = true;
                }
                // Determines if the answer C was selected
                else if (answerC == true)
                {
                    // Sets the grid space to the players marker if the C answer was correct
                    if ((questionsScript.randomCategory3.level1[randomNumber].answer == Questions.Answer.C && level1Selected) || (questionsScript.randomCategory3.level2[randomNumber].answer == Questions.Answer.C && level2Selected) ||
                        (questionsScript.randomCategory3.level3[randomNumber].answer == Questions.Answer.C && level3Selected))
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();

                    questionAnswered = true;
                }
            }
        }

        // Resets all the question values back to false
        level1Selected = false;
        level2Selected = false;
        level3Selected = false;
        answerA = false;
        answerB = false;
        answerC = false;
        SetBoardInteractable(true);
        cardPanel.SetActive(false);
        EndTurn();
    }
}
