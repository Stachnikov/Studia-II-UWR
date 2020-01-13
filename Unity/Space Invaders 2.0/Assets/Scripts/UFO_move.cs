using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UFO_move : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        GetComponent<Rigidbody>().velocity = new Vector3(20.0f, 0, 0);
    }

    // Update is called once per frame
    void Update()
    {
        if(transform.position.x >= 300)
        {
            GetComponent<AudioSource>().Play();
            Destroy(this.gameObject);
        }
    }
}
