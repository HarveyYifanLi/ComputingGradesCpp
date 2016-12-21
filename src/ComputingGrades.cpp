//============================================================================
// Name        : ComputingGrades.cpp
// Author      : Yifan Li
// Version     :
// Copyright   : Your copyright notice
// Description : Read, store and manipulate some data in C++, Ansi-style
//============================================================================

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;

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
    cout << "Enter all your homework grades, " // note: strings separated by a single space will
                                               // be concatenated.
            "followed by end-of-file: ";

    // the number and sum of grades read so far
    int count = 0 ;
    double sum = 0.0;

    // a variable into which to read
    double x;

    // invariant:
    //    we have read count grades so far, and
    //    sum is the sum of the first count grades
    //    after entering the last value, hit the F6 button, then enter (to indicate end of file)
    //    or hit Ctrl+z, then enter,
    // in fact any input value other than the type of doube will terminate the read in the while loop.
    while (cin >> x) // The condition/subject of the while will be true,
                    // if the read procedure succeeds, and also then x will hold the value we just read.
                   // equivalent to do cin >> x first and then do test while(cin),again, cin will be converted to the
                  // value of true when the read succeed.
    {
        ++count;
        sum += x;
    }

    //double dummy = count; // for some reason the code fails unless I add this line.

    // write the result
    streamsize out_prec = cout.precision(); // Store the value of the precision of the original output
                                          // so that we can reset it once we finished outputing

     cout << "Your final grade is " << setprecision(3)
          << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
          << setprecision(out_prec) << endl; // reset the original output precision

    return 0;
}
