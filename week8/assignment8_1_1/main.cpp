#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <numeric>
#include <string>
#include <vector>

template <typename T>
bool elements_in_contiguous_memory(const T& container)
{
   
    //Create two pointers to the first element in the container
    auto ptr{ &(*container.begin()) };
    auto prev_ptr{ ptr };

    //If container has 0 or 1 element, return true.
    if (container.size() < 2)
    {
        return true;
    }
    //In a loop, move pointer to next element in container, 
    //and check if there's 1 between element and previous element
    auto it{ container.begin() };
    ++it;
    for (; it != container.end(); ++it)
    {
        ptr = &(*it);

        //If the elements aren't in contiguous memory, return false
        if (ptr - prev_ptr != 1)
        {
            return false;
        }
        prev_ptr = ptr;
    }
    //If the loop is done, return true
    return true;
}

template <typename T>
void fill_container(T& container)
{
    std::iota(container.begin(), container.end(), 0);
}

int create_integer()
{
    return 1;
}

int create_integer_2()
{
    return 2;
}

void print_vec_addresses(const std::vector<int>& int_vec)
{
    std::cout << "Address of vector itself: " << &int_vec << '\n';
    for (int i{ 1 }; const auto& element: int_vec)
    {
        std::cout << i << "): " << &element
            << " sizeof(element): " << sizeof(element) << '\n';
        ++i;
    }
    std::cout << "int_vec.size(): " << int_vec.size()
        << "\nint_vec.capacity(): " << int_vec.capacity() << '\n';
        std::cout << "sizeof(int_vec): " << sizeof(int_vec) << '\n';
}

int main()
{
    //Exercise 1

    std::cout << "\nEXERCISE 1\n\n";
    int integer{ 1 };

    std::cout << "int integer{1} memory address: " << &integer << '\n';

    int integer_2{ create_integer() };
 
    std::cout << "int integer{2} memory address: " << &integer_2 << '\n';

    std::cout << "The difference between the addresses &integer_2 - &integer = "
        << (&integer_2 - &integer) << '\n';

    std::cout << "The address of the function create_integer(): " 
    << (reinterpret_cast<void*>(&create_integer)) << '\n';
    std::cout << "The address of the function create_integer_2(): " 
        << (reinterpret_cast<void*>(&create_integer_2)) << '\n';

    //Exercise 2

    std::cout << "\nEXERCISE 2\n\n";

    std::vector<int> int_vec(10);

    print_vec_addresses(int_vec);

    /*
    The address of the container and it's elements differs, as the container
    itself is stored on the stack, while it's elements are in the heap.
    */


    
    /*
    The vector itself, is of the same size on the stack, independent of it's contents.
    Just an experiment.
    */

    //Exercise 3

    std::cout << "\nEXERCISE 3\n\n";

    std::list<int> int_list1000(1000);
    std::deque<int> int_deque1000(1000);
    std::vector<int> int_vec1000(1000);
    std::array<int, 1000> int_array1000;

    fill_container(int_list1000);
    fill_container(int_deque1000);
    fill_container(int_vec1000);
    fill_container(int_array1000);

    std::list<int> int_list1000000(1000000);
    std::deque<int> int_deque1000000(1000000);
    std::vector<int> int_vec1000000(1000000);
    //std::array<int, 1000000> int_array1000000;

    fill_container(int_list1000000);
    fill_container(int_deque1000000);
    fill_container(int_vec1000000);
    //fill_container(int_array1000000);

    std::list<int> int_list10000000(10000000);
    std::deque<int> int_deque10000000(10000000);
    std::vector<int> int_vec10000000(10000000);
    //std::array<int, 10000000> int_array10000000;

    fill_container(int_list10000000);
    fill_container(int_deque10000000);
    fill_container(int_vec10000000);
    //fill_container(int_array10000000);

    

    std::cout << std::boolalpha << "int_list1000's element are int contiguous memory: "
        << elements_in_contiguous_memory(int_list1000) << '\n';
    
    std::cout << std::boolalpha << "int_deque1000's element are int contiguous memory: "
        << elements_in_contiguous_memory(int_deque1000) << '\n';

    std::cout << std::boolalpha << "int_vec1000's element are int contiguous memory: "
        << elements_in_contiguous_memory(int_vec1000) << '\n';

    std::cout << std::boolalpha << "int_array1000's element are int contiguous memory: "
        << elements_in_contiguous_memory(int_array1000) << '\n';


    std::cout << std::boolalpha << "int_list1000000's element are int contiguous memory: "
        << elements_in_contiguous_memory(int_list1000000) << '\n';

    std::cout << std::boolalpha << "int_deque1000000's element are int contiguous memory: "
        << elements_in_contiguous_memory(int_deque1000000) << '\n';

    std::cout << std::boolalpha << "int_vec1000000's element are int contiguous memory: "
        << elements_in_contiguous_memory(int_vec1000000) << '\n';

    // std::cout << std::boolalpha << "int_array1000000's element are int contiguous memory: "
    //     << elements_in_contiguous_memory(int_array1000000) << '\n';



    std::cout << std::boolalpha << "int_list10000000's element are int contiguous memory: "
        << elements_in_contiguous_memory(int_list10000000) << '\n';

    std::cout << std::boolalpha << "int_deque10000000's element are int contiguous memory: "
        << elements_in_contiguous_memory(int_deque10000000) << '\n';

    std::cout << std::boolalpha << "int_vec10000000's element are int contiguous memory: "
        << elements_in_contiguous_memory(int_vec10000000) << '\n';

    // std::cout << std::boolalpha << "int_array10000000's element are int contiguous memory: "
    //     << elements_in_contiguous_memory(int_array10000000) << '\n';




    std::cout << "Push one element to front of deque and check again\n";
    int_deque1000.push_front(0);

    std::cout << std::boolalpha << "int_deque10's element are int contiguous memory: "
        << elements_in_contiguous_memory(int_deque1000) << '\n';
    

    //Exercise 4

    std::cout << "\nEXERCISE 4\n\n";

    std::vector<std::vector<int>> vec_int_vecs1000(1000);

    std::cout << std::boolalpha << "vec_int_vecs1000's element are int contiguous memory: "
        << elements_in_contiguous_memory(vec_int_vecs1000) << '\n';
    
    return 0;
}
