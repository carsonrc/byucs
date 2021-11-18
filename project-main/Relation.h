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


    Header CombineHeaders(Header head1, Header head2) {
        std::vector<std::string> newHeaderContents;
        std::vector<std::string> holder;
        holder = head1.getVector();
        holder.insert(newHeaderContents.end(),head2.getVector().begin(), head2.getVector().end());

        std::sort(holder.begin(),holder.end());
        std::unique(holder.begin(),holder.end());

        for (int i = 0; i < head1.size(); i++) {
            for (int j = 0; j < holder.size(); j++) {
                if (head1.at(i) == holder.at(j)) {
                    newHeaderContents.push_back(head1.at(i));
                }
            }
        }

        for (int i = 0; i < head2.size(); i++) {
            for (int j = 0; j < holder.size(); j++) {
                if (head1.at(i) == holder.at(j)) {
                    newHeaderContents.push_back(head2.at(i));
                }
            }
        }

        return Header(newHeaderContents);
    }

    bool IsJoinable(Tuple tup1, Tuple tup2, std::vector<int> overlap1, std::vector<int> overlap2) {
        for (int i = 0; i < overlap1.size(); i++) {
            if (tup1.at(overlap1.at(i)) != tup2.at(overlap2.at(i))) {
                return false;
            }
            else {
                return true;
            }
        }

    }

    Tuple CombineTuples(Tuple tup1, Tuple tup2, std::vector<int> overlap1, std::vector<int> overlap2) {
        std::vector<std::string> result = tup1.GetTupleContents();
        std::vector<std::string> tup2UniqueElements = tup2.GetTupleContents();
        for (int i = 0; i < overlap2.size(); i++) {
            tup2UniqueElements.erase(tup2UniqueElements.begin() + overlap2.at(i));
        }

        result.insert(result.end(), tup2UniqueElements.begin(), tup2UniqueElements.end());
        return Tuple(result);
    }

    Relation Join(std::string name, Relation rel1, Relation rel2) {
        std::vector<int> overlap1;
        std::vector<int> overlap2;

        for (int i = 0; i < rel1.header.size(); i++) {
            for (int j = 0; j < rel2.header.size(); i++) {
                if (rel1.header.at(i) == rel2.header.at(j)) {
                    overlap1.push_back(i);
                    overlap2.push_back(j);
                }
            }
        }


        Relation result = Relation(name,CombineHeaders(rel1.header, rel2.header));

        for (auto i : rel1.relationTuples) {
            for (auto j : rel2.relationTuples) {
                if (IsJoinable(i, j, overlap1, overlap2)) {
                    CombineTuples(i,j,overlap1,overlap2);
                }
            }
        }
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
