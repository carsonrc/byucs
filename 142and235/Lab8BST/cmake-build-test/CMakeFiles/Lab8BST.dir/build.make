# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /home/carson/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.7628.27/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/carson/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.7628.27/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/backups/CLionProjects/Lab8BST

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/backups/CLionProjects/Lab8BST/cmake-build-test

# Include any dependencies generated for this target.
include CMakeFiles/Lab8BST.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab8BST.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab8BST.dir/flags.make

CMakeFiles/Lab8BST.dir/main.cpp.o: CMakeFiles/Lab8BST.dir/flags.make
CMakeFiles/Lab8BST.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/backups/CLionProjects/Lab8BST/cmake-build-test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab8BST.dir/main.cpp.o"
	/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab8BST.dir/main.cpp.o -c /mnt/backups/CLionProjects/Lab8BST/main.cpp

CMakeFiles/Lab8BST.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab8BST.dir/main.cpp.i"
	/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/backups/CLionProjects/Lab8BST/main.cpp > CMakeFiles/Lab8BST.dir/main.cpp.i

CMakeFiles/Lab8BST.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab8BST.dir/main.cpp.s"
	/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/backups/CLionProjects/Lab8BST/main.cpp -o CMakeFiles/Lab8BST.dir/main.cpp.s

# Object files for target Lab8BST
Lab8BST_OBJECTS = \
"CMakeFiles/Lab8BST.dir/main.cpp.o"

# External object files for target Lab8BST
Lab8BST_EXTERNAL_OBJECTS =

Lab8BST: CMakeFiles/Lab8BST.dir/main.cpp.o
Lab8BST: CMakeFiles/Lab8BST.dir/build.make
Lab8BST: CMakeFiles/Lab8BST.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/backups/CLionProjects/Lab8BST/cmake-build-test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab8BST"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab8BST.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab8BST.dir/build: Lab8BST

.PHONY : CMakeFiles/Lab8BST.dir/build

CMakeFiles/Lab8BST.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab8BST.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab8BST.dir/clean

CMakeFiles/Lab8BST.dir/depend:
	cd /mnt/backups/CLionProjects/Lab8BST/cmake-build-test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/backups/CLionProjects/Lab8BST /mnt/backups/CLionProjects/Lab8BST /mnt/backups/CLionProjects/Lab8BST/cmake-build-test /mnt/backups/CLionProjects/Lab8BST/cmake-build-test /mnt/backups/CLionProjects/Lab8BST/cmake-build-test/CMakeFiles/Lab8BST.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab8BST.dir/depend

