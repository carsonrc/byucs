//
// Created by carso on 7/21/2021.
//

#ifndef LAB6RAILROAD_STACK_H
#define LAB6RAILROAD_STACK_H
#include "Deque.h"

template<typename T>
class Stack
{
private:
    Deque<T> sDeque;
public:
    std::string push(const T& car) {
        sDeque.push_back(car);
        return "OK\n";
    };

    void pop(){
        sDeque.pop_back();
    };

    T& top() {
        return sDeque.back();
    };

    size_t size() {
        return sDeque.size();
    };

    T& at(size_t num) {
        return sDeque.at(num);
    };

    std::string toString() const {
        return sDeque.toString();
    };
};

#endif //LAB6RAILROAD_STACK_H
