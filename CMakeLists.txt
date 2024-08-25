cmake_minimum_required(VERSION 3.10)

# Set the project name
project(TCP_CHAT_APP)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)

# Add options to build client and/or server
option(BUILD_CLIENT "Build the client code" ON)
option(BUILD_SERVER "Build the server code" ON)

# Include the header files directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Define preprocessor symbols
if(BUILD_CLIENT)
    add_definitions(-DBUILD_CLIENT)
endif()

if(BUILD_SERVER)
    add_definitions(-DBUILD_SERVER)
endif()

# Shared sources
set(SHARED_SOURCES
    src/Comms.cpp
)

# Conditionally add client sources
if(BUILD_CLIENT)
    set(CLIENT_SOURCES
        src/main_client.cpp
        src/Client.cpp
    )
    add_executable(Client ${CLIENT_SOURCES} ${SHARED_SOURCES})
endif()

# Conditionally add server sources
if(BUILD_SERVER)
    set(SERVER_SOURCES
        src/main_server.cpp
        src/Server.cpp
    )
    add_executable(Server ${SERVER_SOURCES} ${SHARED_SOURCES})
endif()
