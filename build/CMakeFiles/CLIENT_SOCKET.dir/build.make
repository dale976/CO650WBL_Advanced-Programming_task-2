# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.5/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/daleal/Workspace/UNI/CO650WBL_TASK-2_CHAT-APPLICATION

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/daleal/Workspace/UNI/CO650WBL_TASK-2_CHAT-APPLICATION/build

# Include any dependencies generated for this target.
include CMakeFiles/CLIENT_SOCKET.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CLIENT_SOCKET.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CLIENT_SOCKET.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CLIENT_SOCKET.dir/flags.make

CMakeFiles/CLIENT_SOCKET.dir/src/main.cpp.o: CMakeFiles/CLIENT_SOCKET.dir/flags.make
CMakeFiles/CLIENT_SOCKET.dir/src/main.cpp.o: /Users/daleal/Workspace/UNI/CO650WBL_TASK-2_CHAT-APPLICATION/src/main.cpp
CMakeFiles/CLIENT_SOCKET.dir/src/main.cpp.o: CMakeFiles/CLIENT_SOCKET.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/daleal/Workspace/UNI/CO650WBL_TASK-2_CHAT-APPLICATION/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CLIENT_SOCKET.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CLIENT_SOCKET.dir/src/main.cpp.o -MF CMakeFiles/CLIENT_SOCKET.dir/src/main.cpp.o.d -o CMakeFiles/CLIENT_SOCKET.dir/src/main.cpp.o -c /Users/daleal/Workspace/UNI/CO650WBL_TASK-2_CHAT-APPLICATION/src/main.cpp

CMakeFiles/CLIENT_SOCKET.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CLIENT_SOCKET.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/daleal/Workspace/UNI/CO650WBL_TASK-2_CHAT-APPLICATION/src/main.cpp > CMakeFiles/CLIENT_SOCKET.dir/src/main.cpp.i

CMakeFiles/CLIENT_SOCKET.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CLIENT_SOCKET.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/daleal/Workspace/UNI/CO650WBL_TASK-2_CHAT-APPLICATION/src/main.cpp -o CMakeFiles/CLIENT_SOCKET.dir/src/main.cpp.s

# Object files for target CLIENT_SOCKET
CLIENT_SOCKET_OBJECTS = \
"CMakeFiles/CLIENT_SOCKET.dir/src/main.cpp.o"

# External object files for target CLIENT_SOCKET
CLIENT_SOCKET_EXTERNAL_OBJECTS =

CLIENT_SOCKET: CMakeFiles/CLIENT_SOCKET.dir/src/main.cpp.o
CLIENT_SOCKET: CMakeFiles/CLIENT_SOCKET.dir/build.make
CLIENT_SOCKET: CMakeFiles/CLIENT_SOCKET.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/daleal/Workspace/UNI/CO650WBL_TASK-2_CHAT-APPLICATION/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CLIENT_SOCKET"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CLIENT_SOCKET.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CLIENT_SOCKET.dir/build: CLIENT_SOCKET
.PHONY : CMakeFiles/CLIENT_SOCKET.dir/build

CMakeFiles/CLIENT_SOCKET.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CLIENT_SOCKET.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CLIENT_SOCKET.dir/clean

CMakeFiles/CLIENT_SOCKET.dir/depend:
	cd /Users/daleal/Workspace/UNI/CO650WBL_TASK-2_CHAT-APPLICATION/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/daleal/Workspace/UNI/CO650WBL_TASK-2_CHAT-APPLICATION /Users/daleal/Workspace/UNI/CO650WBL_TASK-2_CHAT-APPLICATION /Users/daleal/Workspace/UNI/CO650WBL_TASK-2_CHAT-APPLICATION/build /Users/daleal/Workspace/UNI/CO650WBL_TASK-2_CHAT-APPLICATION/build /Users/daleal/Workspace/UNI/CO650WBL_TASK-2_CHAT-APPLICATION/build/CMakeFiles/CLIENT_SOCKET.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/CLIENT_SOCKET.dir/depend

