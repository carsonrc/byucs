//
// Created by carson on 9/14/21.
//

#include "WhitespaceAutomaton.h"

void WhitespaceAutomaton::S0(const std::string& input) {
    if (input[index] == ' ' || input[index] == '\t') {
        inputRead = 1;
    }
    if (input[index] == '\n') {
        inputRead = 1;
        newLines++;
    }
    else {
        Serr();
    }
}