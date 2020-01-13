using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy_move : MonoBehaviour
{
    public Vector3 StartPos;
    private bool onStart = false;
    private Transform enemyHolder;
    public float speed;

    public GameObject shot;
    public float fireRate = 0.997f;
    private int count = 0;

    // Use this for initialization
    void Start()
    {
        count = GameObject.FindGameObjectsWithTag("Enemy").Length;
        enemyHolder = GetComponent<Transform>();
        MoveToStart();
        if(onStart)
            InvokeRepeating("MoveEnemy", 0.1f, count / 40.0f);
    }


    void MoveToStart()
    {
        foreach (Transform enemy in enemyHolder)
        {
            float time = UnityEngine.Random.Range(1.0f, 1.5f);
            iTween.MoveTo(enemy.gameObject, iTween.Hash("position",StartPos,"time",time,"easetype",iTween.EaseType.easeOutBounce));
        }
        onStart = true;
    }

    void MoveEnemy()
    {
        enemyHolder.position += Vector3.right * speed;

        foreach (Transform enemy in enemyHolder)
        {
            if (enemy.childCount == 0)
            {
                Destroy(enemy.gameObject);
                return;
            }

            if (enemy.position.x < -39 || enemy.position.x > 15)
            {
                speed = -speed;
                enemyHolder.position += -Vector3.forward * 5f;
                return;
            }
            if(enemy.position.z < -200)
            {
                Destroy(GameObject.Find("Player"));
            }

            if (UnityEngine.Random.value > fireRate)
            {
                    Instantiate(shot, enemy.GetChild(0).position, Quaternion.identity);
            }

        }

        if (count != GameObject.FindGameObjectsWithTag("Enemy").Length)
        {
            count = GameObject.FindGameObjectsWithTag("Enemy").Length;
            CancelInvoke();
            Camera.main.GetComponent<AudioSource>().pitch += 0.005f;
            InvokeRepeating("MoveEnemy", 0.1f, count/40.0f);
        }

    }

}
