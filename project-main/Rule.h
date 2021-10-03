//
// Created by carsoncall on 10/2/21.
//

#ifndef PROJECT_1_MAIN_RULE_H
#define PROJECT_1_MAIN_RULE_H

#include "Predicate.h"

class Rule {

private:
    Predicate* headPredicate;
    std::vector<Predicate*> bodyPredicates;

public:
    void setHeadPredicate(Predicate* headPredicate) {
        this->headPredicate = headPredicate;
    }

    void setBodyPredicates(std::vector<Predicate*> bodyPredicates) {
        this->bodyPredicates = bodyPredicates;
    }

    std::string toString() {
        std::string theString;
        theString = headPredicate->ToString() + " :- ";

        for (auto i : bodyPredicates) {
            theString = theString + i->ToString();
        }
    }

};


#endif //PROJECT_1_MAIN_RULE_H
