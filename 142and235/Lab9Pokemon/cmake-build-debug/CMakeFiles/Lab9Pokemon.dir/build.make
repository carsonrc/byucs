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
CMAKE_SOURCE_DIR = /mnt/backups/CLionProjects/Lab9Pokemon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/backups/CLionProjects/Lab9Pokemon/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab9Pokemon.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab9Pokemon.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab9Pokemon.dir/flags.make

CMakeFiles/Lab9Pokemon.dir/main.cpp.o: CMakeFiles/Lab9Pokemon.dir/flags.make
CMakeFiles/Lab9Pokemon.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/backups/CLionProjects/Lab9Pokemon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab9Pokemon.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab9Pokemon.dir/main.cpp.o -c /mnt/backups/CLionProjects/Lab9Pokemon/main.cpp

CMakeFiles/Lab9Pokemon.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab9Pokemon.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/backups/CLionProjects/Lab9Pokemon/main.cpp > CMakeFiles/Lab9Pokemon.dir/main.cpp.i

CMakeFiles/Lab9Pokemon.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab9Pokemon.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/backups/CLionProjects/Lab9Pokemon/main.cpp -o CMakeFiles/Lab9Pokemon.dir/main.cpp.s

# Object files for target Lab9Pokemon
Lab9Pokemon_OBJECTS = \
"CMakeFiles/Lab9Pokemon.dir/main.cpp.o"

# External object files for target Lab9Pokemon
Lab9Pokemon_EXTERNAL_OBJECTS =

Lab9Pokemon: CMakeFiles/Lab9Pokemon.dir/main.cpp.o
Lab9Pokemon: CMakeFiles/Lab9Pokemon.dir/build.make
Lab9Pokemon: CMakeFiles/Lab9Pokemon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/backups/CLionProjects/Lab9Pokemon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab9Pokemon"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab9Pokemon.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab9Pokemon.dir/build: Lab9Pokemon

.PHONY : CMakeFiles/Lab9Pokemon.dir/build

CMakeFiles/Lab9Pokemon.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab9Pokemon.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab9Pokemon.dir/clean

CMakeFiles/Lab9Pokemon.dir/depend:
	cd /mnt/backups/CLionProjects/Lab9Pokemon/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/backups/CLionProjects/Lab9Pokemon /mnt/backups/CLionProjects/Lab9Pokemon /mnt/backups/CLionProjects/Lab9Pokemon/cmake-build-debug /mnt/backups/CLionProjects/Lab9Pokemon/cmake-build-debug /mnt/backups/CLionProjects/Lab9Pokemon/cmake-build-debug/CMakeFiles/Lab9Pokemon.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab9Pokemon.dir/depend

