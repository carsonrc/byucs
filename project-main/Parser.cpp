//
// Created by carsoncall on 9/27/21.
//

#include "Parser.h"
#include "DatalogProgram.h"

void Parser::ParserRun(std::vector<Token*> tokens) {
    this->bigDaddy = DatalogParser(tokens);
}

DatalogProgram Parser::GetDaddy() {
    return bigDaddy;
}

DatalogProgram Parser::DatalogParser(std::vector<Token*> tokens) {

    DatalogProgram bigDaddy;

    if (tokens[index]->GetType() == TokenType::SCHEMES){ index++;} else throw index;
    if (tokens[index]->GetType() == TokenType::COLON  ){ index++;} else throw index;
    bigDaddy.addScheme(SchemeParser(tokens));
    bigDaddy.addSchemes(SchemeListParser(tokens));

    if (tokens[index]->GetType() == TokenType::FACTS  ){ index++;} else throw index;
    if (tokens[index]->GetType() == TokenType::COLON  ){ index++;} else throw index;
    bigDaddy.addFacts(FactListParser(tokens));

    if (tokens[index]->GetType() == TokenType::RULES  ){ index++;} else throw index;
    if (tokens[index]->GetType() == TokenType::COLON  ){ index++;} else throw index;
    bigDaddy.addRules(RuleListParser(tokens));

    if (tokens[index]->GetType() == TokenType::QUERIES){ index++;} else throw index;
    if (tokens[index]->GetType() == TokenType::COLON  ){ index++;} else throw index;
    bigDaddy.addQuery(QueryParser(tokens));
    bigDaddy.addQueries(QueryListParser(tokens));

    return bigDaddy;
}

// type parsers=========================================================================================================
Predicate Parser::SchemeParser(std::vector<Token *> tokens) {

    Predicate scheme;
    std::vector<Parameter*> idList;

    if (tokens[index]->GetType() == TokenType::ID) {
        scheme.SetID(tokens[index]->GetDescription());
        index++;
    } else throw index;

    if (tokens[index]->GetType() == TokenType::LEFT_PAREN) { index++;} else throw index;

    if (tokens[index]->GetType() == TokenType::ID) {
        auto param = new Parameter(tokens[index]->GetDescription(), false);
        scheme.AddParameter(param);
        index++;
    } else throw index;

    idList = IdListParser(tokens);
    scheme.AddParameters(idList);

    if (tokens[index]->GetType() == TokenType::RIGHT_PAREN){ index++;} else throw index;

    return scheme;
}

Predicate Parser::FactParser(std::vector<Token *> tokens) {

    Predicate fact;
    std::vector<Parameter*> stringList;

    if (tokens[index]->GetType() == TokenType::ID) {
        fact.SetID(tokens[index]->GetDescription());
        index++;
    } else throw index;

    if (tokens[index]->GetType() == TokenType::LEFT_PAREN) { index++;} else throw index;

    if (tokens[index]->GetType() == TokenType::STRING)     {
        auto param = new Parameter(tokens[index]->GetDescription(), true);
        fact.AddParameter(param);
        index++;
    } else throw index;

    stringList = StringListParser(tokens);
    fact.AddParameters(stringList);

    if (tokens[index]->GetType() == TokenType::RIGHT_PAREN){ index++;} else throw index;
    if (tokens[index]->GetType() == TokenType::PERIOD)     { index++;} else throw index;

    return fact;
}

Rule Parser::RuleParser(std::vector<Token *> tokens) {

    Rule rule;
    std::vector<Predicate> predHolder;

    rule.setHeadPredicate(HeadPredicateParser(tokens));

    if (tokens[index]->GetType() == TokenType::COLON_DASH) { index++;} else throw index;
    predHolder.push_back(PredicateParser(tokens));

    std::vector<Predicate> tempVector;
    tempVector = PredicateListParser(tokens);
    predHolder.insert(predHolder.end(),tempVector.begin(),tempVector.end());

    rule.setBodyPredicates(predHolder);

    if (tokens[index]->GetType() == TokenType::PERIOD)     { index++;} else throw index;

    return rule;

}

Predicate Parser::QueryParser(std::vector<Token *> tokens) {
    Predicate query;
    query = PredicateParser(tokens);

    if (tokens[index]->GetType() == TokenType::QUESTION_MARK)  { index++;} else throw index;

    return query;

}

//type list parsers=====================================================================================================
std::vector<Predicate> Parser::SchemeListParser(std::vector<Token*> tokens) {
    std::vector<Predicate> schemeList;
    if (tokens[index]->GetType() != TokenType::ID && tokens[index]->GetType() != TokenType::FACTS) {throw index;}
    if (tokens[index]->GetType() == TokenType::ID) {
        schemeList.push_back(SchemeParser(tokens));
        std::vector<Predicate> tempVector = SchemeListParser(tokens);
        schemeList.insert(schemeList.end(),tempVector.begin(),tempVector.end());
    }

    return schemeList; //lambda do nothing
}

std::vector<Predicate> Parser::FactListParser(std::vector<Token *> tokens) {
    std::vector<Predicate> factList;
    if (tokens[index]->GetType() != TokenType::ID && tokens[index]->GetType() != TokenType::RULES) {throw index;}
    if (tokens[index]->GetType() == TokenType::ID) {
        factList.push_back(FactParser(tokens));
        std::vector<Predicate> tempVector = FactListParser(tokens);
        factList.insert(factList.end(),tempVector.begin(),tempVector.end());
    }
        return factList; //lambda do nothing
}

std::vector<Rule> Parser::RuleListParser(std::vector<Token *> tokens) {
    std::vector<Rule> ruleList;
    if (tokens[index]->GetType() != TokenType::ID && tokens[index]->GetType() != TokenType::QUERIES) {throw index;}
    if (tokens[index]->GetType() == TokenType::ID) {
        ruleList.push_back(RuleParser(tokens));
        std::vector<Rule> tempVector = RuleListParser(tokens);
        ruleList.insert(ruleList.end(),tempVector.begin(),tempVector.end());
    }
        return ruleList; //lambda do nothing
}

std::vector<Predicate> Parser::QueryListParser(std::vector<Token *> tokens) {
    std::vector<Predicate> queryList;
    if (tokens[index]->GetType() != TokenType::ID && tokens[index]->GetType() != TokenType::END_OF_FILE) {throw index;}
    if (tokens[index]->GetType() == TokenType::ID) {
        queryList.push_back(QueryParser(tokens));
        std::vector<Predicate> tempVector = QueryListParser(tokens);
        queryList.insert(queryList.end(),tempVector.begin(),tempVector.end());
    }
        return queryList; // lambda do nothing
}

//predicate parsers=====================================================================================================
Predicate Parser::HeadPredicateParser(std::vector<Token *> tokens) {

    Predicate theHeadPred;

    if (tokens[index]->GetType() == TokenType::ID)         {
        theHeadPred.SetID(tokens[index]->GetDescription());
        index++;
    }
    else throw index;

    if (tokens[index]->GetType() == TokenType::LEFT_PAREN) { index++; } else throw index;
    if (tokens[index]->GetType() == TokenType::ID)         {
        auto* firstParam = new Parameter(tokens[index]->GetDescription(), false);
        theHeadPred.AddParameter(firstParam);
        index++;
    }
    else throw index;

    theHeadPred.AddParameters(IdListParser(tokens));

    if (tokens[index]->GetType() == TokenType::RIGHT_PAREN){ index++; } else throw index;

    return theHeadPred;

}

Predicate Parser::PredicateParser(std::vector<Token *> tokens) {
    Predicate thePred;
    if (tokens[index]->GetType() == TokenType::ID)         {
        thePred.SetID(tokens[index]->GetDescription());
        index++;
    }
    else throw index;

    if (tokens[index]->GetType() == TokenType::LEFT_PAREN) { index++; } else throw index;

    thePred.AddParameter(ParameterParser(tokens));
    thePred.AddParameters(ParameterListParser(tokens));
    if (tokens[index]->GetType() == TokenType::RIGHT_PAREN){ index++;} else throw index;
    return thePred;
}

//string or id list parsers=============================================================================================
std::vector<Predicate> Parser::PredicateListParser(std::vector<Token *> tokens) {

    std::vector<Predicate> predicateList;
    if (tokens[index]->GetType() != TokenType::COMMA && tokens[index]->GetType() != TokenType::PERIOD) {throw index;}
    if (tokens[index]->GetType() == TokenType::COMMA) {
        index++;
        predicateList.push_back(PredicateParser(tokens));
        std::vector<Predicate> tempVector;
        tempVector = PredicateListParser(tokens);
        predicateList.insert(predicateList.end(),tempVector.begin(),tempVector.end());
    }
        return predicateList;

}

std::vector<Parameter *> Parser::ParameterListParser(std::vector<Token *> tokens) {

    std::vector<Parameter*> parameterList;
    if (tokens[index]->GetType() != TokenType::COMMA && tokens[index]->GetType() != TokenType::RIGHT_PAREN) {throw index;}
    if (tokens[index]->GetType() == TokenType::COMMA) {
        index++;
        parameterList.push_back(ParameterParser(tokens));
        std::vector<Parameter *> tempVector = ParameterListParser(tokens);
        parameterList.insert(parameterList.end(),tempVector.begin(),tempVector.end());
    }
        return parameterList; // nope
}

std::vector<Parameter*> Parser::IdListParser(std::vector<Token*> tokens) {
    std::vector<Parameter*> idList;

    if (tokens[index]->GetType() == TokenType::COMMA)  { index++; }
    if (tokens[index]->GetType() == TokenType::ID)     {
        auto param = new Parameter(tokens[index]->GetDescription(),false);
        idList.push_back(param);
        index++;
    }

    if (tokens[index]->GetType() == TokenType::COMMA) { // continue recursion?
        std::vector<Parameter*> tempVector = IdListParser(tokens);
        idList.insert(idList.end(),tempVector.begin(),tempVector.end());
    }
    return idList;  //lambda do nothing
}

std::vector<Parameter*> Parser::StringListParser(std::vector<Token *> tokens) {
    std::vector<Parameter*> stringList;

    if (tokens[index]->GetType() == TokenType::COMMA)  { index++; }
    if (tokens[index]->GetType() == TokenType::STRING)  {
        auto param = new Parameter(tokens[index]->GetDescription(), true);
        stringList.push_back(param);
        index++;
    }

    if (tokens[index]->GetType() == TokenType::COMMA)  { // continue recursion?
        std::vector<Parameter*> tempVector = StringListParser(tokens);
        stringList.insert(stringList.end(),tempVector.begin(),tempVector.end());
    }
    return stringList;//do nothing
}

Parameter* Parser::ParameterParser(std::vector<Token *> tokens) {
    if (tokens[index]->GetType() == TokenType::STRING) {
        auto* stringParam = new Parameter(tokens[index]->GetDescription(), true);
        index++;
        return stringParam;
    } // production 1
    else if (tokens[index]->GetType() == TokenType::ID) {
        auto* idParam = new Parameter(tokens[index]->GetDescription(), false);
        index++;
        return idParam;
    } // production 2
    else { throw index; }
}