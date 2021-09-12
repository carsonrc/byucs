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
    return name + " has a GPA of " + to_string(gpa);
}
string GetUserString(const std::string& prompt) {
    std::string userAnswer = "none";

    std::cout << prompt;
    std::getline(std::cin, userAnswer);
    std::cout << std::endl;
    return userAnswer;
}

int main() {
    vector<Student*> students;
    string userName = "none";
    double userGpa = 0.0;
    int userIndex = 0;
    string userMenuChoice = "none";
    bool continueMenuLoop = true;

    while (continueMenuLoop) {

        userMenuChoice = GetUserString("Enter Option: ");

        if (userMenuChoice == "add") {
            cout << "Student name: " << endl;
            getline(cin, userName);
            cout << userName << "'s GPA: " << endl;
            cin >> userGpa;
            cin.ignore();
            auto* studentPtr = new Student;
            studentPtr->SetName(userName);
            studentPtr->SetGPA(userGpa);
            students.push_back(studentPtr);
        }
        else if(userMenuChoice == "print") {
            for (int i = 0; i < students.size(); i++) {
                cout << i << ": " << students[i]->ToString() << endl;
            }
            cout << endl;
        }

        else if (userMenuChoice == "drop") {
            cout << "Index of student to drop: " << endl;
            cin >> userIndex;
            cin.ignore();
            auto userPtr = students[userIndex];
            delete userPtr;
            students.erase(students.begin() + userIndex);

        }
        else if (userMenuChoice == "quit"){
            continueMenuLoop = false;
        }
    }

    return 0;
}