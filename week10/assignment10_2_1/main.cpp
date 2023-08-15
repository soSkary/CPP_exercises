// #include <cstdint>
// #include <iostream>

// struct vector_xyz
// {
//     int32_t x_pos;
//     int32_t y_pos;
//     int32_t z_pos;

//     bool operator==(const vector_xyz&) const = default;

//     vector_xyz& operator+=(const vector_xyz& other)
//     {
//         x_pos += other.x_pos;
//         y_pos += other.y_pos;
//         z_pos += other.z_pos;

//         return *this;
//     }

// };



// struct planet
// {

//     planet(int x, int y, int z) : coordinates{ x,y,z } {}
    
//     vector_xyz coordinates;
//     vector_xyz velocity{ 0,0,0 };

//     vector_xyz original_coordinates;

//     bool back_to_initial()
//     {
//         return coordinates == original_coordinates;
//     }

//     void calculate_velocity(planet& other)
//     {
//         if (other.coordinates.x_pos > coordinates.x_pos)
//         {
//             --other.velocity.x_pos;
//             ++velocity.x_pos;
//         }
//         else if (other.coordinates.x_pos < coordinates.x_pos)
//         {
//             ++other.velocity.x_pos;
//             --velocity.x_pos;
//         }
        
//         if (other.coordinates.y_pos > coordinates.y_pos)
//         {
//             --other.velocity.y_pos;
//             ++velocity.y_pos;
//         }
//         else if (other.coordinates.y_pos < coordinates.y_pos)
//         {
//             ++other.velocity.y_pos;
//             --velocity.y_pos;
//         }
        
//         if (other.coordinates.z_pos > coordinates.z_pos)
//         {
//             --other.velocity.z_pos;
//             ++velocity.z_pos;
//         }
//         else if (other.coordinates.z_pos < coordinates.z_pos)
//         {
//             ++other.velocity.z_pos;
//             --velocity.z_pos;
//         }
//     }
    

    
// };

//     void calculate_velocity(planet& a, planet& b, planet& c, planet& d, planet& e )
//     {
//         a.calculate_velocity(b);
//         a.calculate_velocity(c);
//         a.calculate_velocity(d);
//         a.calculate_velocity(e);

//         b.calculate_velocity(c);
//         b.calculate_velocity(d);
//         b.calculate_velocity(e);
        
//         c.calculate_velocity(d);
//         c.calculate_velocity(e);
        
//         d.calculate_velocity(e);
//     }
// int main()
// {
//     planet a{ 0, 5, 2 };
//     planet b{ -10, 7, -94 };
//     planet c{ 6042, 4, 8 };
//     planet d{ -42, 55, 92 };
//     planet e{ 0, -54189072, 0 };

//     uint32_t steps{ 1 };

//     a.original_coordinates = a.coordinates;
//     b.original_coordinates = b.coordinates;
//     c.original_coordinates = c.coordinates;
//     d.original_coordinates = d.coordinates;
//     e.original_coordinates = e.coordinates;


//     calculate_velocity(a, b, c, d, e);


//     a.coordinates += a.velocity;
//     b.coordinates += b.velocity;
//     c.coordinates += c.velocity;
//     d.coordinates += d.velocity;
//     e.coordinates += e.velocity;

//     while (!(a.back_to_initial() && b.back_to_initial() && c.back_to_initial() && d.back_to_initial() && e.back_to_initial()))
//     {
        
//         calculate_velocity(a, b, c, d, e);
        
//         a.coordinates += a.velocity;
//         b.coordinates += b.velocity;
//         c.coordinates += c.velocity;
//         d.coordinates += d.velocity;
//         e.coordinates += e.velocity;

//         ++steps;
//     }

//     std::cout << "steps: " << steps << '\n';
    
//     return 0;
// }


#include <array>
#include <cstdint>
#include <future>
#include <iostream>
#include <numeric>
#include <thread>


constexpr auto lcm(auto x, auto... xs)
{
    return ((x = std::lcm(x, xs)), ...);
}

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

void new_coordinates(std::array<int32_t, 5>& pos_arr, const std::array<int32_t, 5>& vel_arr)
{
    pos_arr.at(0) += vel_arr.at(0);
    pos_arr.at(1) += vel_arr.at(1);
    pos_arr.at(2) += vel_arr.at(2);
    pos_arr.at(3) += vel_arr.at(3);
    pos_arr.at(4) += vel_arr.at(4);
}

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
    count_promise.set_value(steps);
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


    

    std::cout << "steps: " << lcm(x_future.get()*2, y_future.get()*2, z_future.get()*2) << '\n';


    return 0;
}


