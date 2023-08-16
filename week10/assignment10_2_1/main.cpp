#include <array>
#include <cstdint>
#include <future>
#include <iostream>
#include <numeric>
#include <thread>

//template function for least common multiplier which takes n parameters
constexpr auto lcm(auto x, auto... xs)
{
    return ((x = std::lcm(x, xs)), ...);
}

//function for calculating the velocity for one axle at a time
constexpr void calculate_velocity(const std::array<int32_t, 5>& pos_arr, std::array<int32_t, 5>& vel_arr)
{
    for (std::size_t i{ 0 }; i < pos_arr.size(); ++i)
    {
        for (std::size_t j{ i + 1 }; j < pos_arr.size(); ++j)
        {
            if (pos_arr.at(i) > pos_arr.at(j))
            {
                --vel_arr.at(i);
                ++vel_arr.at(j);
            }
            else if (pos_arr.at(i) < pos_arr.at(j))
            {
                ++vel_arr.at(i);
                --vel_arr.at(j);
            }
        }
    }
}

//function for adding the velocity to get the new positions
void new_coordinates(std::array<int32_t, 5>& pos_arr, const std::array<int32_t, 5>& vel_arr)
{
    for (std::size_t i{ 0 }; i < 5; ++i)
    {
        pos_arr.at(i) += vel_arr.at(i);
    }
}


//function to get the period for an axle, by checking when the velocity stops. 
//Then we know we're at the halfway point and can only double the value.
//Use the promise/future to get the value to main thread when done.
void period(std::array<int32_t, 5>& pos, std::array<int32_t, 5>& velocity, std::promise<int> count_promise)
{
    calculate_velocity(pos, velocity);
    new_coordinates(pos, velocity);
    
    uint32_t steps{ 1 };

    while (!(velocity == std::array<int32_t, 5>{0,0,0,0,0}))

    {
        calculate_velocity(pos, velocity);

        new_coordinates(pos, velocity);

        ++steps;

    };
    count_promise.set_value(steps*2);
}

int main()
{

    std::array<int32_t, 5> x_pos{ 0, -10, 6042, -42, 0 };
    std::array<int32_t, 5> y_pos{ 5, 7, 4, 55, -54189072 };
    std::array<int32_t, 5> z_pos{ 2, -94, 8, 92, 0 };

    std::array<int32_t, 5> x_velocity{ 0,0,0,0,0 };
    std::array<int32_t, 5> y_velocity{ 0,0,0,0,0 };
    std::array<int32_t, 5> z_velocity{ 0,0,0,0,0 };


    std::promise<int> x_promise;
    std::promise<int> y_promise;
    std::promise<int> z_promise;

    std::future<int> x_future = x_promise.get_future();
    std::future<int> y_future = y_promise.get_future();
    std::future<int> z_future = z_promise.get_future();

    std::jthread x_thread(period, std::ref(x_pos), std::ref(x_velocity), std::move(x_promise));
    std::jthread y_thread(period, std::ref(y_pos), std::ref(y_velocity), std::move(y_promise));
    std::jthread z_thread(period, std::ref(z_pos), std::ref(z_velocity), std::move(z_promise));

    std::cout << "steps: " << lcm(x_future.get(), y_future.get(), z_future.get()) << '\n';


    return 0;
}


