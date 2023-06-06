#include <iostream>
#include <limits>           //for std::numeric_limits

void printFibonacciSeq(const int howMany)
{
    int previous {1};
    int previousPrevious {0};
    
    std::cout << "First " << howMany << " numbers of the Fibonacci sequence:\n\n";
    std::cout << previousPrevious << ' ' << previous << ' ';
    int current {};

    for (int counter {2}; counter <= howMany; ++counter)
    {
        current = previous + previousPrevious;
        std::cout << current << ' ';
        previousPrevious = previous;
        previous = current;

    }
}
int getNumberOfRounds()
{
    int howMany{};
    while (true)
    {
        std::cout << "How many numbers of the Fibonacci sequence do you want? ";
        std::cin >> howMany;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else 
            return howMany;
    }

}

int main ()
{
    int howManyNumbers{getNumberOfRounds()};
    printFibonacciSeq(howManyNumbers);
}