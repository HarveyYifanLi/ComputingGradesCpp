#ifndef GUARD_STUDENT_INFO_H
#define GUARD_STUDENT_INFO_H
 
// Student_info.h
#include <iostream>
#include <string>
#include <vector>
 
struct Student_info
{
    std::string name;
 
    // Exercise 4-6: no longer need to the followings in the Student_info object
    /*
    double midterm, final;
    std::vector<double> homework;
    */
 
    // Exercise 4-6: store only final_grade
    double final_grade;
};
 
bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
 
#endif // GUARD_STUDENT_INFO_H