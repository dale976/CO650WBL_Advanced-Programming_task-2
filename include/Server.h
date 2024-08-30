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
    static void* receiveMessages(void* arg) {
        Server* server = static_cast<Server*>(arg);
        // Keep receiving messages until the client disconnects
        int valread;
        while ((valread = recv(server->client_socket, server->buffer, sizeof(server->buffer), 0)) > 0) {
            server->buffer[valread] = '\0'; // Null-terminate the received data
            cout << "Message received: " << server->buffer << endl;
            // Send a response to the client
            server->send(server->response);
            cout << "Response sent to client" << endl;
        }
        
        if (valread == 0) {
            cout << "Client disconnected" << endl;
        } else if (valread < 0) {
            cerr << "recv() error" << endl;
        }
        return nullptr;
    };
    static void* sendMessages(void* arg){
        Server* server = static_cast<Server*>(arg);
        string msg;
        while (true) {
            cout << "Enter message to send: ";
            getline(cin, msg);
            server->send(msg);
            if (msg == "QUIT") {
                break;
            }
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
    void send(const string &msg){
        ::send(client_socket, msg.c_str(), msg.length(), 0);
    };
    void sendAndReceive() {
        // create threads
        pthread_create(&receive_t, nullptr, receiveMessages, this);
        pthread_create(&send_t, nullptr, sendMessages, this);
        // join threads
        pthread_join(receive_t, nullptr);
        pthread_join(send_t, nullptr);
    }
    
};


#endif // SERVER_H
