//
// Created by carso on 8/10/2021.
//

#ifndef LAB2SNAP_CSG_H
#define LAB2SNAP_CSG_H

#include "Snap.h"

class Csg : public Snap {
private:
    string grade;
    string number;
    string courseID;

public:
    Csg() = default;
    Csg(string grade, string number,string courseID) {
        this->grade = grade;
        this->number = number;
        this->courseID = courseID;
    }

    string getNumber() {
        return number;
    }

    string getGrade() {
        //this->grade.pop_back();
        //this->grade.pop_back();
        //this->grade.pop_back();
        return grade;
    };

    string getCourseID() {
        return courseID;
    }

    string toStringC() {
        string theString;
        theString = "csg(" + courseID + "," + number + "," + grade;
        //theString.pop_back();
        theString.pop_back();
        return theString;
    }
};

/*friend std::ostream& operator<<(std::ostream& out, const Snap& snap) {
    out << Snap.toString() << endl;
    return out;
}*/
#endif //LAB2SNAP_CSG_H
