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
CMAKE_SOURCE_DIR = C:\Users\carso\CLionProjects\Final

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\carso\CLionProjects\Final\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Final.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Final.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Final.dir/flags.make

CMakeFiles/Final.dir/main.cpp.obj: CMakeFiles/Final.dir/flags.make
CMakeFiles/Final.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\carso\CLionProjects\Final\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Final.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Final.dir\main.cpp.obj -c C:\Users\carso\CLionProjects\Final\main.cpp

CMakeFiles/Final.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Final.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\carso\CLionProjects\Final\main.cpp > CMakeFiles\Final.dir\main.cpp.i

CMakeFiles/Final.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Final.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\carso\CLionProjects\Final\main.cpp -o CMakeFiles\Final.dir\main.cpp.s

CMakeFiles/Final.dir/Person.cpp.obj: CMakeFiles/Final.dir/flags.make
CMakeFiles/Final.dir/Person.cpp.obj: ../Person.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\carso\CLionProjects\Final\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Final.dir/Person.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Final.dir\Person.cpp.obj -c C:\Users\carso\CLionProjects\Final\Person.cpp

CMakeFiles/Final.dir/Person.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Final.dir/Person.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\carso\CLionProjects\Final\Person.cpp > CMakeFiles\Final.dir\Person.cpp.i

CMakeFiles/Final.dir/Person.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Final.dir/Person.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\carso\CLionProjects\Final\Person.cpp -o CMakeFiles\Final.dir\Person.cpp.s

CMakeFiles/Final.dir/PeopleList.cpp.obj: CMakeFiles/Final.dir/flags.make
CMakeFiles/Final.dir/PeopleList.cpp.obj: ../PeopleList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\carso\CLionProjects\Final\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Final.dir/PeopleList.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Final.dir\PeopleList.cpp.obj -c C:\Users\carso\CLionProjects\Final\PeopleList.cpp

CMakeFiles/Final.dir/PeopleList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Final.dir/PeopleList.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\carso\CLionProjects\Final\PeopleList.cpp > CMakeFiles\Final.dir\PeopleList.cpp.i

CMakeFiles/Final.dir/PeopleList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Final.dir/PeopleList.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\carso\CLionProjects\Final\PeopleList.cpp -o CMakeFiles\Final.dir\PeopleList.cpp.s

# Object files for target Final
Final_OBJECTS = \
"CMakeFiles/Final.dir/main.cpp.obj" \
"CMakeFiles/Final.dir/Person.cpp.obj" \
"CMakeFiles/Final.dir/PeopleList.cpp.obj"

# External object files for target Final
Final_EXTERNAL_OBJECTS =

Final.exe: CMakeFiles/Final.dir/main.cpp.obj
Final.exe: CMakeFiles/Final.dir/Person.cpp.obj
Final.exe: CMakeFiles/Final.dir/PeopleList.cpp.obj
Final.exe: CMakeFiles/Final.dir/build.make
Final.exe: CMakeFiles/Final.dir/linklibs.rsp
Final.exe: CMakeFiles/Final.dir/objects1.rsp
Final.exe: CMakeFiles/Final.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\carso\CLionProjects\Final\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Final.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Final.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Final.dir/build: Final.exe

.PHONY : CMakeFiles/Final.dir/build

CMakeFiles/Final.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Final.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Final.dir/clean

CMakeFiles/Final.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\carso\CLionProjects\Final C:\Users\carso\CLionProjects\Final C:\Users\carso\CLionProjects\Final\cmake-build-debug C:\Users\carso\CLionProjects\Final\cmake-build-debug C:\Users\carso\CLionProjects\Final\cmake-build-debug\CMakeFiles\Final.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Final.dir/depend
