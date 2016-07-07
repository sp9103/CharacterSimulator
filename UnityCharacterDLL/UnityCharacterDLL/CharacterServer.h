//#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>

#include "Thread.h"

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
	void getData();

private:
	int _portNum;
	char _IP[256];
	WSADATA wsaData;
	SOCKET hServSock;
	SOCKET hClntSock;
	SOCKADDR_IN servAddr;
	SOCKADDR_IN clntAddr;
	int szClntAddr;

	Thread m_Thread;
	bool m_ThreadOpen;

	void ErrorHandling(char *message);
	void openServer(char *ip, int portNum);
	static UINT WINAPI serverThread(LPVOID param);
};

