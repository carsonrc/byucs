//
// Created by carso on 8/10/2021.
//

#ifndef LAB2SNAP_CR_H
#define LAB2SNAP_CR_H

class Cr {
private:
    string courseID;
    string classroom;

public:
    Cr() = default;
    Cr(string courseID,string classroom) {
        this->courseID = courseID;
        this->classroom = classroom;
    }
    ~Cr() = default;

    string getCourseID() {
        return courseID;
    }
    string getClassroom() {
        return classroom;
    }

    string toString() {
        string theString;
        theString = "cr(" + courseID + "," + classroom;
        //theString.pop_back();
        theString.pop_back();
        return theString;
    }
};

#endif //LAB2SNAP_CR_H
