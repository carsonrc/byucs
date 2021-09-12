#include <iostream>
#include <fstream>
#include "Maze.h"

using namespace std;


int main(int argc, char* argv[]) {

    enum CellValue_t { OPEN, BLOCKED, VISITED, EXIT, LEFT, RIGHT, UP, DOWN, OUT, IN };

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

    int height;
    int width;
    int layer;

    int holder = 666;

    //takes size of array
    in >> height >> width >> layer;
    in.ignore();

    Maze deathtrap(height,width,layer);

    //populates array
    for (int k = 0; k < layer; k++){
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                in >> holder;
                deathtrap.setValue(i,j,k,holder);
            }
        }
        in.ignore();
    }
    //outputs maze, solves, then outputs again
    out << "Solve Maze: \n";
    out << deathtrap.toString();
    if (deathtrap.find_maze_path()) {
        out << "\nSolution: \n";
        out << deathtrap.toString();
    }
    else {out << "No Solution Exists!";}

    return 0;
}
