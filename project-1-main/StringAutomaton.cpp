//
// Created by carsoncall on 9/15/21.
//

#include "StringAutomaton.h"


void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string& input) {
    while (true) {
        if (input[index] == '\'') {
            inputRead++;
            index++;
            S2(input);
            break;
        }
        if (index == input.size()) {
            type = TokenType::UNDEFINED;
            //do not increment for EOF because that is accounted for in EOF token
            break;
        }
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;

    }
}

void StringAutomaton::S2(const std::string &input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    //no else, because this was a peek and if it passes, we are done
}