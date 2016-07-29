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

    public GameObject character;


	// Use this for initialization
	void Start () {
        serverInit();
	}
	
	// Update is called once per frame
	void Update () {
        
	}

    //종료시 실행 함수 -> Deinit 단
    void OnApplicationQuit()
    {
        serverDeinit();
    }
}
