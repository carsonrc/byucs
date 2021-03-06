//
// Created by carsoncall on 10/2/21.
//

#include "DatalogProgram.h"

#include <iostream>

void DatalogProgram::setDomain() {
    for (auto i : facts) {
        std::vector<Parameter*> parameterList = i.GetParameters();
        for (auto j : parameterList) {
            domain.insert( j->GetParam());
        }
    }
}

void DatalogProgram::toCout() {

    std::cout << "Schemes(" << schemes.size() << "):" << std::endl;
    for (auto i : schemes) {
        std::cout << "  " << i.ToString() << std::endl;
    }

    std::cout << "Facts(" << facts.size() << "):" << std::endl;
    for (auto i : facts) {
        std::cout << "  " << i.ToString() << "." << std::endl;
    }

    std::cout << "Rules(" << rules.size() << "):" << std::endl;
    for (auto i : rules) {
        std::cout << "  " << i.toString() << "." << std::endl;
    }

    std::cout << "Queries(" << queries.size() << "):" << std::endl;
    for (auto i : queries) {
        std::cout << "  " << i.ToString() << "?" << std::endl;
    }

    setDomain();

    std::cout << "Domain(" << domain.size() << "):" << std::endl;
    for (auto i : domain) {
        std::cout << "  " << i << std::endl;
    }
}

std::vector<Predicate> DatalogProgram::GetSchemes() {
    return schemes;
}
std::vector<Predicate> DatalogProgram::GetFacts() {
    return facts;
}
std::vector<Predicate> DatalogProgram::GetQueries() {
    return queries;
}
std::vector<Rule> DatalogProgram::GetRules() {
    return rules;
}
