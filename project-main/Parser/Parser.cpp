//
// Created by carsoncall on 9/27/21.
//

#include "Parser.h"


void Parser::DatalogParser(std::vector<Token*> tokens) {
    if (tokens[index]->GetType() == TokenType::SCHEMES){ index++;} else throw index;
    if (tokens[index]->GetType() == TokenType::COLON  ){ index++;} else throw index;
    SchemeParser(tokens);
    SchemeListParser(tokens);

    if (tokens[index]->GetType() == TokenType::FACTS  ){ index++;} else throw index;
    if (tokens[index]->GetType() == TokenType::COLON  ){ index++;} else throw index;
    //FactListParser(tokens);

    if (tokens[index]->GetType() == TokenType::RULES  ){ index++;} else throw index;
    if (tokens[index]->GetType() == TokenType::COLON  ){ index++;} else throw index;
    //RuleListParser(tokens);

    if (tokens[index]->GetType() == TokenType::QUERIES){ index++;} else throw index;
    if (tokens[index]->GetType() == TokenType::COLON  ){ index++;} else throw index;
    //QueriesParser(tokens);
    //QueryListParser(tokens);
}

void Parser::SchemeParser(std::vector<Token *> tokens) {
    if (tokens[index]->GetType() == TokenType::ID)         { index++;} else throw index;
    if (tokens[index]->GetType() == TokenType::LEFT_PAREN) { index++;} else throw index;
    if (tokens[index]->GetType() == TokenType::ID)         { index++;} else throw index;
    //IdListParser(tokens);
    if (tokens[index]->GetType() == TokenType::RIGHT_PAREN){ index++;} else throw index;
}

void Parser::SchemeListParser(std::vector<Token*> tokens) {
    if (tokens[index]->GetType() == TokenType::ID) {
        SchemeParser(tokens);
        SchemeListParser(tokens);
    }
    else if (tokens[index]->GetType() == TokenType::FACTS) {
        return; //lambda do nothing
    }
    else {throw index;}
    }

void Parser::IdListParser(std::vector<Token*> tokens) {
    if (tokens[index]->GetType() == TokenType::)
    if (tokens[index]->GetType() == TokenType::COMMA)  { index++;} else throw index;
    if (tokens[index]->GetType() == TokenType::ID)     { index++;} else throw index;
    IdListParser(tokens);
}
/*
bool Parser::contains(const std::vector<Token *> &tokens, std::string nonterminal, size_t index) {
    if (std::find(firstSets[nonterminal].begin(), firstSets[nonterminal].end(), tokens[index]->GetType())
        != firstSets[nonterminal].end()) {
        return true;
    }
    return false;
};
*/