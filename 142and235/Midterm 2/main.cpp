#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    vector<int> userInput;
    for (auto i = userInput.begin(); i < userInput.end(); ++i) {
        cin >> *i;
    }

    for (int i = 0; i < userInput.at(2); i++) {
        for (int j = 0; j < userInput.at(1); j++) {
            cout << fixed << setprecision(3) << right << setw(9) << showpoint << targetArray[i][j];
            if (((j + 1) % 10) != 0){
                cout << ",";
            }
            if (((j + 1) % 10) == 0) {
                cout << endl;
            }
        }
    }