#include <iostream>
#include <iosfwd>
#include <istream>
#include <sstream>
#include <limits>
#include "ExpressionManager.h"

using namespace std;


int main(int argc, char* argv[])
{
    //opens input and output files
    if (argc < 3)
    {
        cerr << "Please provide name of input and output files";
        return 1;
    }
    cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);
    if (!in)
    {
        cerr << "Unable to open " << argv[1] << " for input";
        return 2;
    }
    cout << "Output file: " << argv[2] << endl;
    ofstream out(argv[2]);
    if (!out)
    {
        in.close();
        cerr << "Unable to open " << argv[2] << " for output";
        return 3;
    }

    string inputCommand = "nothing";
    string expression = "nothing";
    ExpressionManager thisExpression(expression);

    while (in)
    {
        // parsing input command
        in >> inputCommand;
        if (inputCommand != "Expression:")
        {
            in.ignore(numeric_limits<int>::max(), '\n');
        }
        else
        {
            getline(in, expression);
            thisExpression.setExpression(expression);
            out << "Expression:" << thisExpression.getExpression() << endl;
        }

        //menu
        if (inputCommand == "Infix:")
        {
            try {
                string infixString = thisExpression.infix();
                out << "Infix:" << infixString << endl;
            }catch (string& e) {out << "Infix: " << e;};
        }
        else if (inputCommand == "Prefix:")
        {
            string prefixString = thisExpression.prefix();
            out << "Prefix: " << prefixString << endl;
        }
        else if (inputCommand == "Postfix:")
        {
            string postfixString = thisExpression.postfix();
            out << "Postfix: " << postfixString << endl;
        }
        else if (inputCommand == "Value:")
        {
            int value = thisExpression.value();
            out << "Value: " << value << endl;
        }
    }

    return 0;
}
