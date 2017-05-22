#include<WinSock2.h>
#include<stdio.h>
#include<Windows.h>
#pragma comment(lib,"WS2_32.lib")

int main()
{
	WSADATA data;
	WORD w = MAKEWORD(2, 0);
	//init
	::WSAStartup(w, &data);
	SOCKET s;
	char sztext[10] = { 0 };
	//create
	s = ::socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(75);
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	printf("客户端已启动\r\n");
	//connect
	::connect(s, (sockaddr*)&addr, sizeof(addr));
	//read
	::recv(s, sztext, sizeof(sztext), 0);
	printf("%s\r\n", sztext);

	//close
	::closesocket(s);
	//clear
	::WSACleanup();

	if (getchar())
	{
		return 0;
	}
	else
	{
		::Sleep(100);
	}



}