#include <iostream>
#include <vector>

namespace grid_2d {
    
    template <typename T>
    class grid_2d
    {
    public:
        
        using value_type = typename T::value_type;
        using reference = typename T::reference;
        using const_reference = typename T::const_reference;
        using iterator = std::vector<T>::iterator;
        using const_iterator = std::vector<T>::const_iterator;
        using difference_type = std::vector<T>::difference_type;
        using size_type = std::vector<T>::size_type;
        using storage_type = std::vector<T>;

        std::size_t width{3};
        std::size_t height{3};

        std::size_t position;
        T& at(std::size_t x, std::size_t y)
        {
            return data.at(x * width + y);
        }

        friend std::ostream& operator<<(std::ostream& out, const grid_2d& grid);

    private:
        std::vector<T> data{1,2,3,4,5,6,7,8,9};
    };

    // template <typename T>
    // T& grid_2d::at(std::size_t x, std::size_t y)
    // {
    //     return data.at(x * width + y);
    // }

    std::ostream& operator<<(std::ostream& out, const grid_2d& grid)
    {
        for (int counter{ 0 }; const auto& element: grid.data)
        {
            out << element << ' ';
            ++counter;

            if (counter == width)
            {
                out << '\n';
                counter = 0;
            }
        }
        return out;
    }
}



int main()
{
    grid_2d::grid_2d grid{};

    std::cout << grid;

    return 0;

}
