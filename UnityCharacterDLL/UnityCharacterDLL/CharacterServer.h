//#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>

#include "Thread.h"
#include "define.h"

#pragma comment(lib, "ws2_32.lib")

#define PORT 2252

class CharacterServer
{
public:
	CharacterServer(void);
	~CharacterServer(void);

	void GetIPAddress(char *ip);
	void Init();
	void DeInit();
	void getData(int *count, StateVector *stateVec);

private:
	int _portNum;
	char _IP[256];
	WSADATA wsaData;
	SOCKET hServSock;
	SOCKET hClntSock;
	SOCKADDR_IN clntAddr;
	SOCKADDR_IN servAddr;
	int szClntAddr;

	Thread m_Thread;
	bool m_ThreadOpen;
	bool m_ThreadClose;

	CRITICAL_SECTION cs;

	int dataCount;
	StateVector stateVec_[2];				//�񱳴��� ���� ��� �ִ� �ΰ��� �޾ƿ�

	void ErrorHandling(char *message);
	void openServer(char *ip, int portNum);
	static UINT WINAPI serverThread(LPVOID param);
};

