#include <cstdint>
#include <iostream>


struct vector_xyz
{
    int32_t x_pos;
    int32_t y_pos;
    int32_t z_pos;

    vector_xyz& operator+=(const vector_xyz& other)
    {
        x_pos += other.x_pos;
        y_pos += other.y_pos;
        z_pos += other.z_pos;

        return *this;
    }

    bool operator==(const vector_xyz& other)
    {
        return (x_pos == other.x_pos && y_pos == other.y_pos && z_pos == other.z_pos);
    }

    bool operator!=(const vector_xyz& other)
    {
        return !(*this == other);
    }
    
};

std::ostream& operator<<(std::ostream& out, const vector_xyz& vec_xyz)
{
    out << "( " << vec_xyz.x_pos << ", " << vec_xyz.y_pos << ", " << vec_xyz.z_pos << " )";
    return out;
}

struct planet
{

    planet(int x, int y, int z) : coordinates{ x,y,z } {}
    vector_xyz coordinates;
    vector_xyz velocity{ 0,0,0 };

    vector_xyz original_coordinates;

    bool done{ false };

    bool back_to_initial()
    {
        return coordinates == original_coordinates;
    }

    void calculate_velocity(const vector_xyz& others_coordinates)
    {
        if (others_coordinates.x_pos > coordinates.x_pos)
        {
            ++velocity.x_pos;
        }
        else if (others_coordinates.x_pos < coordinates.x_pos)
        {
            --velocity.x_pos;
        }
        
        if (others_coordinates.y_pos > coordinates.y_pos)
        {
            ++velocity.y_pos;
        }
        else if (others_coordinates.y_pos < coordinates.y_pos)
        {
            --velocity.y_pos;
        }
        
        if (others_coordinates.z_pos > coordinates.z_pos)
        {
            ++velocity.z_pos;
        }
        else if (others_coordinates.z_pos < coordinates.z_pos)
        {
            --velocity.z_pos;
        }
    }
    
    void calculate_velocity(vector_xyz& a, vector_xyz& b, vector_xyz& c, vector_xyz& d)
    {
        calculate_velocity(a);
        calculate_velocity(b);
        calculate_velocity(c);
        calculate_velocity(d);
    }

    
};

int main()
{
    planet a{ 0, 5, 2 };
    planet b{ -10, 7, -94 };
    planet c{ 6042, 4, 8 };
    planet d{ -42, 55, 92 };
    planet e{ 0, -54189072, 0 };

    uint32_t steps{ 1 };

    a.original_coordinates = a.coordinates;
    b.original_coordinates = b.coordinates;
    c.original_coordinates = c.coordinates;
    d.original_coordinates = d.coordinates;
    e.original_coordinates = e.coordinates;

    a.calculate_velocity(b.coordinates, c.coordinates, d.coordinates, e.coordinates);
    b.calculate_velocity(a.coordinates, c.coordinates, d.coordinates, e.coordinates);
    c.calculate_velocity(b.coordinates, a.coordinates, d.coordinates, e.coordinates);
    d.calculate_velocity(b.coordinates, c.coordinates, a.coordinates, e.coordinates);
    e.calculate_velocity(b.coordinates, c.coordinates, d.coordinates, a.coordinates);
    
    a.coordinates += a.velocity;
    b.coordinates += b.velocity;
    c.coordinates += c.velocity;
    d.coordinates += d.velocity;
    e.coordinates += e.velocity;

    while ((!a.done) || (!b.done) || (!c.done) || (!d.done) || (!e.done))
    
    {


        

        // std::cout << "a current coordinates:\t" << a.coordinates << " a current velocity:\t" << a.velocity << '\n';
        // std::cout << "b current coordinates:\t" << b.coordinates << " b current velocity:\t" << b.velocity << '\n';
        // std::cout << "c current coordinates:\t" << c.coordinates << " c current velocity:\t" << c.velocity << '\n';
        // std::cout << "d current coordinates:\t" << d.coordinates << " d current velocity:\t" << d.velocity << '\n';
        // std::cout << "e current coordinates:\t" << e.coordinates << " e current velocity:\t" << e.velocity << '\n';
        // std::cout << '\n';
        a.calculate_velocity(b.coordinates, c.coordinates, d.coordinates, e.coordinates);
        b.calculate_velocity(a.coordinates, c.coordinates, d.coordinates, e.coordinates);
        c.calculate_velocity(b.coordinates, a.coordinates, d.coordinates, e.coordinates);
        d.calculate_velocity(b.coordinates, c.coordinates, a.coordinates, e.coordinates);
        e.calculate_velocity(b.coordinates, c.coordinates, d.coordinates, a.coordinates);
        
        a.coordinates += a.velocity;
        b.coordinates += b.velocity;
        c.coordinates += c.velocity;
        d.coordinates += d.velocity;
        e.coordinates += e.velocity;

        ++steps;
        
        if (a.done == false && a.back_to_initial())
        {
            a.done = true;
            std::cout << "a done: " << steps << '\n';
        }
        if (b.done == false && b.back_to_initial())
        {
            b.done = true;
            std::cout << "b done: " << steps << '\n';
        }
        if (c.done == false && c.back_to_initial())
        {
            c.done = true;
            std::cout << "c done: " << steps << '\n';
            
        }
        if (d.done == false && d.back_to_initial())
        {
            d.done = true;
            std::cout << "d done: " << steps << '\n';
            
        }
        if (e.done == false && e.back_to_initial())
        {
            e.done = true;
            std::cout << "e done: " << steps << '\n';
        }

    }

    return 0;
}




    


