//
// Created by carso on 8/10/2021.
//

#ifndef LAB2SNAP_SNAP_H
#define LAB2SNAP_SNAP_H

#include <string>
using namespace std;

class Snap {
private:
    string studentID;
    string studentName;
    string studentAddress;
    string studentPhone;

public:
    Snap() = default;
    Snap(string studentID,string studentName,string studentAddress,string studentPhone) {
        this->studentID = studentID;
        this->studentName = studentName;
        this->studentAddress = studentAddress;
        this->studentPhone = studentPhone;

        //this->studentPhone.pop_back();
        //this->studentPhone.pop_back();
        //this->studentPhone.pop_back();
    }
    ~Snap() = default;

    string getNumber(){
        return studentPhone;
    }

    string getName() {
        return studentName;
    }

    string getStudentID() {
        return studentID;
    }

    string getAddress() {
        return studentAddress;
    }


    string toString() {
        string theString;
        theString = "snap(" + studentID + "," + studentName + "," + studentAddress + "," + studentPhone;
        theString.pop_back();
        //theString.pop_back();
        return theString;
    }
};

#endif //LAB2SNAP_SNAP_H
