#include <arpa/inet.h>
#include <iostream>
#include <netdb.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

void createServer() {
    // STEP 1 - EQUIV. OF WSAStartUp()
    // sockaddr_in serverSocket;
    sockaddr_in service;
    string address = "127.0.0.1";

    // char host[NI_MAXHOST];

    // STEP 2 - CREATE THE SOCKET
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        cout << "Error whilst creating socket " << endl;
    } else {
        cout << "Socket created" << endl;
    }

    // PART 3 - BIND
    service.sin_family = AF_INET; // IPV4
    service.sin_port = htons(5400); // PORT
    
    // verifies the conversion of an IP address from its string representation to binary form 
    if(inet_pton(AF_INET, address.c_str(), &service.sin_addr) <= 0) {
        cerr << "Invalid IP address or inet_pton failed" << endl;
    } else {
        cout << "inet_pton successful" << endl;
    }

    if (bind(sock, (sockaddr*)&service, sizeof(service)) == -1) {
        cout << "bind() failed" << endl;
    } else {
        cout << "bind() successful" << endl;
    }

    // PART 4 - LISTEN
    if (listen(sock, SOMAXCONN) == -1) {
        cout << "Listen failed" << endl;
    } else {
        cout << "Listen Successful" << endl;
    }

    // PART 5 - ACCEPT
    sockaddr_storage client;
    socklen_t clientSize = sizeof(client);

    int clientSocket = accept(sock, (sockaddr*)&client, &clientSize);

    if (clientSocket == -1) {
        cout << "accept error" << endl;
    } else {
        cout << "accept successful" << endl;
    }

    // Close socket
    close(sock);
}

void createClient() {
    // STEP 1 - EQUIV. OF WSAStartUp()
    sockaddr_in clientSocket;
	sockaddr_in clientService;

	string address = "127.0.0.1";

	char host[NI_MAXHOST];
	char service[NI_MAXSERV];

    const char *message = "Hello, Server!";
    char buffer[1024] = {0}; // Buffer to store the response from the server

    // STEP 2  - CREATE THE SOCKET
	int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        cout << "error with creating socket" << endl;
        close(sock);
    }
	else {
        cout << "socket created" << endl;
    }
		

    clientService.sin_family = AF_INET;
	clientService.sin_port = htons(5400);
	inet_pton(AF_INET, address.c_str(), &clientService.sin_addr);

    // STEP 3 - CONNECT ON CLIENT SOCKET
	int connectRes = connect(sock, (sockaddr*)&clientService, sizeof(clientService));
	if (connectRes == -1) {
        cout << "error with connection" << endl;
        close(sock);
    }
	else {
        cout << "connection okay - now connected to Server" << endl;
    }
		

    // close(sock);
    send(sock, message, strlen(message), 0);

    // Receive response from the server
    int valread = recv(sock, buffer, sizeof(buffer), 0);
    if (valread > 0) {
        buffer[valread] = '\0'; // Null-terminate the received data
        std::cout << "Response from server: " << buffer << std::endl;
    } else if (valread == 0) {
        std::cout << "Server closed the connection" << std::endl;
    } else {
        std::cerr << "recv() error" << std::endl;
    }



    // close(sock);
}

int main() {
    // createServer();
    createClient();
    return 0;
}