#pragma once

#ifndef SERVER_H
#define SERVER_H


#include "Comms.h"
#include <arpa/inet.h>
#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>


using namespace std;

class Server : public Comms {
private:
    char buffer[1024] = {0}; // Buffer to store the received message
    const char *response = "Message received";
    char host[NI_MAXHOST];
    int client_socket;
public: 
    Server() : client_socket(-1) {};
    ~Server() {
        if (client_socket != -1) {
            close(client_socket);
            client_socket = -1; 
        }
    };
    void connect() override {
        service.sin_family = AF_INET; // IPV4
        service.sin_port = htons(PORT); // PORT
        // move to helper function or base method
        // verifies the conversion of an IP address from its string representation to binary form 
        if(inet_pton(AF_INET, IP_ADDRESS.c_str(), &service.sin_addr) == -1) {
            handleError("Invalid IP address or inet_pton failed");
        }

        if (bind(base_socket, (sockaddr *)&service, sizeof(service)) == -1) {
            handleError("bind() failed");
        }
        
        if (listen(base_socket, SOMAXCONN) == -1) {
            handleError("Listen failed");
        }

        cout << "Server ready; listening for connections on port " << PORT << endl;
    };
    void acceptClient() {
        socklen_t clientSize = sizeof(service);

        client_socket = accept(base_socket, (sockaddr*)&service, &clientSize);

        if (client_socket == -1) {
            handleError("client accept fail");
        }
    };
    void receive() {
        // Keep receiving messages until the client disconnects
        int valread;
        while ((valread = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
            buffer[valread] = '\0'; // Null-terminate the received data
            cout << "Message received: " << buffer << endl;
            // Send a response to the client
            ::send(client_socket, response, strlen(response), 0);
            cout << "Response sent to client" << endl;
        }
        
        if (valread == 0) {
            cout << "Client disconnected" << endl;
        } else if (valread < 0) {
            cerr << "recv() error" << endl;
        }
    };
    void send(const string &msg){
        ::send(client_socket, msg.c_str(), msg.length(), 0);
    };
};


#endif // SERVER_H



// void createServer() {
//     // STEP 1 - EQUIV. OF WSAStartUp()
//     sockaddr_in serverSocket;
//     sockaddr_in service;
//     string address = "127.0.0.1";
//     char buffer[1024] = {0}; // Buffer to store the received message
//     const char *response = "Message received";

//     char host[NI_MAXHOST];

//     // STEP 2 - CREATE THE SOCKET
//     int sock = socket(AF_INET, SOCK_STREAM, 0);
//     if(sock == -1) {
//         cout << "Error whilst creating socket " << endl;
//     } else {
//         cout << "Socket created" << endl;
//     }

//     // PART 3 - BIND
//     service.sin_family = AF_INET; // IPV4
//     service.sin_port = htons(5400); // PORT
    
//     // verifies the conversion of an IP address from its string representation to binary form 
//     if(inet_pton(AF_INET, address.c_str(), &service.sin_addr) <= 0) {
//         cerr << "Invalid IP address or inet_pton failed" << endl;
//     } else {
//         cout << "inet_pton successful" << endl;
//     }

//     if (bind(sock, (sockaddr*)&service, sizeof(service)) == -1) {
//         cout << "bind() failed" << endl;
//     } else {
//         cout << "bind() successful" << endl;
//     }

//     // PART 4 - LISTEN
//     if (listen(sock, SOMAXCONN) == -1) {
//         cout << "Listen failed" << endl;
//     } else {
//         cout << "Listen Successful" << endl;
//     }

//     // PART 5 - ACCEPT
//     sockaddr_storage client;
//     socklen_t clientSize = sizeof(client);

//     int clientSocket = accept(sock, (sockaddr*)&client, &clientSize);

//     if (clientSocket == -1) {
//         cout << "accept error" << endl;
//     } else {
//         cout << "accept successful" << endl;
//     }

//      // Keep receiving messages until the client disconnects
//     int valread;
//     while ((valread = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0) {
//         buffer[valread] = '\0'; // Null-terminate the received data
//         std::cout << "Message received: " << buffer << std::endl;
        
//         // Send a response to the client
//         send(clientSocket, response, strlen(response), 0);
//         std::cout << "Response sent to client" << std::endl;
//     }
    
//     if (valread == 0) {
//         std::cout << "Client disconnected" << std::endl;
//     } else if (valread < 0) {
//         std::cerr << "recv() error" << std::endl;
//     }
    

//     // Close socket
//     close(clientSocket);
//     close(sock);
// }
