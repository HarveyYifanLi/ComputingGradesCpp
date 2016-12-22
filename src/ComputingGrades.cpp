//============================================================================
// Name        : ComputingGrades.cpp
// Author      : Yifan Li
// Version     :
// Copyright   : Your copyright notice
// Description : Read, store (in the type of vector<double>) and manipulate some data in C++.
//============================================================================

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
    // ask for and read the student's name
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    // ask for and read the midterm and final grades
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    // ask for the homework grades
    cout << "Enter all your homework grades (based on the 100/100 marking standard), "
            "followed by end-of-file: ";

    vector<double> homework;
    double x;
    int count = 0;
    double sum = 0.0;

    // invariant: homework contains all the homework grades read so far
    while (cin >> x){

    	++count;
        sum+=x;

        homework.push_back(x);

    }

    // check that the student entered some homework grades
    typedef vector<double>::size_type vector_size;
    vector_size size = homework.size();

    if (size == 0)
    {
        cout << endl << "Your grades must be numbers. "
                        "Please try again." << endl;
        return 1;
    }

    // sort the grades
    sort(homework.begin(), homework.end());

    // compute the median homework grade
    vector_size mid = size/2;
    double median = size % 2;

    median == 0 ? (homework[mid] + homework[mid-1]) / 2
                : homework[mid];

    // compute write the final grade
    streamsize prec = cout.precision();

    cout << "Based on the Median calculation, your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * median
         << endl;
    cout << "Based on the Average calculation, your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * (sum/count)
         << setprecision(prec)  << endl;

    return 0;
}
