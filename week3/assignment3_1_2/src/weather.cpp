#include "weather.h"
#include "random.h"
#include "utility_functions.h"

#include <chrono>
#include <iostream>

void simulate_weather_change(Weather& weather)
{
    //For do-while loops to get appropriate random weather change
    double temperature_change;
    do
    {
        temperature_change = Random::get(-3, 3) ;
    } while (weather.m_temperature + temperature_change < -45.0 || weather.m_temperature + temperature_change > 35.0);
    weather.m_temperature += temperature_change;

    int humidity_change;
    do
    {
        humidity_change = Random::get(-10, 10);
    } while (weather.m_humidity + humidity_change < 50 || weather.m_humidity + humidity_change > 100);
    weather.m_humidity += humidity_change;

    int wind_change;
    do
    {
        wind_change = Random::get(-10, 10);
    } while (weather.m_wind_speed + wind_change < 0 || weather.m_wind_speed + wind_change > 27);
    weather.m_wind_speed += wind_change;

    int pressure_change;
    do
    {
        pressure_change = Random::get(-5, 5);
    } while (weather.m_atmospheric_pressure + pressure_change < 950 || weather.m_atmospheric_pressure + pressure_change > 1066);
    weather.m_atmospheric_pressure += pressure_change;

    //Get the current time and save it to weather
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    weather.m_date_and_time = std::chrono::system_clock::to_time_t(now);

    //Log weather reading to file
    log_weather(weather);
}

void manual_weather_reading(Weather& weather)
{
    std::cout << "Please input temperature in celsius: ";
    double temperature{ get_user_double() };
    std::cout << "Please input humidity in %: ";
    int humidity{ get_user_int() };
    std::cout << "Please input wind speed in m/s: ";
    int wind_speed{ get_user_int() };
    std::cout << "Please input atmospheric pressure in kPa: ";
    int pressure{ get_user_int() };

    if (temperature < -45.0 || temperature > 35 ||
        humidity < 50 || humidity > 100 ||
        wind_speed < 0 || wind_speed > 30 ||
        pressure < 940 || pressure > 1070)
    {
        throw std::runtime_error("Error. Given values overexceeding limits, exiting function.");
    }

    //Get the current time and save it to weather
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    weather.m_date_and_time = std::chrono::system_clock::to_time_t(now);
    weather.m_temperature = temperature;
    weather.m_humidity = humidity;
    weather.m_wind_speed = wind_speed;
    weather.m_atmospheric_pressure = pressure;

    log_weather(weather);

    std::cout << "Logged weather reading to file!\n";
}

