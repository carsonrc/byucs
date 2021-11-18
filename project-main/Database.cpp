//
// Created by carsoncall on 10/26/21.
//

#include "Database.h"

Relation Database::FindRelation(std::string name) {
    return theRelations.at(name);
}

void Database::AddRelation(Relation newRelation) {
    std::string name = newRelation.GetName();
    theRelations[name] = newRelation;
}

void Database::ToCout() {
    for (auto i : theRelations) {
        std::cout << "Relation " << i.first << ':' << std::endl;
        std::cout << i.second.ToString();
    }

    std::cout << theRelations.begin()->second.ToString();
    std::cout << theRelations.end()->second.ToString();

    std::cout << Join

}

