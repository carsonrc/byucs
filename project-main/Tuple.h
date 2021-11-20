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

    //
    bool isJoinable(Tuple tup,std::vector<std::pair<size_t,size_t>> overlap) {
        for (auto i : overlap) {
            if(this->at(i.first) != tup.at(i.second)) {
                return false;
            }
        }
        return true;
    }

    // this function copies the caller tuple and argument tuple, deletes the tuple elements that are contained in the
    //seconds
    Tuple CombineTuples(Tuple tup, std::vector<std::pair<size_t,size_t>> overlap) {
        std::vector<std::string> newTuple;
        newTuple = this->tupleContents;
        std::vector<std::string> modifiedArgTuple = tup.tupleContents;

        // deletes all the tuple elements that are duplicates as contained in the vector of pairs's second
        // note: this assumes that a prior check has been made to check that they are combinable
        for (auto i : overlap) {
            modifiedArgTuple.erase(modifiedArgTuple.begin()+i.second);
        }

        // concatenate modifiedArgTuple to end of the first tuple
        newTuple.insert(newTuple.end(),modifiedArgTuple.begin(),modifiedArgTuple.end());

        //return the new tuple
        return Tuple(newTuple);
    }

};


#endif //PROJECT_1_MAIN_TUPLE_H
