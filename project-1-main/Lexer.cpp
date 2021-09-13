#include <iostream>
#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "Token.h"
Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    // TODO: Add the other needed automata here
}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    /*
    set lineNumber to 1
    // While there are more characters to tokenize
    loop while input.size() > 0 {
        set maxRead to 0
        set maxAutomaton to the first automaton in automata

        // TODO: you need to handle whitespace inbetween tokens

        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        foreach automaton in automata {
            inputRead = automaton.Start(input)
            if (inputRead > maxRead) {
                set maxRead to inputRead
                set maxAutomaton to automaton
            }
        }
        // Here is the "Max" part of the algorithm
        if maxRead > 0 {
            set newToken to maxAutomaton.CreateToken(...)
                increment lineNumber by maxAutomaton.NewLinesRead()
                add newToken to collection of all tokens
        }
        // No automaton accepted input
        // Create single character undefined token
        else {
            set maxRead to 1
                set newToken to a  new undefined Token
                (with first character of input)
                add newToken to collection of all tokens
        }
        // Update `input` by removing characters read to create Token
        remove maxRead characters from input
    }
    add end of file token to all tokens
    */
    int lineNumber = 0;
    while (input.size() > 0) {
        int maxRead = 0;
        Automaton* maxAutomaton = nullptr;
        //TODO: handle whitespace

        //Parallel part of algorithm
        for (auto &&automaton : automata) {
            int inputRead = automaton->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automaton;
                lineNumber = automaton->NewLinesRead();
            }
        }

        //Max part of algorithm
        if (maxRead > 0) {
            Token* newToken = maxAutomaton->CreateToken(input.substr(0,maxRead),lineNumber);
            tokens.push_back(newToken);
        }

        //If no automaton accepted input, create a single character undefined token
        else {
            maxRead = 1;
                Token* newToken = new Token(TokenType::UNDEFINED,input.substr(0,1),lineNumber);
                maxRead = 1;
                tokens.push_back(newToken);
        }

        input = input.substr(maxRead,input.size()); //TODO: make sure there is no problem with maxRead
    }

    Token* eofToken = new Token(TokenType::END_OF_FILE,"",lineNumber);
    tokens.push_back(eofToken);

    for (auto& token : tokens) {
        std::cout << token;
    }
}
