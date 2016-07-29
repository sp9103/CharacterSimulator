using UnityEngine;
using System.Collections;
using System;
using System.Runtime.InteropServices;

public class CharacterController : MonoBehaviour {

    [DllImport("UnityCharacterDLL")]
    private static extern void TEST();
    [DllImport("UnityCharacterDLL")]
    private static extern void serverInit();
    [DllImport("UnityCharacterDLL")]
    private static extern void serverDeinit();
    [DllImport("UnityCharacterDLL")]
    private static extern int getData(float[] joint);

    public GameObject character;

    private int dataCount;
    float[] jointAll = new float[3 * 19 * 2];

	// Use this for initialization
	void Start () {
        dataCount = 0;
        serverInit();
	}
	
	// Update is called once per frame
	void Update () {
        int dataCount = getData(jointAll);
        
        //Create or Make model
	}

    //종료시 실행 함수 -> Deinit 단
    void OnApplicationQuit()
    {
        serverDeinit();
    }
}
