using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class RegularCell : MonoBehaviour {

    public Text dnaText;

    private int dna;

	public Vector2 cellPosition;

	// Use this for initialization
	void Start ()
    {
	}

    void OnMouseDown()
    {
        Debug.Log("I'm Hit");
    }

	// Update is called once per frame
	void Update ()
    {
		while (gameObject != null) {
			// updates the dna dpending on where the the cell is located on screen
			if (cellPosition.y >= 4) {
				dna += 5;
			} else if (cellPosition.y >= 2) {
				dna += 4;
			} else if (cellPosition.y > 0) {
				dna += 3;
			}else if (cellPosition.y >= -2) {
				dna += 2;
			} else if (cellPosition.y >= -4) {
				dna += 1;
			}
		}
	}    

   /* void SetDNAText ()
    {
        dnaText.text = "DNA: " + dna.ToString;
    }*/
}


/*using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class PlayerController : MonoBehaviour {

    public float speed;
    public Text countText;
    public Text winText;

    private Rigidbody rb;
    private int count;

    void Start()
    {
        rb = GetComponent<Rigidbody>();
        count = 0;
        SetCountText();
        winText.text = "";
    }

    void FixedUpdate()
    {
        float moveHorizontal = Input.GetAxis("Horizontal");
        float moveVertical = Input.GetAxis("Vertical");

        Vector3 movement = new Vector3(moveHorizontal, 0.0f, moveVertical);

        rb.AddForce(movement * speed);
    }

    void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.CompareTag("Pick Up"))
        {
            other.gameObject.SetActive (false);
            count = count + 1;
            SetCountText();
        }
    }

    void SetCountText()
    {
        countText.text = "Count: " + count.ToString();
        if (count >= 12)
        {
            winText.text = "You Win!";
        }
    }
} */