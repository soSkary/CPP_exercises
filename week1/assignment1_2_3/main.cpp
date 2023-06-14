
#include "customFunc.h"

#include <iostream>






int main ()
{


    auto student_group{ create_student_group() };
    create_group_members(student_group);
    

    std::cout << "Student group size: " << student_group.size() << '\n';

    for (auto& s : student_group)
    {
        std::cout << s << '\n';
    }
    std::cout << '\n';

    std::cout << "The best student(s) in the group: ";
    print_best_students(student_group);
    std::cout << '\n';
    
    std::cout << "The average grade of the group was: " << get_group_average_grade(student_group) << '\n';

    return 0;
}
