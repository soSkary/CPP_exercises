#ifndef CUSTOMFUNC_H
#define CUSTOMFUNC_H

#include <iostream>
#include <string>
#include <vector>

struct Student
{
    std::string name;
    int age;
    int grade;

    friend std::ostream& operator<<(std::ostream& ostream, Student& student);
};

std::string reverseString(const std::string& str);

bool passwordVerifier(const std::string& password);

std::vector<Student> createStudentGroup();
std::string getName();
int getAge();
int getGrade();
void createGroupMembers(std::vector<Student>& studentGroup);
double getGroupAverageGrade(std::vector<Student>& studentGroup);
std::vector<std::string> getBestStudents(std::vector<Student>& studentGroup);
void printBestStudents(std::vector<Student>& studentGroup);

#endif
