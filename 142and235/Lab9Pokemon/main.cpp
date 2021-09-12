//
// Created by carson on 8/4/21.
//

#include <iostream>
#include <fstream>
#include "Pair.h"
#include "Set.h"
#include "HashMap.h"
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
    HashMap<string,string> pokemon;
    HashMap<string, string> moves;
    HashMap<string, Set<string>> effectivities;
    HashMap<string, Set<string>> ineffectivities;
    while (in) {
        in >> inputCommand;
        out << inputCommand;
        if (inputCommand == "Set:") {
            Set<string> theSet;
            while (in.peek() != '\n') {
                string holder;
                in >> holder;
                out << holder << " ";
                theSet.insert(holder);
            }
            out <<  endl << "[" << theSet.toStringOther() << "]" << endl;
        }
        if (inputCommand == "Pokemon:") {
            string species, type;
            in >> species >> type;
            out << " " << species << " " << type;
            pokemon[species] = type;
            in.ignore();
            out << endl;
        }
        if (inputCommand == "Pokemon") {
            out << ": ";
            out << pokemon.toString() << endl;
        }
        if (inputCommand == "Move:") {
            string move, type;
            in >> move >> type;
            out << " " << move << " " << type;
            moves[move] = type;
            in.ignore();
            out << endl;
        }
        if (inputCommand == "Moves") {
            out << ": ";
            out << moves.toString() << endl;
        }

        if (inputCommand == "Effective:") {
            string key, stuff, type;
            in >> key;
            getline(in, stuff);
            out << " " << key << stuff << endl;
            stringstream ss(stuff);
            Set<string> holder;
            while (ss) {
                ss >> type;
                holder.insert(type);
                type = "";
            }
            Pair<string, Set<string>> thePair;
            thePair.first = key;
            thePair.second = holder;
            effectivities[key] = holder;
        }

        if (inputCommand == "Effectivities") {
            out << ": ";
            out << effectivities.sizeOf << "/" << effectivities.capacity << endl;
            out << effectivities << endl;
        }
        if (inputCommand == "Ineffective:") {
            string key, stuff, type;
            in >> key;
            getline(in, stuff);
            out << " " << key << stuff << endl;
            stringstream ss(stuff);
            Set<string> holder;
            while (ss) {
                ss >> type;
                holder.insert(type);
                type = "";
            }
            Pair<string, Set<string>> thePair;
            thePair.first = key;
            thePair.second = holder;
            ineffectivities[key] = holder;
        }
        if (inputCommand == "Ineffectivities") {
            out << ": ";
            out << ineffectivities.sizeOf << "/" << ineffectivities.capacity << endl;
            out << ineffectivities << endl;
        }
        if (inputCommand == "Battle:") {
                string pokemon1, move1, pokemon2, move2;
                in >> pokemon1 >> move1 >> pokemon2 >> move2;

                out << pokemon1 << " " << move1 << " " << pokemon2 << " " << move2 << endl;

                int damageAToB = effectivities[moves[move1]].count(pokemon[pokemon2])
                                 - ineffectivities[moves[move1]].count(pokemon[pokemon2]);
                int damageBToA = effectivities[moves[move2]].count(pokemon[pokemon1])
                                 - ineffectivities[moves[move2]].count(pokemon[pokemon1]);

                out << "  " << pokemon1 << " (" << move1 << ") vs " << pokemon2 << " (" << move2 << ")" << endl;
                out << "  " << pokemon1 << " is a " << pokemon[pokemon1] << " type Pokemon." << endl;
                out << "  " << pokemon2 << " is a " << pokemon[pokemon2] << " type Pokemon." << endl;
                out << "  " << move1 << " is a " << moves[move1] << " type move." << endl;
                out << "  " << move2 << " is a " << moves[move2] << " type move." << endl;

            switch (damageAToB) {

                case -1:
                    out << "  " << pokemon1 << "'s " << move1 << " is ineffective against " << pokemon2 << endl;
                    break;
                case 0:
                    out << "  " << pokemon1 << "'s " << move1 << " is effective against " << pokemon2 << endl;
                    break;
                case 1:
                    out << "  " << pokemon1 << "'s " << move1 << " is super effective against " << pokemon2 << endl;
                    break;
            }

            switch (damageBToA) {

                case -1:
                    out << "  " << pokemon2 << "'s " << move2 << " is ineffective against " << pokemon1 << endl;
                    break;
                case 0:
                    out << "  " << pokemon2 << "'s " << move2 << " is effective against " << pokemon1 << endl;
                    break;
                case 1:
                    out << "  " << pokemon2 << "'s " << move2 << " is super effective against " << pokemon1 << endl;
                    break;
            }

            if ((damageAToB - damageBToA) == 0) {
                out << "  The battle between " << pokemon1 << " and " << pokemon2 << " is a tie." << endl;

            }
            if ((damageAToB - damageBToA) < 0) {
                out << "  In the battle between " << pokemon1 << " and " << pokemon2 << ", " << pokemon1 << " wins!" << endl;
            }
            if ((damageAToB - damageBToA) > 0) {

                out << "  In the battle between " << pokemon1 << " and " << pokemon2 << ", " << pokemon2 << " wins!" << endl;
            }
            out << endl;

        }
        inputCommand = "";

    }


    return 0;
}