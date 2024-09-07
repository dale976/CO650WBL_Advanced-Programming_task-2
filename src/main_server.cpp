#include "Server.h"
#include <iostream>

using namespace std;

int main() {
    Server server;
    string message;

    if (server.initialise()) {
        server.connect();
        server.acceptClient();
        server.sendAndReceive();
    }

    return 0;
}
