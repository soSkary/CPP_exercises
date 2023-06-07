#include "customFunc.h"

#include <algorithm>            //for std::any_of
#include <cctype>               //for std::isupper and std::islower
#include <iostream>
#include <limits>               //for numeric_limits

std::string reverse_string(const std::string& str)
{
    if (str.size() == 1 || str.empty())
    {
        return str;
    }
    else
    {
        std::string return_string{};
        for (auto revIt{ str.rbegin()}; revIt != str.rend(); ++revIt)
        {
            return_string.push_back( *revIt );
        }
        return return_string;
    }
}

bool password_verifier(const std::string& password)
{
    //Various if statements, and if all passed, password is valid and return true, else return false

    if (password.size() < 8)
    {
        return false;
    }
    //Check if none of characters is uppercase
    else if (!std::any_of(password.begin(), password.end(), [](unsigned char c) {
        return std::isupper(c);}
    ))
    {
        return false;
    }
    //Check if none of characters is lowercase
    else if (!std::any_of(password.begin(), password.end(),
        [](unsigned char c) {return std::islower(c);}
    ))
    {
        return false;
    }
    //Check if none of characters is numeric
    else if (!std::any_of(password.begin(), password.end(),
        [](unsigned char c) {return std::isdigit(c);}
    ))
    {
        return false;
    }
    //Check if none of characters is special character
    else if (!std::any_of(password.begin(), password.end(),
        [](unsigned char c) {return std::ispunct(c);}
    ))
    {
        return false;
    }
    else
    {
        return true;
    }
}

std::string get_name()
{
    std::string name{};
    while (true)
    {
        std::cout << "Please insert name: ";
        std::cin >> name;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }
    return name;
}
int get_age()
{
    int age{};
    while (true)
    {
        std::cout << "Please insert age: ";
        std::cin >> age;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin || age < 1 || age > 120 )
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }
    return age;
}
int get_grade()
{
    int grade{};
    while (true)
    {
        std::cout << "Please insert grade between 4 and 10: ";
        std::cin >> grade;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin || grade < 4 || grade > 10 )
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }
    return grade;
}

//Create a group of students according to user input
std::vector<Student> create_student_group()
{
    std::size_t groupSize{};
    
    while (true)
    {
        std::cout << "Please input size of student group: ";
        std::cin >> groupSize;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
        std::vector<Student> student_group( groupSize );
        return student_group;
    }
}
//Overload << operator to print students
std::ostream& operator<<(std::ostream& ostream, Student& student)
{
    ostream << "Name: " << student.name << "\tAge: " << student.age << "\tGrade: " << student.grade;
    return ostream;
}
//Fill group with students input from user
void create_group_members(std::vector<Student>& student_group)
{
    if (student_group.size() == 0)
    {
        std::cout << "The group is empty!!!\n";
        return;
    }
        for (int i{ 0 }; i < student_group.size(); ++i)
    {
        
        std::cout << "Insert information for student number: " << i+1 << '\n';
        student_group.at(i) = { get_name(), get_age(), get_grade() };
        std::cout << '\n';
    }
    
}

double get_group_average_grade(std::vector<Student>& student_group)
{
    if (student_group.size() == 0)
    {
        std::cout << "The group is empty!!!\n";
        return {};
    }
    else if (student_group.size() == 1)
    {
        return static_cast<double>( student_group.at(0).grade );
    }
    else
    {
        
        double sum_of_grades{ 0 };
        for (const auto& student : student_group)
        {
            sum_of_grades += student.grade;
        }
        return sum_of_grades / static_cast<double>(student_group.size());
    }
}
//Get list of students with best grade
std::vector<std::string> get_best_students(std::vector<Student>& student_group)
{
    if (student_group.size() == 0)
    {
        std::cout << "The group is empty!!!\n";
        return {};
    }
    else if (student_group.size() == 1)
    {
        return { student_group.at(0).name };
    }
    else
    {
        
        std::vector<std::string> best_students{};
        int maxGrade{ student_group.at(0).grade };

        for (const auto& student : student_group)
        {
            if (student.grade > maxGrade)
            {
                best_students.clear();
                best_students.push_back(student.name);
                maxGrade = student.grade;
            }
            else if (student.grade == maxGrade)
            {
                best_students.push_back(student.name);
            }
            else
            {}
        }
        return best_students;
    }    
}
//Function for printing best students
void print_best_students(std::vector<Student>& student_group)
{
    std::vector<std::string> best_students{};
    best_students = get_best_students(student_group);

    for (const auto& student : best_students)
    {
        std::cout << student << ", ";
    }
}
