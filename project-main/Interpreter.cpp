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
void QueryCout(Predicate predicate, Relation relation) {
    //to std output
    if (relation.IsNotEmpty()){
        std::cout << predicate.ToString() << "? Yes(" << relation.Size() << ")" << std::endl;
        std::cout << relation.ToString();
    }
    else {
        std::cout << predicate.ToString() << "? No" << std::endl;
    }
}

Relation Interpreter::EvaluatePredicate(Predicate predicate) {
    std::vector<Parameter *> parameters = predicate.GetParameters();
    std::map<std::string, size_t> selectVariables;
    std::vector<size_t> projectOrder;
    std::vector<std::string> renameOrder;
    std::string relationName = predicate.GetID();

    Relation result = theDatabase.FindRelation(relationName);

    //whittles down original relation tuples to find the ones we need
    size_t counter = 0;
    for (auto i : parameters) {

        if (i->checkIsString()) {
            result = result.select(counter, i->GetParam());
        } else {
            if (selectVariables.count(i->GetParam()) == 1) {
                result = result.select(selectVariables.at(i->GetParam()), counter);
            } else {
                projectOrder.push_back(counter);
                renameOrder.push_back(i->GetParam());
                selectVariables[i->GetParam()] = counter;
            }
        }
        counter++;
    }

    //now, to project and rename
    result = result.project(projectOrder);
    result.ChangeHeader(renameOrder);

    return result;
}

void Interpreter::EvaluateAllPredicates() {
    //project 4 evaluate rules before the queries
    auto rules = theData.GetRules();

    std::cout << "Rule Evaluation" << std::endl;
    size_t onwards = true;
    size_t counter = 0;

    while (onwards) {
        onwards = 0;
        for (auto &rule: rules) {
            std::cout << rule.toString()  << '.' << std::endl;
            std::string name = rule.GetHeadPredicate().GetID();
            std::vector<std::string> headPredicateElements = rule.GetHeadPredicate().GetStrings();
            std::vector<Predicate> bodyPredicates = rule.GetBodyPredicates();

            //first result is the base relation that is joined to the other results
            Relation result = EvaluatePredicate(bodyPredicates.at(0));

            //evaluating each subsequent predicate in rule body and joining it to result
            for (size_t j = 1; j < bodyPredicates.size(); j++) {
                Relation temp = EvaluatePredicate(bodyPredicates.at(j));
                result = result.Join(name, temp);
            }

            //projecting the columns that appear in head predicate, first by finding positions of wanted columns
            std::vector<size_t> columnsForProject;
            std::vector<std::string> resultHeader = result.GetHeader().getVector();
            for (auto headPredicateElement: headPredicateElements) {
                for (size_t resultHeaderIndex = 0; resultHeaderIndex < resultHeader.size(); resultHeaderIndex++) {
                    if (resultHeader.at(resultHeaderIndex) == headPredicateElement) {
                        columnsForProject.push_back(resultHeaderIndex);
                    }
                }
            }


            //then, using that to project
            result = result.project(columnsForProject);

            //renaming the relation to make it union-compatible
            Header targetHeader = theDatabase.FindRelation(name).GetHeader();
            result.ChangeHeader(targetHeader.getVector());

            //finally, union result with the matching relation in the Database
            Relation target = theDatabase.FindRelation(name);
            onwards += target.unite(result);
            theDatabase.AddRelation(target);
        }
        counter++;
    }
    std::cout << '\n' << "Schemes populated after " << counter << " passes through the Rules. \n" << std::endl;

    //project 3 evaluate queries
    std::cout << "Query Evaluation" << std::endl;
    auto queries = theData.GetQueries();
    for (auto& i : queries) {
        QueryCout(i,EvaluatePredicate(i));
    }



}



