#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <string>
#include <limits>

//Memory Check
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif
using namespace std;

int main(int argc, char* argv[])
{
    VS_MEM_CHECK               // enable memory leak check

    //opens input and output files
    if (argc < 3)
    {
        cerr << "Please provide name of input and output files";
        return 1;
    }
    cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);
    if (!in)
    {
        cerr << "Unable to open " << argv[1] << " for input";
        return 2;
    }
    cout << "Output file: " << argv[2] << endl;
    ofstream out(argv[2]);
    if (!out)
    {
        in.close();
        cerr << "Unable to open " << argv[2] << " for output";
        return 3;
    }

    //reading from a file to determine array sizes
    int num_students, num_exams;
    in >> num_students >> num_exams;
    in.ignore(numeric_limits<int>::max(), '\n');

    // reading from a file to make array of names and a temp array to hold score strings
    string students[num_students];
    string scoresHolder[num_students];
    for (int i = 0; i < num_students; i++)
    {
        getline(in, students[i]);
        size_t p = 0;
        while (!isdigit(students[i][p])) ++p;	// line[p] is the first digit
        scoresHolder[i] = students[i];
        scoresHolder[i] = scoresHolder[i].substr(p,1000); //holds numbers in array of strings to be parsed
        students[i] = students[i].substr(0,(p));
    }

    //creating a dynamic 2D array for exam scores and filling it
    int **scores = new int*[num_students];
    for (int i = 0; i < num_students; i++)
    {
        scores[i] = new int[num_exams];
        istringstream iss(scoresHolder[i]);
        for (int j = 0; j < num_exams; j++)
        {
            iss >> scores[i][j];
        }
    }

    //output part 1- names and grades
    out << "Student Scores:" << endl;

    for (int i = 0; i < num_students; i++)
    {
        out << setw(22) << students[i] << " ";
        out << fixed << setprecision(0) << setw(6) << scoresHolder[i] << endl;
    }

    //output part 2- exam averages (calculations)
    out << "Exam Averages:" << endl;

    float averages[num_exams];
    for (int j = 0; j < num_exams; j++)
    {
        int sum = 0;
        for (int i = 0; i < num_students; i++)
        {
            sum += scores[i][j];
            averages[j] = static_cast<float>(sum); //fills array with sums of scores of each exam
        }
    }
    for (int j = 0; j < num_exams; j++)
    {
        averages[j] = averages[j] / static_cast<float>(num_students); //finds average
    }

    //output part 2- exam averages (output)
    for (int j = 0; j < num_exams; j++)
    {
        out << setw(10) << setprecision(1) << "Exam " << (j+1) << " Average = " << averages[j] << endl;
    }

    //creating a dynamic 2D array for exam letter freq and filling it
    int** letters = new int*[num_exams];
    for (int j = 0; j < num_exams; j++)
    {
        letters[j] = new int[5];   // each row of the array has 5 elements for the 5 possible letter grades
        for (int k = 0; k < 5; k++)
        {
            letters[j][k] = 0;
        }
    }


    //output part 3- student exam grades and counting number of instances of a given letter grade
    out << "Student Exam Grades:" << endl;
    char gradeLetter;
    for (int i = 0; i < num_students; i++)
    {
        out << setw(22) << students[i];
        for (int j = 0; j < num_exams; j++)
        {
            if (static_cast<float>(scores[i][j]) <= (averages[j] + 5) && static_cast<float>(scores[i][j]) >= (averages[j] - 5))
            {
                gradeLetter = 'C';
                letters[j][2]++;
            }
            else if (static_cast<float>(scores[i][j]) >= averages[j] && static_cast<float>(scores[i][j]) <= (averages[j] + 15))
            {
                gradeLetter = 'B';
                letters[j][1]++;
            }
            else if (static_cast<float>(scores[i][j]) <= averages[j] && static_cast<float>(scores[i][j]) >= (averages[j] - 15))
            {
                gradeLetter = 'D';
                letters[j][3]++;
            }
            else if (static_cast<float>(scores[i][j]) >= (averages[j] + 15))
            {
                gradeLetter = 'A';
                letters[j][0]++;
            }
            else if (static_cast<float>(scores[i][j]) <= (averages[j] - 15))
            {
                gradeLetter = 'E';
                letters[j][4]++;
            }
            out << fixed << setprecision(0) << setw(6) << scores[i][j] <<"(" << gradeLetter << ")";
        }
        out << endl;
    }

    //output part 4- letter grade totals per exam
    out << "Exam Grades:" << endl;
    for (int j = 0; j < num_exams; j++)
    {
        out << setw(10) << "Exam " << j+1;
        for (int k = 0; k < 5; k++)
        {
            out << setw(10) << letters[j][k];
            switch (k)
            {
                case 0: out << "(A)"; break;
                case 1: out << "(B)"; break;
                case 2: out << "(C)"; break;
                case 3: out << "(D)"; break;
                case 4: out << "(E)"; break;
            }
        }
        out << endl;
    }
    //output part 5- calculating final grades
    float finalGrades[num_students];
    float classAverage = 0;
    for (int i = 0; i < num_students; i++)
    {
        finalGrades[i] = 0;
        for (int j = 0; j < num_exams; j++)
        {
            finalGrades[i] += static_cast<float>(scores[i][j]);
        }
        finalGrades[i] = finalGrades[i] / static_cast<float>(num_exams);
    }
    for (int i = 0; i < num_students; i++)
    {
        classAverage += finalGrades[i];
    }
    classAverage = classAverage / static_cast<float>(num_students);


    //output part 5- Final Grades output
    out << "Student Final Grades:" << endl;
    for (int i = 0; i < num_students; i++)
    {
        out << setw(22) << students[i] << " ";
        if (finalGrades[i] < (classAverage + 5) && finalGrades[i] > (classAverage - 5))
        {
            gradeLetter = 'C';
        }
        else if (finalGrades[i] > classAverage && finalGrades[i] < (classAverage + 15))
        {
            gradeLetter = 'B';
        }
        else if (finalGrades[i] < classAverage && finalGrades[i] > (classAverage - 15))
        {
            gradeLetter = 'D';
        }
        else if (finalGrades[i] > (classAverage + 15))
        {
            gradeLetter = 'A';
        }
        else if (finalGrades[i] < (classAverage - 15))
        {
            gradeLetter = 'E';
        }
        out << fixed << setprecision(1) << setw(6) << finalGrades[i] <<"(" << gradeLetter << ")";
        out << endl;
    }

    out << "Class Average Score = " << classAverage;

    //deleting dynamic arrays
    for (int j = 0; j < num_exams; j++)
    {
        delete[] letters[j];
    }
    delete[] letters;

    for (int i = 0; i < num_students; i++)
    {
        delete[] scores[i];
    }
    delete[] scores;

    return 0;
}

