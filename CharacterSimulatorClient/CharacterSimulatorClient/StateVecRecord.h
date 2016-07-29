#pragma once

#ifndef DEFINE_HEADER
#define DEFINE_HEADER
#include "define.h"
#endif

#include <stdio.h>
#include <stdlib.h>

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

