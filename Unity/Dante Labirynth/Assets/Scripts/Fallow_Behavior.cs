using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Fallow_Behavior : StateMachineBehaviour
{
    public AudioClip[] ogresound;
    public float speed;
    Vector2 movement;

    public float seeDist;
    public float stoppingDist;
    public float retreatDist;

    private float timeBtwShots;
    public float StartTimeBtwShots;

    public GameObject rock;
    private Transform player;

    override public void OnStateEnter(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        animator.GetComponent<AudioSource>().PlayOneShot(ogresound[0]);
        player = GameObject.FindGameObjectWithTag("Player").transform;
        movement = animator.transform.position;
        timeBtwShots = StartTimeBtwShots;
    }

    override public void OnStateUpdate(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        if (Vector2.Distance(animator.transform.position, player.position) > seeDist)
        {
            animator.SetBool("is_chasing", false);
            animator.SetBool("is_patroling", true);
        }

        movement = animator.transform.position;
        if (Vector2.Distance(animator.transform.position, player.position) > stoppingDist)
        {
            animator.transform.position = Vector2.MoveTowards(animator.transform.position, player.position, speed * Time.deltaTime);

            animator.SetFloat("Horizontal", -movement.x + animator.transform.position.x);
            animator.SetFloat("Vertical", -movement.y + animator.transform.position.y);
        }
        else if (Vector2.Distance(animator.transform.position, player.position) <= stoppingDist && Vector2.Distance(animator.transform.position, player.position) > retreatDist)
        {
            animator.transform.position = animator.transform.position;
        }
        else if (Vector2.Distance(animator.transform.position, player.position) < retreatDist)
        {
            animator.transform.position = Vector2.MoveTowards(animator.transform.position, player.position, -speed * Time.deltaTime);

            animator.SetFloat("Horizontal", movement.x - animator.transform.position.x);
            animator.SetFloat("Vertical", movement.y - animator.transform.position.y);
        }


        if (timeBtwShots <= 0)
        {
            animator.GetComponent<AudioSource>().PlayOneShot(ogresound[Random.Range(1,ogresound.Length-1)]);
            Instantiate(rock, animator.transform.position, Quaternion.identity);
            timeBtwShots = StartTimeBtwShots;
        }
        else
        {
            timeBtwShots -= Time.deltaTime;
        }
    }

    override public void OnStateExit(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        
    }

    // OnStateMove is called right after Animator.OnAnimatorMove()
    //override public void OnStateMove(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    //{
    //    // Implement code that processes and affects root motion
    //}

    // OnStateIK is called right after Animator.OnAnimatorIK()
    //override public void OnStateIK(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    //{
    //    // Implement code that sets up animation IK (inverse kinematics)
    //}
}
