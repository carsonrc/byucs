//
// Created by carsoncall on 10/26/21.
//

#include "Interpreter.h"

Interpreter::Interpreter(DatalogProgram data) {
    theData = data;

}

void Interpreter::GenerateDatabase() {
    for ( auto i : theData.GetSchemes()) {
        Header head = Header(i.GetStrings());
        Relation temp = Relation(i.GetID(),head);

        for (auto j : theData.GetFacts()) {
            if (j.GetID() == temp.GetName()) {
                temp.AddTuple(Tuple(j.GetStrings()));
            }
        }
        theDatabase.AddRelation(temp);
    }

    for (auto i : theData.GetQueries()) {

    }
}

void Interpreter::ToCout() {
    theDatabase.ToCout();
}