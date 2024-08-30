#ifndef CLIENT_H
#define CLIENT_H


#include "Comms.h"
#include <arpa/inet.h>
#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

class Client : public Comms {
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
            cout << "connection okay - now connected to Server on port " << PORT << endl;
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