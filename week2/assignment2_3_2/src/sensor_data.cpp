#include "sensor_data.h"
#include "random.h"

#include <algorithm>
#include <iterator>
#include <cmath>

Sensor_reading::Sensor_reading(const std::string& sensor_id)
    : m_sensor_id{ sensor_id }, m_sensor_value{ Random::random_float_0_1(Random::mt) }
{
    static int timestamp{ 1 };
    m_timestamp = timestamp++;
    m_outlier_checked = false;
    m_is_outlier = false;
}
//Overloaded operator<< to print a Sensor_reading
std::ostream& operator<<(std::ostream& out, Sensor_reading reading)
{
    out << "Timestamp: " << reading.m_timestamp << ", Sensor_id: " << reading.m_sensor_id
        << ", Value: " << reading.m_sensor_value;
    return out;
}
//A function to simulate data ingestion - takes an int to define size of data dump
//Returns a vector of Sensor_reading
std::vector<Sensor_reading> simulate_data_ingestion(const int nr_of_readings)
{
    std::vector<Sensor_reading> return_vector(nr_of_readings);
    for (int i{ 1 }; auto& elem: return_vector)
    {
        if (i == 4)
        {
            i = 1;
        }
            elem = Sensor_reading{ "sensor" + std::to_string(i++) };
    }
    
    return return_vector;
}

//Function that takes a vector of Sensor_reading and a string
//Returns a new vector with only matching sensor_ids
std::vector<Sensor_reading> filter_data_per_id(const std::vector<Sensor_reading>& data_dump, const std::string& sensor_id)
{
    std::vector<Sensor_reading> return_vector;

    //Copy reading over, if m_sensor_id matches function parameter sensor_id
    std::copy_if(data_dump.begin(), data_dump.end(), std::back_inserter(return_vector),
        [&sensor_id](const auto& reading)
        {
            return reading.m_sensor_id == sensor_id;
        });
    return return_vector;
}
//Function to print a dataset of sensor readings
void print_data(const std::vector<Sensor_reading>& data)
{
    for (const auto& elem : data)
    {
        std::cout << elem << '\n';
    }
}

//Function to print a vector of strings
void print_data(const std::vector<std::string>& data)
{
    for (const auto& elem : data)
    {
        std::cout << elem << '\n';
    }
}

//Function to sort data ascending on timestamp
void sort_data_time_ascending(std::vector<Sensor_reading>& data)
{
    std::sort(data.begin(), data.end(),
        [](const auto& a, const auto& b)
        {
            return a.m_timestamp < b.m_timestamp;
        });
}
//Function to sort data descending on timestamp
void sort_data_time_descending(std::vector<Sensor_reading>& data)
{
    std::sort(data.begin(), data.end(),
        [](const auto& a, const auto& b)
        {
            return a.m_timestamp > b.m_timestamp;
        });
}
//Function to get the mean of sensor_values
float get_value_mean(const std::vector<Sensor_reading>& data)
{
    float sum{ 0.0f };
    for (auto const& reading : data)
    {
        sum += reading.m_sensor_value;
    }
    return sum / data.size();
}

float get_absolute_difference(float a, float b)
{
    return std::abs(a - b);
}
//Function to get standard deviation for sensor_values
float get_value_std_deviation(const std::vector<Sensor_reading>& data)
{
    float sum_of_distances_squared{ 0.0f };
    float mean{ get_value_mean(data) };
    for (const auto& reading : data)
    {
        sum_of_distances_squared += std::pow(get_absolute_difference(reading.m_sensor_value, mean), 2.0);
    }
    return std::sqrt(sum_of_distances_squared / data.size());
}
//Function checks if value is outlier
bool value_is_outlier(float distance, float std_deviation)
{
    return distance > std_deviation;
}

//A function for checking outliers
//Checks and sets the flags for m_is_outlier and m_outlier_checked accordingly
void check_for_outliers(std::vector<Sensor_reading>&data)
{
    float mean{ get_value_mean(data) };
    float std_deviation{ get_value_std_deviation(data) };
    int counter{ 0 };
    for (auto& reading : data)
    {
        if (get_absolute_difference(mean, reading.m_sensor_value) > std_deviation)
        {
            reading.m_is_outlier = true;
            std::cout << "Outlier found: " << reading << '\n';
            ++counter;
        }
        reading.m_outlier_checked = true;
    }
    std::cout << "Outliers found: " << counter << '\n';
}
//A function that checks which sensor(s) are the most active, giving out most
//sensor readings - returns a vector of strings with sensor_ids
std::vector<std::string> most_frequent_sensor(std::vector<Sensor_reading>& data)
{
    //Sort the data according to sensor_id
    std::sort(data.begin(), data.end(), [](const auto& a, const auto& b)
        {
            return a.m_sensor_id < b.m_sensor_id;
        });
    
    int max_count{ 0 };
    std::vector<std::string> max_values{};
    int current_count{ 0 };

    //Loop through the data once,  as we have ensured its sorted
    for (auto it{ data.begin() }; it != data.end();++it )
    {
        //Value to test against
        std::string current_value{it->m_sensor_id};
        
        //Fast forward and count as long as value stays the same or next is not .end()
        while ((it + 1)->m_sensor_id == current_value && (it + 1) != data.end())
        {
            ++current_count;
            ++it;

        }
        //Add the last count after while loop 
        ++current_count;
        
        //If the new count is as big as max_count, add to vector
        if (current_count == max_count)
        {
            max_values.push_back(current_value);
        }
        //If the new count is bigger than max_count, clear and add to vector
        else if (current_count > max_count)
        {
            max_values.clear();
            max_values.push_back(current_value);
            max_count = current_count;
        }
        //Reset current_count when going to next value
        current_count = 0;
    }
    return max_values;
}
