#ifndef GRID_2D_HPP
#define GRID_2D_HPP

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <utility>

namespace grid_2d {

    template <typename T>
    class grid_2d
    {
    public:
        using storage_type = std::vector<T>;
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using iterator = storage_type::iterator;
        using const_iterator = storage_type::const_iterator;
        using difference_type = storage_type::difference_type;
        using size_type = storage_type::size_type;

        grid_2d() = default;

        grid_2d(size_type row_count, size_type col_count)
            : rows{ row_count }, columns{ col_count }, data_container(row_count* col_count) {}

        grid_2d(size_type row_count, size_type col_count, storage_type values) : rows{ row_count }, columns{ col_count }
        {
            if ((row_count * col_count) != values.size())
                throw std::runtime_error("row_count * col_count doesn't match with initalizing vector.size()");
            data_container = values;
        }

        //copy
        grid_2d(const grid_2d&) = default;
        grid_2d& operator=(const grid_2d&) = default;

        //move
        grid_2d(grid_2d&& other) = default;
        grid_2d& operator=(grid_2d&& other) = default;

        ~grid_2d() = default;

        iterator begin();
        iterator end();

        T& back() { return *(end() - 1); }
        T& front() { return *begin(); }

        bool empty() const { return data_container.empty(); }

        const_iterator cbegin() const;
        const_iterator cend() const;

        size_type size() const { return data_container.size(); }
        std::pair<size_type, size_type> size_2d() const { return { rows, columns }; }

        size_type max_size() const { return data_container.max_size(); }

        void resize(size_type new_width, size_type new_height);

        T& at(std::size_t x, std::size_t y);

        T* data();

        void fill_data();

        friend std::ostream& operator<<<T>(std::ostream& out, const grid_2d<T>& grid);

    private:
        size_type rows{ 0 };
        size_type columns{ 0 };

        storage_type data_container;

    };
    /*********************************************************************************/
    //Here 's move semantics applied by myself, but these are unnecessary at this point
    //So following the rule of 0
    /*********************************************************************************/
    // template <typename T>
    // grid_2d<T>::grid_2d(grid_2d&& other)
    //     :   data_container{ std::move(other.data_container) },
    //         rows{ std::exchange(other.rows, 0) },
    //         columns{ std::exchange(other.columns, 0)}
    // {}

    // template <typename T>
    // grid_2d<T>& grid_2d<T>::operator=(grid_2d&& other)
    // {
    //     //to prevent self-assignment, trivial in this case, but nevertheless
    //     if (this == &other)
    //         return *this;
    //     //move the values of other to *this
    //     rows = std::exchange(other.rows, 0);
    //     columns = std::exchange(other.columns, 0);
    //     data_container = std::move(other.data_container);

    //     return *this;
    // }
    /**********************************************************************************/
    template <typename T>
    T& grid_2d<T>::at(std::size_t x, std::size_t y)
    {
        if (x >= rows || y >= columns)
            throw std::runtime_error("Coordinates at.(x,y) out of bounds");

        return data_container.at(x * columns + y);
    }

    template <typename T>
    grid_2d<T>::iterator grid_2d<T>::begin()
    {
        return data_container.begin();
    }
    template <typename T>
    grid_2d<T>::iterator grid_2d<T>::end()
    {
        return data_container.end();
    }

    template <typename T>
    grid_2d<T>::const_iterator grid_2d<T>::cbegin() const
    {
        return data_container.cbegin();
    }

    template <typename T>
    grid_2d<T>::const_iterator grid_2d<T>::cend() const
    {
        return data_container.cend();
    }

    /*
    Had to comment out 0 initialization in resize, so the grid could be used with non-arithmetic types
    (i.e. new_data.at(0) = 0)
    Will have to think about a better way to do this
    */

    template <typename T>
    void grid_2d<T>::resize(grid_2d::size_type new_rows, grid_2d::size_type new_columns)
    {
        if (new_rows == rows && new_columns == columns)
        {
            return;
        }
        if (new_rows == 0 || new_columns == 0)
        {
            throw std::runtime_error("Can't resize to 0");
        }
        else
        {
            grid_2d::size_type counter{ 0 };
            grid_2d::size_type column_size_difference{ 0 };
            if (new_columns >= columns)
            {
                column_size_difference = new_columns - columns;
            }
            grid_2d::size_type current_row{ 0 };
            std::vector<T> new_data(new_rows * new_columns);

            //If more of either columns, rows or both:
            if (new_rows >= rows && new_columns >= columns)
            {
                //loop through the new data container
                for (grid_2d::size_type index{ 0 }; index < new_data.size(); ++index)
                {
                    //if there's more rows than in the old one, fill with 0
                    if (current_row >= rows)
                    {
                        new_data.at(index) = T{};
                        continue;
                    }
                    //copy over values from old to new
                    new_data.at(index) = data_container.at(current_row * columns + counter);
                    ++counter;

                    //if more values in the new than old row, fill rest with 0 
                    if (counter % columns == 0)
                    {
                        for (grid_2d::size_type i{ 0 }; i < column_size_difference; ++i)
                        {
                            ++index;
                            new_data.at(index) = T{};
                        }
                        //reset counters for keeping row logic intact
                        counter = 0;
                        ++current_row;
                    }
                }
            }
            //if more or same amount of rows, and less or same amount of columns
            else if (new_rows >= rows && new_columns <= columns)
            {
                for (grid_2d::size_type index{ 0 }; index < new_data.size(); ++index)
                {
                    if (current_row >= rows)
                    {
                        new_data.at(index) = T{};
                        continue;
                    }

                    new_data.at(index) = data_container.at(current_row * columns + counter);
                    ++counter;
                    if (counter % new_columns == 0)
                    {
                        counter = 0;
                        ++current_row;
                    }
                }
            }
            //if less or same amount of rows, but more or same amount of columns
            else if (new_rows <= rows && new_columns >= columns)
            {
                for (grid_2d::size_type index{ 0 }; index < new_data.size(); ++index)
                {

                    new_data.at(index) = data_container.at(current_row * columns + counter);
                    ++counter;
                    if (counter % columns == 0)
                    {
                        for (grid_2d::size_type i{ 0 }; i < column_size_difference; ++i)
                        {
                            ++index;
                            new_data.at(index) = T{};
                        }
                        counter = 0;
                        ++current_row;
                    }
                }
            }
            //if new is smaller by rows, columns or both
            else //(new_width <= width && new_height <= height)
            {
                for (grid_2d::size_type index{ 0 }; index < new_data.size(); ++index)
                {

                    new_data.at(index) = data_container.at(current_row * columns + counter);
                    ++counter;
                    if (counter % new_columns == 0)
                    {
                        counter = 0;
                        ++current_row;
                    }
                }
            }

            rows = new_rows;
            columns = new_columns;
            data_container = new_data;

        }

    }
    
    template <typename T>
    void grid_2d<T>::fill_data()
    {
        if constexpr (std::is_arithmetic_v<std::decay_t<T>>)
        {
            T value{ 0 };
            for (auto& element : data_container)
            {
                element = value++;
            }
        }
        else
            std::cout << "Can't fill as type not arithmetic\n";
    }

    template <typename T>
    T* grid_2d<T>::data()
    {
        if (size() == 0)
        {
            return nullptr;
        }
        return data_container.data();
    }
}


template <typename T>
std::ostream& operator<<(std::ostream& out, const grid_2d::grid_2d<T>& grid)
{
    for (std::size_t counter{ 0 }; const auto & element: grid.data_container)
    {
        out << element << ' ';
        ++counter;

        if (counter == grid.columns)
        {
            out << '\n';
            counter = 0;
        }
    }
    return out;
}

template <typename T>
inline bool operator==(const grid_2d::grid_2d<T>& a, const grid_2d::grid_2d<T>& b)
{
    return std::equal(a.cbegin(), a.cend(), b.cbegin(), b.cend());
}

template <typename T>
inline bool operator!=(const grid_2d::grid_2d<T>& a, const grid_2d::grid_2d<T>& b)
{
    return !(operator==(a, b));
}

#endif
