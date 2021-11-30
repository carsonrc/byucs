//
// Created by carsoncall on 10/25/21.
//

#ifndef PROJECT_1_MAIN_HEADER_H
#define PROJECT_1_MAIN_HEADER_H

#include <vector>
#include <string>
#include<algorithm>

#include "Parameter.h"

class Header {

private:
    std::vector<std::string> headerContents;

public:

    Header()= default;;

    explicit Header(const std::vector<std::string>& parameters) {
        headerContents = parameters;
    }

    std::string at(size_t index) {
        return headerContents.at(index);
    }

    //necessary for for loops
    size_t size() {
        return headerContents.size();
    }

    std::vector<std::string> getVector() {
        return headerContents;
    }

    Header projectHeader(const std::vector<size_t> positions) {
        std::vector<std::string> newHeaderContents;
        for (auto i : positions) {
            newHeaderContents.push_back(headerContents.at(i));
        }
        Header newHeader = Header(newHeaderContents);
        return newHeader;
    }

    //function CombineHeaders takes a second header and returns the new header while also writing each instance
    // of equal entries to a vector of pairs, which is passed as an argument.
    Header CombineHeaders(Header head,std::vector<std::pair<size_t,size_t>>& overlap) {
        //we are going to make a vector and then construct the header at the end
        //the vector is going to be initially equal to the vector "headerContents" of the calling object
        std::vector<std::string> resultContents = this->headerContents;

        std::vector<std::string> callerVect = this->headerContents;
        std::vector<std::string> argVect = head.headerContents;

        //now we are going to check each header member of the calling header vs the argument header
        for (size_t i = 0; i < argVect.size(); i++) {
            bool isUnique = true;


            for (size_t j = 0; j < callerVect.size(); j++) {
                if (argVect.at(i) == callerVect.at(j)) {
                    overlap.emplace_back(j,i);
                    isUnique = false;
                }
            }
            if (isUnique) {
                resultContents.push_back(argVect.at(i));
            }
        }

        return Header(resultContents);
    }
};


#endif //PROJECT_1_MAIN_HEADER_H
