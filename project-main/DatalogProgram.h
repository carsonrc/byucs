//
// Created by carsoncall on 10/2/21.
//

#ifndef PROJECT_1_MAIN_DATALOGPROGRAM_H
#define PROJECT_1_MAIN_DATALOGPROGRAM_H
#include <vector>

#include "Predicate.h"
#include "Parameter.h"
#include "Rule.h"

class DatalogProgram {
private:
    std::vector<Predicate> schemes;
    std::vector<Predicate> facts;
    std::vector<Predicate> queries;
    std::vector<Rule> rules;

public:
    void toString();
};


#endif //PROJECT_1_MAIN_DATALOGPROGRAM_H
