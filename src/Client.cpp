#include "Client.h"
#include "Comms.h"
#include <iostream>

#ifdef BUILD_CLIENT
void clientFunction() {
    std::cout << "This is the client function." << std::endl;
    sharedFunction();
}
#endif
