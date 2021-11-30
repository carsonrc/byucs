#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"
#include "Database.h"

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
         parser->ParserRun(tokens);
    } catch (const size_t& e) {
         cout << "Failure!\n" << *tokens[e] << endl;
         return 0;
    }
    //cout << "Success!" << endl;

    //parser->GetDaddy().toCout();

    auto interpreter = new Interpreter(parser->GetDaddy());
    interpreter->GenerateDatabase();
    interpreter->EvaluateAllPredicates();

    //interpreter->DatabaseCout();


    delete lexer;

    return 0;
}
