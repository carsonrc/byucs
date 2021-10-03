//
// Created by carsoncall on 10/2/21.
//

#ifndef PROJECT_1_MAIN_PARAMETER_H
#define PROJECT_1_MAIN_PARAMETER_H


class Parameter {

private:
    std::string param;

public:
    void setParam(std::string parameter) {
        this->param = parameter;
    }

    std::string getParam() {
        return param;
    }
};


#endif //PROJECT_1_MAIN_PARAMETER_H
