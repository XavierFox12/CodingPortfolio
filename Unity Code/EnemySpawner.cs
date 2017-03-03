using UnityEngine;
using System.Collections;

public class EnemySpawner : MonoBehaviour {

	float spawnCD = 0.5f;
	float spawnCDremaining = 0;

	[System.Serializable]
	public class WaveComponent {
		public GameObject enemyPrefab;
		public int num;
		[System.NonSerialized]
		public int spawned = 0;
	}

	public WaveComponent[] waveComps;

	
	// Update is called once per frame
	void Update () {
		bool didSpawn = false;
		spawnCDremaining -= Time.deltaTime;
		if (spawnCDremaining < 0) {
			spawnCDremaining = spawnCD;

			foreach (WaveComponent wc in waveComps) {
				if (wc.spawned < wc.num) {
					wc.spawned++;

					Instantiate (wc.enemyPrefab, this.transform.position, this.transform.rotation);

					didSpawn = true;
					break;
				}
			}

			if (didSpawn == false) {

				if (transform.parent.childCount > 1) {
					transform.parent.GetChild (1).gameObject.SetActive (true);
				} else {
					Debug.Log ("You Win");
				}

				Destroy (gameObject);
			}
		}
	}
}
