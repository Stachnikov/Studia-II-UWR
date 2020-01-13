using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class Highscore : MonoBehaviour
{
    private void Start()
    {
        GetComponent<TextMeshProUGUI>().text = PlayerPrefs.GetInt("Highscore", 0).ToString();
    }
}
