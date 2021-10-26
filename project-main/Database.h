//
// Created by carsoncall on 10/26/21.
//

#ifndef PROJECT_1_MAIN_DATABASE_H
#define PROJECT_1_MAIN_DATABASE_H

#include <map>
#include <string>
#include <vector>
#include <iostream>

#include "Relation.h"

class Database {
private:
    std::map<std::string,Relation> theRelations;

public:

    Relation FindRelation(std::string);

    void AddRelation(Relation newRelation);

    void ToCout();
};


#endif //PROJECT_1_MAIN_DATABASE_H
