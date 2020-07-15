using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Player2AI : MonoBehaviour
{
    private GameController gameController;          // Reference to the GameController script
    private Questions questionScript;               // Reference to the Question script
    private string playerSide;                      // Reference to the Player's character
    private string aiSide;                          // Reference to the AI's character
    private int randomNumber = 0;                   // Holds a random number
    private int aAnswerOdds = 0;                    // Determines the odds for the answer A
    private int bAnswerOdds = 0;                    // Determines the odds for the answer B
    private int cAnswerOdds = 0;                    // Determines the odds for the answer C
    private bool randomCategory1 = false;           // Boolean that determines if the first category is selected
    private bool randomCategory2 = false;           // Boolean that determines if the second category is selected
    private bool randomCategory3 = false;           // Boolean that determines if the third category is selected
    private bool level1 = false;                    // Boolean that determines if the first category is selected
    private bool level2 = false;                    // Boolean that determines if the second category is selected
    private bool level3 = false;                    // Boolean that determines if the third category is selected

    // Use this for initialization
    void Awake ()
    {
        gameController = GetComponent<GameController>();
        questionScript = GetComponent<Questions>();
	}

    public void SetAISide(string sidePlayer, string sideAI)
    {
        playerSide = sidePlayer;
        aiSide = sideAI;
    }

    private void MakeMove()
    {
        // AI Winning Move Top Left 0
        if (gameController.buttonList[0].text == "" && ((gameController.buttonList[1].text == aiSide && gameController.buttonList[2].text == aiSide) || (gameController.buttonList[3].text == aiSide && gameController.buttonList[6].text == aiSide) || (gameController.buttonList[4].text == aiSide && gameController.buttonList[8].text == aiSide)))
        {
            randomCategory1 = true;
            level1 = true;
            gameController.SetButtonArray(0);
            gameController.buttonList[0].GetComponentInParent<GridSpace>().ActivateQuestion();
        }
        // AI Winning Move Top Middle 1
        else if (gameController.buttonList[1].text == "" && ((gameController.buttonList[0].text == aiSide && gameController.buttonList[2].text == aiSide) || (gameController.buttonList[4].text == aiSide && gameController.buttonList[7].text == aiSide)))
        {
            randomCategory2 = true;
            level1 = true;
            gameController.SetButtonArray(1);
            gameController.buttonList[1].GetComponentInParent<GridSpace>().ActivateQuestion();
        }
        // AI Winning Move Top Right 2
        else if (gameController.buttonList[2].text == "" && ((gameController.buttonList[0].text == aiSide && gameController.buttonList[1].text == aiSide) || (gameController.buttonList[5].text == aiSide && gameController.buttonList[8].text == aiSide) || (gameController.buttonList[4].text == aiSide && gameController.buttonList[6].text == aiSide)))
        {
            randomCategory3 = true;
            level1 = true;
            gameController.SetButtonArray(2);
            gameController.buttonList[2].GetComponentInParent<GridSpace>().ActivateQuestion();
        }
        // AI Winning Move Middle Left 3
        else if (gameController.buttonList[3].text == "" && ((gameController.buttonList[0].text == aiSide && gameController.buttonList[6].text == aiSide) || (gameController.buttonList[4].text == aiSide && gameController.buttonList[5].text == aiSide)))
        {
            randomCategory1 = true;
            level2 = true;
            gameController.SetButtonArray(3);
            gameController.buttonList[3].GetComponentInParent<GridSpace>().ActivateQuestion();
        }
        // AI Winning Move Middle 4
        else if (gameController.buttonList[4].text == "" && ((gameController.buttonList[0].text == aiSide && gameController.buttonList[8].text == aiSide) || (gameController.buttonList[2].text == aiSide && gameController.buttonList[6].text == aiSide) || (gameController.buttonList[1].text == aiSide && gameController.buttonList[7].text == aiSide) || (gameController.buttonList[3].text == aiSide && gameController.buttonList[5].text == aiSide)))
        {
            randomCategory2 = true;
            level2 = true;
            gameController.SetButtonArray(4);
            gameController.buttonList[4].GetComponentInParent<GridSpace>().ActivateQuestion();
        }
        // AI Winning Move Middle Right 5
        else if (gameController.buttonList[5].text == "" && ((gameController.buttonList[2].text == aiSide && gameController.buttonList[8].text == aiSide) || (gameController.buttonList[3].text == aiSide && gameController.buttonList[4].text == aiSide)))
        {
            randomCategory3 = true;
            level2 = true;
            gameController.SetButtonArray(5);
            gameController.buttonList[5].GetComponentInParent<GridSpace>().ActivateQuestion();
        }
        // AI Winning Move Bottom Left 6
        else if (gameController.buttonList[6].text == "" && ((gameController.buttonList[0].text == aiSide && gameController.buttonList[3].text == aiSide) || (gameController.buttonList[2].text == aiSide && gameController.buttonList[4].text == aiSide) || (gameController.buttonList[7].text == aiSide && gameController.buttonList[8].text == aiSide)))
        {
            randomCategory1 = true;
            level3 = true;
            gameController.SetButtonArray(6);
            gameController.buttonList[6].GetComponentInParent<GridSpace>().ActivateQuestion();
        }
        // AI Winning Move Bottom Middle 7
        else if (gameController.buttonList[7].text == "" && ((gameController.buttonList[6].text == aiSide && gameController.buttonList[8].text == aiSide) || (gameController.buttonList[1].text == aiSide && gameController.buttonList[4].text == aiSide)))
        {
            randomCategory2 = true;
            level3 = true;
            gameController.SetButtonArray(7);
            gameController.buttonList[7].GetComponentInParent<GridSpace>().ActivateQuestion();
        }
        // AI Winning Move Bottom Right 8
        else if (gameController.buttonList[8].text == "" && ((gameController.buttonList[6].text == aiSide && gameController.buttonList[7].text == aiSide) || (gameController.buttonList[0].text == aiSide && gameController.buttonList[4].text == aiSide) || (gameController.buttonList[2].text == aiSide && gameController.buttonList[5].text == aiSide)))
        {
            randomCategory3 = true;
            level3 = true;
            gameController.SetButtonArray(8);
            gameController.buttonList[8].GetComponentInParent<GridSpace>().ActivateQuestion();
        }
        // Player Winning Move Top Left 0
        else if (gameController.buttonList[0].text == "" && ((gameController.buttonList[1].text == playerSide && gameController.buttonList[2].text == playerSide) || (gameController.buttonList[3].text == playerSide && gameController.buttonList[6].text == playerSide) || (gameController.buttonList[4].text == playerSide && gameController.buttonList[8].text == playerSide)))
        {
            randomCategory1 = true;
            level1 = true;
            gameController.SetButtonArray(0);
            gameController.buttonList[0].GetComponentInParent<GridSpace>().ActivateQuestion();
        }
        // Player Winning Move Top Middle 1
        else if (gameController.buttonList[1].text == "" && ((gameController.buttonList[0].text == playerSide && gameController.buttonList[2].text == playerSide) || (gameController.buttonList[4].text == playerSide && gameController.buttonList[7].text == playerSide)))
        {
            randomCategory2 = true;
            level1 = true;
            gameController.SetButtonArray(1);
            gameController.buttonList[1].GetComponentInParent<GridSpace>().ActivateQuestion();
        }
        // Player Winning Move Top Right 2
        else if (gameController.buttonList[2].text == "" && ((gameController.buttonList[0].text == playerSide && gameController.buttonList[1].text == playerSide) || (gameController.buttonList[5].text == playerSide && gameController.buttonList[8].text == playerSide) || (gameController.buttonList[4].text == playerSide && gameController.buttonList[6].text == playerSide)))
        {
            randomCategory3 = true;
            level1 = true;
            gameController.SetButtonArray(2);
            gameController.buttonList[2].GetComponentInParent<GridSpace>().ActivateQuestion();
        }
        // Player Winning Move Middle Left 3
        else if (gameController.buttonList[3].text == "" && ((gameController.buttonList[0].text == playerSide && gameController.buttonList[6].text == playerSide) || (gameController.buttonList[4].text == playerSide && gameController.buttonList[5].text == playerSide)))
        {
            randomCategory1 = true;
            level2 = true;
            gameController.SetButtonArray(3);
            gameController.buttonList[3].GetComponentInParent<GridSpace>().ActivateQuestion();
        }
        // Player Winning Move Middle 4
        else if (gameController.buttonList[4].text == "" && ((gameController.buttonList[0].text == playerSide && gameController.buttonList[8].text == playerSide) || (gameController.buttonList[2].text == playerSide && gameController.buttonList[6].text == playerSide) || (gameController.buttonList[1].text == playerSide && gameController.buttonList[7].text == playerSide) || (gameController.buttonList[3].text == playerSide && gameController.buttonList[5].text == playerSide)))
        {
            randomCategory2 = true;
            level2 = true;
            gameController.SetButtonArray(4);
            gameController.buttonList[4].GetComponentInParent<GridSpace>().ActivateQuestion();
        }
        // Player Winning Move Middle Right 5
        else if (gameController.buttonList[5].text == "" && ((gameController.buttonList[2].text == playerSide && gameController.buttonList[8].text == playerSide) || (gameController.buttonList[3].text == playerSide && gameController.buttonList[4].text == playerSide)))
        {
            randomCategory3 = true;
            level2 = true;
            gameController.SetButtonArray(5);
            gameController.buttonList[5].GetComponentInParent<GridSpace>().ActivateQuestion();
        }
        // Player Winning Move Bottom Left 6
        else if (gameController.buttonList[6].text == "" && ((gameController.buttonList[0].text == playerSide && gameController.buttonList[3].text == playerSide) || (gameController.buttonList[2].text == playerSide && gameController.buttonList[4].text == playerSide) || (gameController.buttonList[7].text == playerSide && gameController.buttonList[8].text == playerSide)))
        {
            randomCategory1 = true;
            level3 = true;
            gameController.SetButtonArray(6);
            gameController.buttonList[6].GetComponentInParent<GridSpace>().ActivateQuestion();
        }
        // Player Winning Move Bottom Middle 7
        else if (gameController.buttonList[7].text == "" && ((gameController.buttonList[6].text == playerSide && gameController.buttonList[8].text == playerSide) || (gameController.buttonList[1].text == playerSide && gameController.buttonList[4].text == playerSide)))
        {
            randomCategory2 = true;
            level3 = true;
            gameController.SetButtonArray(7);
            gameController.buttonList[7].GetComponentInParent<GridSpace>().ActivateQuestion();
        }
        // Player Winning Move Bottom Right 8
        else if (gameController.buttonList[8].text == "" && ((gameController.buttonList[6].text == playerSide && gameController.buttonList[7].text == playerSide) || (gameController.buttonList[0].text == playerSide && gameController.buttonList[4].text == playerSide) || (gameController.buttonList[2].text == playerSide && gameController.buttonList[5].text == playerSide)))
        {
            randomCategory3 = true;
            level3 = true;
            gameController.SetButtonArray(8);
            gameController.buttonList[8].GetComponentInParent<GridSpace>().ActivateQuestion();
        }
        else
        {
            bool freeSpace = false;

            while (!freeSpace)
            {
                randomNumber = Random.Range(0, 9);
                if (gameController.buttonList[randomNumber].text == "")
                {
                    freeSpace = true;
                }
            }

            //TODO: Find a more efficient way to do this
            if (randomNumber == 0)
            {
                randomCategory1 = true;
                level1 = true;
                gameController.SetButtonArray(0);
            }
            else if (randomNumber == 1)
            {
                randomCategory2 = true;
                level1 = true;
                gameController.SetButtonArray(1);
            }
            else if (randomNumber == 2)
            {
                randomCategory3 = true;
                level1 = true;
                gameController.SetButtonArray(2);
            }
            else if (randomNumber == 3)
            {
                randomCategory1 = true;
                level2 = true;
                gameController.SetButtonArray(3);
            }
            else if (randomNumber == 4)
            {
                randomCategory2 = true;
                level2 = true;
                gameController.SetButtonArray(4);
            }
            else if (randomNumber == 5)
            {
                randomCategory3 = true;
                level2 = true;
                gameController.SetButtonArray(5);
            }
            else if (randomNumber == 6)
            {
                randomCategory1 = true;
                level3 = true;
                gameController.SetButtonArray(6);
            }
            else if (randomNumber == 7)
            {
                randomCategory2 = true;
                level3 = true;
                gameController.SetButtonArray(7);
            }
            else
            {
                randomCategory3 = true;
                level3 = true;
                gameController.SetButtonArray(8);
            }
            gameController.buttonList[randomNumber].GetComponentInParent<GridSpace>().ActivateQuestion();
        }
    }

    // Selection for the easiest AI
    public void EasyAISelection()
    {
        MakeMove();
        EasyAIAnswer();
    }

    // Selection for the moderate AI
    public void MediumAISelection()
    {
        MakeMove();
        MediumAIAnswer();
    }

    // Selection for the hard AI
    public void HardAISelection()
    {
        MakeMove();
        HardAIAnswer();
    }

    // Easy AI answer
    private void EasyAIAnswer()
    {
        randomNumber = Random.Range(0, 3);

        // Randomly chooses the answer
        if(randomNumber == 0)
        {
            gameController.SetAnswerA();
        }
        else if(randomNumber == 1)
        {
            gameController.SetAnswerB();
        }
        else
        {
            gameController.SetAnswerC();
        }
        gameController.AnsweredQuestion();
    }

    // Moderate AI answer
    private void MediumAIAnswer()
    {
        Questions.Answer correctAnswer = GetCorrectAnswer();

        // Determines which letter is the correct answer,
        // then sets the odds for it being selected
        if(correctAnswer == Questions.Answer.A)
        {
            aAnswerOdds = 5;
            bAnswerOdds = 7;
            cAnswerOdds = 9;
        }
        else if (correctAnswer == Questions.Answer.B)
        {
            aAnswerOdds = 2;
            bAnswerOdds = 7;
            cAnswerOdds = 9;
        }
        else
        {
            aAnswerOdds = 2;
            bAnswerOdds = 4;
            cAnswerOdds = 9;
        }

        randomNumber = Random.Range(1, 10);

        // Determines if the random number is the correct answer
        if (randomNumber >= 1 && randomNumber <= aAnswerOdds)
        {
            gameController.SetAnswerA();
        }
        else if (randomNumber >= aAnswerOdds + 1 && randomNumber <= bAnswerOdds)
        {
            gameController.SetAnswerB();
        }
        else
        {
            gameController.SetAnswerC();
        }

        // Resets the numbers and answers the question
        aAnswerOdds = 0;
        bAnswerOdds = 0;
        cAnswerOdds = 0;
        gameController.AnsweredQuestion();
    }

    // Hard AI answer
    private void HardAIAnswer()
    {
        Questions.Answer correctAnswer = GetCorrectAnswer();

        // Determines which letter is the correct answer,
        // then sets the odds for it being selected
        if (correctAnswer == Questions.Answer.A)
        {
            aAnswerOdds = 7;
            bAnswerOdds = 8;
            cAnswerOdds = 9;
        }
        else if (correctAnswer == Questions.Answer.B)
        {
            aAnswerOdds = 1;
            bAnswerOdds = 8;
            cAnswerOdds = 9;
        }
        else
        {
            aAnswerOdds = 1;
            bAnswerOdds = 2;
            cAnswerOdds = 9;
        }

        randomNumber = Random.Range(1, 10);

        // Determines if the random number is the correct answer
        if (randomNumber >= 1 && randomNumber <= aAnswerOdds)
        {
            gameController.SetAnswerA();
        }
        else if (randomNumber >= aAnswerOdds + 1 && randomNumber <= bAnswerOdds)
        {
            gameController.SetAnswerB();
        }
        else
        {
            gameController.SetAnswerC();
        }

        // Resets the numbers and answers the question
        aAnswerOdds = 0;
        bAnswerOdds = 0;
        cAnswerOdds = 0;
        gameController.AnsweredQuestion();
    }

    // Determines what the correct answer is for the question
    private Questions.Answer GetCorrectAnswer()
    {
        Questions.Answer correctAnswer;
        int num = gameController.GetRandomNumber();

        // Determines what category and what level the question selected is on
        if(randomCategory1)
        {
            if(level1)
            {
                correctAnswer = questionScript.randomCategory1.level1[num].answer;
            }
            else if(level2)
            {
                correctAnswer = questionScript.randomCategory1.level2[num].answer;
            }
            else
            {
                correctAnswer = questionScript.randomCategory1.level3[num].answer;
            }
        }
        else if(randomCategory2)
        {
            if (level1)
            {
                correctAnswer = questionScript.randomCategory2.level1[num].answer;
            }
            else if (level2)
            {
                correctAnswer = questionScript.randomCategory2.level2[num].answer;
            }
            else
            {
                correctAnswer = questionScript.randomCategory2.level3[num].answer;
            }
        }
        else
        {
            if (level1)
            {
                correctAnswer = questionScript.randomCategory3.level1[num].answer;
            }
            else if (level2)
            {
                correctAnswer = questionScript.randomCategory3.level2[num].answer;
            }
            else
            {
                correctAnswer = questionScript.randomCategory3.level3[num].answer;
            }
        }

        // Resets the boolean values and returns the correct answer
        randomCategory1 = false;
        randomCategory2 = false;
        randomCategory3 = false;
        level1 = false;
        level2 = false;
        level3 = false;
        return correctAnswer;
    }
}
