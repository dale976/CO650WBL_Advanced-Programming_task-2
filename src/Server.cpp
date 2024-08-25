#include "Server.h"
#include "Comms.h"
#include <iostream>

#ifdef BUILD_SERVER
void serverFunction() {
    std::cout << "This is the server function." << std::endl;
    sharedFunction();
}
#endif
