//
// Created by carson on 8/4/21.
//

#ifndef LAB9POKEMON_HASHMAP_H
#define LAB9POKEMON_HASHMAP_H
#include <string>
#include "Pair.h"
#include <cmath>
using namespace std;

#define DEFAULT_MAP_HASH_TABLE_SIZE	31
#define HASH_CONSTANT				3
#define LOAD_THRESHOLD				75

/** Hash Function Objects Template */
template<typename Key_Type>
struct myHash {};

template<>
struct myHash<std::string>
{
    size_t operator()(const string& s) {
        long long hash = 0;
        int size = s.size();
        int  decrement = size;
        for (int i = 0; i < size; i++) {
            hash += s[i] * pow(HASH_CONSTANT, (decrement-1));
            decrement--;
        }
        return hash;
    }
};


template <typename K, typename V>
class HashMap {
private:
    Pair<std::string,V>* myPairs;

    void rehash() {
        cout << endl << "Rehash " << sizeOf << "/" << capacity << " to " << capacity * 2;
        size_t old_capacity = capacity;
        capacity = capacity * 2;
        auto *new_myPairs = new Pair<string, V>[capacity];
        for (size_t index = 0; index < old_capacity; ++index) {
            if (myPairs[index].first != "") {
                size_t hashIndex = myHash<std::string>()(myPairs[index].first) % capacity;
                int probe = -1;
                while (new_myPairs[hashIndex].first != "") {
                    probe = probe + 2;
                    hashIndex = (hashIndex + probe) % capacity;
                }
                // **Deep assignment
                new_myPairs[hashIndex] = myPairs[index];
            }
        }
        delete[] myPairs;
        myPairs = new_myPairs;
    }

public:
    size_t sizeOf;
    size_t capacity;
    HashMap() : sizeOf(0),
                capacity(DEFAULT_MAP_HASH_TABLE_SIZE),
                myPairs(new Pair<std::string, V>[DEFAULT_MAP_HASH_TABLE_SIZE]) {};

    ~HashMap() {delete[] myPairs;};

    /** Read/write index access operator.
    If the key is not found, an entry is made for it.
    @return: Read and write access to the value mapped to the provided key. */
    V &operator[](const string &key) {
        // check load factor and maybe rehash...
        cout << endl << "Load = " << ((sizeOf * 100) / capacity);
        if (((sizeOf * 100) / capacity) > LOAD_THRESHOLD) rehash();

        size_t hashIndex = myHash<std::string>()(key) % capacity;
        int k = -1;
        while (true) {
            if (myPairs[hashIndex].first.length() == 0) {
                ++sizeOf;
                myPairs[hashIndex].first = key;
                break;
            }
            if (myPairs[hashIndex].first == key) break;
            cout << endl << "Collision of " << key << " with " << myPairs[hashIndex].first;
            k = k + 2;
            hashIndex = (hashIndex + k) % capacity;
        }
        return myPairs[hashIndex].second;
    }
    HashMap& operator=(Pair<string, Set<string>> pair) {

        return myPairs;
    }

    friend std::ostream &operator<<(std::ostream &os, const HashMap &hmap) {
        for (size_t i = 0; i < hmap.capacity; ++i) {
            if (hmap.myPairs[i].first != "") {
                os << std::endl << " [" << i << ":";
                os << hmap.myPairs[i];
                os << "]";
            }
        }
        return os;
    }

    /** @return: the number of elements that match the key in the Map. */
    size_t count(const K &key) {
        size_t count = 0;
        for (size_t i = 0; i < capacity; i++) {
            if (myPairs[i].first == key)
                count++;
        }
        return count;
    }

    /** Removes all items from the Map. */
    void clear() {

    };

    /** @return: number of Key-Value pairs stored in the Map. */
    size_t size() const {
        return 0;
    };

    /** @return: maximum number of Key-Value pairs that the Map can hold. */
    size_t max_size() const {
        return 0;
    };

    /** @return: string representation of Key-Value pairs in Map. */
    std::string toString() const {
        std::string theString = to_string(sizeOf) + "/" + to_string(capacity) + "\n";
        for (int i = 0; i < capacity; i++) {
            if (myPairs[i].first != "") {
                theString = theString + "  [" + to_string(i) + ":" + myPairs[i].first + "->"
                            + myPairs[i].second + "]" + "\n";
            }

        }
        return theString;
    };

};


#endif //LAB9POKEMON_HASHMAP_H
