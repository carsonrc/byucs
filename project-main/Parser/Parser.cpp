//
// Created by carsoncall on 9/27/21.
//

#include "Parser.h"


void Parser::DatalogParser(std::vector<Token*> tokens) {
    if (contains(tokens, "datalogProgram",index)) {

        index += 2;
        SchemeParser(tokens);
        /*
        SchemeListParser(tokens)
        FactListParser(tokens)
        RuleListParser
        QueryParser
        QueryListParser
        */
    }
    else {
        throw index;
    }
}

void Parser::SchemeParser(std::vector<Token *> tokens) {
    if (contains(tokens, "scheme",index)) {
        SchemeParser(tokens);
        //SchemeListParser(tokens);
    }
}

bool Parser::contains(const std::vector<Token *> &tokens, std::string nonterminal, size_t index) {
    if (std::find(firstSets[nonterminal].begin(), firstSets[nonterminal].end(), tokens[index]->GetType())
        != firstSets[nonterminal].end()) {
        return true;
    }
    return false;
};
