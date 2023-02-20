#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
	WSAData wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKADDR_IN ServerSockAddr;
	ZeroMemory(&ServerSockAddr, sizeof(ServerSockAddr));
	ServerSockAddr.sin_family = AF_INET;
	ServerSockAddr.sin_port = htons(4000);
	ServerSockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
	connect(ServerSocket, (SOCKADDR*)&ServerSockAddr, sizeof(ServerSockAddr));
	char Buffer[1024] = { 0, };
	recv(ServerSocket, Buffer, sizeof(Buffer)-1, 0);

	std::cout << Buffer << std::endl;
	
	WSACleanup();

	return 0;
}