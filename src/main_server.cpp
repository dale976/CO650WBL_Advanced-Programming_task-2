#include "Server.h"
#include <iostream>

using namespace std;

int main() {
    cout << "main_server" << endl;
    Server server;

    if (server.initialise()) {
        server.connect();
        server.acceptClient();
        server.receive();
        server.send("SOME SERVER MESSAGE");
    }

    return 0;
}
