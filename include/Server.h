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
#include <pthread.h>

using namespace std;

class Server : public Comms {
private:
    char buffer[1024] = {0}; // Buffer to store the received message
    const string response = "Message received";
    char host[NI_MAXHOST];
    int client_socket;
    pthread_t receive_t, send_t;
    static void* receiveMessage(void* arg) {
        Server* server = (Server*)arg;
        // Keep receiving messages until the client disconnects
        int valread;
        while ((valread = recv(server->client_socket, server->buffer, sizeof(server->buffer), 0)) > 0) {
            server->buffer[valread] = '\0'; // Null-terminate the received data
            cout << "\rMessage received: " << server->buffer << endl;
            cout.flush();

            cout << "Send a response to the client: ";
            cout.flush();
            string msg;
            getline(cin, msg);
            server->send(msg);
            cout << "Message sent: " << endl;
        }
        
        if (valread == 0) {
            cout << "Client disconnected" << endl;
            cout.flush();
            
        } else if (valread < 0) {
            cerr << "recv() error" << endl;
            cout.flush();
        }

        return nullptr;
    };
public: 
    Server() : client_socket(-1) {};
    ~Server() {
        if (client_socket != -1) {
            close(client_socket);
            client_socket = -1; 
        }
    };
    void connect() override {
        base_service.sin_family = AF_INET;
        base_service.sin_port = htons(PORT);
        // move to helper function or base method
        // verifies the conversion of an IP address from its string representation to binary form 
        if(inet_pton(AF_INET, IP_ADDRESS.c_str(), &base_service.sin_addr) == -1) {
            handleError("Invalid IP address or inet_pton failed");
        }

        if (bind(base_socket, (sockaddr *)&base_service, sizeof(base_service)) == -1) {
            handleError("bind() failed");
        }
        
        if (listen(base_socket, SOMAXCONN) == -1) {
            handleError("Listen failed");
        }

        cout << "Server ready; listening for connections on port " << PORT << endl;
    };
    void acceptClient() {
        socklen_t clientSize = sizeof(base_service);

        client_socket = accept(base_socket, (sockaddr*)&base_service, &clientSize);

        if (client_socket == -1) {
            handleError("client accept fail");
        }
    };
    void send(const string &msg) override {
        ::send(client_socket, msg.c_str(), msg.length(), 0);
    };
    void sendAndReceive() override {
        // create threads
        pthread_create(&receive_t, nullptr, receiveMessage, this);
        // join threads
        pthread_join(receive_t, nullptr);
    }
    
};


#endif // SERVER_H
