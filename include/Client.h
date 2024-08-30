#ifndef CLIENT_H
#define CLIENT_H

// void clientFunction();


#include "Comms.h"
#include <arpa/inet.h>
#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

class Client : public Comms {
    private:
        // sockaddr_in clientSocket;
        // sockaddr_in clientService;
        // string address = "127.0.0.1";
        // char host[NI_MAXHOST];
	    // char service[NI_MAXSERV];

    public:
        Client(){};
        ~Client(){};
        void connect() {
            cout << "connect from client not comms" << endl;
            cout << PORT << endl;
            service.sin_family = AF_INET;
            service.sin_port = htons(PORT);

            // verifies the conversion of an IP address from its string representation to binary form 
            if(inet_pton(AF_INET, IP_ADDRESS.c_str(), &service.sin_addr) <= 0) {
                handleError("Invalid IP address or inet_pton failed");
            } else {
                cout << "inet_pton successful" << endl;
            }

            // use the scope resolution operator as connect already exists as a method on the base class
            int connectRes = ::connect(base_socket, (sockaddr*)&service, sizeof(service));
            if (connectRes == -1) {
                handleError("error with connection");
            }
            cout << "connection okay - now connected to Server " << endl;
        };
        void receive() {
            char buffer[1024] = {0}; // Buffer to store the received message
            int valread = read(base_socket, buffer, sizeof(buffer));
            cout << "Message from server received: " << buffer << endl;
        };
        void send(const string &msg) {
            ::send(base_socket, msg.c_str(), msg.length(), 0);
        };
};


#endif // CLIENT_H

// void createClient() {
//     // STEP 1 - EQUIV. OF WSAStartUp()
//     // sockaddr_in clientSocket;
// 	// sockaddr_in clientService;

	
// 	// char host[NI_MAXHOST];
// 	// char service[NI_MAXSERV];

//     // STEP 2  - CREATE THE SOCKET
// 	int sock = socket(AF_INET, SOCK_STREAM, 0);
//     if (sock == -1)
// 		cout << "error with creating socket" << endl;
// 	else
// 		cout << "socket created" << endl;

//     clientService.sin_family = AF_INET;
// 	clientService.sin_port = htons(5400);
// 	inet_pton(AF_INET, address.c_str(), &clientService.sin_addr);

//     // STEP 3 - CONNECT ON CLIENT SOCKET
// 	int connectRes = connect(sock, (sockaddr*)&clientService, sizeof(clientService));
// 	if (connectRes == -1)
// 		cout << "error with connection" << endl;
// 	else
// 		cout << "connection okay - now connected to Server" << endl;



//     close(sock);
// }
