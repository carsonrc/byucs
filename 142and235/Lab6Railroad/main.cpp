#include <iostream>
#include <iosfwd>
#include <istream>
#include <limits>
#include <fstream>
#include "Car.h"
#include "Station.h"

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

    string inputCommand = "nothing";

    Station<Car> hell;


    while (in) {
        //parsing input from file
        in >> inputCommand;
        out << inputCommand << " ";
        if (inputCommand != "Add:station" && inputCommand != "Find") {
            in.ignore(numeric_limits<int>::max(), '\n');
        }

// menu for commands
        if (inputCommand == "Add:station") {
            int id = 0;
            string num = " ";
            in >> num;
            id = stoi(num);
            Car newCar(id);
            out << num  << " " << hell.addCar(newCar);

        } else if (inputCommand == "Remove:station") {
            out << hell.removeCar();

        } else if (inputCommand == "Add:queue") {
            out << hell.addQueue();

        } else if (inputCommand == "Remove:queue") {
            out << hell.removeQueue();

        } else if (inputCommand == "Add:stack") {
            out << hell.addStack();

        } else if (inputCommand == "Remove:stack") {
            out << hell.removeStack();
        }
        else if (inputCommand == "Top:station") {
            out << hell.topCar() << endl;

        } else if (inputCommand == "Top:queue") {
            out << hell.topQueue() << endl;

        } else if (inputCommand == "Top:stack") {
            out << hell.topStack() << endl;

        } else if (inputCommand == "Size:queue") {
            out << hell.queueSize() << endl;

        } else if (inputCommand == "Size:stack") {
            out << hell.stackSize() << endl;

        } else if (inputCommand == "Size:train") {
            out << hell.trainSize() << endl;

        } else if (inputCommand == "Queue") {
            out << hell.queue() << endl;

        } else if (inputCommand == "Stack") {
            out << hell.stack() << endl;

        } else if (inputCommand == "Train") {
            out << hell.train() << endl;

        } else if (inputCommand == "Find") {
            int id = 0;
            in >> id;
            out << id << " " << hell.find(id) << endl;
        }
    }
    return 0;
}