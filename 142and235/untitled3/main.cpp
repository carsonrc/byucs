#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Student {
public:
    Student(string name = "not initialized", double gpa = 0.0);
    void SetName(string studentName);
    void SetGPA(double newGPA);
    string ToString() const;
private:
    string name;
    double gpa;
};

Student::Student(string initialName, double initialGPA) {
    name = initialName;
    gpa = initialGPA;
}

void Student::SetName(string inputName) {
    name = inputName;
}

void Student::SetGPA(double newGPA) {
    gpa = newGPA;
}

string Student::ToString() const {
    string output;
    output = name + "has a GPA of " + to_string(gpa);
    return output;
}

    int main() {
        vector<Student*> students;
        string userInput;
        string nameHolder;
        double gpaHolder;
        Student* ptrStudent;

        while (userInput != "quit") {
            cout << "Enter Option: " << endl;
            cin >> userInput;

            if (userInput == "add") {
                cout << "Student name: " << endl;
                cin >> nameHolder;
                cout << nameHolder << "'s GPA: " << endl;
                cin >> gpaHolder;
                Student newStudent (nameHolder, gpaHolder);

                ptrStudent = &newStudent;
                students.push_back(ptrStudent);
            }
            if (userInput == "print") {
                for (int i = 0; i < students.size(); i++) {
                    cout << i << ": ";
                    ptrStudent = students.at(i);
                    ptrStudent->ToString();
                }
            }
            if (userInput == "drop") {
                int userIndex;
                cout << "Index of student to drop: " << endl;
                cin >> userIndex;
                delete students.at(userIndex);
                students.erase(students.begin() + userIndex);
            }
        }


        //Insert your code for main here

        return 0;
    }