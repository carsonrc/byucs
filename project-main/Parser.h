//
// Created by carsoncall on 9/27/21.
//

#ifndef PROJECT_2_MAIN_PARSER_H
#define PROJECT_2_MAIN_PARSER_H

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "Token.h"

class Parser {

private:
    //add all the data structures produced
    size_t index = 0;
/*
    bool contains(std::vector<Token*> const& tokens, std::string nonterminal, size_t index);

    std::unordered_map<std::string,std::vector<TokenType>> firstSets = {
            {"datalogProgram",{TokenType::SCHEMES,TokenType::COLON,TokenType::FACTS,TokenType::RULES,
                               TokenType::QUERIES,TokenType::ID,TokenType::LEFT_PAREN,TokenType::RIGHT_PAREN,
                               TokenType::PERIOD,TokenType::COLON_DASH,TokenType::QUESTION_MARK,TokenType::COMMA,
                               TokenType::STRING}},
            {"scheme", {TokenType::ID,TokenType::LEFT_PAREN,TokenType::COMMA}},
            {"schemeList",{TokenType::COMMA}}
    };
*/


public:
    //functions for all nonterminals



    DatalogProgram DatalogParser(std::vector<Token*> tokens);

    void SchemeParser(std::vector<Token*> tokens);
    void SchemeListParser(std::vector<Token *> tokens);

    void FactParser(std::vector<Token *> tokens);
    void FactListParser(std::vector<Token *> tokens);

    void RuleParser(std::vector<Token *> tokens);
    void RuleListParser(std::vector<Token *> tokens);

    void QueryParser(std::vector<Token *> tokens);
    void QueryListParser(std::vector<Token *> tokens);

    void HeadPredicateParser(std::vector<Token *> tokens);

    void IdListParser(std::vector<Token *> tokens);

    void StringListParser(std::vector<Token *> tokens);

    void PredicateParser(std::vector<Token *> tokens);

    void PredicateListParser(std::vector<Token *> tokens);

    void ParameterListParser(std::vector<Token *> tokens);

    void ParameterParser(std::vector<Token *> tokens);
};




#endif //PROJECT_2_MAIN_PARSER_H
