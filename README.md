# CO650WBL_Advanced-Programming_task-2
## Server/Client TCP Chat application (C++)

#### Uses CMake for build and compilation

### Build only client:
mkdir build && cd build
cmake -DBUILD_SERVER=OFF ..
make

### Run client:
cd build
./Client

### Build only server:
mkdir build && cd build
cmake -DBUILD_CLIENT=OFF ..
make

### Run server:
cd build
./Server

In VS Code, the launch JSON and the tasks files have been created to allow build and execution within VS Code using the CMake extension.

All executables can be compiled, or a single one can be selected