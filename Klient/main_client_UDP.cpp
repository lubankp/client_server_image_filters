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

	//Create a hint structure for the server
	sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(54000);
	inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

	// Socket creation
	SOCKET out = socket(AF_INET, SOCK_DGRAM, 0);

	int serverLength = sizeof(server);

	char buf[1024];

	while (true) {
		//Write out to that socket
		std::string s;
		std::getline(std::cin, s);

		int sendOK = sendto(out, s.c_str(), s.size() + 1, 0, (sockaddr*)&server, sizeof(server));

		if (sendOK == SOCKET_ERROR) {

			std::cout << "That didn't work!" << WSAGetLastError() << std::endl;
		}

		ZeroMemory(&buf, sizeof(buf));
		// Wait for message
		int bytesIn = recvfrom(out, buf, sizeof(buf), 0, (sockaddr*)&server, &serverLength);
		if (bytesIn == SOCKET_ERROR) {

			std::cout << "Error reciving from client " << WSAGetLastError() << std::endl;
			continue;
		}
		//Display message and client info
		char clientIp[256];
		ZeroMemory(&clientIp, sizeof(clientIp));

		inet_ntop(AF_INET, &server.sin_addr, clientIp, sizeof(clientIp));

		std::cout << "Message recv from " << clientIp << " : " << buf << std::endl;

	}
	//
	closesocket(out);

	std::string key;
	std::getline(std::cin, key);
	// close down Winsock
	WSACleanup();
}
*/