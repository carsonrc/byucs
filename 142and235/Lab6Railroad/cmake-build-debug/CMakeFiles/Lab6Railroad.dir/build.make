# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\CLionProjects\Lab6Railroad

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\CLionProjects\Lab6Railroad\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab6Railroad.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab6Railroad.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab6Railroad.dir/flags.make

CMakeFiles/Lab6Railroad.dir/main.cpp.obj: CMakeFiles/Lab6Railroad.dir/flags.make
CMakeFiles/Lab6Railroad.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\CLionProjects\Lab6Railroad\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab6Railroad.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab6Railroad.dir\main.cpp.obj -c E:\CLionProjects\Lab6Railroad\main.cpp

CMakeFiles/Lab6Railroad.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab6Railroad.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\CLionProjects\Lab6Railroad\main.cpp > CMakeFiles\Lab6Railroad.dir\main.cpp.i

CMakeFiles/Lab6Railroad.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab6Railroad.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\CLionProjects\Lab6Railroad\main.cpp -o CMakeFiles\Lab6Railroad.dir\main.cpp.s

# Object files for target Lab6Railroad
Lab6Railroad_OBJECTS = \
"CMakeFiles/Lab6Railroad.dir/main.cpp.obj"

# External object files for target Lab6Railroad
Lab6Railroad_EXTERNAL_OBJECTS =

Lab6Railroad.exe: CMakeFiles/Lab6Railroad.dir/main.cpp.obj
Lab6Railroad.exe: CMakeFiles/Lab6Railroad.dir/build.make
Lab6Railroad.exe: CMakeFiles/Lab6Railroad.dir/linklibs.rsp
Lab6Railroad.exe: CMakeFiles/Lab6Railroad.dir/objects1.rsp
Lab6Railroad.exe: CMakeFiles/Lab6Railroad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\CLionProjects\Lab6Railroad\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab6Railroad.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lab6Railroad.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab6Railroad.dir/build: Lab6Railroad.exe

.PHONY : CMakeFiles/Lab6Railroad.dir/build

CMakeFiles/Lab6Railroad.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab6Railroad.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lab6Railroad.dir/clean

CMakeFiles/Lab6Railroad.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\CLionProjects\Lab6Railroad E:\CLionProjects\Lab6Railroad E:\CLionProjects\Lab6Railroad\cmake-build-debug E:\CLionProjects\Lab6Railroad\cmake-build-debug E:\CLionProjects\Lab6Railroad\cmake-build-debug\CMakeFiles\Lab6Railroad.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab6Railroad.dir/depend
