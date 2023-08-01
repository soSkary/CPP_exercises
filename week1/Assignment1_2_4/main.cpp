#include <chrono>
#include <iostream>
#include <thread>       //for delaying system


std::time_t get_current_time()
{
    return { std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) };
}

std::time_t calculate_elapsed_time(const std::time_t start, const std::time_t stop)
{
    return stop - start;
}

void print_minutes_seconds(const std::time_t time)
{
    std::cout << time / 60 << " minutes " << time % 60 << " seconds\n";
}

void print_local_time(std::time_t system_time)
{
    std::tm* local_time{localtime(&system_time)};
    std::cout << "Time and date: " << std::asctime(local_time);
}

int main()
{
    
    
    const auto start{ get_current_time() };
    print_local_time(start);
    
    
    std::this_thread::sleep_for(std::chrono::seconds(5));
    
    const auto end{ get_current_time() };
    print_local_time(end);

    const auto elapsed{ calculate_elapsed_time(start, end) };
    std::cout << "Elapsed time: ";
    print_minutes_seconds(elapsed);

    return 0;
}


