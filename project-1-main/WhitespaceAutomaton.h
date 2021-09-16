//
// Created by carson on 9/14/21.
//

#ifndef PROJECT_1_MAIN_WHITESPACEAUTOMATON_H
#define PROJECT_1_MAIN_WHITESPACEAUTOMATON_H

#include "Automaton.h"

class WhitespaceAutomaton : public Automaton
{
public:
    WhitespaceAutomaton() : Automaton(TokenType::WHITESPACE) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif //PROJECT_1_MAIN_WHITESPACEAUTOMATON_H
