#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "weather.h"


TEST_CASE("Testing weather app")
{
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    std::time_t date_and_time = std::chrono::system_clock::to_time_t(now);

    Weather weather{ date_and_time, 25.0, 88, 9, 1050 };
    simulate_weather_change(weather);
    CHECK(weather.m_temperature <= 28.0);
    CHECK(weather.m_temperature >= 22.0);
    CHECK(weather.m_humidity <= 99);
    CHECK(weather.m_wind_speed >= 0);
    CHECK(weather.m_atmospheric_pressure <= 1055);
};
