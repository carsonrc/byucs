#include <iostream>
#include <istream>
#include <iosfwd>
#include <fstream>
#include <sstream>
#include <limits>
#include <string>
#include "CMakeFiles/LinkedList.h"
using namespace std;

// Written by Carson Call 7-9-2021

int main(int argc, char* argv[]) {
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
    LinkedList<string> myList;

    while (in)
    {
        //parsing input from file
        in >> inputCommand;
        if (inputCommand != "Insert" && inputCommand != "Remove" && inputCommand != "Find" && inputCommand != "InsertBefore"
                && inputCommand != "InsertAfter" && inputCommand != "Erase" && inputCommand != "Replace")
        {
            in.ignore(numeric_limits<int>::max(), '\n');
        }
        out << inputCommand << " ";

// menu for commands
        if (inputCommand == "Clear")
        {
            myList.clear();
            out << "OK";
        }

        else if (inputCommand == "Empty")
        {
            if (myList.empty())
            {
                out << "true";
            }
            else {out << "false";}
        }

        else if (inputCommand == "Delete")
        {
            try {
                if (myList.empty()) {throw string("Empty!");}
                myList.pop_front();
                out << "OK";
            }
            catch (string& e) {out << e;}

        }

        else if (inputCommand == "First")
        {
            try {
                if (myList.empty()) {throw string("Empty!");}
                out << myList.front();
            }
            catch (string& e) {out << e;}
        }

        else if (inputCommand == "Insert")
        {
            string holder;
            getline(in, holder);
            istringstream hol(holder);
            while (hol)
            {
                string newData;
                hol >> newData;
                hol.ignore();
                myList.push_front(newData);
                out << newData << " ";
            }
        }

        else if (inputCommand == "PrintList")
        {
            out << myList.toString();
        }

        else if (inputCommand == "Remove")
        {
            string holder;
            in >> holder;
            in.ignore();
            out << holder;
            for (int i = 0; i < 20; i++)
            {
                myList.remove(holder);
            }                                   //sorry this is so ugly pls dont hate me

        }

        else if (inputCommand == "Reverse")
        {
            try
            {
                if (myList.empty()) {throw string("Empty!");}
                myList.reverse();
                out << "OK";
            }
            catch (string& e) {out << e;}
        }

        else if (inputCommand == "Size")
        {
            out << myList.size();
        }
//All new stuff is past here ===========================================================================================
        else if (inputCommand == "Iterate")
        {
            LinkedList<string>::Iterator iter = myList.begin();
            while (iter != myList.end())
            {
                out << endl << " [" << *iter << "]";
                ++iter;
            }
            if (iter == myList.begin()) {out << "Empty!";}
        }

        else if (inputCommand == "Find")
        {
            string holder;
            in >> holder;
            in.ignore();
            out << holder;

            try
            {
               LinkedList<string>::Iterator position = myList.find(myList.begin(), myList.end(),holder);
                if (position != NULL) {out << " OK";}
                else {throw string(" Not Found");}
            } catch (string& e) {out << e;}
        }

        else if (inputCommand == "InsertBefore")
        {
            try
            {
                string item1, item2;
                in >> item1 >> item2;
                out << item1 << " " << item2;
                LinkedList<string>::Iterator position = myList.find(myList.begin(), myList.end(), item2);
                if (position == myList.getHead())
                {
                    myList.push_front(item1);
                    out << " OK";
                }
                 else if (position != nullptr)
                {
                    LinkedList<string>::Iterator result = myList.insert(position, item1);
                    out << " OK";
                }
                 else {throw string(" Not Found");}
            } catch (string& e) { out << e;}

        }

        else if (inputCommand == "InsertAfter")
        {
            try
            {
                string item1, item2;
                in >> item1 >> item2;
                out << item1 <<" " << item2;
                LinkedList<string>::Iterator position = myList.find(myList.begin(), myList.end(), item2);
                if (position == NULL ){throw string(" Not Found");}
                LinkedList<string>::Iterator result = myList.insert_after(position, item1);

                if (result != NULL) {out << " OK";}
            } catch (string& e) { out << e;}
        }

        else if (inputCommand == "Erase")
        {
            try
            {
                string holder;
                in >> holder;
                out << " " << holder;
                LinkedList<string>::Iterator position = myList.find(myList.begin(), myList.end(), holder);
                LinkedList<string>::Iterator result = myList.erase(position);
                out << " OK";
            } catch (string& e) { out << e;}
        }

        else if (inputCommand == "Replace")
        {
            string item1,item2;
            in >> item1 >> item2;
            out << item1 <<" " << item2 << " OK";
            myList.replace(myList.begin(), myList.end(), item1, item2);
        }
        out << endl;
    }
    while(!myList.empty())
    {
        myList.pop_front();
    }
    return 0;
}
