#include <stdio.h>
#include <string>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

#define EXPORT_API __declspec(dllexport)
#define PORT 2252

extern "C"{
	void EXPORT_API	TEST(){
		MessageBox(NULL, L"HELLO WORLD!", L"TEST", MB_OK);
	}
}