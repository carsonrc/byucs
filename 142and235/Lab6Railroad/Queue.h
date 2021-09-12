//
// Created by carso on 7/21/2021.
//
#ifndef LAB6RAILROAD_QUEUE_H
#define LAB6RAILROAD_QUEUE_H
#include "Deque.h"

template <typename T>
class Queue
{
private:
    Deque<T> qDeque;
public:
    std::string push(const T& car) {
        qDeque.push_back(car);
        return "OK\n";
    };

    void pop(){
        qDeque.pop_front();
    };

    T& top() {
        qDeque.front();
    };

    size_t size() {
        return qDeque.size();
    };

    T& at(size_t num) {
        return qDeque.at(num);
    };

    std::string toString() const {
        return qDeque.toString();
    };
};

#endif //LAB6RAILROAD_QUEUE_H
