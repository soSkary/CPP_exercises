#include <atomic>
#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

std::atomic_bool keep_alive{ true };

struct log
{
    std::vector<std::string> data;
    std::mutex log_mutex;

};

//Function to print out the log file (thread safe, read-only)
void output_log_file(const log& log_file)
{
    for (const auto& string : log_file.data)
    {
        std::cout << string << '\n';
    }
}

//a function to read user input and log it
void read_user_input(log& log_file)
{
    std::string input_string;
    while (input_string != "quit")
    {
        std::getline(std::cin, input_string);
        std::scoped_lock s_lock{ log_file.log_mutex };
        if (input_string == "log")
        {
            output_log_file(log_file);
        }
            log_file.data.push_back(input_string);
    }
    keep_alive = false;
}

//function to be run on a separate thread to log the time passing
void log_message_every_second(log& log_file)
{
    using namespace std::chrono_literals;
    
    int elapsed{ 0 };
    std::string text{ "Seconds elapsed: "};
    while (keep_alive)
    {
        std::this_thread::sleep_for(1s);
        ++elapsed;
        std::scoped_lock s_lock{ log_file.log_mutex };
        log_file.data.push_back(text + std::to_string(elapsed));
    }
}


int main()
{
    log log_file;
    {
        std::jthread thread1{ read_user_input, std::ref(log_file) };
        std::jthread thread2{ log_message_every_second, std::ref(log_file) };
    }

    return 0;
}
