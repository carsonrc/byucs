#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//place function prototypes here...
double CalcRectanglePerimeter(double height, double width);

double DoubleRectanglePerimeter(double& height, double& width);

void PrintRectanglePerimeter(double height, double width);

double CalcCircumferenceOfCircle(double radiusCircle);

double CalcAreaOfCircle(double radiusCircle);

double CalcVolumeOfSphere(double radiusSphere);

void Swap(int& valueA, int& valueB);

void Swap(double& valueA, double& valueB);

//global variable
const double PI = 3.14;

//main function
int main(){
    cout << "Getting this line to print earns you points!" << endl;

    double height = 0;
    double width = 0;
    double radius = 0;

    int testA = 5;
    int testB = 6;

    cin >> height >> width >> radius;

    PrintRectanglePerimeter(height, width);
    cout << CalcRectanglePerimeter(height, width) << endl;
    cout << "... about to double height and width..." << endl;
    DoubleRectanglePerimeter(height, width);
    PrintRectanglePerimeter(height, width);
    cout << endl;

    //swap test
    Swap(testA, testB);
    cout << testA << "   " << testB;

    return 0;
}
//custom function definitions
double CalcRectanglePerimeter(double height, double width) {
    return (2 * height) + (2 * width);
}

double DoubleRectanglePerimeter(double& height, double& width) {
    height = height * 2;
    width = width * 2;
    double newRectanglePerimeter = CalcRectanglePerimeter(height, width);
    return newRectanglePerimeter;
}

void PrintRectanglePerimeter(double height, double width) {
    double rectanglePerimeter = CalcRectanglePerimeter(height, width);
    cout << fixed << setprecision(1) << "A rectangle with height " << height << " and width " << width << " has a perimeter of "
         << rectanglePerimeter << ".";
}

double CalcCircumferenceOfCircle(double radiusCircle) {
    return 2 * radiusCircle * PI;
}

double CalcAreaOfCircle(double radiusCircle){
    return radiusCircle * radiusCircle * PI;
}

double CalcVolumeOfSphere(double radiusSphere){
    return (4.0 / 3.0) * PI * radiusSphere * radiusSphere * radiusSphere;
}

void Swap(int& valueA, int& valueB){
    int holdValueA;
    holdValueA = valueA;
    valueA = valueB;
    valueB = holdValueA;
}

void Swap(double& valueA, double& valueB){
    double holdValueA;
    holdValueA = valueA;
    valueA = valueB;
    valueB = holdValueA;
}


