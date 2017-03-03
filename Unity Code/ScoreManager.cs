using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class GameManager : MonoBehaviour {

    public int cells = 20;
    public int dna = 100;

    public Text cellsText;
    public Text dnaText;
	public int hazardsRound1;
	public int hazardsRound2;
	public int hazardsRound3;
	public float spawnWait;
	public float startWait;
	public float waveWait;

	void Start ()
	{
		//StartCoroutine (GenerateEnemies ());
	}

    public void LoseCell(int l = 1)
    {
        cells -= 1;
        if (cells <= 0)
        {
            GameOver();
        }
    }

    public void GameOver()
    {
        Debug.Log("Game Over");
        SceneManager.LoadScene(SceneManager.GetActiveScene().name);
    }

    void Update()
    {
        dnaText.text = "DNA: " + dna.ToString();
        cellsText.text = "Cells: " + cells.ToString();
    }

	/* IEnumerator GenerateEnemies ()
	{
		yield return new WaitForSeconds (startWait);
		while (true) {
			for (int i = 0; i < hazardsRound1; i++) { 
				yield return new WaitForSeconds (spawnWait);
			}
		}
		yield return new WaitForSeconds (waveWait);
	} */
}

//GameObject.FindObjectOfType<ScoreManager>().LoseCell();
//Destroy(gameObject);