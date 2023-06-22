
#include "weather_logs.h"

#include <chrono>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iomanip>

namespace fs = std::filesystem;

//Function for logging a weather reading to a file
void log_weather(const Weather& weather)
{
    //create a filesystem path
    fs::path path("weather_logs");
    
    //check that it exists, and is a directory
    if (!fs::exists(path) || !fs::is_directory(path))
    {
        //if not, create it
        fs::create_directory(path);
    }

    //create path for log file
    path /= "station_logs.csv";

    std::ofstream file_output;
    //check if file doesn't exist, and if not, write header file
    if (!fs::exists(path))
    {
        file_output.open(path, std::ios::out);
        if (!file_output.is_open())
        {
            throw std::runtime_error("Couldn't open file for writing");
        }
        file_output << "date_and_time,temperature,humidity,wind_speed,atmospheric_pressure\n";
    }
    else
    {
        file_output.open(path, std::ios::app);
        if (!file_output.is_open())
        {
            throw std::runtime_error("Couldn't open file for writing");
        }
    }
    //get date and time
    
    file_output << std::put_time(std::localtime(&weather.m_date_and_time), "%F-%T,")
        << weather.m_temperature << ',' << weather.m_humidity << ',' << weather.m_wind_speed
        << ',' << weather.m_atmospheric_pressure << '\n';

    file_output.close();
}

//Function for printing the saved logs to screen
void print_logs()
{
    //create a filesystem path
    fs::path path("weather_logs/station_logs.csv");
    
    //check that it exists
    if (!fs::exists(path))
    {
        throw std::runtime_error("Didn't find file weather_logs/station_logs.csv");
    }
    //open file for reading
    std::ifstream file_input(path, std::ios::in);
    //check that it's open
    if (!file_input.is_open())
    {
        throw std::runtime_error("Couldn't open file for writing");
    }

    //loop through the file and print to screen
    std::string print_output;
    while (std::getline(file_input, print_output))
    {
        std::cout << print_output << '\n';
    }

    file_input.close();
}
