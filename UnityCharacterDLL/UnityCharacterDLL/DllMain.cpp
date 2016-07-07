#include <stdio.h>
#include <string>

#include "CharacterServer.h"

#define EXPORT_API __declspec(dllexport)

extern "C"{
	CharacterServer server_;

	void EXPORT_API	TEST(){
		MessageBox(NULL, L"HELLO WORLD!", L"TEST", MB_OK);
	}
	
	void EXPORT_API servertInit(){
	}

	void EXPORT_API getData(){
	}

	void EXPORT_API	serverDeinit(){
	}
}