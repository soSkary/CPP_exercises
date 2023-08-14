#include <atomic>
#include <chrono>
#include <iostream>
#include <mutex>
#include <stop_token>
#include <string>
#include <thread>
#include <vector>

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
void read_user_input(log& log_file, std::stop_source st_source)
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

    st_source.request_stop();
}

//function to be run on a separate thread to log the time passing
void log_message_every_second(log& log_file, std::stop_source st_source)
{
    using namespace std::chrono_literals;

    std::stop_token st_token{ st_source.get_token() };

    int elapsed{ 0 };
    std::string text{ "Seconds elapsed: "};
    while (!st_token.stop_requested())
    {
        std::this_thread::sleep_for(1s);
        ++elapsed;
        std::scoped_lock s_lock{ log_file.log_mutex };
        log_file.data.push_back(text + std::to_string(elapsed));
    }
}


int main()
{
    std::stop_source st_source;
    
    log log_file;
    {
        std::jthread thread1{ read_user_input, std::ref(log_file), st_source };
        std::jthread thread2{ log_message_every_second, std::ref(log_file), st_source };
    }

    return 0;
}
