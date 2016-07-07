using UnityEngine;
using System.Collections;

public class CharacterController : MonoBehaviour {
    public GameObject character;
    public bool ReadFromFile;
    public int FrameRate = 30;
    public string FilePath;

    private float waitInterval;

	// Use this for initialization
	void Start () {
        if (FrameRate <= 0) FrameRate = 30;

        waitInterval = 1000.0f / (float)FrameRate;
	}
	
	// Update is called once per frame
	void Update () {
        //파일에서부터 읽어들일때
        if (ReadFromFile)
        {

        }
        else        //통신으로부터 직접받아올
        {
            //TO-DO
        }
	}
}
