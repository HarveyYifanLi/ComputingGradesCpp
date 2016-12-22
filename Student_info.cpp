#include "Student_info.h"
#include "grade.h"
#include <stdexcept>
/* #include <iostream> */   
 
using std::istream;
using std::vector;
using std::domain_error;
/* using std::cout; */    
 
// we are interested in sorting the Student_info object by the student's name
bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}
 
// modified the following function
//    now read student's name, and compute the overall_grade directly.
//    Store only the student's name and final_grade to the Student_info object
//    we use local variable to handle the rest
 
istream& read(istream& is, Student_info& s)
{
    double midterm;
    double final;
    vector<double> homework;
 
    is >> s.name >> midterm >> final;
 
    // read and store all the student's homework scores (to the temporary vector<double> container)
    read_hw(is, homework);
 
    // compute the student's overall score, and store to the Student_info object
    try
    {
        s.final_grade = grade(midterm, final, homework);
    }
    catch (domain_error e)
    {
        s.final_grade = -1;  // indicating student has done no homework
    }
    return is;
}
 
// read homework grades from an input stream into a vector<double>

istream& read_hw(istream& in, vector<double>& hw)
{
    if (in)
    {
        // get rid of previous contents
        hw.clear();
 
        // read homework grades
        double x;
        while (in >> x)
            hw.push_back(x);
 
        // clear the stream so that input will work for the next student
        in.clear();
    }
    return in;
}