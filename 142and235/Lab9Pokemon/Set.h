//
// Created by carson on 8/4/21.
//

#ifndef LAB9POKEMON_SET_H
#define LAB9POKEMON_SET_H
#include <list>
#include <sstream>
template<typename T>
class Set {
public:
    Set() {};
    ~Set() = default;
    std::list<T> theList;
    /** Inserts item into the set, if the container doesn't
        already contain an element with an equivalent value. */
    bool insert(const T& item) {
        theList.push_back(item);
        theList.unique();
        theList.sort();
        return true;
    };

    /** Removes all items from the set. */
    void clear() {
        theList.clear();
    };

    /** @return: the number of elements contained by the Set. */
    size_t size() const {
        return theList.size();
    };

    /** @return: return 1 if contains element equivalent to item, else 0. */
    size_t count(const T& item) {
        int oldSize = theList.size();
        std::list<T> copy = theList;
        copy.push_back(item);
        copy.unique();
        if (copy.size() != oldSize) {
            std::cout << "TRUE" << std::endl;
            return 1;
        }
        std::cout << "FALSE" << std::endl;
        return 0; // if not found above
    };

    /** @return: string representation of items in Set. */
    std::string toString() const {
        std::string theString;
        for (auto const& i : theList) {
            theString += i + ",";
        };
        theString.pop_back();
        theString.erase(0,1);
        return theString;
    };

    std::string toStringOther() const {
        std::string theString;
        for (auto const& i : theList) {
            theString += i + ",";
        };
        theString.pop_back();
        return theString;
    };


};

#endif //LAB9POKEMON_SET_H
