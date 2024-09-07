#pragma once

#ifndef CLIENT_H
#define CLIENT_H

#include "Comms.h"
#include <arpa/inet.h>
#include <iostream>
#include <netdb.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

class Client : public Comms {
    private:
        char buffer[1024] = {0}; // Buffer to store the received message
        pthread_t receive_t, send_t;
        static void* receiveMessage(void* arg);
        static void* sendMessage(void* arg);
    public:
        Client();
        ~Client();
        void connect() override;
        void send(const string &msg) override;
        void sendAndReceive() override;
};

#endif // CLIENT_H