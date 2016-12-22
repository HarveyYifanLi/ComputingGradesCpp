#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
/* #include <stdexcept> */ 
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"
 
using std::cin;
using std::cout;
using std::endl;
/* using std::domain_error; */  
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
 
int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;   // the length of the longest name
 
    // read and store all the student's data.
    // Invariant:   students contain all the student records read so far
    //              maxlen contains the length of the longest name in students
    while (read(cin, record))
    {
        // find the length of longest name
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }
 
    // alphabetize the student records
    sort(students.begin(), students.end(), compare);
 
    // write the names and grades
    for (vector<Student_info>::size_type i = 0;
         i != students.size(); ++i)
    {
        // write the name, padded on the right to maxlen + 1 characters
        cout << students[i].name
             << string(maxlen + 1 - students[i].name.size(), ' ');
 
        streamsize prec = cout.precision();
 
        // write the overall_grade out directly
        cout << setprecision(3)
             << students[i].final_grade
             << setprecision(prec) << endl;
    }
 
    cout << endl;
    cout << "*****************************************************************" << endl;
    cout << "*** Note: a grade of -1 implies student has done no homework. ***" << endl;
    cout << "*****************************************************************" << endl;
    return 0;
}