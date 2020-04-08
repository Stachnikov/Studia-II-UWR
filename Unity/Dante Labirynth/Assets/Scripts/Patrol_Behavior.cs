using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Patrol_Behavior : StateMachineBehaviour
{
    public float seeDist;
    public float speed;
    Vector2 movement;
    private Waypoints wp;
    private int wp_index;
    private Transform player;

    override public void OnStateEnter(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        movement = animator.transform.position;
        wp = GameObject.FindGameObjectWithTag("Waypoints").GetComponent<Waypoints>();
        player = GameObject.FindGameObjectWithTag("Player").GetComponent<Transform>();
        wp_index = 0;
    }

    override public void OnStateUpdate(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        movement = animator.transform.position;
        if(Vector2.Distance(animator.transform.position, player.position) < seeDist)
        {
            animator.SetBool("is_patroling", false);
            animator.SetBool("is_chasing",true);
        }
        else if (Vector2.Distance(animator.transform.position, wp.waypoints[wp_index].position) >= 0.01f)
        {
            animator.transform.position = Vector2.MoveTowards(animator.transform.position, wp.waypoints[wp_index].position, speed * Time.deltaTime);

            animator.SetFloat("Horizontal", -movement.x + animator.transform.position.x);
            animator.SetFloat("Vertical", -movement.y + animator.transform.position.y);
        }
        else if(wp_index < wp.waypoints.Length-1)
        {
            wp_index++;
        }else
        {
            wp_index = 0;
            System.Array.Reverse(wp.waypoints);
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
