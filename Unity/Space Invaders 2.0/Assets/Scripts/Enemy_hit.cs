using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class Enemy_hit : MonoBehaviour
{
    private Vector3 offset = new Vector3(0.0f,10.0f);
    public GameObject floatingPointsPrefab;
    private ShakeScript ShakeCamera;
    public GameObject explosion;
    public int value;
    private void Start()
    {
        ShakeCamera = Camera.main.GetComponent<ShakeScript>();
    }

    void ShowPoints(string points)
    {
        var go = Instantiate(floatingPointsPrefab, transform.position + offset, Quaternion.identity);
        go.GetComponent<TextMesh>().text = "+" + points;
        go.GetComponent<Rigidbody>().velocity = Vector3.up * 5.0f;
        go.transform.Rotate(Vector3.left,Random.Range(10.0f,45.0f));
        Destroy(go, 2.0f);
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Laser"))
        {
            GameObject.Find("GameManager").GetComponent<manager>().AddScore(value);
            GameObject.Find("GameManager").GetComponent<AudioSource>().Play();
            Object.Destroy(other.gameObject);
            var temp = Instantiate(explosion,this.transform.position,Quaternion.identity);
            if(floatingPointsPrefab)
                ShowPoints(value.ToString());
            Destroy(temp, 4f);
            Object.Destroy(this.gameObject);
            StartCoroutine(ShakeCamera.Shake(0.01f, 3.0f));
        }
    }
}


