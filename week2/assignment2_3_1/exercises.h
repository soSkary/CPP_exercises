

#include <array>
#include <vector>
#include <string>
#include <utility>

void sort_arr(std::array<int, 10>& arr);
void sort_arr(std::vector<int>& arr);
void sort_arr(std::vector<double>& arr);
void sort_arr(std::vector<std::string>& arr);
void sort_arr(std::vector<std::pair<std::string, int>>& arr);

void sort_arr_maintain_relative_order(std::vector<std::pair<std::string, int>>& arr);
void sort_arr_string_size(std::vector<std::string>& arr);

void sort_arr_descending(std::array<int, 10>& arr);
void sort_arr_descending(std::vector<int>& arr);

std::vector<int> create_sorted_arr(const std::vector<int>& arr);
std::vector<int> find_top_five(const std::vector<int>& arr);

void print_arr(const std::array<int, 10>& arr);
void print_arr(const std::vector<double>& arr);
void print_arr(const std::vector<int>& arr);
void print_arr(const std::vector<std::string>& arr);
void print_arr(const std::vector<std::pair<std::string, int>>& arr);
