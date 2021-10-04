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
#include "DatalogProgram.h"

class Parser {

private:
    //add all the data structures produced
    size_t index = 0;
    DatalogProgram bigDaddy;
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

    void ParserRun(std::vector<Token*> tokens);

    DatalogProgram DatalogParser(std::vector<Token*> tokens);

    Predicate SchemeParser(std::vector<Token*> tokens);
    std::vector<Predicate> SchemeListParser(std::vector<Token *> tokens);

    Predicate FactParser(std::vector<Token *> tokens);
    std::vector<Predicate> FactListParser(std::vector<Token *> tokens);

    Rule RuleParser(std::vector<Token *> tokens);
    std::vector<Rule> RuleListParser(std::vector<Token *> tokens);

    Predicate QueryParser(std::vector<Token *> tokens);
    std::vector<Predicate> QueryListParser(std::vector<Token *> tokens);

    Predicate HeadPredicateParser(std::vector<Token *> tokens);

    std::vector<Parameter *> IdListParser(std::vector<Token *> tokens);

    std::vector<Parameter *> StringListParser(std::vector<Token *> tokens);

    Predicate PredicateParser(std::vector<Token *> tokens);

    std::vector<Predicate> PredicateListParser(std::vector<Token *> tokens);

    std::vector<Parameter *> ParameterListParser(std::vector<Token *> tokens);

    Parameter * ParameterParser(std::vector<Token *> tokens);

    DatalogProgram GetDaddy();
};




#endif //PROJECT_2_MAIN_PARSER_H
