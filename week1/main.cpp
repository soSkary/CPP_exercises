
#include "customFunc.h"

#include <iostream>






int main ()
{


    auto studentGroup{ createStudentGroup() };
    createGroupMembers(studentGroup);
    

    std::cout << "Student group size: " << studentGroup.size() << '\n';

    for (auto& s : studentGroup)
    {
        std::cout << s << '\n';
    }
    std::cout << '\n';

    std::cout << "The best student(s) in the group: ";
    printBestStudents(studentGroup);
    std::cout << '\n';
    
    std::cout << "The average grade of the group was: " << getGroupAverageGrade(studentGroup) << '\n';

    return 0;
}
