//
// Created by carsoncall on 9/13/21.
//

#include "QuestionMarkAutomaton.h"

void QuestionMarkAutomaton::S0(const std::string& input) {
    if (input[index] == '?') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}