//
// Created by carsoncall on 10/25/21.
//

#ifndef PROJECT_1_MAIN_TUPLE_H
#define PROJECT_1_MAIN_TUPLE_H

#include <vector>
#include <string>

#include "Parameter.h"

class Tuple {
private:
    std::vector<std::string> tupleContents;

public:

    //TODO: constructor?
    //takes the vector from the Predicate class and converts it into a vector of strings
    explicit Tuple(const std::vector<std::string>& parameters) {
        tupleContents = parameters;
    }

    bool operator< (const Tuple &rhs) const {
        return tupleContents < rhs.tupleContents;
    }

    std::vector<std::string> GetTupleContents() {
        return tupleContents;
    }

    //used in Relation.toString
    std::string at(size_t index) {
        return tupleContents.at(index);
    }

    //for testing
    std::string ToString() {
        std::string theString;
        for (const auto& i : tupleContents) {
            theString += i + ' ';
        }
        return theString;
    }

};


#endif //PROJECT_1_MAIN_TUPLE_H
