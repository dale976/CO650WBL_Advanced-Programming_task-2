#pragma once

#ifndef SERVER_H
#define SERVER_H

#include "Comms.h"
#include <arpa/inet.h>
#include <iostream>
#include <netdb.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

using namespace std;

class Server : public Comms {
private:
    char buffer[1024] = {0}; // Buffer to store the received message
    char host[NI_MAXHOST];
    int client_socket;
    pthread_t receive_t, send_t;
    static void* receiveMessage(void* arg);
public: 
    Server();
    ~Server();
    void connect() override;
    void acceptClient();
    void send(const string &msg) override;
    void sendAndReceive() override;
    
};

#endif // SERVER_H
