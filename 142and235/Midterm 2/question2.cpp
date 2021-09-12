#include <iostream>
 using namespace std;


int main() {
    double latitude = 0;
    double longitude = 0;

    cout << "Please enter the latitude of the position: " << endl;
    cout << "Please enter the longitude of the position: " << endl;

    cin >> latitude;
    cin >> longitude;

    cout << "The position is in ";

    if ((latitude <= 41.0) && (latitude >= 37.0)) {
        if ((longitude <= 114.0) && (longitude >= 109.0)) {
            cout << "Utah";
        }
        if ((longitude <= 109.0) && (longitude >= 102.0)) {
            cout << "Colorado";
        }
        else if (longitude > 114.0) {
            cout << "the West";
        }
        else if (longitude < 102.0) {
            cout << "the East";
        }
    }
    if ((latitude < 37.0) && (latitude >= 31.0)) {
        if ((longitude <= 114.0) && (longitude >= 109.0)) {
                cout << "Arizona";
            }
        if ((longitude <= 109.0) && (longitude >= 102.0)) {
            cout << "New Mexico";
        }
        else if (longitude > 114.0) {
            cout << "the West";
        }
        else if (longitude < 102.0) {
            cout << "the East";
        }
    }
    else if (latitude > 41.0) {
        cout << "the North";
    }
    else if (latitude < 31.0) {
        cout << "the South";
    }
    cout << endl;

    return 0;
}
