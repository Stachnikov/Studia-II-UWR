using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Moving_script : MonoBehaviour
{
    public GameObject Shooting_holder;
    public GameObject laser;
    private Rigidbody rb;
    public float cooldown;
    private float nextFireTime=0;
    private float y0;
    // Start is called before the first frame update
    void Start()
    {
        rb = GetComponent<Rigidbody>();
        y0 = transform.position.y;
    }

    // Update is called once per frame
    void Update()
    {
        //Moving
        float moveHorizontal = Input.GetAxis("Horizontal");
        Vector3 temp = new Vector3(80.0f * moveHorizontal, 0, 0);
        rb.velocity = temp;
        
        float hover = y0 + 2.0f * Mathf.Sin(Time.time * 2.0f);
        rb.transform.position = new Vector3(rb.transform.position.x, hover, rb.transform.position.z);


        //Shooting
        if (Time.time > nextFireTime)
        {
            if (Input.GetKeyDown(KeyCode.UpArrow))
            {
                GameObject laserbeam = Instantiate(laser, Shooting_holder.transform.position, Shooting_holder.transform.rotation);
                laserbeam.GetComponent<Rigidbody>().velocity = new Vector3(0.0f, 0.0f, 80.0f);
                nextFireTime = Time.time + cooldown;
            }
        }
    }
}
