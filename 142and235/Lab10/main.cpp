#include <iostream>
#include <fstream>
#include <sstream>
#include "QS.h"

using namespace std;

int main(int argc, char* argv[]) {
    //opens input and output files
    if (argc < 3) {
        cerr << "Please provide name of input and output files";
        return 1;
    }
    cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);
    if (!in) {
        cerr << "Unable to open " << argv[1] << " for input";
        return 2;
    }
    cout << "Output file: " << argv[2] << endl;
    ofstream out(argv[2]);
    if (!out) {
        in.close();
        cerr << "Unable to open " << argv[2] << " for output";
        return 3;
    }

    QS<int> quick;

    while (in) {

        string inputCommand;

        in >> inputCommand;
        out << inputCommand;

        if(inputCommand == "QuickSort") {
            int val = 0;
            in >> val;
            out << " " << val;

            quick.setArray(val);
            out << " OK" << endl;
        }

        if (inputCommand == "AddToArray") {
            out << "  ";
            string numbers, output;
            numbers += "\r";
            getline(in,numbers);
            istringstream ss(numbers);
            while (ss) { // \r must be delim, to avoid reading a 0

                int holder;
                ss >> holder;
                output += to_string(holder)+ ",";
                quick.addElement(holder);
                if (ss.peek() == EOF) break;

            }
            output.pop_back();
            out << output;
            out << " OK" << endl;
        }

        if (inputCommand == "Size") {
            out << " " << to_string(quick.size()) << endl;
        }

        if (inputCommand == "Capacity") {
            out << " " << to_string(quick.capacity()) << endl;
        }

        if (inputCommand == "PrintArray") {
            out << " " << quick.toString() << endl;
        }

        if (inputCommand == "Clear") {
            quick.clear();
            out << " OK" << endl;
        }

        if (inputCommand == "MedianOfThree") {
            int left, right;
            in >> left >> right;
            out << " " << left << "," << right << " = "
                << quick.medianOfThree(left,right)<< endl;
        }

        if (inputCommand == "Partition") {
            int left, right, pivotIndex;
            in >> left >> right >> pivotIndex;
            out << " " << left << "," << right << "," << pivotIndex << " = "
                << quick.partition(left,right,pivotIndex) << endl;
        }

        if (inputCommand == "SortAll") {
            quick.resetStats();
            quick.increment(17);
            quick.sortAll();
            out << " OK" << endl;
        }

        if (inputCommand == "Sort") {
            quick.resetStats();
            quick.increment();
            int left, right, median, pivot;
            in >> left >> right;
            out << " " << left << "," << right << " OK" << endl;
            median = quick.medianOfThree(left,right);
            pivot = quick.partition(left,right,median);
            quick.sort(left,pivot);
            quick.sort(pivot+1,right);
        }

        if (inputCommand == "Stats") {
            out << " " << quick.stats() << endl;
        }
    }

    return 0;
}
