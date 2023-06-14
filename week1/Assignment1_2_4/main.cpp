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

int main()
{
    using namespace std::chrono_literals;
    
    const auto start{ get_current_time() };
    std::this_thread::sleep_for(5000ms);
    const auto end{ get_current_time() };

    const auto elapsed{ calculate_elapsed_time(start, end) };

    std::cout << "Start: " << start << '\n';
    std::cout << "End: " << end << '\n';
    std::cout << "Elapsed: ";
    print_minutes_seconds(elapsed);

}


