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

    //select that finds all tuples that have a certain value in a certain column. Position is column.
    //returns a new relation with the same name and header
    Relation select(size_t position, std::string value) {
        Relation result = Relation(this->name,this->header); // same name and header
        for (auto i : relationTuples) {
            if (i.at(position) == value) {
                result.AddTuple(i);
            }
        }
        return result;
    }

    //select that finds all tuples that are equal, given two columns (positions)
    //returns a new relation with the same name and header
    Relation select(size_t position1, size_t position2) {
        Relation result = Relation(this->name, this->header);
        for (auto i : relationTuples) {
            if (i.at(position1) == i.at(position2)) {
                result.AddTuple(i);
            }
        }
        return result;
    }

    //takes a vector of columns (by position) and makes a new relation with those columns, in the order
    // they are given.
    Relation project(std::vector<size_t> positionList) {
        Relation result = Relation(this->name, this->header.projectHeader(positionList));
        for (auto i : relationTuples) {
            std::vector<std::string> newTupleContents;
            for (auto j : positionList) {
                newTupleContents.push_back(i.at(j));
            }
            Tuple newTuple = Tuple(newTupleContents);
            result.AddTuple(newTuple);
        }

        return result;
    }


};


#endif //PROJECT_1_MAIN_RELATION_H
