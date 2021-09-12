//
// Created by carso on 7/21/2021.
//

#ifndef LAB6RAILROAD_CAR_H
#define LAB6RAILROAD_CAR_H

#include <string>
#include <sstream>

struct Car
{
    unsigned int id;
    explicit Car(int data) {id = data;}
    Car() : id(0) {}
    ~Car() = default;

    bool operator==(const Car car) const { return this->id == car.id; }
    bool operator!=(const Car car) const { return this->id != car.id; }
    unsigned int operator*() const {return this->id;}

    /** Return the Car as a string */
    std::string toString() const
    {
        std::stringstream out;
        out << id;
        return out.str();
    } // end toString()

    /** Make insertion operator friend for a Car */
    friend std::ostream& operator<< (std::ostream& os, const Car& c)
    {
        os << c.toString();
        return os;
    } // end operator<<
};

#endif //LAB6RAILROAD_CAR_H
