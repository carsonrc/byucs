//
// Created by carsoncall on 10/25/21.
//

#ifndef PROJECT_1_MAIN_RELATION_H
#define PROJECT_1_MAIN_RELATION_H

#include <string>
#include <set>
#include <vector>

#include "Tuple.h"
#include "Header.h"

class Relation {
private:
    std::string name;
    Header header;
    std::set<Tuple> relationTuples = {};

public:

    Relation()= default;;
    //note: made from Schemes; schemes are predicates, so predicate.id = name and header is made from getPredicates
    Relation(std::string name, Header header) {
        this->name = name;
        this->header = header;
    }

    void AddTuple(Tuple newTuple) {
        relationTuples.insert(newTuple);
    }

    std::string ToString() {
        std::string theString;
        for (auto i : relationTuples) {
            for (int j = 0; j < header.size(); j++) {
                theString += header.at(j) + '=' + i.at(j) + ", ";
            }
            theString.pop_back();
            theString.pop_back();
            theString += '\n';
        }
        return theString;
    }

    std::string GetName() {
        return name;
    }

    // relational operators
    Relation Select(size_t row, std::string value) {

    }

    Relation Select(size_t row1, size_t row2) {

    }



};


#endif //PROJECT_1_MAIN_RELATION_H
