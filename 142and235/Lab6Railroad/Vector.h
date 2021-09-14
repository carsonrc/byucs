//
// Created by carso on 7/21/2021.
//

#ifndef LAB6RAILROAD_VECTOR_H
#define LAB6RAILROAD_VECTOR_H
#include "Deque.h"

template<typename T>
class Train
{
private:
    Deque<T> tDeque;
public:
    std::string push(const T& car) {
        tDeque.push_back(car);
        return "OK\n";
    };

    void pop(){
        tDeque.pop_front();
    };

    T& top() {
        tDeque.front();
    };

    size_t size() {
        return tDeque.size();
    };

    T& at(size_t num) {
        return tDeque.at(num);
    };

    std::string toString() const {
        return tDeque.toString();
    };
};


#endif //LAB6RAILROAD_VECTOR_H
