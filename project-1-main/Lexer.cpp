#include <iostream>

#include "Lexer.h"

#include "AddAutomaton.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "CommentAutomaton.h"
#include "FactsAutomaton.h"
#include "IDAutomaton.h"
#include "LeftParenAutomaton.h"
#include "MultiplyAutomaton.h"
#include "PeriodAutomaton.h"
#include "QueriesAutomaton.h"
#include "QuestionMarkAutomaton.h"
#include "RightParenAutomaton.h"
#include "RulesAutomaton.h"
#include "SchemesAutomaton.h"
#include "StringAutomaton.h"
#include "WhitespaceAutomaton.h"
#include "Token.h"

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {

    //precedence 1
    automata.push_back(new RulesAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new WhitespaceAutomaton());

    automata.push_back(new AddAutomaton());
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QuestionMarkAutomaton());
    automata.push_back(new RightParenAutomaton());

    automata.push_back(new StringAutomaton());
    automata.push_back(new IDAutomaton());
    automata.push_back(new CommentAutomaton());

    // TODO: Add the other needed automata here
}

void Lexer::Run(std::string& input) {

    int lineNumber = 1;

    while (!input.empty()) {
        int maxRead = 0;
        Automaton* maxAutomaton = nullptr;
        //whitespace handled with automaton

        //Parallel part of algorithm
        for (auto &&automaton : automata) {
            int inputRead = automaton->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automaton;
                lineNumber += automaton->NewLinesRead();
            }
        }

        //Max part of algorithm
        if (maxRead > 0){
            if (maxAutomaton->GetType() != TokenType::WHITESPACE) {
                Token* newToken =maxAutomaton->CreateToken(input.substr(0,maxRead),
                                                           lineNumber -(maxAutomaton->NewLinesRead()));
                tokens.push_back(newToken);
            }
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

    for (auto& token : tokens) { // outputs each token
        std::cout << *token << std::endl;
    }

    std::cout << "Total Tokens = " << tokens.size();
}
