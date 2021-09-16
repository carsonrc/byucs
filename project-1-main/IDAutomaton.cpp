//
// Created by carsoncall on 9/15/21.
//

#include "IDAutomaton.h"


void IDAutomaton::S0(const std::string& input) {
    if (isalpha(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IDAutomaton::S1(const std::string& input) {
    while (isalnum(input[index])) {
        inputRead++;
        index++;
    }
}