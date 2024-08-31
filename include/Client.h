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
    private:
        char buffer[1024] = {0}; // Buffer to store the received message
        pthread_t receive_t, send_t;
        static void* receiveMessage(void* arg) {
            Client* client = (Client*)arg;
            // Keep receiving messages until the client disconnects
            int valread;
            while ((valread = recv(client->base_socket, client->buffer, sizeof(client->buffer), 0)) > 0) {
                client->buffer[valread] = '\0'; // Null-terminate the received data
                cout << "\rMessage received: " << client->buffer << endl;
                cout.flush();
                cout << "Enter message to send: ";
                cout.flush();
            }
            return nullptr;
        };
        static void* sendMessage(void* arg) {
            Client* client = (Client*)arg;
            string msg;
            while (true) {
                cout << "Enter message to send: ";
                getline(cin, msg);
                client->send(msg);
                if (msg == "QUIT") {
                    client->closeConnetion();
                    break;
                }
            }
            return nullptr;
        }
    public:
        Client(){};
        ~Client(){};
        void connect() override {
            cout << "connect from client not comms" << endl;
            cout << PORT << endl;
            base_service.sin_family = AF_INET;
            base_service.sin_port = htons(PORT);

            // verifies the conversion of an IP address from its string representation to binary form 
            if(inet_pton(AF_INET, IP_ADDRESS.c_str(), &base_service.sin_addr) <= 0) {
                handleError("Invalid IP address or inet_pton failed");
            } else {
                cout << "inet_pton successful" << endl;
            }

            // use the scope resolution operator as connect already exists as a method on the base class
            int connectRes = ::connect(base_socket, (sockaddr*)&base_service, sizeof(base_service));
            if (connectRes == -1) {
                handleError("error with connection");
            }
            cout << "connection okay - now connected to Server on port " << PORT << endl;
        };
        void send(const string &msg) override {
            ::send(base_socket, msg.c_str(), msg.length(), 0);
        };
        void sendAndReceive() override {
            // create threads
            pthread_create(&receive_t, nullptr, receiveMessage, this);
            pthread_create(&send_t, nullptr, sendMessage, this);
            // join threads
            pthread_join(receive_t, nullptr);
            pthread_join(send_t, nullptr);
        }
};


#endif // CLIENT_H