#include "Client.h"

int main() {
    Client client;

    if (client.initialise()) {
        client.connect();
        client.send("SOME CLIENT MESSAGE");
        client.receive();
    }

    return 0;
}
