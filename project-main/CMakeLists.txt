cmake_minimum_required(VERSION 3.19)
project(project_1_main)

set(CMAKE_CXX_STANDARD 14)

add_executable(project_1_main main.cpp
        Lexer/ColonAutomaton.cpp
        Lexer/ColonAutomaton.h
        Lexer/ColonDashAutomaton.cpp
        Lexer/ColonDashAutomaton.h
        Lexer/Lexer.cpp
        Lexer/Lexer.h
        Lexer/Token.cpp
        Lexer/Token.h
        Lexer/CommaAutomaton.cpp
        Lexer/CommaAutomaton.h
        Lexer/PeriodAutomaton.cpp
        Lexer/PeriodAutomaton.h
        Lexer/QuestionMarkAutomaton.cpp
        Lexer/QuestionMarkAutomaton.h
        Lexer/WhitespaceAutomaton.cpp
        Lexer/WhitespaceAutomaton.h
        Lexer/LeftParenAutomaton.cpp
        Lexer/LeftParenAutomaton.h
        Lexer/RightParenAutomaton.cpp
        Lexer/RightParenAutomaton.h
        Lexer/MultiplyAutomaton.cpp
        Lexer/MultiplyAutomaton.h
        Lexer/AddAutomaton.cpp
        Lexer/AddAutomaton.h
        Lexer/SchemesAutomaton.cpp
        Lexer/SchemesAutomaton.h
        Lexer/RulesAutomaton.cpp
        Lexer/RulesAutomaton.h
        Lexer/QueriesAutomaton.cpp
        Lexer/QueriesAutomaton.h
        Lexer/IDAutomaton.cpp
        Lexer/IDAutomaton.h
        Lexer/StringAutomaton.cpp
        Lexer/StringAutomaton.h
        Lexer/CommentAutomaton.cpp
        Lexer/CommentAutomaton.h
        Lexer/FactsAutomaton.cpp
        Lexer/FactsAutomaton.h

        Parser/Parser.cpp
        Parser/Parser.h)
