//
// Created by carsoncall on 9/13/21.
//

#ifndef PROJECT_1_MAIN_QUESTIONMARKAUTOMATON_H
#define PROJECT_1_MAIN_QUESTIONMARKAUTOMATON_H

#include "Automaton.h"

class QuestionMarkAutomaton : public Automaton
{
public:
    QuestionMarkAutomaton() : Automaton(TokenType::QUESTION_MARK) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT_1_MAIN_QUESTIONMARKAUTOMATON_H
