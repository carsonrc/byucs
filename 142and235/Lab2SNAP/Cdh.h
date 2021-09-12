//
// Created by carso on 8/10/2021.
//

#ifndef LAB2SNAP_CDH_H
#define LAB2SNAP_CDH_H

class Cdh {
private:
    string courseID;
    string day;
    string time;

public:
    Cdh() = default;
    Cdh(string course, string day, string time) {
        this->courseID = course;
        this->day = day;
        this->time = time;
    }
    ~Cdh() = default;

    string getCourseID() {
        return courseID;
    }
    string getDay() {
        return day;
    }
    string getTime() {
        return time;
    }

    string toString() {
        string theString;
        theString = "cdh(" + courseID + "," + day + "," + time;
        //theString.pop_back();
        theString.pop_back();
        return theString;
    }

};


#endif //LAB2SNAP_CDH_H
