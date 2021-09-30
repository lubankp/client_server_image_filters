#include <iostream>
#include <WS2tcpip.h>
#include <string>

/*
int main() {

//Startup Winsock
	WSADATA data;
	WORD version = MAKEWORD(2, 2);
	int wsOK = WSAStartup(version, &data);
	if (wsOK != 0) {
		std::cout << "Can't start Winsock! " << wsOK;
	}

//Bind socket to ip address and port
	SOCKET in = socket(AF_INET, SOCK_DGRAM, 0);
	sockaddr_in serverHint;
	serverHint.sin_addr.S_un.S_addr = ADDR_ANY;
	serverHint.sin_family = AF_INET;
	serverHint.sin_port = htons(54000); // Convert from little to big endian

	if (bind(in, (sockaddr*)&serverHint, sizeof(serverHint)) == SOCKET_ERROR) {

		std::cout << "Can't bind socket! " << WSAGetLastError() << std::endl;
		return 0;
	}

	sockaddr_in client;
	int clientLenght = sizeof(client);
	ZeroMemory(&client, clientLenght);

	char buf[1024];

//Enter a loop
	while (true) {

		ZeroMemory(&buf, sizeof(buf));
		// Wait for message
		int bytesIn = recvfrom(in, buf, sizeof(buf), 0, (sockaddr*)&client, &clientLenght);
		if (bytesIn == SOCKET_ERROR) {

			std::cout << "Error reciving from client " << WSAGetLastError() << std::endl;
			continue;
		}
		//Display message and client info
		char clientIp[256];
		ZeroMemory(&clientIp, sizeof(clientIp));

		inet_ntop(AF_INET, &client.sin_addr, clientIp, sizeof(clientIp));

		std::cout << "Message recv from " << clientIp << " : " << buf << std::endl;

		std::string s;
		std::getline(std::cin, s);

		int sendOK = sendto(in, s.c_str(), s.size() + 1, 0, (sockaddr*)&client, sizeof(client));

		if (sendOK == SOCKET_ERROR) {

			std::cout << "That didn't work!" << WSAGetLastError() << std::endl;
		}

	}
	//Close socket
	closesocket(in);

	//Shutdown winsock
	WSACleanup();

}
*/