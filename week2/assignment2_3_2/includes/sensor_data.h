#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H



#include <iostream>
#include <string>
#include <vector>

struct Sensor_reading
{
    int m_timestamp{0};
    std::string m_sensor_id{};
    float m_sensor_value{};

    bool m_outlier_checked{ false };
    bool m_is_outlier{ false };

    Sensor_reading(const std::string& sensor_id);
    Sensor_reading() = default;

    friend std::ostream& operator<<(std::ostream& out, Sensor_reading reading);
};

std::vector<Sensor_reading> simulate_data_ingestion(const int nr_of_readings);
std::vector<Sensor_reading> filter_data_per_id(const std::vector<Sensor_reading>& data_dump, const std::string& sensor_id);

void print_data(const std::vector<Sensor_reading>& data);
void sort_data_time_ascending(std::vector<Sensor_reading>& data);
void sort_data_time_descending(std::vector<Sensor_reading>& data);
void check_for_outliers(std::vector<Sensor_reading>& data);

float get_value_mean(const std::vector<Sensor_reading>& data);
float get_absolute_difference(float a, float b);
float get_value_std_deviation(const std::vector<Sensor_reading>& data);

bool value_is_outlier(float distance, float std_deviation);


#endif 
