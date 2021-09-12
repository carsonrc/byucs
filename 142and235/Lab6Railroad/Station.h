//
// Created by carso on 7/21/2021.
//

#ifndef LAB6RAILROAD_STATION_H
#define LAB6RAILROAD_STATION_H
#include "Queue.h"
#include "Stack.h"
#include "Vector.h"

template <typename T>
class Station{
private:
    T turntable;
    bool occupied;
    Queue<T> sQueue{};
    Stack<T> sStack{};
    Train<T> sVector{};

public:
    Station() : turntable(0),
                occupied(false) {};
    ~Station() = default;

    std::string addCar(const T& car) {
        if (occupied) {
            return "Turntable occupied! \n";
        }
        else {
            turntable = car;
            occupied = true;
            return "OK\n";
        }
    }

    std::string addQueue() {
        if (!occupied) {
            return "Turntable empty! \n";
        }
        else {
            occupied = false;
            return sQueue.push(turntable); //returns OK if successful
        }
    }

    std::string addStack() {
        if (!occupied) {
            return "Turntable empty! \n";
        }
        else {
            occupied = false;
            return sStack.push(turntable); //returns OK if successful
        }
    }

    std::string removeCar() {
        if (!occupied) {
            return "Turntable empty! \n";
        }
        else {
            occupied = false;
            return sVector.push(turntable); //returns OK if successful
        }
    }

    std::string removeQueue() {
        if (occupied) {
            return "Turntable occupied! \n";
        }
        if (sQueue.size() == 0) {
            return "Queue empty!\n";
        } else {
            occupied = true;
            turntable = sQueue.top();
            sQueue.pop();
            return "OK \n";
        }
    }

    std::string removeStack() {
        if (occupied) {
            return "Turntable occupied!\n";
        }
        if (sStack.size() == 0) {
            return "Stack empty!\n";
        } else {
            occupied = true;
            turntable = sStack.top();
            sStack.pop();
            return "OK \n";
        }
    }

    std::string topCar() {
        std::string holder = turntable.toString();
        return holder;
    }

    std::string topStack() {
        std::string holder = sStack.top().toString();
        return holder;
    }

    std::string topQueue() {
        std::string holder = sQueue.top().toString();
        return holder;
    }

    std::string train() {
        return sVector.toString();
    }
    std::string trainSize() {
        std::string size = std::to_string(sVector.size());
        return size;
    }
    std::string stack() {
        return sStack.toString();
    }
    std::string stackSize() {
        std::string size = std::to_string(sStack.size());
        return size;
    }
    std::string queue() {
        return sQueue.toString();
    }
    std::string queueSize() {
        std::string size = std::to_string(sQueue.size());
        return size;
    }

    std::string find(size_t theOne){

        for (int i = 0; i < sQueue.size(); i++) {
            if (*sQueue.at(i) == theOne) {
                std::string yeet = "Queue[" + std::to_string(i) + "]";
                return yeet;
            }
        }
        for (int i = 0; i < sStack.size(); i++) {
            if (*sStack.at(i) == theOne) {
                std::string yeet = "Stack[" + std::to_string(i) + "]";
                return yeet;
            }
        }
        for (int i = 0; i < sVector.size(); i++) {
            if (*sVector.at(i) == theOne) {
                std::string yeet = "Train[" + std::to_string(i) + "]";
                return yeet;
            }
        }
        return "Not Found!"

    }



};
#endif //LAB6RAILROAD_STATION_H
