#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>


using namespace std;

#include "Lexer.h"
#include "Parser.h"

int main(int argc, char* argv[]) {

    //opens input file
    if (argc < 2) {
        cerr << "Please provide name of input file";
        return 1;
    }
   // cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);
    if (!in) {
        cerr << "Unable to open " << argv[1] << " for input";
        return 2;
    }

    //converts input into a single string
    stringstream buffer;
    buffer << in.rdbuf();
    string input = buffer.str();

    auto lexer = new Lexer();
    lexer->Run(input);
    vector<Token*> tokens = lexer->ReturnTokens();

    auto parser = new Parser();
    try {
        parser->DatalogParser(tokens);
    } catch (const size_t& e) {
/*
          cout << "AntePenPrevious Token: " << *tokens[e-3] << endl;
          cout << "AntePrevious Token: " << *tokens[e-2] << endl;
          cout << "Previous Token: " << *tokens[e-1] << endl;
          cout << "Failure!\n" << *tokens[e] << endl;
          cout << "Next Token: " << *tokens[e+1] << endl;
*/

         cout << "Failure!\n" << *tokens[e] << endl;
         return 0;
    }
    cout << "Success!" << endl;


    delete lexer;

    return 0;
}
