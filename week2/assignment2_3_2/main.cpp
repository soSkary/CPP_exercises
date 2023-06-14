
#include "sensor_data.h"

int main()
{
    std::vector<Sensor_reading> reading_simulation1{simulate_data_ingestion(10)};
    std::cout << "Initial data dump:\n\n";
    print_data(reading_simulation1);

    std::vector<Sensor_reading> filtered_data1{filter_data_per_id(reading_simulation1, "sensor1")};
    std::cout << "\n\nFiltered data on 'sensor1':\n\n";
    print_data(filtered_data1);

    std::cout << "\n\nFiltered data sorted descending on timestamp:\n\n";
    sort_data_time_descending(filtered_data1);
    print_data(filtered_data1);

    std::cout << "\n\nFiltered data sorted ascending on timestamp:\n\n";
    sort_data_time_ascending(filtered_data1);
    print_data(filtered_data1);

    std::cout << "\n\nCheck for outliers:\n\n";
    check_for_outliers(reading_simulation1);

    return 0;

}
