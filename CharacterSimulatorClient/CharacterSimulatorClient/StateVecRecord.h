#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "define.h"

#define DEFAULT_FILE_PATH "BinaryData\\."

class StateVecRecord
{
public:
	StateVecRecord(void);
	~StateVecRecord(void);

	void OpenFile(char *Path, char *filename, char mode);					//mode 'r' = read, mode 'w' = write	
	void CloseFile();

	void WriteState(StateVector src);
	bool ReadState(StateVector *dst);

	bool ReadAver(StateVector *dst);

	bool ReadCenter(StateVector *dst);

private:
	FILE *m_fp;																//file pointer;
	FILE *m_aver;
	FILE *m_center;

	bool isOpen;
};

