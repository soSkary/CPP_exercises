#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

static int sum_result{ 0 };
std::atomic_int atomic_sum_result{ 0 };

std::mutex m;


void atomic_add(int increment, int times)
{
    for (int i{ 0 }; i < times; ++i)
    {
        atomic_sum_result += increment;
    }
}

void add_with_lock(int increment, int times)
{

    std::scoped_lock s_lock{ m };
    
    for (int i{ 0 }; i < times; ++i)
    {
        sum_result += increment;
    }
    
}

void add(int increment, int times)
{
    for (int i{ 0 }; i < times; ++i)
    {
        sum_result += increment;
    }
}

void hello()
{
    std::cout << "Hello ";
}

void world()
{
    std::cout << "world!\n";
}

int main()
{
    //Exercise 1
    std::cout << "Exercise 1\n\n";
    {
        std::jthread thread1{ hello };
        std::jthread thread2{ world };        
    }

    /*
    As these are ran in parallel, there's no guaranteed order.
    So sometimes, world() is called before hello().
    */


    //Exercise 2

    std::cout << "\nExercise 2\n\n";

    {
        std::vector<std::jthread> thread_vec(100);
        
        for (auto& elem : thread_vec)
        {
            elem = std::jthread{add, 5, 5};
        }
    
    }
    std::cout << "sum_result after multi threading (with race conditions) add(int, int) a hundred times: " << sum_result << '\n';
    std::cout << "Set sum_result to zero and do the same computation on a single thread.\n";

    sum_result = 0;
    
    for (int i{ 0 }; i < 100; ++i)
    {
        add(5, 5);
    }
    std::cout << "sum_result after add(int, int) a hundred times on a single thread: " << sum_result << '\n';

    /*
    I think the difference occurs, as we access the same static resource in parallel,
    so the tracked value can't keep up with the calls.
    */

    //Exercise 3 - using lock guard
    std::cout << "\nExercise 3\n\n";
    sum_result = 0;

    {
        std::vector<std::jthread> thread_vec(100);

        for (auto& elem: thread_vec)
        {
            elem = std::jthread{ add_with_lock, 5, 5 };
        }
        
    }

    std::cout << "The same exercise as above, but using scoped_lock: " << sum_result << '\n';

    //Exercise 4 - using atomic
    std::cout << "\nExercise 4\n\n";
    
    {
        std::vector<std::jthread> thread_vec(100);

        for (auto& elem: thread_vec)
        {
            elem = std::jthread{ atomic_add, 5, 5 };
        }
        
    }
    std::cout << "The same exercise as above, but using atomic_int: " << atomic_sum_result << '\n';


    return 0;


}

