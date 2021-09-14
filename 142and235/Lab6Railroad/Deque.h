
//**** YOU MAY NOT MODIFY THIS DOCUMENT ****/
#ifndef DEQUE_H
#define DEQUE_H

#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>
#include <utility>
#include "DequeInterface.h"


#define DEFAULT_CAPACITY 4

template<typename T>
class Deque : public DequeInterface<T>
{
private:
    size_t capacity = DEFAULT_CAPACITY;
    size_t num_items = 0;
    size_t front_index = 0;
    size_t rear_index = DEFAULT_CAPACITY - 1;
    T *the_data;

public:
    Deque() : capacity(DEFAULT_CAPACITY),
              num_items(0),
              front_index(0),
              rear_index(DEFAULT_CAPACITY - 1) {
        the_data = new T[DEFAULT_CAPACITY];
    };
    ~Deque() {
        delete [] the_data;
    };

    /** Insert item at front of deque !*/
    void push_front(const T& value){
        if (num_items == capacity) {
            reallocate();
        }
        num_items++;
        front_index = (front_index - 1) % capacity;
        the_data[front_index] = T(value);
    };

    /** Insert item at rear of deque */
    void push_back(const T& value) {
        if (num_items == capacity) {
            reallocate();
        }
        num_items++;
        rear_index = (rear_index + 1) % capacity;
        the_data[rear_index] = value;
    };

    /** Remove the front item of the deque */
    void pop_front() {
        front_index = (front_index + 1) % capacity;
        num_items--;
    };

    /** Remove the rear item of the deque !*/
    void pop_back() {
        rear_index = (rear_index - 1) % capacity;
        num_items--;
    };

    /** Return the front item of the deque (Do not remove) */
    T& front(){
        return the_data[front_index];
    };

    /** Return the rear item of the deque (Do not remove) */
    T& back(){
        return the_data[rear_index];
    };

    /** Return the number of items in the deque */
    size_t size() const{
        return num_items;
    };

    /** Return true if deque is empty */
    bool empty() const {
        return num_items == 0;
    };

    /** Return item in deque at index (0 based) */
    T& at(size_t index){
        return the_data[index];
    };

    /** Return the deque items */
    std::string toString() const {
        std::string theDeque;
        size_t j = front_index;
        for (int i = 0; i < num_items; i++) {
            theDeque += std::to_string(*the_data[j]);
            theDeque += " ";
            j = (j + 1) % capacity;
        }
        return theDeque;
    };

    /** Doubles the capacity and reallocates the data*/
    void reallocate() {
        size_t new_capacity = 2 * capacity;
        T* new_data = new T[new_capacity];
        size_t j = front_index;
        for (size_t i = 0; i < num_items; i++) {
            new_data[i] = the_data[j];
            j = (j + 1) % capacity;
        }
        front_index = 0;
        rear_index = num_items - 1;
        capacity = new_capacity;
        std::swap(the_data,new_data);
        delete[] new_data;
    }
};
#endif // DEQUE_INTERFACE_H

