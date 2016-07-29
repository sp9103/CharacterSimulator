#pragma once
#ifndef DEFINE_HEADER
#define DEFINE_HEADER
#include "define.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 2252

class CharacterClient
{
public:
	CharacterClient(void);
	~CharacterClient(void);

	void GetIPAddress(char *ip);
	void Init();
	void DeInit();
	void sendData(StateVector *data, int count);

private:
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;
	int _portNum;
	char _IP[256];

	void ErrorHandling(char *message);
};

