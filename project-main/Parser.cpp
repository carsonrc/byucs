//
// Created by carsoncall on 9/27/21.
//

#include "Parser.h"
#include "DatalogProgram.h"


DatalogProgram Parser::DatalogParser(std::vector<Token*> tokens) {

    DatalogProgram bigDaddy;

    if (tokens[index]->GetType() == TokenType::SCHEMES){ index++;} else throw index;
    if (tokens[index]->GetType() == TokenType::COLON  ){ index++;} else throw index;
    SchemeParser(tokens);
    SchemeListParser(tokens);

    if (tokens[index]->GetType() == TokenType::FACTS  ){ index++;} else throw index;
    if (tokens[index]->GetType() == TokenType::COLON  ){ index++;} else throw index;
    FactListParser(tokens);

    if (tokens[index]->GetType() == TokenType::RULES  ){ index++;} else throw index;
    if (tokens[index]->GetType() == TokenType::COLON  ){ index++;} else throw index;
    RuleListParser(tokens);

    if (tokens[index]->GetType() == TokenType::QUERIES){ index++;} else throw index;
    if (tokens[index]->GetType() == TokenType::COLON  ){ index++;} else throw index;
    QueryParser(tokens);
    QueryListParser(tokens);

    return bigDaddy;
}

// type parsers=========================================================================================================
void Parser::SchemeParser(std::vector<Token *> tokens) {
    if (tokens[index]->GetType() == TokenType::ID)         { index++;} else throw index;
    if (tokens[index]->GetType() == TokenType::LEFT_PAREN) { index++;} else throw index;
    if (tokens[index]->GetType() == TokenType::ID)         { index++;} else throw index;
    IdListParser(tokens);
    if (tokens[index]->GetType() == TokenType::RIGHT_PAREN){ index++;} else throw index;
}

void Parser::FactParser(std::vector<Token *> tokens) {
    if (tokens[index]->GetType() == TokenType::ID)         { index++;} else throw index;
    if (tokens[index]->GetType() == TokenType::LEFT_PAREN) { index++;} else throw index;
    if (tokens[index]->GetType() == TokenType::STRING)     { index++;} else throw index;
    StringListParser(tokens);
    if (tokens[index]->GetType() == TokenType::RIGHT_PAREN){ index++;} else throw index;
    if (tokens[index]->GetType() == TokenType::PERIOD)     { index++;} else throw index;
}

void Parser::RuleParser(std::vector<Token *> tokens) {
    HeadPredicateParser(tokens);
    if (tokens[index]->GetType() == TokenType::COLON_DASH) { index++;} else throw index;
    PredicateParser(tokens);
    PredicateListParser(tokens);
    if (tokens[index]->GetType() == TokenType::PERIOD)     { index++;} else throw index;
}

void Parser::QueryParser(std::vector<Token *> tokens) {
    PredicateParser(tokens);
if (tokens[index]->GetType() == TokenType::QUESTION_MARK)  { index++;} else throw index;

}

//type list parsers=====================================================================================================
void Parser::SchemeListParser(std::vector<Token*> tokens) {
    if (tokens[index]->GetType() == TokenType::ID) {
        SchemeParser(tokens);
        SchemeListParser(tokens);
    }
    else if (tokens[index]->GetType() == TokenType::FACTS) {
        return; //lambda do nothing
    }
    else {throw index; }
}

void Parser::FactListParser(std::vector<Token *> tokens) {
    if (tokens[index]->GetType() == TokenType::ID) {
        FactParser(tokens);
        FactListParser(tokens);
    }
    else if (tokens[index]->GetType() == TokenType::RULES){
        return; //lambda do nothing
    }
    else { throw index; }
}

void Parser::RuleListParser(std::vector<Token *> tokens) {
    if (tokens[index]->GetType() == TokenType::ID) {
        RuleParser(tokens);
        RuleListParser(tokens);
    }
    else if (tokens[index]->GetType() == TokenType::QUERIES) {
        return; //lambda do nothing
    }
    else { throw index; }
}

void Parser::QueryListParser(std::vector<Token *> tokens) {
    if (tokens[index]->GetType() == TokenType::ID) {
        QueryParser(tokens);
        QueryListParser(tokens);
    }
    else if (tokens[index]->GetType() == TokenType::END_OF_FILE) {
        return; // lambda do nothing
    }
    else { throw index; }
}

//predicate parsers=====================================================================================================
void Parser::HeadPredicateParser(std::vector<Token *> tokens) {
    if (tokens[index]->GetType() == TokenType::ID)         { index++; } else throw index;
    if (tokens[index]->GetType() == TokenType::LEFT_PAREN) { index++; } else throw index;
    if (tokens[index]->GetType() == TokenType::ID)         { index++; } else throw index;
    IdListParser(tokens);
    if (tokens[index]->GetType() == TokenType::RIGHT_PAREN){ index++; } else throw index;
}
void Parser::PredicateParser(std::vector<Token *> tokens) {
    if (tokens[index]->GetType() == TokenType::ID)         { index++; } else throw index;
    if (tokens[index]->GetType() == TokenType::LEFT_PAREN) { index++; } else throw index;
    ParameterParser(tokens);
    ParameterListParser(tokens);
    if (tokens[index]->GetType() == TokenType::RIGHT_PAREN){ index++;} else throw index;
}

//string or id list parsers=============================================================================================
void Parser::PredicateListParser(std::vector<Token *> tokens) {
    if (tokens[index]->GetType() == TokenType::COMMA) {
        index++;
        PredicateParser(tokens);
        PredicateListParser(tokens);
    }
    else if (tokens[index]->GetType() == TokenType::PERIOD) { // continue recursion?
        return; //nope
    }
    else { throw index; }
}

void Parser::ParameterListParser(std::vector<Token *> tokens) {
    if (tokens[index]->GetType() == TokenType::COMMA) {
        index++;
        ParameterParser(tokens);
        ParameterListParser(tokens);
    }
    else if (tokens[index]->GetType() == TokenType::RIGHT_PAREN) { // continue recursion?
        return; // nope
    }
    else { throw index; }
}

void Parser::IdListParser(std::vector<Token*> tokens) {
    if (tokens[index]->GetType() == TokenType::COMMA)  { index++; }
    if (tokens[index]->GetType() == TokenType::ID)     { index++; }

    if (tokens[index]->GetType() == TokenType::COMMA) { // continue recursion?
        IdListParser(tokens);
    }
    else { return; } //lambda do nothing
}

void Parser::StringListParser(std::vector<Token *> tokens) {
    if (tokens[index]->GetType() == TokenType::COMMA)  { index++; }
    if (tokens[index]->GetType() == TokenType::STRING)  { index++; }

    if (tokens[index]->GetType() == TokenType::COMMA)  { // continue recursion?
        StringListParser(tokens);
    } else { return; } //do nothing
}

void Parser::ParameterParser(std::vector<Token *> tokens) {
    if (tokens[index]->GetType() == TokenType::STRING) { index++; } // production 1
    else if (tokens[index]->GetType() == TokenType::ID) { index++; } // production 2
    else { throw index; }
}