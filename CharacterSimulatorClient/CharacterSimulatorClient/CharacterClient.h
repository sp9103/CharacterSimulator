#pragma once
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

private:

};

