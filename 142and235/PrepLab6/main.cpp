#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int PLATE_HEIGHT = 10;
const int PLATE_WIDTH = 10;
void PrintArray(double targetArray[10][10]);
void ArrayAlgorithm(double targetArray[10][10], double tempTargetArray[10][10]);

int main() {

    double maxDiff;
    double hotPlate[PLATE_HEIGHT][PLATE_WIDTH] = {0};
    double tempHotPlate[PLATE_HEIGHT][PLATE_WIDTH] = {0};
    double hotPlateDifferences[PLATE_HEIGHT - 1][PLATE_WIDTH - 1] = {0};
    ofstream outFS;
    ifstream inFS;
    int iterationCounter = 0;

    cout << "Hotplate Simulator\n" << endl;

    //populating array
    int i;
    int j;
    for (i = 0; i < PLATE_HEIGHT; ++i) {
        for (j = 1; j < PLATE_WIDTH - 1; ++j) {
            if (i == 0) {
                hotPlate[i][j] = 100;
            }
            if (i == 9) {
                hotPlate[i][j] = 100;
            }
        }
    }

    cout << "Printing the initial plate values..." << endl;
    PrintArray(hotPlate);

    //iterating algorithm
    do { //makes copy of hotplate array for algorithm
        for (i = 0; i < PLATE_HEIGHT; i++) {
            for (j = 0; j < PLATE_WIDTH; j++) {
                tempHotPlate[i][j] = hotPlate[i][j];
            }
        }

        maxDiff = 0;

        //algorithm
        ArrayAlgorithm(hotPlate, tempHotPlate);
        for (i = 1; i < PLATE_HEIGHT - 1; ++i){
            for (j = 1; j < PLATE_WIDTH - 1; ++j){
                hotPlateDifferences[i][j] = hotPlate[i][j] - tempHotPlate[i][j];
            }
        }
        for (i = 1; i < PLATE_HEIGHT - 1; i++) {
            for (j = 1; j < PLATE_WIDTH - 1; j++) {
                if (hotPlateDifferences[i][j] > maxDiff) {
                    maxDiff = hotPlateDifferences[i][j];
                }
            }
        }

        if (iterationCounter == 0){
            cout << "Printing plate after one iteration..." << endl;
            PrintArray(hotPlate);
        }

        iterationCounter++;

    } while (maxDiff > .1);
    cout << "Printing final plate..." << endl;
    PrintArray(hotPlate);

    //output to file
    cout << "Writing final plate to \"Hotplate.csv\"...\n" << endl;
    outFS.open("Hotplate.csv");
    if (!outFS.is_open()) {
        cout << "error";
        exit (0);
    }

    for (i = 0; i < PLATE_HEIGHT; i++) {
        for (j = 0; j < PLATE_WIDTH; j++) {
            outFS << fixed << setprecision(3) << left << setw(9) << showpoint << hotPlate[i][j];
        }
    }


    outFS.close();

    // input plate thing
    inFS.open("Inputplate.txt");
    if (!inFS.is_open()) {
        cout << "thumbs down";
        exit (0);
    }
    double tempArray[10][10] = {0};
    while (!inFS.eof()) {
        for (i = 0; i < PLATE_HEIGHT; ++i){
            for (j = 0; j < PLATE_WIDTH; ++j){
                inFS >> tempArray[i][j];
            }
        }
    }

    inFS.close();
    ArrayAlgorithm(hotPlate, tempArray);
    ArrayAlgorithm(hotPlate, hotPlate);
    ArrayAlgorithm(hotPlate, hotPlate);
    cout << "Printing input plate after 3 updates..." << endl;
    PrintArray(hotPlate);
    return 0;
}

void PrintArray(double targetArray[10][10]){
    int i;
    int j;
    for (i = 0; i < PLATE_HEIGHT; i++) {
        for (j = 0; j < PLATE_WIDTH; j++) {
            cout << fixed << setprecision(3) << right << setw(9) << showpoint << targetArray[i][j];
            if (((j + 1) % 10) == 0) {
                cout << endl;
            }
        }
    }
    cout << endl;
}

void ArrayAlgorithm(double targetArray[10][10], double tempTargetArray[10][10]) {
    for (int i = 1; i < PLATE_HEIGHT - 1; ++i) {
        for (int j = 1; j < PLATE_WIDTH - 1; ++j) {
            targetArray[i][j] = (tempTargetArray[i + 1][j] + tempTargetArray[i - 1][j] + tempTargetArray[i][j   + 1] + tempTargetArray[i][j - 1]) / 4.0;
        }
    }
}

