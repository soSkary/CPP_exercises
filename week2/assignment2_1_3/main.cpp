/*
You are teaching a programming course and you have many exercises that require peer reviews.
The system that is hosting these exercises has broken
and the automatic peer review assignment is not working.
Write a program that lists all the students, and when the program gets run
it will automatically create a peer review list
where every student gets to review someone else's exercise.

Each student will review another person and two students can't review each others assignments.
*/
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>



//Create a random number for seeding
std::random_device rd;
//Get 8 random integers for our seed
std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
//Initialize Mersenne Twister with the seeder
std::mt19937 mt{ ss };



//Enumeration of students
enum Students
{
    Anna,
    Elisa,
    Heidi,
    Juho,
    Karri,
    Kirsi,
    Mikko,
    Oskar,
    Ville,

    max_students
};

void print_student(Students student)
{
    switch (student)
    {
        case Anna:
            std::cout << "Anna";
            break;
        case Elisa:
            std::cout << "Elisa";
            break;
        case Heidi:
            std::cout << "Heidi";
            break;
        case Juho:
            std::cout << "Juho";
            break;
        case Karri:
            std::cout << "Karri";
            break;
        case Kirsi:
            std::cout << "Kirsi";
            break;
        case Mikko:
            std::cout << "Mikko";
            break;
        case Oskar:
            std::cout << "Oskar";
            break;
        case Ville:
            std::cout << "Ville";
            break;
        default:
            std::cout << "Error! Undefined student!";
            break;
    }
}

void shuffle_students(std::vector<Students>& students)
{
    std::shuffle(students.begin(), students.end(), mt);
}

void print_student_reviews(const std::vector<Students>& students)
{
    for (std::size_t i {0}; i < students.size()-1; ++i)
    {
        print_student(students.at(i));
        std::cout << "\twill review\t";
        print_student(students.at(i + 1));
        std::cout << ".\n";
    }
    print_student(students.at(students.size()-1));
    std::cout << "\twill review\t";
    print_student(students.at(0));
    std::cout << ".\n";
}

int main()
{
    
    //Create a vector of students
    std::vector<Students> students(static_cast<std::size_t>(max_students));

    //Populate the vector with students
    for (std::size_t i{0}; i < students.size(); ++i)
    {
        students.at(i) = static_cast<Students>(i);
    }

    //Shuffle the student group
    shuffle_students(students);

    //Print the reviewers and reviewees
    print_student_reviews(students);

    return 0;
}

