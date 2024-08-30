#ifndef SHARED_H
#define SHARED_H

#include <iostream>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

class Comms {
    public:
        Comms(): base_socket(-1){
            cout << "Comms constructor" << endl;
        }; // any other constructor code?
        virtual ~Comms(){
            cout << "Comms deconstructor" << endl;
            closeConnetion();
        }; // destructor to be overriden in subclass
        bool initialise() {
            cout << "Comms socket initialise" << endl;
            base_socket = socket(AF_INET, SOCK_STREAM, 0);
            if (base_socket < 0) {
                handleError("Error creating socket");
                return false;
            }
            return true;
        };
        void closeConnetion(){
            cout << "Comms close connection" << endl;
            if (base_socket != 0) {
                close(base_socket);
                cout << "Connection Closed" << endl;
            }
        };
    protected: // Make protected so only this class and any subclasses can access the following members
        const int PORT = 5400;
        const string IP_ADDRESS = "127.0.0.1";
        int base_socket;
        sockaddr_in service;

        virtual void connect() = 0; // override in subclass

        void handleError(const string &msg){
            cerr << msg << endl;
            exit(1);
        };

        
};

#endif // SHARED_H
