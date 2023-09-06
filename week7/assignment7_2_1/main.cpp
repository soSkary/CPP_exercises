#include "template_variadics.hpp"
#include <array>
#include <list>
#include <vector>

int main()
{
    std::cout << "EXERCISE 1a \n\n";
    print_1a(0, 1, 2, 3, 4, 5);

    std::cout << "\nEXERCISE 1b \n\n";
    print_1b(5, 4, 3, 2, 1, 0);

    std::cout << "\nEXERCISE 2 \n\n";
    int integer{ 4 };
    int& integer_ref{ integer };

    auto value{ sum(5,integer_ref,3,'c',"213(this is a string)",0) };
    std::cout << value << '\n';

    std::cout << "\nEXERCISE 3 \n\n";
    std::cout << "All of same type { 5, 4.2, 3, 'c', 1, 0}: " << std::boolalpha << all_of_same_type(5, 4.2, 3, 'c', 1, 0) << '\n';
    std::cout << "All of same type { 5, 'c', 3, 2, 1, 0}: " << std::boolalpha << all_of_same_type(5, 'c', 3, 2, 1, 0) << '\n';
    std::cout << "All of same type { 5, 4, 3, 2, 1, 31.5f}: " << std::boolalpha << all_of_same_type(5, 4, 3, 2, 1, 31.5f) << '\n';
    std::cout << "All of same type { 5.0, 4.0, 3.0, 2.0, 1.0, 0.0}: " << std::boolalpha << all_of_same_type(5.0, 4.0, 3.0, 2.0, 1.0, 0.0) << '\n';
    std::cout << "All of same type { 5, 4, 3, 2, 1, 0}: " << std::boolalpha << all_of_same_type(5, 4, 3, 2, 1, 0) << '\n';

    std::cout << "\nEXERCISE 4 \n\n";
    std::cout << "Product of arguments times the number of arguments (5,4,3,2,1,0) = 15 * 6: "
        << product_of_args_times_number_of_args(5, 4, 3, 2, 1, 0) << '\n';
    std::cout << "Product of arguments times the number of arguments (5.0,4.32,3,2,1,0) = 15.32 * 6: "
        << product_of_args_times_number_of_args(5.0, 4.32, 3, 2, 1, 0) << '\n';
    std::cout << "Product of arguments times the number of arguments (5,4.32,3,2,1,0) = 15.32 * 6: "
        << product_of_args_times_number_of_args(5, 4.32, 3, 2, 1, 0) << '\n';

    std::cout << "\nEXERCISE 5 \n\n";
    std::cout << "Concatenate containers: std::vector<int> {1, 2, 3 },"
        << "std::array<int, 3> {4,5,6}, std::list<int> {7,8,9}\n";
    std::vector<int> a{ 1, 2, 3 };
    std::array<int, 3> b{ 4, 5, 6 };
    std::list<int> c{ 7, 8, 9 };

    auto concatenated_container{ concatenate_containers(a,b,c)};

    for (const auto& element : concatenated_container)
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    
    return 0;
}
