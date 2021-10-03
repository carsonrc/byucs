cmake_minimum_required(VERSION 3.19)
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
        Token.h
        CommaAutomaton.cpp
        CommaAutomaton.h
        PeriodAutomaton.cpp
        PeriodAutomaton.h
        QuestionMarkAutomaton.cpp
        QuestionMarkAutomaton.h
        WhitespaceAutomaton.cpp
        WhitespaceAutomaton.h
        LeftParenAutomaton.cpp
        LeftParenAutomaton.h
        RightParenAutomaton.cpp
        RightParenAutomaton.h
        MultiplyAutomaton.cpp
        MultiplyAutomaton.h
        AddAutomaton.cpp
        AddAutomaton.h
        SchemesAutomaton.cpp
        SchemesAutomaton.h
        RulesAutomaton.cpp
        RulesAutomaton.h
        QueriesAutomaton.cpp
        QueriesAutomaton.h
        IDAutomaton.cpp
        IDAutomaton.h
        StringAutomaton.cpp
        StringAutomaton.h
        CommentAutomaton.cpp
        CommentAutomaton.h
        FactsAutomaton.cpp
        FactsAutomaton.h

        Parser.cpp
        Parser.h DatalogProgram.cpp DatalogProgram.h Rule.h Predicate.h Parameter.h)
