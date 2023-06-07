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

std::string reverse_string(const std::string& str);

bool password_verifier(const std::string& password);

std::vector<Student> create_student_group();
std::string get_name();
int get_age();
int get_grade();
void create_group_members(std::vector<Student>& student_group);
double get_group_average_grade(std::vector<Student>& student_group);
std::vector<std::string> get_best_students(std::vector<Student>& student_group);
void print_best_students(std::vector<Student>& student_group);

#endif
