# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/carsoncall/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/carsoncall/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/carsoncall/CLionProjects/byucs/project-main

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project_1_main.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/project_1_main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project_1_main.dir/flags.make

CMakeFiles/project_1_main.dir/main.cpp.o: CMakeFiles/project_1_main.dir/flags.make
CMakeFiles/project_1_main.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project_1_main.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1_main.dir/main.cpp.o -c /home/carsoncall/CLionProjects/byucs/project-main/main.cpp

CMakeFiles/project_1_main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1_main.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carsoncall/CLionProjects/byucs/project-main/main.cpp > CMakeFiles/project_1_main.dir/main.cpp.i

CMakeFiles/project_1_main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1_main.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carsoncall/CLionProjects/byucs/project-main/main.cpp -o CMakeFiles/project_1_main.dir/main.cpp.s

CMakeFiles/project_1_main.dir/Lexer/ColonAutomaton.cpp.o: CMakeFiles/project_1_main.dir/flags.make
CMakeFiles/project_1_main.dir/Lexer/ColonAutomaton.cpp.o: ../Lexer/ColonAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project_1_main.dir/Lexer/ColonAutomaton.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1_main.dir/Lexer/ColonAutomaton.cpp.o -c /home/carsoncall/CLionProjects/byucs/project-main/Lexer/ColonAutomaton.cpp

CMakeFiles/project_1_main.dir/Lexer/ColonAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1_main.dir/Lexer/ColonAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carsoncall/CLionProjects/byucs/project-main/Lexer/ColonAutomaton.cpp > CMakeFiles/project_1_main.dir/Lexer/ColonAutomaton.cpp.i

CMakeFiles/project_1_main.dir/Lexer/ColonAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1_main.dir/Lexer/ColonAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carsoncall/CLionProjects/byucs/project-main/Lexer/ColonAutomaton.cpp -o CMakeFiles/project_1_main.dir/Lexer/ColonAutomaton.cpp.s

CMakeFiles/project_1_main.dir/Lexer/ColonDashAutomaton.cpp.o: CMakeFiles/project_1_main.dir/flags.make
CMakeFiles/project_1_main.dir/Lexer/ColonDashAutomaton.cpp.o: ../Lexer/ColonDashAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/project_1_main.dir/Lexer/ColonDashAutomaton.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1_main.dir/Lexer/ColonDashAutomaton.cpp.o -c /home/carsoncall/CLionProjects/byucs/project-main/Lexer/ColonDashAutomaton.cpp

CMakeFiles/project_1_main.dir/Lexer/ColonDashAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1_main.dir/Lexer/ColonDashAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carsoncall/CLionProjects/byucs/project-main/Lexer/ColonDashAutomaton.cpp > CMakeFiles/project_1_main.dir/Lexer/ColonDashAutomaton.cpp.i

CMakeFiles/project_1_main.dir/Lexer/ColonDashAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1_main.dir/Lexer/ColonDashAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carsoncall/CLionProjects/byucs/project-main/Lexer/ColonDashAutomaton.cpp -o CMakeFiles/project_1_main.dir/Lexer/ColonDashAutomaton.cpp.s

CMakeFiles/project_1_main.dir/Lexer/Lexer.cpp.o: CMakeFiles/project_1_main.dir/flags.make
CMakeFiles/project_1_main.dir/Lexer/Lexer.cpp.o: ../Lexer/Lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/project_1_main.dir/Lexer/Lexer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1_main.dir/Lexer/Lexer.cpp.o -c /home/carsoncall/CLionProjects/byucs/project-main/Lexer/Lexer.cpp

CMakeFiles/project_1_main.dir/Lexer/Lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1_main.dir/Lexer/Lexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carsoncall/CLionProjects/byucs/project-main/Lexer/Lexer.cpp > CMakeFiles/project_1_main.dir/Lexer/Lexer.cpp.i

CMakeFiles/project_1_main.dir/Lexer/Lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1_main.dir/Lexer/Lexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carsoncall/CLionProjects/byucs/project-main/Lexer/Lexer.cpp -o CMakeFiles/project_1_main.dir/Lexer/Lexer.cpp.s

CMakeFiles/project_1_main.dir/Lexer/Token.cpp.o: CMakeFiles/project_1_main.dir/flags.make
CMakeFiles/project_1_main.dir/Lexer/Token.cpp.o: ../Lexer/Token.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/project_1_main.dir/Lexer/Token.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1_main.dir/Lexer/Token.cpp.o -c /home/carsoncall/CLionProjects/byucs/project-main/Lexer/Token.cpp

CMakeFiles/project_1_main.dir/Lexer/Token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1_main.dir/Lexer/Token.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carsoncall/CLionProjects/byucs/project-main/Lexer/Token.cpp > CMakeFiles/project_1_main.dir/Lexer/Token.cpp.i

CMakeFiles/project_1_main.dir/Lexer/Token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1_main.dir/Lexer/Token.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carsoncall/CLionProjects/byucs/project-main/Lexer/Token.cpp -o CMakeFiles/project_1_main.dir/Lexer/Token.cpp.s

CMakeFiles/project_1_main.dir/Lexer/CommaAutomaton.cpp.o: CMakeFiles/project_1_main.dir/flags.make
CMakeFiles/project_1_main.dir/Lexer/CommaAutomaton.cpp.o: ../Lexer/CommaAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/project_1_main.dir/Lexer/CommaAutomaton.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1_main.dir/Lexer/CommaAutomaton.cpp.o -c /home/carsoncall/CLionProjects/byucs/project-main/Lexer/CommaAutomaton.cpp

CMakeFiles/project_1_main.dir/Lexer/CommaAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1_main.dir/Lexer/CommaAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carsoncall/CLionProjects/byucs/project-main/Lexer/CommaAutomaton.cpp > CMakeFiles/project_1_main.dir/Lexer/CommaAutomaton.cpp.i

CMakeFiles/project_1_main.dir/Lexer/CommaAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1_main.dir/Lexer/CommaAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carsoncall/CLionProjects/byucs/project-main/Lexer/CommaAutomaton.cpp -o CMakeFiles/project_1_main.dir/Lexer/CommaAutomaton.cpp.s

CMakeFiles/project_1_main.dir/Lexer/PeriodAutomaton.cpp.o: CMakeFiles/project_1_main.dir/flags.make
CMakeFiles/project_1_main.dir/Lexer/PeriodAutomaton.cpp.o: ../Lexer/PeriodAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/project_1_main.dir/Lexer/PeriodAutomaton.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1_main.dir/Lexer/PeriodAutomaton.cpp.o -c /home/carsoncall/CLionProjects/byucs/project-main/Lexer/PeriodAutomaton.cpp

CMakeFiles/project_1_main.dir/Lexer/PeriodAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1_main.dir/Lexer/PeriodAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carsoncall/CLionProjects/byucs/project-main/Lexer/PeriodAutomaton.cpp > CMakeFiles/project_1_main.dir/Lexer/PeriodAutomaton.cpp.i

CMakeFiles/project_1_main.dir/Lexer/PeriodAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1_main.dir/Lexer/PeriodAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carsoncall/CLionProjects/byucs/project-main/Lexer/PeriodAutomaton.cpp -o CMakeFiles/project_1_main.dir/Lexer/PeriodAutomaton.cpp.s

CMakeFiles/project_1_main.dir/Lexer/QuestionMarkAutomaton.cpp.o: CMakeFiles/project_1_main.dir/flags.make
CMakeFiles/project_1_main.dir/Lexer/QuestionMarkAutomaton.cpp.o: ../Lexer/QuestionMarkAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/project_1_main.dir/Lexer/QuestionMarkAutomaton.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1_main.dir/Lexer/QuestionMarkAutomaton.cpp.o -c /home/carsoncall/CLionProjects/byucs/project-main/Lexer/QuestionMarkAutomaton.cpp

CMakeFiles/project_1_main.dir/Lexer/QuestionMarkAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1_main.dir/Lexer/QuestionMarkAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carsoncall/CLionProjects/byucs/project-main/Lexer/QuestionMarkAutomaton.cpp > CMakeFiles/project_1_main.dir/Lexer/QuestionMarkAutomaton.cpp.i

CMakeFiles/project_1_main.dir/Lexer/QuestionMarkAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1_main.dir/Lexer/QuestionMarkAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carsoncall/CLionProjects/byucs/project-main/Lexer/QuestionMarkAutomaton.cpp -o CMakeFiles/project_1_main.dir/Lexer/QuestionMarkAutomaton.cpp.s

CMakeFiles/project_1_main.dir/Lexer/WhitespaceAutomaton.cpp.o: CMakeFiles/project_1_main.dir/flags.make
CMakeFiles/project_1_main.dir/Lexer/WhitespaceAutomaton.cpp.o: ../Lexer/WhitespaceAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/project_1_main.dir/Lexer/WhitespaceAutomaton.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1_main.dir/Lexer/WhitespaceAutomaton.cpp.o -c /home/carsoncall/CLionProjects/byucs/project-main/Lexer/WhitespaceAutomaton.cpp

CMakeFiles/project_1_main.dir/Lexer/WhitespaceAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1_main.dir/Lexer/WhitespaceAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carsoncall/CLionProjects/byucs/project-main/Lexer/WhitespaceAutomaton.cpp > CMakeFiles/project_1_main.dir/Lexer/WhitespaceAutomaton.cpp.i

CMakeFiles/project_1_main.dir/Lexer/WhitespaceAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1_main.dir/Lexer/WhitespaceAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carsoncall/CLionProjects/byucs/project-main/Lexer/WhitespaceAutomaton.cpp -o CMakeFiles/project_1_main.dir/Lexer/WhitespaceAutomaton.cpp.s

CMakeFiles/project_1_main.dir/Lexer/LeftParenAutomaton.cpp.o: CMakeFiles/project_1_main.dir/flags.make
CMakeFiles/project_1_main.dir/Lexer/LeftParenAutomaton.cpp.o: ../Lexer/LeftParenAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/project_1_main.dir/Lexer/LeftParenAutomaton.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1_main.dir/Lexer/LeftParenAutomaton.cpp.o -c /home/carsoncall/CLionProjects/byucs/project-main/Lexer/LeftParenAutomaton.cpp

CMakeFiles/project_1_main.dir/Lexer/LeftParenAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1_main.dir/Lexer/LeftParenAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carsoncall/CLionProjects/byucs/project-main/Lexer/LeftParenAutomaton.cpp > CMakeFiles/project_1_main.dir/Lexer/LeftParenAutomaton.cpp.i

CMakeFiles/project_1_main.dir/Lexer/LeftParenAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1_main.dir/Lexer/LeftParenAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carsoncall/CLionProjects/byucs/project-main/Lexer/LeftParenAutomaton.cpp -o CMakeFiles/project_1_main.dir/Lexer/LeftParenAutomaton.cpp.s

CMakeFiles/project_1_main.dir/Lexer/RightParenAutomaton.cpp.o: CMakeFiles/project_1_main.dir/flags.make
CMakeFiles/project_1_main.dir/Lexer/RightParenAutomaton.cpp.o: ../Lexer/RightParenAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/project_1_main.dir/Lexer/RightParenAutomaton.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1_main.dir/Lexer/RightParenAutomaton.cpp.o -c /home/carsoncall/CLionProjects/byucs/project-main/Lexer/RightParenAutomaton.cpp

CMakeFiles/project_1_main.dir/Lexer/RightParenAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1_main.dir/Lexer/RightParenAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carsoncall/CLionProjects/byucs/project-main/Lexer/RightParenAutomaton.cpp > CMakeFiles/project_1_main.dir/Lexer/RightParenAutomaton.cpp.i

CMakeFiles/project_1_main.dir/Lexer/RightParenAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1_main.dir/Lexer/RightParenAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carsoncall/CLionProjects/byucs/project-main/Lexer/RightParenAutomaton.cpp -o CMakeFiles/project_1_main.dir/Lexer/RightParenAutomaton.cpp.s

CMakeFiles/project_1_main.dir/Lexer/MultiplyAutomaton.cpp.o: CMakeFiles/project_1_main.dir/flags.make
CMakeFiles/project_1_main.dir/Lexer/MultiplyAutomaton.cpp.o: ../Lexer/MultiplyAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/project_1_main.dir/Lexer/MultiplyAutomaton.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1_main.dir/Lexer/MultiplyAutomaton.cpp.o -c /home/carsoncall/CLionProjects/byucs/project-main/Lexer/MultiplyAutomaton.cpp

CMakeFiles/project_1_main.dir/Lexer/MultiplyAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1_main.dir/Lexer/MultiplyAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carsoncall/CLionProjects/byucs/project-main/Lexer/MultiplyAutomaton.cpp > CMakeFiles/project_1_main.dir/Lexer/MultiplyAutomaton.cpp.i

CMakeFiles/project_1_main.dir/Lexer/MultiplyAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1_main.dir/Lexer/MultiplyAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carsoncall/CLionProjects/byucs/project-main/Lexer/MultiplyAutomaton.cpp -o CMakeFiles/project_1_main.dir/Lexer/MultiplyAutomaton.cpp.s

CMakeFiles/project_1_main.dir/Lexer/AddAutomaton.cpp.o: CMakeFiles/project_1_main.dir/flags.make
CMakeFiles/project_1_main.dir/Lexer/AddAutomaton.cpp.o: ../Lexer/AddAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/project_1_main.dir/Lexer/AddAutomaton.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1_main.dir/Lexer/AddAutomaton.cpp.o -c /home/carsoncall/CLionProjects/byucs/project-main/Lexer/AddAutomaton.cpp

CMakeFiles/project_1_main.dir/Lexer/AddAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1_main.dir/Lexer/AddAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carsoncall/CLionProjects/byucs/project-main/Lexer/AddAutomaton.cpp > CMakeFiles/project_1_main.dir/Lexer/AddAutomaton.cpp.i

CMakeFiles/project_1_main.dir/Lexer/AddAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1_main.dir/Lexer/AddAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carsoncall/CLionProjects/byucs/project-main/Lexer/AddAutomaton.cpp -o CMakeFiles/project_1_main.dir/Lexer/AddAutomaton.cpp.s

CMakeFiles/project_1_main.dir/Lexer/SchemesAutomaton.cpp.o: CMakeFiles/project_1_main.dir/flags.make
CMakeFiles/project_1_main.dir/Lexer/SchemesAutomaton.cpp.o: ../Lexer/SchemesAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/project_1_main.dir/Lexer/SchemesAutomaton.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1_main.dir/Lexer/SchemesAutomaton.cpp.o -c /home/carsoncall/CLionProjects/byucs/project-main/Lexer/SchemesAutomaton.cpp

CMakeFiles/project_1_main.dir/Lexer/SchemesAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1_main.dir/Lexer/SchemesAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carsoncall/CLionProjects/byucs/project-main/Lexer/SchemesAutomaton.cpp > CMakeFiles/project_1_main.dir/Lexer/SchemesAutomaton.cpp.i

CMakeFiles/project_1_main.dir/Lexer/SchemesAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1_main.dir/Lexer/SchemesAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carsoncall/CLionProjects/byucs/project-main/Lexer/SchemesAutomaton.cpp -o CMakeFiles/project_1_main.dir/Lexer/SchemesAutomaton.cpp.s

CMakeFiles/project_1_main.dir/Lexer/RulesAutomaton.cpp.o: CMakeFiles/project_1_main.dir/flags.make
CMakeFiles/project_1_main.dir/Lexer/RulesAutomaton.cpp.o: ../Lexer/RulesAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/project_1_main.dir/Lexer/RulesAutomaton.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1_main.dir/Lexer/RulesAutomaton.cpp.o -c /home/carsoncall/CLionProjects/byucs/project-main/Lexer/RulesAutomaton.cpp

CMakeFiles/project_1_main.dir/Lexer/RulesAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1_main.dir/Lexer/RulesAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carsoncall/CLionProjects/byucs/project-main/Lexer/RulesAutomaton.cpp > CMakeFiles/project_1_main.dir/Lexer/RulesAutomaton.cpp.i

CMakeFiles/project_1_main.dir/Lexer/RulesAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1_main.dir/Lexer/RulesAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carsoncall/CLionProjects/byucs/project-main/Lexer/RulesAutomaton.cpp -o CMakeFiles/project_1_main.dir/Lexer/RulesAutomaton.cpp.s

CMakeFiles/project_1_main.dir/Lexer/QueriesAutomaton.cpp.o: CMakeFiles/project_1_main.dir/flags.make
CMakeFiles/project_1_main.dir/Lexer/QueriesAutomaton.cpp.o: ../Lexer/QueriesAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/project_1_main.dir/Lexer/QueriesAutomaton.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1_main.dir/Lexer/QueriesAutomaton.cpp.o -c /home/carsoncall/CLionProjects/byucs/project-main/Lexer/QueriesAutomaton.cpp

CMakeFiles/project_1_main.dir/Lexer/QueriesAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1_main.dir/Lexer/QueriesAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carsoncall/CLionProjects/byucs/project-main/Lexer/QueriesAutomaton.cpp > CMakeFiles/project_1_main.dir/Lexer/QueriesAutomaton.cpp.i

CMakeFiles/project_1_main.dir/Lexer/QueriesAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1_main.dir/Lexer/QueriesAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carsoncall/CLionProjects/byucs/project-main/Lexer/QueriesAutomaton.cpp -o CMakeFiles/project_1_main.dir/Lexer/QueriesAutomaton.cpp.s

CMakeFiles/project_1_main.dir/Lexer/IDAutomaton.cpp.o: CMakeFiles/project_1_main.dir/flags.make
CMakeFiles/project_1_main.dir/Lexer/IDAutomaton.cpp.o: ../Lexer/IDAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/project_1_main.dir/Lexer/IDAutomaton.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1_main.dir/Lexer/IDAutomaton.cpp.o -c /home/carsoncall/CLionProjects/byucs/project-main/Lexer/IDAutomaton.cpp

CMakeFiles/project_1_main.dir/Lexer/IDAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1_main.dir/Lexer/IDAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carsoncall/CLionProjects/byucs/project-main/Lexer/IDAutomaton.cpp > CMakeFiles/project_1_main.dir/Lexer/IDAutomaton.cpp.i

CMakeFiles/project_1_main.dir/Lexer/IDAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1_main.dir/Lexer/IDAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carsoncall/CLionProjects/byucs/project-main/Lexer/IDAutomaton.cpp -o CMakeFiles/project_1_main.dir/Lexer/IDAutomaton.cpp.s

CMakeFiles/project_1_main.dir/Lexer/StringAutomaton.cpp.o: CMakeFiles/project_1_main.dir/flags.make
CMakeFiles/project_1_main.dir/Lexer/StringAutomaton.cpp.o: ../Lexer/StringAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/project_1_main.dir/Lexer/StringAutomaton.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1_main.dir/Lexer/StringAutomaton.cpp.o -c /home/carsoncall/CLionProjects/byucs/project-main/Lexer/StringAutomaton.cpp

CMakeFiles/project_1_main.dir/Lexer/StringAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1_main.dir/Lexer/StringAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carsoncall/CLionProjects/byucs/project-main/Lexer/StringAutomaton.cpp > CMakeFiles/project_1_main.dir/Lexer/StringAutomaton.cpp.i

CMakeFiles/project_1_main.dir/Lexer/StringAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1_main.dir/Lexer/StringAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carsoncall/CLionProjects/byucs/project-main/Lexer/StringAutomaton.cpp -o CMakeFiles/project_1_main.dir/Lexer/StringAutomaton.cpp.s

CMakeFiles/project_1_main.dir/Lexer/CommentAutomaton.cpp.o: CMakeFiles/project_1_main.dir/flags.make
CMakeFiles/project_1_main.dir/Lexer/CommentAutomaton.cpp.o: ../Lexer/CommentAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/project_1_main.dir/Lexer/CommentAutomaton.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1_main.dir/Lexer/CommentAutomaton.cpp.o -c /home/carsoncall/CLionProjects/byucs/project-main/Lexer/CommentAutomaton.cpp

CMakeFiles/project_1_main.dir/Lexer/CommentAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1_main.dir/Lexer/CommentAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carsoncall/CLionProjects/byucs/project-main/Lexer/CommentAutomaton.cpp > CMakeFiles/project_1_main.dir/Lexer/CommentAutomaton.cpp.i

CMakeFiles/project_1_main.dir/Lexer/CommentAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1_main.dir/Lexer/CommentAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carsoncall/CLionProjects/byucs/project-main/Lexer/CommentAutomaton.cpp -o CMakeFiles/project_1_main.dir/Lexer/CommentAutomaton.cpp.s

CMakeFiles/project_1_main.dir/Lexer/FactsAutomaton.cpp.o: CMakeFiles/project_1_main.dir/flags.make
CMakeFiles/project_1_main.dir/Lexer/FactsAutomaton.cpp.o: ../Lexer/FactsAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building CXX object CMakeFiles/project_1_main.dir/Lexer/FactsAutomaton.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1_main.dir/Lexer/FactsAutomaton.cpp.o -c /home/carsoncall/CLionProjects/byucs/project-main/Lexer/FactsAutomaton.cpp

CMakeFiles/project_1_main.dir/Lexer/FactsAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1_main.dir/Lexer/FactsAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carsoncall/CLionProjects/byucs/project-main/Lexer/FactsAutomaton.cpp > CMakeFiles/project_1_main.dir/Lexer/FactsAutomaton.cpp.i

CMakeFiles/project_1_main.dir/Lexer/FactsAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1_main.dir/Lexer/FactsAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carsoncall/CLionProjects/byucs/project-main/Lexer/FactsAutomaton.cpp -o CMakeFiles/project_1_main.dir/Lexer/FactsAutomaton.cpp.s

CMakeFiles/project_1_main.dir/Parser/Parser.cpp.o: CMakeFiles/project_1_main.dir/flags.make
CMakeFiles/project_1_main.dir/Parser/Parser.cpp.o: ../Parser/Parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Building CXX object CMakeFiles/project_1_main.dir/Parser/Parser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1_main.dir/Parser/Parser.cpp.o -c /home/carsoncall/CLionProjects/byucs/project-main/Parser/Parser.cpp

CMakeFiles/project_1_main.dir/Parser/Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1_main.dir/Parser/Parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carsoncall/CLionProjects/byucs/project-main/Parser/Parser.cpp > CMakeFiles/project_1_main.dir/Parser/Parser.cpp.i

CMakeFiles/project_1_main.dir/Parser/Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1_main.dir/Parser/Parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carsoncall/CLionProjects/byucs/project-main/Parser/Parser.cpp -o CMakeFiles/project_1_main.dir/Parser/Parser.cpp.s

# Object files for target project_1_main
project_1_main_OBJECTS = \
"CMakeFiles/project_1_main.dir/main.cpp.o" \
"CMakeFiles/project_1_main.dir/Lexer/ColonAutomaton.cpp.o" \
"CMakeFiles/project_1_main.dir/Lexer/ColonDashAutomaton.cpp.o" \
"CMakeFiles/project_1_main.dir/Lexer/Lexer.cpp.o" \
"CMakeFiles/project_1_main.dir/Lexer/Token.cpp.o" \
"CMakeFiles/project_1_main.dir/Lexer/CommaAutomaton.cpp.o" \
"CMakeFiles/project_1_main.dir/Lexer/PeriodAutomaton.cpp.o" \
"CMakeFiles/project_1_main.dir/Lexer/QuestionMarkAutomaton.cpp.o" \
"CMakeFiles/project_1_main.dir/Lexer/WhitespaceAutomaton.cpp.o" \
"CMakeFiles/project_1_main.dir/Lexer/LeftParenAutomaton.cpp.o" \
"CMakeFiles/project_1_main.dir/Lexer/RightParenAutomaton.cpp.o" \
"CMakeFiles/project_1_main.dir/Lexer/MultiplyAutomaton.cpp.o" \
"CMakeFiles/project_1_main.dir/Lexer/AddAutomaton.cpp.o" \
"CMakeFiles/project_1_main.dir/Lexer/SchemesAutomaton.cpp.o" \
"CMakeFiles/project_1_main.dir/Lexer/RulesAutomaton.cpp.o" \
"CMakeFiles/project_1_main.dir/Lexer/QueriesAutomaton.cpp.o" \
"CMakeFiles/project_1_main.dir/Lexer/IDAutomaton.cpp.o" \
"CMakeFiles/project_1_main.dir/Lexer/StringAutomaton.cpp.o" \
"CMakeFiles/project_1_main.dir/Lexer/CommentAutomaton.cpp.o" \
"CMakeFiles/project_1_main.dir/Lexer/FactsAutomaton.cpp.o" \
"CMakeFiles/project_1_main.dir/Parser/Parser.cpp.o"

# External object files for target project_1_main
project_1_main_EXTERNAL_OBJECTS =

project_1_main: CMakeFiles/project_1_main.dir/main.cpp.o
project_1_main: CMakeFiles/project_1_main.dir/Lexer/ColonAutomaton.cpp.o
project_1_main: CMakeFiles/project_1_main.dir/Lexer/ColonDashAutomaton.cpp.o
project_1_main: CMakeFiles/project_1_main.dir/Lexer/Lexer.cpp.o
project_1_main: CMakeFiles/project_1_main.dir/Lexer/Token.cpp.o
project_1_main: CMakeFiles/project_1_main.dir/Lexer/CommaAutomaton.cpp.o
project_1_main: CMakeFiles/project_1_main.dir/Lexer/PeriodAutomaton.cpp.o
project_1_main: CMakeFiles/project_1_main.dir/Lexer/QuestionMarkAutomaton.cpp.o
project_1_main: CMakeFiles/project_1_main.dir/Lexer/WhitespaceAutomaton.cpp.o
project_1_main: CMakeFiles/project_1_main.dir/Lexer/LeftParenAutomaton.cpp.o
project_1_main: CMakeFiles/project_1_main.dir/Lexer/RightParenAutomaton.cpp.o
project_1_main: CMakeFiles/project_1_main.dir/Lexer/MultiplyAutomaton.cpp.o
project_1_main: CMakeFiles/project_1_main.dir/Lexer/AddAutomaton.cpp.o
project_1_main: CMakeFiles/project_1_main.dir/Lexer/SchemesAutomaton.cpp.o
project_1_main: CMakeFiles/project_1_main.dir/Lexer/RulesAutomaton.cpp.o
project_1_main: CMakeFiles/project_1_main.dir/Lexer/QueriesAutomaton.cpp.o
project_1_main: CMakeFiles/project_1_main.dir/Lexer/IDAutomaton.cpp.o
project_1_main: CMakeFiles/project_1_main.dir/Lexer/StringAutomaton.cpp.o
project_1_main: CMakeFiles/project_1_main.dir/Lexer/CommentAutomaton.cpp.o
project_1_main: CMakeFiles/project_1_main.dir/Lexer/FactsAutomaton.cpp.o
project_1_main: CMakeFiles/project_1_main.dir/Parser/Parser.cpp.o
project_1_main: CMakeFiles/project_1_main.dir/build.make
project_1_main: CMakeFiles/project_1_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_22) "Linking CXX executable project_1_main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project_1_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project_1_main.dir/build: project_1_main
.PHONY : CMakeFiles/project_1_main.dir/build

CMakeFiles/project_1_main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project_1_main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project_1_main.dir/clean

CMakeFiles/project_1_main.dir/depend:
	cd /home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/carsoncall/CLionProjects/byucs/project-main /home/carsoncall/CLionProjects/byucs/project-main /home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug /home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug /home/carsoncall/CLionProjects/byucs/project-main/cmake-build-debug/CMakeFiles/project_1_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project_1_main.dir/depend

