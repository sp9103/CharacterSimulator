#include <stdio.h>
#include <string>

#include "CharacterServer.h"

#define EXPORT_API __declspec(dllexport)

extern "C"{
	CharacterServer server_;

	void EXPORT_API	TEST(){
		MessageBox(NULL, L"HELLO WORLD!", L"TEST", MB_OK);
	}

	void EXPORT_API serverInit(){
		server_.Init();
	}

	void EXPORT_API getData(int *count, float *joint){
		StateVector temp[2];
		server_.getData(count, temp);

		for(int c = 0; c < *count; c++){
			for(int i = 0; i < Actual_JointType_Count; i++){
				joint[c * Actual_JointType_Count * 3 + 3*i + 0] = temp[c].joints[i].X;
				joint[c * Actual_JointType_Count * 3 + 3*i + 1] = temp[c].joints[i].Y;
				joint[c * Actual_JointType_Count * 3 + 3*i + 2] = temp[c].joints[i].Z;
			}
		}
	}

	void EXPORT_API	serverDeinit(){
		server_.DeInit();
	}
}