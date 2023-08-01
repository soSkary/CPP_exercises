
#include "sensor_data.h"

int main()
{
    std::vector<Sensor_reading> data_dump1{simulate_data_ingestion(11)};
    std::cout << "Initial data dump:\n\n";
    print_data(data_dump1);

    std::vector<Sensor_reading> filtered_data1{filter_data_per_id(data_dump1, "sensor1")};
    std::cout << "\n\nFiltered data on 'sensor1':\n\n";
    print_data(filtered_data1);

    std::cout << "\n\nFiltered data sorted descending on timestamp:\n\n";
    sort_data_time_descending(filtered_data1);
    print_data(filtered_data1);

    std::cout << "\n\nFiltered data sorted ascending on timestamp:\n\n";
    sort_data_time_ascending(filtered_data1);
    print_data(filtered_data1);

    std::cout << "\n\nCheck for outliers:\n\n";
    check_for_outliers(data_dump1);

    std::cout << "\n\nCheck for the most active sensor(s):\n\n";
    std::vector<std::string> most_active_sensors{most_frequent_sensor(data_dump1)};
    print_data(most_active_sensors);

    return 0;

}
