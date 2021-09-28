#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automaton.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "Token.h"

class Lexer
{
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;

    void CreateAutomata();

    // TODO: add any other private methods here (if needed)

public:
    Lexer();
    ~Lexer();

    void Run(std::string& input);

    std::vector<Token*> ReturnTokens() {
        return tokens;
    }

};

#endif // LEXER_H

