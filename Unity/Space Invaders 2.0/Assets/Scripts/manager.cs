using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;
public class manager : MonoBehaviour
{
    int nScore = 0;
    public TextMeshProUGUI text;
    public TextMeshProUGUI highscore;
    public GameObject gameover;
    public GameObject start;
    public GameObject enemyship;
    public GameObject enemygroup;
    private float nextShip = 0;
    // Start is called before the first frame update
    void Start()
    {
        Time.timeScale = 0;
        text.text = "Score : " + nScore.ToString();
        highscore.text = "Highscore : " + PlayerPrefs.GetInt("Highscore",0).ToString();
        gameover.SetActive(false);
    }

    public void AddScore(int n)
    {
        nScore += n;
        text.text = "Score : " + nScore.ToString();
        if (nScore > PlayerPrefs.GetInt("Highscore", 0))
        {
            PlayerPrefs.SetInt("Highscore", nScore);
            highscore.text = "Highscore : " + PlayerPrefs.GetInt("Highscore", 0).ToString();
        }
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.Space))
        {
            GameObject.FindWithTag("StartPanel").GetComponent<AudioSource>().Play();
            Time.timeScale = 1;
            start.transform.position += Vector3.up * 1000.0f;
            Destroy(start, 2.0f);
        }

        if (Input.GetKeyDown(KeyCode.R))
        {
            SceneManager.LoadScene(SceneManager.GetActiveScene().name);
        }

        if (GameObject.Find("Player") is null)
        {
            gameover.SetActive(true);
            Time.timeScale = 0;
            if (nScore > PlayerPrefs.GetInt("Highscore",0))
                PlayerPrefs.SetInt("Highscore", nScore);
        }

        if(GameObject.FindGameObjectsWithTag("Enemy").Length == 0)
        {
            Destroy(GameObject.FindGameObjectsWithTag("EnemyBox")[0]);
            var temp = Instantiate(enemygroup, new Vector3(-14.2f, -11.33f, 1006.0f),Quaternion.identity);
            temp.GetComponent<Enemy_move>().fireRate -= 0.01f;
            Camera.main.GetComponent<AudioSource>().pitch = 0.90f;
        }

        if (Time.time > nextShip)
        {
            nextShip = Time.time + 100.0f;
            Instantiate(enemyship, new Vector3(-380.0f, -1.8f, 183.0f), Quaternion.AngleAxis(90.0f,Vector3.left));
        }
    }
}
