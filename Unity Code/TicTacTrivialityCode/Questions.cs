using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Questions : MonoBehaviour {

    public enum Answer { A, B, C };
    public enum Level { Level1, Level2, Level3};

    [System.Serializable]
    public class QuestionsAndAnswers
    {
        [TextArea]
        public string question;
        public string answerA;
        public string answerB;
        public string answerC;
        public Answer answer;
    }

    [System.Serializable]
    public class LevelOfDifficulty
    {
        public string categoryName;
        public QuestionsAndAnswers[] level1;
        public QuestionsAndAnswers[] level2;
        public QuestionsAndAnswers[] level3;
        public bool picked = false;
    }

    public LevelOfDifficulty videoGamesCategory;
    public LevelOfDifficulty comicsCategory;
    public LevelOfDifficulty sportsCategory;
    public LevelOfDifficulty historyCategory;
    //public LevelOfDifficulty scienceCategory;
    public LevelOfDifficulty spaceCategory;
    public LevelOfDifficulty warsCategory;
    //public LevelOfDifficulty musicCategory;
    public LevelOfDifficulty greekMythologyCategory;
    //public LevelOfDifficulty anthropologyCategory;
    public LevelOfDifficulty movieCategory;
    public LevelOfDifficulty tvCategory;
    //public LevelOfDifficulty socialMediaCategory;
    //public LevelOfDifficulty politicsCategory;
    //public LevelOfDifficulty englishCategory;
    //public LevelOfDifficulty booksCategory;
    //public LevelOfDifficulty geographyCategory;
    public LevelOfDifficulty lgbtCategory;
    //public LevelOfDifficulty foodCategory;
    public LevelOfDifficulty mathCategory;
    //public LevelOfDifficulty celebrityCategory;
    //public LevelOfDifficulty popCultureCategory;
    //public LevelOfDifficulty zoologyCategory;
    public LevelOfDifficulty automobilesCategory;
    //public LevelOfDifficulty medicineCategory;
    //public LevelOfDifficulty fashionCategory;
    //public LevelOfDifficulty computerCategory;
    //public LevelOfDifficulty historicalFiguresCategory;
    //public LevelOfDifficulty psychologyCategory;
    //public LevelOfDifficulty artCategory;
    public LevelOfDifficulty randomCategory1;
    public LevelOfDifficulty randomCategory2;
    public LevelOfDifficulty randomCategory3;

    public void ChooseCategories()
    {
        int numOfCategories = 0;
        int randomNumber = 0;

        videoGamesCategory.picked = false;
        comicsCategory.picked = false;
        sportsCategory.picked = false;
        historyCategory.picked = false;
        greekMythologyCategory.picked = false;
        movieCategory.picked = false;
        tvCategory.picked = false;
        lgbtCategory.picked = false;
        randomCategory1 = new LevelOfDifficulty();
        randomCategory2 = new LevelOfDifficulty();
        randomCategory3 = new LevelOfDifficulty();
        randomCategory1.picked = false;
        randomCategory2.picked = false;
        randomCategory3.picked = false;

        while (numOfCategories < 3)
        {
            randomNumber = Random.Range(0, 8);
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
