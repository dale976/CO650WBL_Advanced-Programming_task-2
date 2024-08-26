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
        };
        // send();
        // receive();
        

        // void createSocket() {
        //     // SETUP SOCKET
        //     // SAME
        //     int sock = socket(AF_INET, SOCK_STREAM, 0);
        //     if (sock == -1)
        //         cout << "error with creating socket" << endl;
        //     else
        //         cout << "socket created" << endl;

        //     clientService.sin_family = AF_INET;
	    //     clientService.sin_port = htons(5400); // does port need to be different?
	    //     inet_pton(AF_INET, address.c_str(), &clientService.sin_addr);


        //     // STEP 3 - CONNECT ON CLIENT SOCKET
        //     int connectRes = connect(sock, (sockaddr*)&clientService, sizeof(clientService));
        //     if (connectRes == -1)
        //         cout << "error with connection" << endl;
        //     else
        //         cout << "connection okay - now connected to Server" << endl;
        // }

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
