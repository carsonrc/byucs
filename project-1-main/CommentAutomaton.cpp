//
// Created by carsoncall on 9/15/21.
//

#include "CommentAutomaton.h"

void CommentAutomaton::S0(const std::string& input) { //start
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input) { //S2 if multiline, S3 normal
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        S3(input);
    }
}

void CommentAutomaton::S2(const std::string &input) { // read until |
    while (true) {
        if (input[index] == '|') {
            inputRead++;
            index++;
            S4(input);
            break;
        }
        if (index == input.size()) {
            type = TokenType::UNDEFINED;
            break;
        }
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;

    }
}

void CommentAutomaton::S3(const std::string &input) { // read until newline state
    while (true) {
        if (input[index] == '\n') {
            break;
            // do not read \n, leave it to the whitespace automaton
            //accept state
        }

        inputRead++;
        index++;
    }
}

void CommentAutomaton::S4(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        //accept state
    }
    else {
        inputRead++;
        index++;
        S2(input); //keep reading
    }

}