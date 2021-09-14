#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>


using namespace std;

#include "Lexer.h"

int main(int argc, char* argv[]) {

    //opens input file
    if (argc < 2) {
        cerr << "Please provide name of input file";
        return 1;
    }
    cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);
    if (!in) {
        cerr << "Unable to open " << argv[1] << " for input";
        return 2;
    }

    auto lexer = new Lexer();

    stringstream buffer;
    buffer << in.rdbuf();
    string input = buffer.str();

    lexer->Run(input);



    delete lexer;

    return 0;
}