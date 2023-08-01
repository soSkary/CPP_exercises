#ifndef WEATHER_H
#define WEATHER_H
#include <ctime>

struct Weather
{
    std::time_t m_date_and_time;
    double m_temperature;
    int m_humidity;
    int m_wind_speed;
    int m_atmospheric_pressure;

};

void simulate_weather_change(Weather& weather);
void log_weather(const Weather& weather);
void print_logs();
void manual_weather_reading(Weather& weather);

#endif
