#include "Comms.h"
#include <iostream>

using namespace std;

Comms::Comms(): base_socket(-1){
    cout << "Comms constructor" << endl;
};

Comms::~Comms(){
    cout << "Comms deconstructor" << endl;
    closeConnetion();
};

bool Comms::initialise() {
    cout << "Comms socket initialise" << endl;
    base_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (base_socket < 0) {
        handleError("Error creating socket");
        return false;
    }
    return true;
};

void Comms::closeConnetion(){
    cout << "Comms close connection" << endl;
    if (base_socket != 0) {
        close(base_socket);
        cout << "Connection Closed" << endl;
    }
};

void Comms::handleError(const string &msg){
    cerr << msg << endl;
    exit(1);
};