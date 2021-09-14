#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Csg.h"
#include "Cdh.h"
#include "Cr.h"

using namespace std;

int main(int argc, char* argv[]) {
    //opens input and output files
    if (argc < 3) {
        cerr << "Please provide name of input and output files";
        return 1;
    }
    cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);
    if (!in) {
        cerr << "Unable to open " << argv[1] << " for input";
        return 2;
    }
    cout << "Output file: " << argv[2] << endl;
    ofstream out(argv[2]);
    if (!out) {
        in.close();
        cerr << "Unable to open " << argv[2] << " for output";
        return 3;
    }

    out << "Input Strings:" << endl;
    vector<Snap> snaps;
    vector<Csg> csgs;
    vector<Cr> crs;
    vector<Cdh> cdhs;
    string inputCommand;
    string data;
    while (in){
        try {

            getline(in, inputCommand, '(');
            getline(in, data);
            istringstream ss(data);

            if (inputCommand == "snap") {
                string ID, name, address, number;

                getline(ss, ID, ',');
                getline(ss, name, ',');
                getline(ss, address, ',');
                getline(ss, number, ',');

                Snap newSnap(ID, name, address, number);
                snaps.push_back(newSnap);
            }

            else if (inputCommand == "csg") {
                string course, number, grade;

                getline(ss, course,',');
                getline(ss,number,',');
                getline(ss,grade,',');

                Csg newCsg(grade, number, course);
                csgs.push_back(newCsg);

            }

            else if (inputCommand == "cdh") {
                string course, day, time;

                getline(ss, course,',');
                getline(ss,day,',');
                getline(ss,time,',');

                Cdh newCdh(course, day, time);
                cdhs.push_back(newCdh);

            }

            else if (inputCommand == "cr") {
                string course, classroom;

                getline(ss,course,',');
                getline(ss,classroom,',');

                Cr newCr(course,classroom);
                crs.push_back(newCr);

            }
            else {throw string("**Error: ");}

        } catch (string& e) {out << e;}

        out << inputCommand << "(" << data << endl;

        if (in.peek() == EOF) { break; }

    }

    //vector outputs
    out << '\n' << "Vectors:" << endl;
    for (auto& i : snaps) {
        out << i.toString() << endl;
    }
    for (auto& i : csgs) {
        out << i.toStringC() << endl;
    }
    for (auto& i : cdhs) {
        out << i.toString() << endl;
    }
    for (auto& i : crs) {
        out << i.toString() << endl;
    }
    out << endl;

    out << "Course Grades:" << endl;
    for (auto& i : csgs) {
        out << i.getCourseID() << ",";
        for (auto& j : snaps) {
            if (i.getNumber() == j.getStudentID()) {
                out << j.getName();
            }
        }
        string grade = i.getGrade();
        //grade.pop_back();
        //grade.pop_back();
        grade.pop_back();
        grade.pop_back();

        out << ',' << grade << endl;
    }

    out << '\n' << "Student Schedules:" << endl;
    for (auto& i : snaps) {
        string number;
        number = i.getNumber();
        //number.pop_back();
        number.pop_back();
        number.pop_back();
        out << i.getName() << ", " << i.getStudentID() << ", " << i.getAddress() << ", " << number << endl;
        for (auto& j : csgs) {
            if (j.getNumber() == i.getStudentID()) {
                out << "  " << j.getCourseID() << " ";
                string theTime;
                string theClassroom;
                for (auto& k : cdhs) {
                    if (k.getCourseID() == j.getCourseID()) {
                        out << k.getDay();
                        theTime = k.getTime();
                    }
                    for (auto& l : crs) {
                        if (l.getCourseID() == k.getCourseID()) {
                            theClassroom = l.getClassroom();
                        }
                    }
                }
                //theTime.pop_back();
                theTime.pop_back();
                theTime.pop_back();
                out << " " << theTime << ",";

                //theClassroom.pop_back();
                theClassroom.pop_back();
                theClassroom.pop_back();
                out << " " << theClassroom << endl << endl;
            }
        }
    }


    return 0;
}


