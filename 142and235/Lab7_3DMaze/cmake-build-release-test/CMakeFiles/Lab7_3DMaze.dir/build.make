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
CMAKE_SOURCE_DIR = /mnt/backups/CLionProjects/Lab7_3DMaze

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/backups/CLionProjects/Lab7_3DMaze/cmake-build-release-test

# Include any dependencies generated for this target.
include CMakeFiles/Lab7_3DMaze.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab7_3DMaze.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab7_3DMaze.dir/flags.make

CMakeFiles/Lab7_3DMaze.dir/main.cpp.o: CMakeFiles/Lab7_3DMaze.dir/flags.make
CMakeFiles/Lab7_3DMaze.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/backups/CLionProjects/Lab7_3DMaze/cmake-build-release-test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab7_3DMaze.dir/main.cpp.o"
	/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab7_3DMaze.dir/main.cpp.o -c /mnt/backups/CLionProjects/Lab7_3DMaze/main.cpp

CMakeFiles/Lab7_3DMaze.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab7_3DMaze.dir/main.cpp.i"
	/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/backups/CLionProjects/Lab7_3DMaze/main.cpp > CMakeFiles/Lab7_3DMaze.dir/main.cpp.i

CMakeFiles/Lab7_3DMaze.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab7_3DMaze.dir/main.cpp.s"
	/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/backups/CLionProjects/Lab7_3DMaze/main.cpp -o CMakeFiles/Lab7_3DMaze.dir/main.cpp.s

# Object files for target Lab7_3DMaze
Lab7_3DMaze_OBJECTS = \
"CMakeFiles/Lab7_3DMaze.dir/main.cpp.o"

# External object files for target Lab7_3DMaze
Lab7_3DMaze_EXTERNAL_OBJECTS =

Lab7_3DMaze: CMakeFiles/Lab7_3DMaze.dir/main.cpp.o
Lab7_3DMaze: CMakeFiles/Lab7_3DMaze.dir/build.make
Lab7_3DMaze: CMakeFiles/Lab7_3DMaze.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/backups/CLionProjects/Lab7_3DMaze/cmake-build-release-test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab7_3DMaze"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab7_3DMaze.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab7_3DMaze.dir/build: Lab7_3DMaze

.PHONY : CMakeFiles/Lab7_3DMaze.dir/build

CMakeFiles/Lab7_3DMaze.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab7_3DMaze.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab7_3DMaze.dir/clean

CMakeFiles/Lab7_3DMaze.dir/depend:
	cd /mnt/backups/CLionProjects/Lab7_3DMaze/cmake-build-release-test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/backups/CLionProjects/Lab7_3DMaze /mnt/backups/CLionProjects/Lab7_3DMaze /mnt/backups/CLionProjects/Lab7_3DMaze/cmake-build-release-test /mnt/backups/CLionProjects/Lab7_3DMaze/cmake-build-release-test /mnt/backups/CLionProjects/Lab7_3DMaze/cmake-build-release-test/CMakeFiles/Lab7_3DMaze.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab7_3DMaze.dir/depend
