#include "Client.h"
#include <iostream>

using namespace std;

int main() {
    Client client;
    string message;

    if (client.initialise()) {
        client.connect();
    }

    while(true) {
        cout << "Enter message to server: " << endl;
        getline(cin, message);

        if (message == "QUIT") {
            break;
        }

        client.send(message);
        client.receive();
    }
    

    return 0;
}
