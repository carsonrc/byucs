//
// Created by carsoncall on 10/25/21.
//

#ifndef PROJECT_1_MAIN_HEADER_H
#define PROJECT_1_MAIN_HEADER_H

#include <vector>
#include <string>

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
};


#endif //PROJECT_1_MAIN_HEADER_H
