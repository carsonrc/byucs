//
// Created by carsoncall on 10/2/21.
//

#ifndef PROJECT_1_MAIN_DATALOGPROGRAM_H
#define PROJECT_1_MAIN_DATALOGPROGRAM_H
#include <vector>
#include <set>
#include <map>

#include "Predicate.h"
#include "Parameter.h"
#include "Rule.h"

//testing
#include "Tuple.h"
#include "Relation.h"
#include "Header.h"


class DatalogProgram {
private:
    std::vector<Predicate> schemes;
    std::vector<Predicate> facts;
    std::vector<Predicate> queries;
    std::vector<Rule> rules;

    std::set<std::string> domain;

public:

    void addScheme(Predicate scheme) {
        schemes.push_back(scheme);
    }
    void addSchemes(std::vector<Predicate> schemeList) {
        schemes.insert(schemes.end(),schemeList.begin(),schemeList.end());
    }
    void addFacts(std::vector<Predicate> factList) {
        facts.insert(facts.end(),factList.begin(),factList.end());
    }
    void addQuery(Predicate query) {
        queries.push_back(query);
    }
    void addQueries(std::vector<Predicate> queryList) {
        queries.insert(queries.end(),queryList.begin(),queryList.end());
    }
    void addRules(std::vector<Rule> ruleList) {
        rules.insert(rules.end(),ruleList.begin(),ruleList.end());
    }

    void setDomain();

    void toCout();

    std::vector<Predicate> GetSchemes();
    std::vector<Predicate> GetFacts();
    std::vector<Predicate> GetQueries();
};


#endif //PROJECT_1_MAIN_DATALOGPROGRAM_H
