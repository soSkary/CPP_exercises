#include "grid_2d.hpp"


int main()
{
    grid_2d::grid_2d<int> grid(5,5);
    grid.fill_data();

    std::cout << "front() " << grid.front() << " back() " << grid.back() << '\n';
    std::cout << "Grid 5x5:\n";
    std::cout << grid;
    std::cout << "size " << grid.size() << "\n\n";

    grid_2d::grid_2d<int> grid2{grid};

    std::cout << std::boolalpha << "grid == grid2: " << (grid == grid2) << "\n\n";
    std::cout << std::boolalpha << "grid != grid2: " << (grid != grid2) << "\n\n";

    grid_2d::grid_2d<int> a{ grid };
    a.resize(7, 5);
    std::cout << "Grid 7x5:\n";
    std::cout << a;
    std::cout << "size " << a.size() << "\n\n";
    
    std::cout << std::boolalpha << "grid == a: " << (grid == a) << "\n\n";
    std::cout << std::boolalpha << "grid != a: " << (grid != a) << "\n\n";

    grid_2d::grid_2d<int> b{ grid };
    b.resize(5, 7);
    std::cout << "Grid 5x7:\n";
    std::cout << b;
    std::cout << "size " << b.size() << "\n\n";
    
    grid_2d::grid_2d<int> c{ grid };
    c.resize(3, 5);
    std::cout << "Grid 3x5:\n";
    std::cout << c;
    std::cout << "size " << c.size() << "\n\n";
    
    grid_2d::grid_2d<int> d{ grid };
    d.resize(5, 3);
    std::cout << "Grid 5x3:\n";
    std::cout << d;
    std::cout << "size " << d.size() << "\n\n";
    
    grid_2d::grid_2d<int> e{ grid };
    e.resize(7,7);
    std::cout << "Grid 7x7:\n";
    std::cout << e;
    std::cout << "size " << e.size() << "\n\n";
    
    grid_2d::grid_2d<int> f{ grid };
    f.resize(3, 3);
    std::cout << "Grid 3x3:\n";
    std::cout << f;
    std::cout << "size " << f.size() << "\n\n";

    std::cout << "f.max_size(): " << f.max_size() << '\n';

    std::cout << "f.at(0,0) = 333\n";
    f.at(0, 0) = 333;
    std::cout << f;
    std::cout << '\n';


    return 0;

}
