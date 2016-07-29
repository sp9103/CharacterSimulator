#include <stdio.h>

#include "StateVecRecord.h"
#include "CharacterClient.h"

int main(){
	StateVecRecord DataReader_;
	CharacterClient client_;

	StateVector characterState[4];
	int count = 0;

	DataReader_.OpenFile("..\\Mocap_Kinect_data", "1CrossingArms1_all", 'r');
	client_.Init();

	while(DataReader_.ReadState(characterState)){
		//client_.
	}

	DataReader_.CloseFile();
	client_.Init();

	return 0;
}