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
        Comms(): skt(-1){
            cout << "Comms constructor" << endl;
        }; // any other constructor code?
        virtual ~Comms(){
            cout << "Comms deconstructor" << endl;
            closeConnetion();
        }; // destructor to be overriden in subclass
        bool initialise() {
            cout << "Comms socket initialise" << endl;
            skt = socket(AF_INET, SOCK_STREAM, 0);
            if (skt == -1) {
                handleError("Error creating socket");
                return false;
            }
            return true;
        };
        void closeConnetion(){
            cout << "Comms close connection" << endl;
            if (skt != -1) {
                close(skt);
                cout << "Connection Closed" << endl;
            }
        };
    protected: // Make protected so only this class and any subclasses can access the following members
        const int PORT = 5400;
        const string IP_ADDRESS = "127.0.0.1";
        int skt;
        sockaddr_in address;

        virtual void connect() = 0; // override in subclass

        void handleError(const string &msg){
            cerr << msg << endl;
            exit(1);
        };

        
};

#endif // SHARED_H
