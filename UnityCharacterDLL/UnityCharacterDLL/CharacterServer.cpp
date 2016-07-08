#include "CharacterServer.h"


CharacterServer::CharacterServer(void)
{
	m_ThreadOpen = false;
	m_ThreadClose = false;

	dataCount = -1;
}


CharacterServer::~CharacterServer(void)
{
}

void CharacterServer::GetIPAddress(char *ip){
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
		// ip address �ľ�
		strcpy(ipaddr, inet_ntoa(*(struct in_addr*)hostinfo->h_addr_list[0]));
	}

	WSACleanup();

	strcpy(ip, ipaddr);
}

void CharacterServer::Init(){
	InitializeCriticalSection(&cs);
	m_Thread.StartThread(serverThread, this);
	m_ThreadOpen = true;
}

void CharacterServer::openServer(char *ip, int portNum){
	_portNum = portNum;

	if(ip == NULL){
		char temp[256];
		GetIPAddress(temp);
		strcpy(_IP, temp);
	}else{
		strcpy(_IP, ip);
	}

	// Load WinSocket 2.2 DLL
	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		ErrorHandling("WSAStartup(), error");
	}

	// ���� ���� ����
	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	if(hServSock == INVALID_SOCKET)
	{
		ErrorHandling("socket() error");
	}

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(_portNum);

	// ���Ͽ� �ּ� �Ҵ�
	if(bind(hServSock, (SOCKADDR*) &servAddr, sizeof(servAddr)) == SOCKET_ERROR)
	{
		ErrorHandling("bind() error");
	}

	// ���� ��û ��� ����
	if(listen(hServSock, 5) == SOCKET_ERROR)
	{
		ErrorHandling("listen() error");
	}
}

void CharacterServer::ErrorHandling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

void CharacterServer::DeInit(){
	m_ThreadClose = true;

	while(m_ThreadOpen) Sleep(10);

	DeleteCriticalSection(&cs);	
}

UINT WINAPI CharacterServer::serverThread(LPVOID param){
	CharacterServer *t_server = (CharacterServer *)param;

	char buf[1024];
	renderData data_;

	//���� ����
	t_server->openServer(NULL, PORT);

	//�޴� ����
	//TO-DO
	while(!t_server->m_ThreadClose){
		int dataLen = recv(t_server->hServSock, buf, sizeof(buf), 0);
		if(dataLen == -1){
			t_server->ErrorHandling("read() Error");
			t_server->m_ThreadClose = true;
			break;
		}

		//���� ������ ��ȯ
		memcpy(&data_, buf, sizeof(renderData));

		//������ ��ȯ
		EnterCriticalSection(&t_server->cs);
		t_server->dataCount = data_.count;
		memcpy(&t_server->stateVec_, data_.character, sizeof(StateVector) * 2);
		LeaveCriticalSection(&t_server->cs);

	}

	// ���� ����
	closesocket(t_server->hServSock);
	WSACleanup();

	t_server->m_ThreadOpen = false;

	return 0;
}

void CharacterServer::getData(int *count, StateVector *dst){
	EnterCriticalSection(&cs);
	*count = dataCount;
	memcpy(dst, stateVec_, sizeof(StateVector) * 2);
	LeaveCriticalSection(&cs);
}

//bool CharacterServer::SendAndCheck(RobotInfoData data){
//	char buf[256];
//	memcpy(buf, &data, sizeof(RobotInfoData));
//	send(hClntSock, buf, sizeof(RobotInfoData), 0);
//	
//	// ������ ���� 
//	char check;
//	int strLen = recv(hClntSock, &check, 1, 0);
//	if(strLen == -1)
//	{
//		ErrorHandling("read() error");
//	}
//
//	return (check == 1) ? true : false;
//}