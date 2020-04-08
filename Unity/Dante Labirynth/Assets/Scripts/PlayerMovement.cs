using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    public GameObject coinparticle;
    private AudioSource audios;
    public AudioClip[] footsteps;
    public float speed = 5f;
    private Animator anim;
    private Rigidbody2D rb;
    Vector2 movement;

    private void Start()
    {
        audios = GetComponent<AudioSource>();
        rb = this.GetComponent<Rigidbody2D>();
        anim = this.GetComponent<Animator>();
    }
    // Update is called once per frame
    private void Update()
    {
        movement.x = Input.GetAxisRaw("Horizontal");
        movement.y = Input.GetAxisRaw("Vertical");

        anim.SetFloat("Horizontal", movement.x);
        anim.SetFloat("Vertical", movement.y);
        anim.SetFloat("Speed", movement.sqrMagnitude);
    }
    private void FixedUpdate()
    {
        rb.MovePosition(rb.position + movement * speed * Time.fixedDeltaTime);
        if(movement != Vector2.zero && audios.isPlaying == false)
        {
            audios.PlayOneShot(footsteps[Random.Range(0, footsteps.Length)]);
        }
    }

    private void OnTriggerEnter2D(Collider2D other)
    {
        if (other.CompareTag("Coins"))
        {
            GameObject.FindGameObjectWithTag("SoundManager").GetComponent<AudioSource>().Play();
            Destroy(Instantiate(coinparticle, other.transform.position,Quaternion.identity), 4);
            Destroy(other.gameObject);
        }
    }
}
