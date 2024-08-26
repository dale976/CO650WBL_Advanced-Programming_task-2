#include "Server.h"
#include "Comms.h"
#include <iostream>

#ifdef BUILD_SERVER
Server::Server(){
    std::cout << "This is the server constructor." << std::endl;

    // sockaddr_in serverSocket;
    // sockaddr_in service;
    // string address = "127.0.0.1";
    // char buffer[1024] = {0}; // Buffer to store the received message
    // const char *response = "Message received";

    // char host[NI_MAXHOST];
}

Server::~Server(){
    std::cout << "This is the server destructor." << std::endl;
}

void Server::connect() {
    cout << "connect from server not comms" << endl;
}

// void Server::createSocket() {
//     std::cout << "This is the server function." << std::endl;
//     sharedFunction();

//     // STEP 2 - CREATE THE SOCKET
//     int sock = socket(AF_INET, SOCK_STREAM, 0);
//     if(sock == -1) {
//         cout << "Error whilst creating socket " << endl;
//     } else {
//         cout << "Socket created" << endl;
//     }

//     // PART 3 - BIND
//     service.sin_family = AF_INET; // IPV4
//     service.sin_port = htons(5400); // PORT
    
//     // verifies the conversion of an IP address from its string representation to binary form 
//     if(inet_pton(AF_INET, address.c_str(), &service.sin_addr) <= 0) {
//         cerr << "Invalid IP address or inet_pton failed" << endl;
//     } else {
//         cout << "inet_pton successful" << endl;
//     }

//     if (bind(sock, (sockaddr*)&service, sizeof(service)) == -1) {
//         cout << "bind() failed" << endl;
//     } else {
//         cout << "bind() successful" << endl;
//     }

//     // PART 4 - LISTEN
//     if (listen(sock, SOMAXCONN) == -1) {
//         cout << "Listen failed" << endl;
//     } else {
//         cout << "Listen Successful" << endl;
//     }

//     // PART 5 - ACCEPT
//     sockaddr_storage client;
//     socklen_t clientSize = sizeof(client);

//     int clientSocket = accept(sock, (sockaddr*)&client, &clientSize);

//     if (clientSocket == -1) {
//         cout << "accept error" << endl;
//     } else {
//         cout << "accept successful" << endl;
//     }

//      // Keep receiving messages until the client disconnects
//     int valread;
//     while ((valread = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0) {
//         buffer[valread] = '\0'; // Null-terminate the received data
//         std::cout << "Message received: " << buffer << std::endl;
        
//         // Send a response to the client
//         send(clientSocket, response, strlen(response), 0);
//         std::cout << "Response sent to client" << std::endl;
//     }
    
//     if (valread == 0) {
//         std::cout << "Client disconnected" << std::endl;
//     } else if (valread < 0) {
//         std::cerr << "recv() error" << std::endl;
//     }
    

//     // Close socket
//     close(clientSocket);
//     close(sock);
// }
#endif
