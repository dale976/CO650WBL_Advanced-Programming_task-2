#include "Client.h"
#include <iostream>

using namespace std;

int main() {
    Client client;
    string message;

    if (client.initialise()) {
        client.connect();
        client.sendAndReceive();
    }

    return 0;
}
