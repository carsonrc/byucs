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
}

void Interpreter::ToCout() {
    theDatabase.ToCout();
}

Relation Interpreter::EvaluatePredicate(Predicate predicate) {
    std::vector<Parameter *> parameters = predicate.GetParameters();
    std::map<std::string, size_t> selectVariables;
    std::vector<size_t> projectOrder;
    std::vector<std::string> renameOrder;
    std::string relationName = predicate.GetID();

    Relation domain = theDatabase.FindRelation(relationName);

    //whittles down original relation tuples to find the ones we need
    size_t counter = 0;
    for (auto i : parameters) {

        if (i->checkIsString()) {
            domain = domain.select(counter, i->GetParam());
        } else {
            if (selectVariables.count(i->GetParam()) == 1) {
                domain = domain.select(selectVariables.at(i->GetParam()), counter);
            } else {
                projectOrder.push_back(counter);
                renameOrder.push_back(i->GetParam());
                selectVariables[i->GetParam()] = counter;
            }
        }
        counter++;
    }

    //now, to project and rename
    domain = domain.project(projectOrder);
    domain.ChangeHeader(renameOrder);


    //to std output
    if (domain.IsNotEmpty()){
        std::cout << predicate.ToString() << "? Yes(" << domain.Size() << ")" << std::endl;
        std::cout << domain.ToString();
    }
    else {
        std::cout << predicate.ToString() << "? No" << std::endl;
    }

    return domain;
}

void Interpreter::EvaluateAllPredicates() {
    auto queries = theData.GetQueries();
    for (const auto& i : queries) {
        EvaluatePredicate(i);
    }


}

