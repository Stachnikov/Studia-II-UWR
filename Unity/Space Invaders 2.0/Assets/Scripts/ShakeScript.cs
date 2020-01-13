using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShakeScript : MonoBehaviour
{

    public IEnumerator Shake(float duration, float strong)
    {
        Vector3 OrgPos = transform.localPosition;

        float xval = Random.Range(-1.0f, 1.0f) * strong;
        float yval = Random.Range(-1.0f, 1.0f) * strong;

        transform.localPosition= new Vector3(xval, yval,OrgPos.z);
        yield return null;
        transform.localPosition = OrgPos;
    }
}
