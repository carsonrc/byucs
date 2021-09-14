cmake_minimum_required(VERSION 3.20)
project(project_1_main)

set(CMAKE_CXX_STANDARD 14)

add_executable(project_1_main main.cpp
                ColonAutomaton.cpp
                ColonAutomaton.h
                ColonDashAutomaton.cpp
                ColonDashAutomaton.h
                Lexer.cpp
                Lexer.h
                Token.cpp
                Token.h CommaAutomaton.cpp CommaAutomaton.h PeriodAutomaton.cpp PeriodAutomaton.h QuestionMarkAutomaton.cpp QuestionMarkAutomaton.h)
