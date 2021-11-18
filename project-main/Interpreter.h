//
// Created by carsoncall on 10/26/21.
//

#ifndef PROJECT_1_MAIN_INTERPRETER_H
#define PROJECT_1_MAIN_INTERPRETER_H


#include <string>
#include <vector>
#include <iostream>

#include "DatalogProgram.h"
#include "Database.h"
#include "Header.h"
#include "Relation.h"
#include "Tuple.h"


class Interpreter {
private:
    DatalogProgram theData;
    Database theDatabase;

public:
    explicit Interpreter(DatalogProgram data);

    void GenerateDatabase();

    void ToCout();

    Relation EvaluatePredicate(Predicate);

    void EvaluateAllPredicates();

};



#endif //PROJECT_1_MAIN_INTERPRETER_H
