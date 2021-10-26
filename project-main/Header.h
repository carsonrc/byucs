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

    Header() {};

    Header(const std::vector<Parameter *>& parameters) {
        for (auto i : parameters) {
            headerContents.push_back(i->getParam());
        }
    }

    std::string at(size_t index) {
        return headerContents.at(index);
    }

    size_t size() {
        return headerContents.size();
    }
};


#endif //PROJECT_1_MAIN_HEADER_H
