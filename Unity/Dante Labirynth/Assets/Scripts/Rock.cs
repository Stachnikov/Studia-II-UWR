using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Rock : MonoBehaviour
{
    public GameObject blood;
    public float speed;
    public AudioClip hitsound;
    private Transform player;
    Vector2 target;

    void Start()
    {
        player = GameObject.FindGameObjectWithTag("Player").transform;
        target = new Vector2(player.position.x, player.position.y);
    }

    void Update()
    {
        transform.position = Vector2.MoveTowards(transform.position, target, speed * Time.deltaTime);

        if(transform.position.x == target.x && transform.position.y == target.y)
        {
            DestroyRock();
        }
    }

    private void OnTriggerEnter2D(Collider2D other)
    {
        if (other.CompareTag("Player"))
        {
            Destroy(Instantiate(blood, other.transform.position, Quaternion.identity), 4);
            other.gameObject.GetComponent<AudioSource>().PlayOneShot(hitsound);
            DestroyRock();
        }
    }

    void DestroyRock()
    {
        Destroy(gameObject);
    }
}
