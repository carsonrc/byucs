//
// Created by carson on 7/27/21.
//

#ifndef LAB7_3DMAZE_MAZE_H
#define LAB7_3DMAZE_MAZE_H
#include "MazeInterface.h"

class Maze : public MazeInterface
{
private:
    int*** theArray;
    int height = 0;
    int width = 0;
    int layer = 0;
    int value = 0;
public:
    Maze (int height, int width, int layer) {
        theArray = new int**[height];
        this->height = height;
        this->width = width;
        this->layer = layer;
        for (int i = 0; i < height; i++) {
            theArray[i] = new int*[width];
            for (int j = 0; j < width; j++) {
                theArray[i][j] = new int[layer];
            }
        }
        for (int k = 0; k < layer; k++) {
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    theArray[i][j][k] = 0;
                }
            }
        }
    }
    ~Maze() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                delete[] theArray[i][j];
            }
            delete[] theArray[i];
        }
        delete[] theArray;
    }

    /** Set maze value
       @parm height
       @parm width
       @parm layer
       @parm value
    */
    void setValue(int h, int w, int l, int v) override {
        theArray[h][w][l] = v;
    };

    /** Solve maze
       @return true if solvable, else false
    */
    enum CellValue_t { OPEN, BLOCKED, VISITED, EXIT, LEFT, RIGHT, UP, DOWN, OUT, IN };
    bool find_maze_path(int h, int w, int l) {
        if (h < 0 || w < 0 || l < 0 || h >= height || w >= width || l >= layer) {
            return false; //cell is out of bounds
        }
        else if (theArray[h][w][l] != OPEN) {
            return false; //Cell is blocked or leads to dead end.
        }
        else if (h == height-1 && w == width-1 && l == layer - 1) {
            theArray[h][w][l] = EXIT;
            return true;
        }
        else {
            theArray[h][w][l] = IN;
            if      (find_maze_path(h,w-1,l))  {theArray[h][w][l] = LEFT;  return true;}
            else if (find_maze_path(h,w+1,l))  {theArray[h][w][l] = RIGHT; return true;}
            else if (find_maze_path(h-1,w,l))  {theArray[h][w][l] = UP;    return true;}
            else if (find_maze_path(h+1,w,l))  {theArray[h][w][l] = DOWN;  return true;}
            else if (find_maze_path(h,w,l-1))  {theArray[h][w][l] = OUT;   return true;}
            else if (find_maze_path(h,w,l+1))  {theArray[h][w][l] = IN;    return true;}
            else {
                theArray[h][w][l] = VISITED;
                return false;
            }
        }
    }
    bool find_maze_path() override {
        return find_maze_path(0,0,0);
    };

    /** Output maze (same order as input maze)
      @return string of 2D layers
    */
    std::string toString() const override {
        std::string theString;
        for (int k = 0; k < layer; k++){
            theString += "Layer " + std::to_string(k+1) + "\n";
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if      (theArray[i][j][k] == OPEN)    { theString += "_"; }
                    else if (theArray[i][j][k] == BLOCKED) { theString += "X"; }
                    else if (theArray[i][j][k] == VISITED) { theString += "*"; }
                    else if (theArray[i][j][k] == EXIT)    { theString += "E"; }
                    else if (theArray[i][j][k] == LEFT)    { theString += "L"; }
                    else if (theArray[i][j][k] == RIGHT)   { theString += "R"; }
                    else if (theArray[i][j][k] == UP)      { theString += "U"; }
                    else if (theArray[i][j][k] == DOWN)    { theString += "D"; }
                    else if (theArray[i][j][k] == IN)      { theString += "I"; }
                    else if (theArray[i][j][k] == OUT)     { theString += "O"; }
                    else { theString += std::to_string(theArray[i][j][k]); }
                    theString += " ";
                }
                theString += "\n";
            }
        }
        return theString;
    };

};

#endif //LAB7_3DMAZE_MAZE_H
