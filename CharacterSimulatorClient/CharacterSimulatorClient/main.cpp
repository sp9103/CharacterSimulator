#include <stdio.h>

#include "CharacterClient.h"
#include "StateVecRecord.h"

int main(){
	StateVecRecord DataReader_;
	CharacterClient client_;

	StateVector characterState[4];
	int count = 0;

	DataReader_.OpenFile("..\\Mocap_Kinect_data", "1CrossingArms1_all", 'r');

	while(DataReader_.ReadState(characterState)){
	}

	DataReader_.CloseFile();

	return 0;
}