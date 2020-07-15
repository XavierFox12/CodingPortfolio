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
    public GameObject[] match3Lines;                // Reference to the Match 3 lines
    public GameObject gameOverPanel;                // Reference to the Game Over panel
    public Text gameOverText;                       // Reference to the Game Over text
    public GameObject restartButton;                // Reference to the Restart button
    public GameObject scoreCard;                    // Reference to the Score Card Panel

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
    public Text xWinsLoses;                         // Reference to the amount of wins and loses for X
    public Text oWinsLoses;                         // Reference to the amount of wins and loses for O
    public Text draws;                              // Reference to the amount of draws
    public Slider questionSlider;                   // Reference to the timer slider
    public static bool enableAI;                    // Determines if the AI will be playing
    [Range(1, 3)] public static int aiLevel;        // Determines the difficulty of the AI
    public float questionTimer = 10f;               // Question timer for the user

    // Private Variables
    private string playerSide;                      // String that holds if player is either X or O
    private string aiSide;                          // String that holds if the AI is either X or O
    private int category;                           // Integer that determines what category the player picked
    private int moveCount;                          // Integer that determines how many moves have been made between the two players
    private int questionNumber = 0;                 // Integer that determines what question number will be displayed to the user
    private int buttonNumber = 0;                   // Integer that determines what button the player picked on the board
    private int randomNumber;                       // Integer that holds a random number to determine what question will be given
    private int whoGoesFirst = 0;                   // Integer to determine who goes first
    private static int xWins = 0;                   // Integer to determine the amount of X's wins
    private static int xLoses = 0;                  // Integer to determine the amount of X's loses
    private static int oWins = 0;                   // Integer to determine the amount of O's wins
    private static int oLoses = 0;                  // Integer to determine the amount of O's loses
    private static int drawScore = 0;               // Integer to determine the amount of Draws
    private bool answerA = false;                   // Determines if the player picked answer A
    private bool answerB = false;                   // Determines if the player picked answer B
    private bool answerC = false;                   // Determines if the player picked answer C
    private bool questionAnswered = false;          // Determines if the player actually answered the question
    private bool level1Selected = false;            // Determines if a level 1 question was selected
    private bool level2Selected = false;            // Determines if a level 2 question was selected
    private bool level3Selected = false;            // Determines if a level 3 question was selected
    private bool changeColor = true;                // Determines if the X and O panels should update their colors
    private bool timerStart = false;                // Determines if the timer should start

    // These variables are used to determine if any of the 9 buttons were hit
    /*private bool setButtons = false;
    private bool setButtons1 = false;
    private bool setButtons2 = false;
    private bool setButtons3 = false;
    private bool setButtons4 = false;
    private bool setButtons5 = false;
    private bool setButtons6 = false;
    private bool setButtons7 = false;
    private bool setButtons8 = false;*/
    private bool[] buttonSet = new bool[9];
    private Questions questionsScript;              // Reference to the Questions script
    private Player2AI aiScript;                     // Reference to the AI script

    // Sets the categories, gets the reference on the buttons, and disables everything
    private void Awake()
    {
        questionsScript = GetComponent<Questions>();
        aiScript = GetComponent<Player2AI>();
        moveCount = 0;
        SetGameControllerReferenceOnButtons();
        gameOverPanel.SetActive(false);
        restartButton.SetActive(false);
        scoreCard.SetActive(false);

        // Loops through and sets all of the grid buttons to false
        for (int i = 0; i < buttonSet.Length; i++)
        {
            buttonSet[i] = false;
        }

        questionsScript.ChooseCategories();
        category1.text = questionsScript.randomCategory1.categoryName.ToString();
        category2.text = questionsScript.randomCategory2.categoryName.ToString();
        category3.text = questionsScript.randomCategory3.categoryName.ToString();
    }

    private void Update()
    {
        // TESTING ONLY: used to switch the categories by pressing the q button
        if (Input.GetKeyDown("q"))
        {
            //SceneManager.LoadScene("TitleScreen");
            questionsScript.ChooseCategories();
            category1.text = questionsScript.randomCategory1.categoryName.ToString();
            category2.text = questionsScript.randomCategory2.categoryName.ToString();
            category3.text = questionsScript.randomCategory3.categoryName.ToString();
        }

        // Flashes the Player O and Player X panels with different colors to get the users attention
        if (changeColor)
        {
            playerO.panel.color = Color.Lerp(Color.gray, Color.black, Mathf.PingPong(Time.time, 1.2f));
            playerX.panel.color = Color.Lerp(Color.gray, Color.black, Mathf.PingPong(Time.time, 1.2f));
        }

        if(timerStart)
        {
            if(questionTimer <= 0)
            {
                StartCoroutine(DisplayRightOrWrong(false));
            }
            else
            {
                questionTimer -= Time.deltaTime;
                questionSlider.value = questionTimer;
            }
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

    public void QuitToMenu()
    {
        SceneManager.LoadScene("TitleScreen");
    }

    // Determines who goes first depending on if X or O was chosen at the start
    public void SetStartingSide(string startingSide)
    {
        playerSide = startingSide;
        if (playerSide == "X")
        {
            if (enableAI)
            {
                aiScript.SetAISide("X", "O");
                aiSide = "O";
            }
            //SetPlayerColors(playerX, playerO);
        }
        else
        {
            if (enableAI)
            {
                aiScript.SetAISide("O", "X");
                aiSide = "X";
            }
            //SetPlayerColors(playerO, playerX);
        }

        StartCoroutine(CoinFlip());

        //StartGame();
    }

    IEnumerator CoinFlip()
    {
        float randomTimer = 5f;
        SetPlayerButtons(false);

        while (randomTimer >= 0)
        {
            if (playerO.panel.color == Color.black)
            {
                playerO.panel.color = Color.clear;
                playerX.panel.color = Color.black;
            }
            else
            {
                playerO.panel.color = Color.black;
                playerX.panel.color = Color.clear;
            }
            randomTimer -= Time.deltaTime;
            yield return 0;
        }

        whoGoesFirst = Random.Range(0, 2);
        if (whoGoesFirst == 0)
        {
            if (playerSide == "X")
            {
                SetPlayerColors(playerX, playerO);
            }
            else
            {
                SetPlayerColors(playerO, playerX);
            }
        }
        else
        {
            ChangeSides();
        }
        StartGame();
    }

    // Sets the game board to be active
    void StartGame()
    {
        SetBoardInteractable(true);
        //SetPlayerButtons(false);
        startInfo.SetActive(false);
        changeColor = false;
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
            if(enableAI && aiSide == "X")
            {
                if (aiLevel == 1)
                {
                    aiScript.EasyAISelection();
                }
                else if (aiLevel == 2)
                {
                    aiScript.MediumAISelection();
                }
                else if (aiLevel == 3)
                {
                    aiScript.HardAISelection();
                }
            }
        }
        else
        {
            SetPlayerColors(playerO, playerX);
            if (enableAI && aiSide == "O")
            {
                if (aiLevel == 1)
                {
                    aiScript.EasyAISelection();
                }
                else if (aiLevel == 2)
                {
                    aiScript.MediumAISelection();
                }
                else if (aiLevel == 3)
                {
                    aiScript.HardAISelection();
                }
            }
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

        if (buttonList[0].text == playerSide && buttonList[1].text == playerSide && buttonList[2].text == playerSide)
        {
            match3Lines[3].SetActive(true);
            GameOver(playerSide);
        }
        else if (buttonList[3].text == playerSide && buttonList[4].text == playerSide && buttonList[5].text == playerSide)
        {
            match3Lines[4].SetActive(true);
            GameOver(playerSide);
        }
        else if (buttonList[6].text == playerSide && buttonList[7].text == playerSide && buttonList[8].text == playerSide)
        {
            match3Lines[5].SetActive(true);
            GameOver(playerSide);
        }
        else if (buttonList[0].text == playerSide && buttonList[3].text == playerSide && buttonList[6].text == playerSide)
        {
            match3Lines[0].SetActive(true);
            GameOver(playerSide);
        }
        else if (buttonList[1].text == playerSide && buttonList[4].text == playerSide && buttonList[7].text == playerSide)
        {
            match3Lines[1].SetActive(true);
            GameOver(playerSide);
        }
        else if (buttonList[2].text == playerSide && buttonList[5].text == playerSide && buttonList[8].text == playerSide)
        {
            match3Lines[2].SetActive(true);
            GameOver(playerSide);
        }
        else if (buttonList[0].text == playerSide && buttonList[4].text == playerSide && buttonList[8].text == playerSide)
        {
            match3Lines[6].SetActive(true);
            GameOver(playerSide);
        }
        else if (buttonList[2].text == playerSide && buttonList[4].text == playerSide && buttonList[6].text == playerSide)
        {
            match3Lines[7].SetActive(true);
            GameOver(playerSide);
        }
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
            ++drawScore;
            SetPlayerColorsInactive();
        }
        else
        {
            SetGameOverText(winningPlayer + " Wins!");
            if(winningPlayer == "X")
            {
                ++xWins;
                ++oLoses;
            }
            else
            {
                ++oWins;
                ++xLoses;
            }
        }
        restartButton.SetActive(true);
        scoreCard.SetActive(true);
        xWinsLoses.text = "\n" + xWins + "          " + xLoses;
        oWinsLoses.text = "\n" + oWins + "          " + oLoses;
        draws.text = "\n" + drawScore;
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

        moveCount = 0;
        gameOverPanel.SetActive(false);
        restartButton.SetActive(false);
        scoreCard.SetActive(false);
        SetPlayerButtons(true);
        SetPlayerColorsInactive();
        startInfo.SetActive(true);
        SetBoardInteractable(false);
        changeColor = true;

        for (int i = 0; i < buttonList.Length; i++)
        {
            buttonList[i].text = "";
            buttonList[i].GetComponentInParent<GridSpace>().cardPanel.SetActive(true);
        }

        for (int i = 0; i < match3Lines.Length; i++)
        {
            match3Lines[i].SetActive(false);
        }

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

    // Determines if the grid buttons were hit
    public void SetButtonArray(int buttonNumber)
    {
        buttonSet[buttonNumber] = true;
    }


    // These next 9 functions determine if the grid buttons were hit
    /*public void SetButton()
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
    }*/

    // Displays the question and the answers on the card
    public void AskQuestion()
    {
        //randomNumber = Random.Range(0, 5);

        if (buttonSet[0] == true || buttonSet[3] == true || buttonSet[6] == true)
        {
            category = 1;
            if (buttonSet[0] == true)
            {
                randomNumber = Random.Range(0, questionsScript.randomCategory1.level1.Length);

                questionText.text = questionsScript.randomCategory1.level1[randomNumber].question;
                answerAText.text = questionsScript.randomCategory1.level1[randomNumber].answerA;
                answerBText.text = questionsScript.randomCategory1.level1[randomNumber].answerB;
                answerCText.text = questionsScript.randomCategory1.level1[randomNumber].answerC;
                questionNumber = 0;
                buttonNumber = 0;
                //setButtons = false;
                buttonSet[0] = false;
                level1Selected = true;
            }
            else if (buttonSet[3] == true)
            {
                randomNumber = Random.Range(0, questionsScript.randomCategory1.level2.Length);

                questionText.text = questionsScript.randomCategory1.level2[randomNumber].question;
                answerAText.text = questionsScript.randomCategory1.level2[randomNumber].answerA;
                answerBText.text = questionsScript.randomCategory1.level2[randomNumber].answerB;
                answerCText.text = questionsScript.randomCategory1.level2[randomNumber].answerC;
                questionNumber = 1;
                buttonNumber = 3;
                //setButtons3 = false;
                buttonSet[3] = false;
                level2Selected = true;
            }
            else if (buttonSet[6] == true)
            {
                randomNumber = Random.Range(0, questionsScript.randomCategory1.level3.Length);

                questionText.text = questionsScript.randomCategory1.level3[randomNumber].question;
                answerAText.text = questionsScript.randomCategory1.level3[randomNumber].answerA;
                answerBText.text = questionsScript.randomCategory1.level3[randomNumber].answerB;
                answerCText.text = questionsScript.randomCategory1.level3[randomNumber].answerC;
                questionNumber = 2;
                buttonNumber = 6;
                //setButtons6 = false;
                buttonSet[6] = false;
                level3Selected = true;
            }
        }
        else if (buttonSet[1] == true || buttonSet[4] == true || buttonSet[7] == true)
        {
            category = 2;
            if (buttonSet[1] == true)
            {
                randomNumber = Random.Range(0, questionsScript.randomCategory2.level1.Length);

                questionText.text = questionsScript.randomCategory2.level1[randomNumber].question;
                answerAText.text = questionsScript.randomCategory2.level1[randomNumber].answerA;
                answerBText.text = questionsScript.randomCategory2.level1[randomNumber].answerB;
                answerCText.text = questionsScript.randomCategory2.level1[randomNumber].answerC;
                questionNumber = 0;
                buttonNumber = 1;
                //setButtons1 = false;
                buttonSet[1] = false;
                level1Selected = true;
            }
            else if (buttonSet[4] == true)
            {
                randomNumber = Random.Range(0, questionsScript.randomCategory2.level2.Length);

                questionText.text = questionsScript.randomCategory2.level2[randomNumber].question;
                answerAText.text = questionsScript.randomCategory2.level2[randomNumber].answerA;
                answerBText.text = questionsScript.randomCategory2.level2[randomNumber].answerB;
                answerCText.text = questionsScript.randomCategory2.level2[randomNumber].answerC;
                questionNumber = 1;
                buttonNumber = 4;
                //setButtons4 = false;
                buttonSet[4] = false;
                level2Selected = true;
            }
            else if (buttonSet[7] == true)
            {
                randomNumber = Random.Range(0, questionsScript.randomCategory2.level3.Length);

                questionText.text = questionsScript.randomCategory2.level3[randomNumber].question;
                answerAText.text = questionsScript.randomCategory2.level3[randomNumber].answerA;
                answerBText.text = questionsScript.randomCategory2.level3[randomNumber].answerB;
                answerCText.text = questionsScript.randomCategory2.level3[randomNumber].answerC;
                questionNumber = 2;
                buttonNumber = 7;
                //setButtons7 = false;
                buttonSet[7] = false;
                level3Selected = true;
            }
        }
        else if (buttonSet[2] == true || buttonSet[5] == true || buttonSet[8] == true)
        {
            category = 3;
            if (buttonSet[2] == true)
            {
                randomNumber = Random.Range(0, questionsScript.randomCategory3.level1.Length);

                questionText.text = questionsScript.randomCategory3.level1[randomNumber].question;
                answerAText.text = questionsScript.randomCategory3.level1[randomNumber].answerA;
                answerBText.text = questionsScript.randomCategory3.level1[randomNumber].answerB;
                answerCText.text = questionsScript.randomCategory3.level1[randomNumber].answerC;
                questionNumber = 0;
                buttonNumber = 2;
                //setButtons2 = false;
                buttonSet[2] = false;
                level1Selected = true;
            }
            else if (buttonSet[5] == true)
            {
                randomNumber = Random.Range(0, questionsScript.randomCategory3.level2.Length);

                questionText.text = questionsScript.randomCategory3.level2[randomNumber].question;
                answerAText.text = questionsScript.randomCategory3.level2[randomNumber].answerA;
                answerBText.text = questionsScript.randomCategory3.level2[randomNumber].answerB;
                answerCText.text = questionsScript.randomCategory3.level2[randomNumber].answerC;
                questionNumber = 1;
                buttonNumber = 5;
                //setButtons5 = false;
                buttonSet[5] = false;
                level2Selected = true;
            }
            else if (buttonSet[8] == true)
            {
                randomNumber = Random.Range(0, questionsScript.randomCategory3.level3.Length);

                questionText.text = questionsScript.randomCategory3.level3[randomNumber].question;
                answerAText.text = questionsScript.randomCategory3.level3[randomNumber].answerA;
                answerBText.text = questionsScript.randomCategory3.level3[randomNumber].answerB;
                answerCText.text = questionsScript.randomCategory3.level3[randomNumber].answerC;
                questionNumber = 2;
                buttonNumber = 8;
                //setButtons8 = false;
                buttonSet[8] = false;
                level3Selected = true;
            }
        }

        timerStart = true;
    }

    // Gets the random number for the answer to the question
    public int GetRandomNumber()
    {
        return randomNumber;
    }

    private void ResetTimer()
    {
        timerStart = false;
        questionTimer = 10;
        questionSlider.value = 10;
    }

    // Activates when an answer button is clicked
    public void AnsweredQuestion()
    {
        questionAnswered = false;
        
        if (category == 1)
        {
            if (!questionAnswered)
            {
                if (answerA == true)
                {
                    if(level1Selected)
                    {
                        if (questionsScript.randomCategory1.level1[randomNumber].answer == Questions.Answer.A)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                    else if(level2Selected)
                    {
                        if (questionsScript.randomCategory1.level2[randomNumber].answer == Questions.Answer.A)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                    else if(level3Selected)
                    {
                        if (questionsScript.randomCategory1.level3[randomNumber].answer == Questions.Answer.A)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                }
                else if (answerB == true)
                {
                    if (level1Selected)
                    {
                        if (questionsScript.randomCategory1.level1[randomNumber].answer == Questions.Answer.B)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                    else if (level2Selected)
                    {
                        if (questionsScript.randomCategory1.level2[randomNumber].answer == Questions.Answer.B)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                    else if (level3Selected)
                    {
                        if (questionsScript.randomCategory1.level3[randomNumber].answer == Questions.Answer.B)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                }
                else if (answerC == true)
                {
                    if (level1Selected)
                    {
                        if (questionsScript.randomCategory1.level1[randomNumber].answer == Questions.Answer.C)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                    else if (level2Selected)
                    {
                        if (questionsScript.randomCategory1.level2[randomNumber].answer == Questions.Answer.C)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                    else if (level3Selected)
                    {
                        if (questionsScript.randomCategory1.level3[randomNumber].answer == Questions.Answer.C)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                }
            }
        }
        else if (category == 2)
        {
            if (!questionAnswered)
            {
                if (answerA == true)
                {
                    if (level1Selected)
                    {
                        if (questionsScript.randomCategory2.level1[randomNumber].answer == Questions.Answer.A)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                    else if (level2Selected)
                    {
                        if (questionsScript.randomCategory2.level2[randomNumber].answer == Questions.Answer.A)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                    else if (level3Selected)
                    {
                        if (questionsScript.randomCategory2.level3[randomNumber].answer == Questions.Answer.A)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                }
                else if (answerB == true)
                {
                    if (level1Selected)
                    {
                        if (questionsScript.randomCategory2.level1[randomNumber].answer == Questions.Answer.B)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                    else if (level2Selected)
                    {
                        if (questionsScript.randomCategory2.level2[randomNumber].answer == Questions.Answer.B)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                    else if (level3Selected)
                    {
                        if (questionsScript.randomCategory2.level3[randomNumber].answer == Questions.Answer.B)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                }
                else if (answerC == true)
                {
                    if (level1Selected)
                    {
                        if (questionsScript.randomCategory2.level1[randomNumber].answer == Questions.Answer.C)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                    else if (level2Selected)
                    {
                        if (questionsScript.randomCategory2.level2[randomNumber].answer == Questions.Answer.C)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                    else if (level3Selected)
                    {
                        if (questionsScript.randomCategory2.level3[randomNumber].answer == Questions.Answer.C)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                }
            }
        }
        else if (category == 3)
        {
            if (!questionAnswered)
            {
                if (answerA == true)
                {
                    if (level1Selected)
                    {
                        if (questionsScript.randomCategory3.level1[randomNumber].answer == Questions.Answer.A)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                    else if (level2Selected)
                    {
                        if (questionsScript.randomCategory3.level2[randomNumber].answer == Questions.Answer.A)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                    else if (level3Selected)
                    {
                        if (questionsScript.randomCategory3.level3[randomNumber].answer == Questions.Answer.A)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                }
                else if (answerB == true)
                {
                    if (level1Selected)
                    {
                        if (questionsScript.randomCategory3.level1[randomNumber].answer == Questions.Answer.B)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                    else if (level2Selected)
                    {
                        if (questionsScript.randomCategory3.level2[randomNumber].answer == Questions.Answer.B)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                    else if (level3Selected)
                    {
                        if (questionsScript.randomCategory3.level3[randomNumber].answer == Questions.Answer.B)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                }
                else if (answerC == true)
                {
                    if (level1Selected)
                    {
                        if (questionsScript.randomCategory3.level1[randomNumber].answer == Questions.Answer.C)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                    else if (level2Selected)
                    {
                        if (questionsScript.randomCategory3.level2[randomNumber].answer == Questions.Answer.C)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                    else if (level3Selected)
                    {
                        if (questionsScript.randomCategory3.level3[randomNumber].answer == Questions.Answer.C)
                        {
                            CorrectAnswer();
                        }
                        else
                        {
                            IncorrectAnswer();
                        }
                    }
                }
            }
        }


        // OLD VERSION: WORKED WHEN THE RANDOM NUMBER WAS A SET NUMBER
        /*if (category == 1)
        {
            if (!questionAnswered)
            {
                if (answerA == true)
                {
                    if ((questionsScript.randomCategory1.level1[randomNumber].answer == Questions.Answer.A && level1Selected) || (questionsScript.randomCategory1.level2[randomNumber].answer == Questions.Answer.A && level2Selected) ||
                        (questionsScript.randomCategory1.level3[randomNumber].answer == Questions.Answer.A && level3Selected))
                    {
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();
                        StartCoroutine(DisplayRightOrWrong(true));
                    }
                    else
                    {
                        StartCoroutine(DisplayRightOrWrong(false));
                    }
                }
                else if (answerB == true)
                {
                    if ((questionsScript.randomCategory1.level1[randomNumber].answer == Questions.Answer.B && level1Selected) || (questionsScript.randomCategory1.level2[randomNumber].answer == Questions.Answer.B && level2Selected) ||
                        (questionsScript.randomCategory1.level3[randomNumber].answer == Questions.Answer.B && level3Selected))
                    {
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();
                        StartCoroutine(DisplayRightOrWrong(true));
                    }
                    else
                    {
                        StartCoroutine(DisplayRightOrWrong(false));
                    }
                }
                else if (answerC == true)
                {
                    if ((questionsScript.randomCategory1.level1[randomNumber].answer == Questions.Answer.C && level1Selected) || (questionsScript.randomCategory1.level2[randomNumber].answer == Questions.Answer.C && level2Selected) ||
                        (questionsScript.randomCategory1.level3[randomNumber].answer == Questions.Answer.C && level3Selected))
                    {
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();
                        StartCoroutine(DisplayRightOrWrong(true));
                    }
                    else
                    {
                        StartCoroutine(DisplayRightOrWrong(false));
                    }
                }
            }
        }
        else if (category == 2)
        {
            if (!questionAnswered)
            {
                if (answerA == true)
                {
                    if ((questionsScript.randomCategory2.level1[randomNumber].answer == Questions.Answer.A && level1Selected) || (questionsScript.randomCategory2.level2[randomNumber].answer == Questions.Answer.A && level2Selected) ||
                        (questionsScript.randomCategory2.level3[randomNumber].answer == Questions.Answer.A && level3Selected))
                    {
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();
                        StartCoroutine(DisplayRightOrWrong(true));
                    }
                    else
                    {
                        StartCoroutine(DisplayRightOrWrong(false));
                    }
                }
                else if (answerB == true)
                {
                    if ((questionsScript.randomCategory2.level1[randomNumber].answer == Questions.Answer.B && level1Selected) || (questionsScript.randomCategory2.level2[randomNumber].answer == Questions.Answer.B && level2Selected) ||
                        (questionsScript.randomCategory2.level3[randomNumber].answer == Questions.Answer.B && level3Selected))
                    {
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();
                        StartCoroutine(DisplayRightOrWrong(true));
                    }
                    else
                    {
                        StartCoroutine(DisplayRightOrWrong(false));
                    }
                }
                else if (answerC == true)
                {
                    if ((questionsScript.randomCategory2.level1[randomNumber].answer == Questions.Answer.C && level1Selected) || (questionsScript.randomCategory2.level2[randomNumber].answer == Questions.Answer.C && level2Selected) ||
                        (questionsScript.randomCategory2.level3[randomNumber].answer == Questions.Answer.C && level3Selected))
                    {
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();
                        StartCoroutine(DisplayRightOrWrong(true));
                    }
                    else
                    {
                        StartCoroutine(DisplayRightOrWrong(false));
                    }
                }
            }
        }
        else if (category == 3)
        {
            if (!questionAnswered)
            {
                if (answerA == true)
                {
                    if ((questionsScript.randomCategory3.level1[randomNumber].answer == Questions.Answer.A && level1Selected) || (questionsScript.randomCategory3.level2[randomNumber].answer == Questions.Answer.A && level2Selected) ||
                        (questionsScript.randomCategory3.level3[randomNumber].answer == Questions.Answer.A && level3Selected))
                    {
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();
                        StartCoroutine(DisplayRightOrWrong(true));
                    }
                    else
                    {
                        StartCoroutine(DisplayRightOrWrong(false));
                    }
                }
                else if (answerB == true)
                {
                    if ((questionsScript.randomCategory3.level1[randomNumber].answer == Questions.Answer.B && level1Selected) || (questionsScript.randomCategory3.level2[randomNumber].answer == Questions.Answer.B && level2Selected) ||
                        (questionsScript.randomCategory3.level3[randomNumber].answer == Questions.Answer.B && level3Selected))
                    {
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();
                        StartCoroutine(DisplayRightOrWrong(true));
                    }
                    else
                    {
                        StartCoroutine(DisplayRightOrWrong(false));
                    }
                }
                else if (answerC == true)
                {
                    if ((questionsScript.randomCategory3.level1[randomNumber].answer == Questions.Answer.C && level1Selected) || (questionsScript.randomCategory3.level2[randomNumber].answer == Questions.Answer.C && level2Selected) ||
                        (questionsScript.randomCategory3.level3[randomNumber].answer == Questions.Answer.C && level3Selected))
                    {
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();
                        StartCoroutine(DisplayRightOrWrong(true));
                    }
                    else
                    {
                        StartCoroutine(DisplayRightOrWrong(false));
                    }
                }
            }
        }*/
    }

    // Starts the coroutine if the answer is correct
    private void CorrectAnswer()
    {
        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();
        StartCoroutine(DisplayRightOrWrong(true));
    }

    // Starts the coroutine if the answer is incorrect
    private void IncorrectAnswer()
    {
        StartCoroutine(DisplayRightOrWrong(false));
    }

    // Displays whether or not the player got the question right or wrong
    IEnumerator DisplayRightOrWrong(bool correct)
    {
        ResetTimer();
        questionAnswered = true;
        level1Selected = false;
        level2Selected = false;
        level3Selected = false;
        answerA = false;
        answerB = false;
        answerC = false;
        //SetBoardInteractable(true);
        cardPanel.SetActive(false);
        gameOverPanel.SetActive(true);
        if (correct)
        {
            gameOverText.text = "Correct";
        }
        else
        {
            gameOverText.text = "Incorrect";
        }
        yield return new WaitForSeconds(2f);
        gameOverPanel.SetActive(false);
        SetBoardInteractable(true);
        gameOverText.text = "";
        EndTurn();
        //yield return 0;
    }

    // Activates when an answer button is clicked
    /*public void AnsweredQuestion()
    {
        questionAnswered = false;

        if (category == 1)
        {
            if (!questionAnswered)
            {
                if (answerA == true)
                {
                    if ((questionsScript.randomCategory1.level1[randomNumber].answer == Questions.Answer.A && level1Selected) || (questionsScript.randomCategory1.level2[randomNumber].answer == Questions.Answer.A && level2Selected) ||
                        (questionsScript.randomCategory1.level3[randomNumber].answer == Questions.Answer.A && level3Selected))
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();

                    questionAnswered = true;
                }
                else if (answerB == true)
                {
                    if ((questionsScript.randomCategory1.level1[randomNumber].answer == Questions.Answer.B && level1Selected) || (questionsScript.randomCategory1.level2[randomNumber].answer == Questions.Answer.B && level2Selected) ||
                        (questionsScript.randomCategory1.level3[randomNumber].answer == Questions.Answer.B && level3Selected))
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();

                    questionAnswered = true;
                }
                else if (answerC == true)
                {
                    if ((questionsScript.randomCategory1.level1[randomNumber].answer == Questions.Answer.C && level1Selected) || (questionsScript.randomCategory1.level2[randomNumber].answer == Questions.Answer.C && level2Selected) ||
                        (questionsScript.randomCategory1.level3[randomNumber].answer == Questions.Answer.C && level3Selected))
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();

                    questionAnswered = true;
                }
            }
        }
        else if (category == 2)
        {
            if (!questionAnswered)
            {
                if (answerA == true)
                {
                    if ((questionsScript.randomCategory2.level1[randomNumber].answer == Questions.Answer.A && level1Selected) || (questionsScript.randomCategory2.level2[randomNumber].answer == Questions.Answer.A && level2Selected) || 
                        (questionsScript.randomCategory2.level3[randomNumber].answer == Questions.Answer.A && level3Selected))
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();

                    questionAnswered = true;
                }
                else if (answerB == true)
                {
                    if ((questionsScript.randomCategory2.level1[randomNumber].answer == Questions.Answer.B && level1Selected) || (questionsScript.randomCategory2.level2[randomNumber].answer == Questions.Answer.B && level2Selected) ||
                        (questionsScript.randomCategory2.level3[randomNumber].answer == Questions.Answer.B && level3Selected))
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();

                    questionAnswered = true;
                }
                else if (answerC == true)
                {
                    if ((questionsScript.randomCategory2.level1[randomNumber].answer == Questions.Answer.C && level1Selected) || (questionsScript.randomCategory2.level2[randomNumber].answer == Questions.Answer.C && level2Selected) ||
                        (questionsScript.randomCategory2.level3[randomNumber].answer == Questions.Answer.C && level3Selected))
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();

                    questionAnswered = true;
                }
            }
        }
        else if (category == 3)
        {
            if (!questionAnswered)
            {
                if (answerA == true)
                {
                    if ((questionsScript.randomCategory3.level1[randomNumber].answer == Questions.Answer.A && level1Selected) || (questionsScript.randomCategory3.level2[randomNumber].answer == Questions.Answer.A && level2Selected) ||
                        (questionsScript.randomCategory3.level3[randomNumber].answer == Questions.Answer.A && level3Selected))
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();

                    questionAnswered = true;
                }
                else if (answerB == true)
                {
                    if ((questionsScript.randomCategory3.level1[randomNumber].answer == Questions.Answer.B && level1Selected) || (questionsScript.randomCategory3.level2[randomNumber].answer == Questions.Answer.B && level2Selected) ||
                        (questionsScript.randomCategory3.level3[randomNumber].answer == Questions.Answer.B && level3Selected))
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();

                    questionAnswered = true;
                }
                else if (answerC == true)
                {
                    if ((questionsScript.randomCategory3.level1[randomNumber].answer == Questions.Answer.C && level1Selected) || (questionsScript.randomCategory3.level2[randomNumber].answer == Questions.Answer.C && level2Selected) ||
                        (questionsScript.randomCategory3.level3[randomNumber].answer == Questions.Answer.C && level3Selected))
                        buttonList[buttonNumber].GetComponentInParent<GridSpace>().SetSpace();

                    questionAnswered = true;
                }
            }
        }

        level1Selected = false;
        level2Selected = false;
        level3Selected = false;
        answerA = false;
        answerB = false;
        answerC = false;
        SetBoardInteractable(true);
        cardPanel.SetActive(false);
        EndTurn();
    }*/
}
