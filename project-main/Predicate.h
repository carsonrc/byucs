//
// Created by carsoncall on 10/2/21.
//

#ifndef PROJECT_1_MAIN_PREDICATE_H
#define PROJECT_1_MAIN_PREDICATE_H

#include <string>
#include <vector>

#include "Parameter.h"

class Predicate {
private:
    std::string id;
    std::vector<Parameter*> parameters;

public:

    void SetID(std::string& id) {
        this->id = id;
    }

    void SetParameters(std::vector<Parameter*>& parameters) {
        this->parameters = parameters;
    }

    std::string ToString() {
        std::string theString;
        theString = id + "(";

        for (auto i : parameters) {
            theString = theString + i->getParam() + ',';
        }

        theString.pop_back();
        theString = theString + ')';
        return theString;
    }
};


#endif //PROJECT_1_MAIN_PREDICATE_H
