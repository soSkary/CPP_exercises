
#include "customFunc.h"

#include <iostream>
#include <iomanip> //for std::boolalpha





int main ()
{

    //Testing passwordVerifier()
    std::string shouldfail0{"!T0osho"};
    std::string shouldfail1{"n0upperc@se"};
    std::string shouldfail2{"N0LOWERC@SE"};
    std::string shouldfail3{"NoNumbers!"};
    std::string shouldfail4{"NoSpeci4lChars"};

    std::string validPass{"@#Th1sSh0uldDo!!!"};

    std::cout << std::boolalpha;
    std::cout << "Testing shouldfail0:\t" << shouldfail0 << "\t\t" << passwordVerifier(shouldfail0) << '\n';
    std::cout << "Testing shouldfail1:\t" << shouldfail1 << "\t\t" << passwordVerifier(shouldfail1) << '\n';
    std::cout << "Testing shouldfail2:\t" << shouldfail2 << "\t\t" << passwordVerifier(shouldfail2) << '\n';
    std::cout << "Testing shouldfail3:\t" << shouldfail3 << "\t\t" << passwordVerifier(shouldfail3) << '\n';
    std::cout << "Testing shouldfail4:\t" << shouldfail4 << "\t\t" << passwordVerifier(shouldfail4) << '\n';

    std::cout << "Testing vaildPass:\t" << validPass << "\t" << passwordVerifier(validPass) << '\n';
    
    return 0;
}
