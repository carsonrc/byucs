//
// Created by carsoncall on 9/13/21.
//

#ifndef PROJECT_1_MAIN_COMMAAUTOMATON_H
#define PROJECT_1_MAIN_COMMAAUTOMATON_H

#include "Automaton.h"

class CommaAutomaton : public Automaton
{
public:
    CommaAutomaton() : Automaton(TokenType::COMMA) {}  // Call the base constructor

    void S0(const std::string& input);
};



#endif //PROJECT_1_MAIN_COMMAAUTOMATON_H
