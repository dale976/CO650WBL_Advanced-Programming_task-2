#ifndef SHARED_H
#define SHARED_H

#include <iostream>
#include <netdb.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

class Comms {
    public:
        Comms();
        virtual ~Comms();
        bool initialise();
        void closeConnetion();
    // Protected members; Only this class and any subclasses can access the following members
    protected: 
        const int PORT = 5400;
        const string IP_ADDRESS = "127.0.0.1";
        int base_socket;
        sockaddr_in service;
        // pure virtual methods, 0 value to indicate to the compiler that this is an empty method
        virtual void connect() = 0;
        virtual void send(const string &msg) = 0;
        virtual void sendAndReceive() = 0;

        void handleError(const string &msg);
};

#endif // SHARED_H
