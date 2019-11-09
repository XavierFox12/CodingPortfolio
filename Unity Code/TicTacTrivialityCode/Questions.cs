using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Questions : MonoBehaviour {

    public enum Answer { A, B, C };                             // Enumerator that gives the options of A, B, or C to be the answer to the question
    public enum Level { Level1, Level2, Level3};                // Enumerator that gives the options to determine if the questions is either a level 1, 2, or 3 question

    // Class that allows the user to enter a question
    [System.Serializable]
    public class QuestionsAndAnswers
    {
        [TextArea]
        public string question;                                 // Text area that allows the user to enter the question
        public string answerA;                                  // String that will display answer A
        public string answerB;                                  // String that will display answer B
        public string answerC;                                  // String that will display answer C
        public Answer answer;                                   // Allows the user to choose which option is the correct answer
    }

    // Class that allows the user to enter a category and all the different levels of questions for that category
    [System.Serializable]
    public class LevelOfDifficulty
    {
        public string categoryName;                             // Category for the questions being asked
        public QuestionsAndAnswers[] level1;                    // Allows the user to enter the level 1 questions for the particular category
        public QuestionsAndAnswers[] level2;                    // Allows the user to enter the level 2 questions for the particular category
        public QuestionsAndAnswers[] level3;                    // Allows the user to enter the level 3 questions for the particular category
        public bool picked = false;                             // Determines if this category was picked for the game
    }

    public LevelOfDifficulty videoGamesCategory;                // Video game category
    public LevelOfDifficulty comicsCategory;                    // Comic book category
    public LevelOfDifficulty sportsCategory;                    // Sports category
    public LevelOfDifficulty historyCategory;                   // History category
    //public LevelOfDifficulty scienceCategory;                 // Science category
    public LevelOfDifficulty spaceCategory;                     // Space category
    public LevelOfDifficulty warsCategory;                      // War category
    //public LevelOfDifficulty musicCategory;                   // music category
    public LevelOfDifficulty greekMythologyCategory;            // Greek Mythology category
    //public LevelOfDifficulty anthropologyCategory;            // Anthropology category
    public LevelOfDifficulty movieCategory;                     // Movie category
    public LevelOfDifficulty tvCategory;                        // Television category
    //public LevelOfDifficulty socialMediaCategory;             // Social Media category
    //public LevelOfDifficulty politicsCategory;                // Politics category
    //public LevelOfDifficulty englishCategory;                 // English category
    //public LevelOfDifficulty booksCategory;                   // Literature category
    //public LevelOfDifficulty geographyCategory;               // Geography category
    public LevelOfDifficulty lgbtCategory;                      // LGBT category
    //public LevelOfDifficulty foodCategory;                    // Food category
    public LevelOfDifficulty mathCategory;                      // Math category
    //public LevelOfDifficulty celebrityCategory;               // Celebrity category
    //public LevelOfDifficulty popCultureCategory;              // Pop Culture category
    //public LevelOfDifficulty zoologyCategory;                 // Zoology category
    public LevelOfDifficulty automobilesCategory;               // Automobiles category
    //public LevelOfDifficulty medicineCategory;                // Medicine category
    //public LevelOfDifficulty fashionCategory;                 // Fashion category
    //public LevelOfDifficulty computerCategory;                // Computer category
    //public LevelOfDifficulty historicalFiguresCategory;       // Historical Figures category
    //public LevelOfDifficulty psychologyCategory;              // Psychology category
    //public LevelOfDifficulty artCategory;                     // Art category
    public LevelOfDifficulty randomCategory1;                   // Random category #1
    public LevelOfDifficulty randomCategory2;                   // Random category #2
    public LevelOfDifficulty randomCategory3;                   // Random category #3

    public void ChooseCategories()
    {
        int numOfCategories = 0;
        int randomNumber = 0;

        // Sets all of the categories picked value to false
        videoGamesCategory.picked = false;
        comicsCategory.picked = false;
        sportsCategory.picked = false;
        historyCategory.picked = false;
        greekMythologyCategory.picked = false;
        movieCategory.picked = false;
        tvCategory.picked = false;
        lgbtCategory.picked = false;
        randomCategory1.picked = false;
        randomCategory2.picked = false;
        randomCategory3.picked = false;

        // Loops through all the categories until 3 of them are chosen
        while (numOfCategories < 3)
        {
            // Generates a random number
            randomNumber = Random.Range(0, 8);
            // If statements that determine if the random number matches the category,
            // then sets that category as one of the 3 categories picked
            if (randomNumber == 0 && !videoGamesCategory.picked)
            {
                if (!randomCategory1.picked)
                {
                    randomCategory1 = videoGamesCategory;
                    randomCategory1.picked = true;
                }
                else if (!randomCategory2.picked)
                {
                    randomCategory2 = videoGamesCategory;
                    randomCategory2.picked = true;
                }
                else
                {
                    randomCategory3 = videoGamesCategory;
                    randomCategory3.picked = true;
                }
                ++numOfCategories;
                videoGamesCategory.picked = true;
            }
            else if (randomNumber == 1 && !comicsCategory.picked)
            {
                if (!randomCategory1.picked)
                {
                    randomCategory1 = comicsCategory;
                    randomCategory1.picked = true;
                }
                else if (!randomCategory2.picked)
                {
                    randomCategory2 = comicsCategory;
                    randomCategory2.picked = true;
                }
                else
                {
                    randomCategory3 = comicsCategory;
                    randomCategory3.picked = true;
                }
                ++numOfCategories;
                comicsCategory.picked = true;
            }
            else if (randomNumber == 2 && !sportsCategory.picked)
            {
                if (!randomCategory1.picked)
                {
                    randomCategory1 = sportsCategory;
                    randomCategory1.picked = true;
                }
                else if (!randomCategory2.picked)
                {
                    randomCategory2 = sportsCategory;
                    randomCategory2.picked = true;
                }
                else
                {
                    randomCategory3 = sportsCategory;
                    randomCategory3.picked = true;
                }
                ++numOfCategories;
                sportsCategory.picked = true;
            }
            else if (randomNumber == 3 && !historyCategory.picked)
            {
                if (!randomCategory1.picked)
                {
                    randomCategory1 = historyCategory;
                    randomCategory1.picked = true;
                }
                else if (!randomCategory2.picked)
                {
                    randomCategory2 = historyCategory;
                    randomCategory2.picked = true;
                }
                else
                {
                    randomCategory3 = historyCategory;
                    randomCategory3.picked = true;
                }
                ++numOfCategories;
                historyCategory.picked = true;
            }
            else if (randomNumber == 4 && !greekMythologyCategory.picked)
            {
                if (!randomCategory1.picked)
                {
                    randomCategory1 = greekMythologyCategory;
                    randomCategory1.picked = true;
                }
                else if (!randomCategory2.picked)
                {
                    randomCategory2 = greekMythologyCategory;
                    randomCategory2.picked = true;
                }
                else
                {
                    randomCategory3 = greekMythologyCategory;
                    randomCategory3.picked = true;
                }
                ++numOfCategories;
                greekMythologyCategory.picked = true;
            }
            else if (randomNumber == 5 && !movieCategory.picked)
            {
                if (!randomCategory1.picked)
                {
                    randomCategory1 = movieCategory;
                    randomCategory1.picked = true;
                }
                else if (!randomCategory2.picked)
                {
                    randomCategory2 = movieCategory;
                    randomCategory2.picked = true;
                }
                else
                {
                    randomCategory3 = movieCategory;
                    randomCategory3.picked = true;
                }
                ++numOfCategories;
                movieCategory.picked = true;
            }
            else if (randomNumber == 6 && !tvCategory.picked)
            {
                if (!randomCategory1.picked)
                {
                    randomCategory1 = tvCategory;
                    randomCategory1.picked = true;
                }
                else if (!randomCategory2.picked)
                {
                    randomCategory2 = tvCategory;
                    randomCategory2.picked = true;
                }
                else
                {
                    randomCategory3 = tvCategory;
                    randomCategory3.picked = true;
                }
                ++numOfCategories;
                tvCategory.picked = true;
            }
            else if (randomNumber == 7 && !lgbtCategory.picked)
            {
                if (!randomCategory1.picked)
                {
                    randomCategory1 = lgbtCategory;
                    randomCategory1.picked = true;
                }
                else if (!randomCategory2.picked)
                {
                    randomCategory2 = lgbtCategory;
                    randomCategory2.picked = true;
                }
                else
                {
                    randomCategory3 = lgbtCategory;
                    randomCategory3.picked = true;
                }
                ++numOfCategories;
                lgbtCategory.picked = true;
            }
        }

        // Sets all of the categories picked value back to false in case of a new game
        videoGamesCategory.picked = false;
        comicsCategory.picked = false;
        sportsCategory.picked = false;
        historyCategory.picked = false;
        greekMythologyCategory.picked = false;
        movieCategory.picked = false;
        tvCategory.picked = false;
        lgbtCategory.picked = false;
        randomCategory1.picked = false;
        randomCategory2.picked = false;
        randomCategory3.picked = false;
    }
}
