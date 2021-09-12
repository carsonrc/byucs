//
// Created by carson on 8/7/21.
//

#ifndef LAB10_QS_H
#define LAB10_QS_H
#include <string>
#include <iostream>
#include "QSInterface.h"

template<typename T>
class QS : public QSInterface<T>
{
private:
    int* theArray = nullptr;
    int sizeOf = 0;
    size_t numElements = 0;
    int comparisons = 0;
    int exchanges = 0;

public:
     QS() = default;
     ~QS() {delete[] theArray;}

     void setArray(const int& size) {
         if (theArray != nullptr) delete[] theArray;
        theArray = new T[size];
        sizeOf = size;
        numElements = 0;
    }

    /** Add an element to the QuickSort array. Dynamically grow array as needed. */
    bool addElement(T element) {

        if ((static_cast<int>(numElements)+1) <= sizeOf) {
            theArray[numElements] = element;
            numElements++;
            return true;

        } else {

            //resizing array
            sizeOf = sizeOf * 2;
            int* tempArray = new int[sizeOf];//TODO: inexplicable mem leak
            for (int i = 0; i < static_cast<int>(numElements); i++) {
                tempArray[i] = theArray[i];
            }
            int* ptr = theArray;
            theArray = tempArray;
            delete[] ptr;
            //assigning value of element to array
            theArray[numElements] = element;
            numElements++;
            return false;

        }
    };

    /** Sort the elements of a QuickSort subarray using median and partition functions. */
    bool sort(size_t left, size_t right) {

        if (right - left > 1) {
            comparisons++;
            int median = medianOfThree(left,right); //pass return of sort to the new sort
            int pivot = partition(left,right,median);
            sort(left, pivot);
            sort(pivot + 1,right);
        }
        return true;
    };

    /** Sort all elements of the QuickSort array using median and partition functions. */
    bool sortAll() {
        comparisons++;
        return sort(0,numElements);
    };

    /** Removes all items from the QuickSort array. */
    bool clear() {
        T* ptr = theArray;
        theArray = nullptr;
        delete[] ptr;
        theArray = new T[sizeOf];
        numElements = 0;
        return true;
    };

    /** Return size of the QuickSort array. */
    size_t capacity() const {
        return sizeOf;
    };

    /** Return number of elements in the QuickSort array. */
    size_t size() const {
        return numElements;
    };

    /** The median of three pivot selection has two parts:
    1) Calculates the middle index by averaging the given left and right indices:
       middle = (left + right)/2
    2) Then bubble-sorts the values at the left, middle, and right indices.

    After this method is called, data[left] <= data[middle] <= data[right].

    @param left - the left boundary for the subarray from which to find a pivot
    @param right - the right + 1 boundary for the subarray from which to find a pivot
    @return the index of the pivot (middle index).
    Return -1 if  1) the array is empty,
                  2) if either of the given integers is out of bounds,
                  3) or if the left index is not less than the right index.
    */
    int medianOfThree(size_t left, size_t right) {
        if (numElements == 0) return -1;
        if (right > numElements) return -1;
        if (left >= right) return -1;


        size_t middle = (right + left)/2;
        if (theArray[left] <= theArray[middle] && theArray[middle] <= theArray[right-1]) {
            comparisons++;
            return static_cast<int>(middle);
        } else do {
            comparisons++;
            if (theArray[left] > theArray[middle]) {
                comparisons++;
                exchanges++;
                int holder = 0;
                holder = theArray[left];
                theArray[left] = theArray[middle];
                theArray[middle] = holder;
            }
            if (theArray[middle] > theArray[right - 1]) {
                comparisons++;
                exchanges++;
                int holder = 0;
                holder = theArray[middle];
                theArray[middle] = theArray[right - 1];
                theArray[right - 1] = holder;
            }
        } while (!(theArray[left] <= theArray[middle] && theArray[middle] <= theArray[right-1]));

        return static_cast<int>(middle);
    };

    /** Partitions a subarray around a pivot value selected according
    to median-of-three pivot selection. Because there are multiple ways
    to partition a list, follow the algorithm on page 611.

    The values less than or equal to the pivot should be placed to the left of the pivot;
    the values greater than the pivot should be placed to the right of the pivot.

    @param left - left index for the subarray to partition.
    @param right - right index + 1 for the subarray to partition.
    @param pivotIndex - index of the pivot in the subarray.
    @return the pivot's ending index after the partition completes:
    Return -1 if  1) the array is empty,
                  2) if any of the given indexes are out of bounds,
                  3) if the left index is not less than the right index.
    */
    int partition(size_t left, size_t right, size_t pivotIndex) {

        if (numElements == 0||
            left < 0 ||
            left > numElements - 2 ||
            right < 1 ||
            right > numElements  ||
            left >= right ||
            pivotIndex < left ||
            pivotIndex > right) return -1;

        //comparisons++;

        //swapping beginning (left) and pivotIndex elements
        exchanges++;
        int holder = 0;
        holder = theArray[left];
        theArray[left] = theArray[pivotIndex];
        theArray[pivotIndex] = holder;
        std::cout << theArray[pivotIndex] << " " << theArray[left] << std::endl;

        //partitioning
        T up = left + 1;
        T down = right - 1;
        do {
            comparisons++;
            while ((up != static_cast<int>(right) - 1) && theArray[left] >= theArray[up]){
                comparisons++;
                ++up;
            }
            while (theArray[left] < theArray[down]) {
                comparisons++;
                --down;
            }
            if (up < down) {
                comparisons++;
                exchanges++;
                holder = 0;
                holder = theArray[up];
                theArray[up] = theArray[down];
                theArray[down] = holder;
            }
        } while (up < down);

        //switching theArray[left] and theArray[down]
        exchanges++;
        holder = 0;
        holder = theArray[left];
        theArray[left] = theArray[down]; // tested with pivotIndex //fail
        theArray[down] = holder;
        return down;
    };

    /** @return: comma delimited string representation of the array. */
    std::string toString() const {
        std::string theString;
        if (numElements > 0) {
            for (int i = 0; i < static_cast<int>(numElements); i++) {
                theString += std::to_string(theArray[i]);
                theString += ",";
            }
            theString.pop_back();
        } else theString = "Empty";
        return theString;
    };


    std::string stats() {
        std::string theString;
        theString = std::to_string(comparisons) + "," + std::to_string(exchanges);
        return theString;
    }

    void resetStats() {
        comparisons = 0;
        exchanges = 0;
    }
    void increment(int num = 1) {
        comparisons += num;
    }
};


#endif //LAB10_QS_H
