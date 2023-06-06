#include "customFunc.h"

#include <algorithm>            //for std::any_of
#include <cctype>               //for std::isupper and std::islower
#include <iostream>
#include <limits>               //for numeric_limits

std::string reverseString(const std::string& str)
{
    if (str.size() == 1 || str.empty())
    {
        return str;
    }
    else
    {
        std::string returnStr{};
        for (auto revIt{ str.rbegin()}; revIt != str.rend(); ++revIt)
        {
            returnStr.push_back( *revIt );
        }
        return returnStr;
    }
}

bool passwordVerifier(const std::string& password)
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

std::string getName()
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
int getAge()
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
int getGrade()
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
std::vector<Student> createStudentGroup()
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
        
        std::vector<Student> studentGroup( groupSize );
        return studentGroup;
    }
}
//Overload << operator to print students
std::ostream& operator<<(std::ostream& ostream, Student& student)
{
    ostream << "Name: " << student.name << "\tAge: " << student.age << "\tGrade: " << student.grade;
    return ostream;
}
//Fill group with students input from user
void createGroupMembers(std::vector<Student>& studentGroup)
{
    if (studentGroup.size() == 0)
    {
        std::cout << "The group is empty!!!\n";
        return;
    }
        for (int i{ 0 }; i < studentGroup.size(); ++i)
    {
        
        std::cout << "Insert information for student number: " << i+1 << '\n';
        studentGroup.at(i) = { getName(), getAge(), getGrade() };
        std::cout << '\n';
    }
    
}

double getGroupAverageGrade(std::vector<Student>& studentGroup)
{
    if (studentGroup.size() == 0)
    {
        std::cout << "The group is empty!!!\n";
        return {};
    }
    else if (studentGroup.size() == 1)
    {
        return static_cast<double>( studentGroup.at(0).grade );
    }
    else
    {
        
        double sumOfGrades{ 0 };
        for (const auto& student : studentGroup)
        {
            sumOfGrades += student.grade;
        }
        return sumOfGrades / static_cast<double>(studentGroup.size());
    }
}
//Get list of students with best grade
std::vector<std::string> getBestStudents(std::vector<Student>& studentGroup)
{
    if (studentGroup.size() == 0)
    {
        std::cout << "The group is empty!!!\n";
        return {};
    }
    else if (studentGroup.size() == 1)
    {
        return { studentGroup.at(0).name };
    }
    else
    {
        
        std::vector<std::string> bestStudents{};
        int maxGrade{ studentGroup.at(0).grade };

        for (const auto& student : studentGroup)
        {
            if (student.grade > maxGrade)
            {
                bestStudents.clear();
                bestStudents.push_back(student.name);
                maxGrade = student.grade;
            }
            else if (student.grade == maxGrade)
            {
                bestStudents.push_back(student.name);
            }
            else
            {}
        }
        return bestStudents;
    }    
}
//Function for printing best students
void printBestStudents(std::vector<Student>& studentGroup)
{
    std::vector<std::string> bestStudents{};
    bestStudents = getBestStudents(studentGroup);

    for (const auto& student : bestStudents)
    {
        std::cout << student << ", ";
    }
}
