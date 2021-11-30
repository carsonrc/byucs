//
// Created by carsoncall on 10/25/21.
//

#ifndef PROJECT_1_MAIN_RELATION_H
#define PROJECT_1_MAIN_RELATION_H

#include <string>
#include <set>
#include <vector>
#include <iostream>

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
            for (size_t j = 0; j < header.size(); j++) {
                theString += "  " + header.at(j) + '=' + i.at(j) + ",";
            }
            if (!(theString.empty())) {
                theString.pop_back();
                //theString.pop_back();
                theString += '\n';
            }
        }
        return theString;
    }

    std::string GetName() {
        return name;
    }

    Tuple CombineTuples(Tuple tup1, Tuple tup2, std::vector<int> overlap1, std::vector<int> overlap2) {
        std::vector<std::string> result = tup1.GetTupleContents();
        std::vector<std::string> tup2UniqueElements = tup2.GetTupleContents();
        for (size_t i = 0; i < overlap2.size(); i++) {
            tup2UniqueElements.erase(tup2UniqueElements.begin() + overlap2.at(i));
        }

        result.insert(result.end(), tup2UniqueElements.begin(), tup2UniqueElements.end());
        return Tuple(result);
    }

    //requires a name for the result relation and a second relation to join with
    Relation Join(std::string name, Relation rel) {

        //required to be able to return overlapping header entries
        std::vector<std::pair<size_t,size_t>> overlap;

        //returns the new header and populates the overlap vector of pairs
        Header newHeader = this->header.CombineHeaders(rel.GetHeader(),overlap);

        //initializes result relation
        Relation result = Relation(name, newHeader);

        for (auto i : this->relationTuples) {
            for (auto j : rel.relationTuples) {
                if (i.isJoinable(j,overlap)) {
                    result.AddTuple(i.CombineTuples(j,overlap));
                }
            }
        }
        return result;
    }

    //adds the tuples of two relations that have equal headers. should be called "union"
    //note: call this on the DATABASE relation, not the JOIN resulting relation
    bool unite(Relation rel) {
        bool result = false;
        std::string theString;
        for (auto i : rel.relationTuples) {
            if (this->relationTuples.insert(i).second) {
                result = true;
                for (size_t j = 0; j < header.size(); j++) {
                    theString += "  " + header.at(j) + '=' + i.at(j) + ",";
                }
                if (!(theString.empty())) {
                    theString.pop_back();
                    //theString.pop_back();
                    theString += '\n';
                }
            }
            std::cout << theString;
            theString = "";
        }
        return result;
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

    //takes a vector of columns (by position in this->relation) and makes a new relation with those columns,
    // in the order they are given.
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

    void ChangeHeader(std::vector<std::string> newNames) {
        this->header = Header(newNames);
    }

    Header GetHeader() {
        return header;
    }

    bool IsNotEmpty() {
        return !(relationTuples.empty());
    }

    size_t Size() {
        return relationTuples.size();
    }


};


#endif //PROJECT_1_MAIN_RELATION_H
