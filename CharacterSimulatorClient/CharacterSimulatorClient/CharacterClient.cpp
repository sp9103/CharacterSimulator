#include "CharacterClient.h"


CharacterClient::CharacterClient(void)
{
}


CharacterClient::~CharacterClient(void)
{
}

void CharacterClient::GetIPAddress(char *ip){
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	PHOSTENT hostinfo;
	char hostname[50];
	char ipaddr[50];
	memset(hostname, 0, sizeof(hostname));
	memset(ipaddr, 0, sizeof(ipaddr));

	int nError = gethostname(hostname, sizeof(hostname));
	if (nError == 0)
	{
		hostinfo = gethostbyname(hostname);
		// ip address 파악
		strcpy(ipaddr, inet_ntoa(*(struct in_addr*)hostinfo->h_addr_list[0]));
	}

	WSACleanup();

	strcpy(ip, ipaddr);
}

void CharacterClient::Init(){
	_portNum = PORT;
	char temp[256];
	GetIPAddress(temp);
	strcpy(_IP, temp);

	//소켓 초기화
	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		ErrorHandling("WSAStartup(), error");
	}

	// 서버 접속을 위한 소켓 생성
	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if(hSocket == INVALID_SOCKET)
	{
		ErrorHandling("hSocketet(), error");
	}

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(_IP);
	servAddr.sin_port = htons(_portNum);

	// 서버로 연결 요청
	if(connect(hSocket, (SOCKADDR*) &servAddr, sizeof(servAddr)) == SOCKET_ERROR)
	{
		ErrorHandling("Connect() error");
		//소켓 정리
		DeInit();

		return;
	}
}


void CharacterClient::DeInit(){

}

void CharacterClient::sendData(StateVector *data, int count){
	renderData sendVec;
	char buf[1024];
	sendVec.count = count;
	for(int i = 0; i < count; i++)	sendVec.character[i] = data[0];

	memcpy(buf, &sendVec, sizeof(renderData));
	int sendresult = send(hSocket, buf, sizeof(renderData), 0);
}

void CharacterClient::ErrorHandling(char *message)
{
	printf("%s\n", message);
}