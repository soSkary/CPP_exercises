#include "weather.h"
#include "utility_functions.h"

#include <chrono>
#include <ctime>
#include <iostream>

void weather_loop(Weather& weather)
{
    while (true)
    {
        std::cout << "\n\nWEATHER STATION XYZ\n"
            << "Input action:\n"
            << "1) Simulate weather reading\n"
            << "2) Input manual weather reading\n"
            << "3) Print logs from file\n"
            << "4) Exit\n\n";
        int choice{ get_user_int() };
        switch (choice)
        {
        case 1:
            try
            {
                simulate_weather_change(weather);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            break;
        case 2:
            try
            {
                manual_weather_reading(weather);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            break;
        case 3:
            try
            {
                print_logs();
            }
            catch (const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            break;
        case 4:
        std::cout << "Exiting weather station! Bye!\n";
            return;
        default:
            break;
        }
    }
}

int main()
{

    
    //Get the current time and save it to weather
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    std::time_t date_and_time = std::chrono::system_clock::to_time_t(now);

    //Create a Weather and log it to file
    Weather weather{ date_and_time, 26.7, 85, 4, 1040 };
    log_weather(weather);

    //Start user_loop
    weather_loop(weather);

    return 0;

}
