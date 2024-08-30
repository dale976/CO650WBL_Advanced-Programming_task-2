#include "Server.h"
#include <iostream>

using namespace std;

int main() {
    cout << "main_server" << endl;
    Server server;
    string message;

    if (server.initialise()) {
        server.connect();
        server.acceptClient();
        server.sendAndReceive();
        // server.send("SOME SERVER MESSAGE");
    }

    // while(true) {
    //     cout << "Enter message to client: " << endl;
    //     getline(cin, message);

    //     if (message == "QUIT") {
    //         break;
    //     }

    //     server.send(message);
    // }

    return 0;
}
