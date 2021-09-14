#include <iostream>
#include <fstream>
#include "BST.h"
using namespace std;

// created by Carson... not finished though lol

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
    string inputCommand;
    in >> inputCommand;
    int numNodes = 0;
    if (inputCommand == "INT" && in) {
        BST<int> theTree;
        out << "INT true" << endl;

        while (inputCommand != "STRING") {
            in >> inputCommand;
            out << inputCommand;

            if (inputCommand == "add") {
                int data = 0;
                in >> data;
                in.ignore();
                if (theTree.addNode(data)) {
                    out << " " << data << " true" << endl;
                    numNodes++;
                } else { out << " " << data << " false" << endl; }

            } else if (inputCommand == "remove") {
                int data = 0;
                in >> data;
                in.ignore();
                if (theTree.removeNode(data)) {
                    out << " " << data << " true" << endl;
                    numNodes--;
                } else {
                    out << " " << data << " false" << endl;
                }
            } else if (inputCommand == "clear") {
                theTree.clearTree();
                out << " true" << endl;
                numNodes = 0;
            } else if (inputCommand == "size") {
                out << " " << numNodes << endl;
            } else if (inputCommand == "print") {
                out << ": ";
                if (numNodes == 0) out << "empty" << endl;
                else out << theTree.toString() << endl;
                inputCommand = "";
            } else if (inputCommand == "find") {
                int data = 0;
                in >> data;
                if (theTree.find(data)) {
                    out << " " << data << " found" << endl;
                } else {
                    out << " " << data << " not found" << endl;
                }

            }
        }
    }
    if (inputCommand == "STRING") {
        BST<string> theTree;
        out << " true" << endl;
        numNodes = 0;

        while (inputCommand != "INT" && in) {
            in >> inputCommand;
            out << inputCommand;

            if (inputCommand == "add") {
                string data;
                in >> data;
                //in.ignore();
                if (theTree.addNode(data)) {
                    out << " " << data << " true" << endl;
                    numNodes++;
                } else { out << " " << data << " false" << endl; }
            } else if (inputCommand == "remove") {
                string data;
                in >> data;
                in.ignore();
                if (theTree.removeNode(data)) {
                    out << " " << data << " true" << endl;
                    numNodes--;
                } else {
                    out << " " << data << " false" << endl;
                }

            } else if (inputCommand == "clear") {
                theTree.clearTree();
                out << " true" << endl;
                numNodes = 0;
            } else if (inputCommand == "size") {
                out << " " << numNodes << endl;
            } else if (inputCommand == "print") {
                out << ": ";
                if (numNodes == 0) out << "empty" << endl;
                else out << theTree.toString() << endl;
                inputCommand = "";
            } else if (inputCommand == "find") {
                string data;
                in >> data;
                if (theTree.find(data)) {
                    out << " " << data << " found" << endl;
                } else {
                    out << " " << data << " not found" << endl;

                }
            }
        }
        return 0;
    }
}