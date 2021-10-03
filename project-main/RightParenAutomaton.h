//
// Created by carson on 9/14/21.
//

#ifndef PROJECT_1_MAIN_RIGHTPARENAUTOMATON_H
#define PROJECT_1_MAIN_RIGHTPARENAUTOMATON_H

#include "Automaton.h"

class RightParenAutomaton : public Automaton
{
public:
    RightParenAutomaton() : Automaton(TokenType::RIGHT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT_1_MAIN_RIGHTPARENAUTOMATON_H
