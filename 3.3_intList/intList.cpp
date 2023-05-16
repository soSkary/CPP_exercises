#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <limits>
#include <vector>

const int getIntCount()
{
    int returnCount {};
    while (true)
    {
        std::cout << "How many integers do you want to input? ";
        std::cin >> returnCount;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            return returnCount;
    }
}

std::vector<int> getIntList (const int count)
{
    std::vector<int> returnList(count);
    for (int index {0}; index < count; ++index)
    {
        while (true)
        {
            std::cout << "Please give an int value for element at index " << index << ": ";
            std::cin >> returnList.at(index);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            if (!std::cin)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
                break;
        }
    }
    return returnList;
}
void printMode(std::vector<int>& intList)
{
    
    int maxCount{ 0 };
    int currentCount{ 0 };
    std::vector<int> maxNumber{ intList.at(0) };        //the number(s) to output as the mode needs to be an array, as there could be several modes
    int currentNumber{ intList.at(0) };
    bool severalModes { false };                        //this is maybe a bit superfluous, only for correct suffix and preposition (mode is/modes are)
    std::vector<int> numbersTested( intList.size() );   //this is to save numbers already tested, to minimize extra looping
    for (int i {0}; i < intList.size(); ++i)
    {
        currentNumber = intList.at(i);
        currentCount = 1;
        if (std::find(numbersTested.begin(), numbersTested.end(), currentNumber) == numbersTested.end())
        {
            for (int j {i+1}; j < intList.size(); ++j)
            {
                if (currentNumber == intList.at(j))
                {
                    ++currentCount;
                }
            }
            numbersTested.push_back(currentNumber);
            if (currentCount > maxCount)
            {
                maxCount = currentCount;
                maxNumber.clear();
                maxNumber.push_back( currentNumber );
                severalModes = false;
            }
            else if (currentCount == maxCount)
            {
                maxNumber.push_back(currentNumber);
                severalModes = true;
            }
        }
    }
    if (!severalModes)
    std::cout << "The mode is:\t\t" << maxNumber.at(0) << '\n';
    else
    {
        std::cout << "The modes are:\t\t";
        for (auto element: maxNumber)
        {
            std::cout << element << ' ';
        }
        std::cout << '\n';
    }
}
void printListStats (std::vector<int>& intList)
{
   
    int sum{ std::accumulate(intList.begin(),intList.end(), 0) } ;
    std::cout << "The sum is:\t\t" << sum << '\n';
    
    double average{ static_cast<double>(sum) / static_cast<double>(intList.size()) };
    std::cout << "The average is:\t\t" << std::fixed << std::setprecision(1) << average << '\n';
    
    //as the mode gets a bit complicated, it warranted it's own function
    printMode( intList );
   
    auto largest{ std::max_element( intList.begin(), intList.end()) };
    std::cout << "The largest value:\t" << *largest << '\n';
    
    auto smallest{ std::min_element(intList.begin(), intList.end()) };
    std::cout << "The smallest value:\t" << *smallest << '\n';
    
    std::cout <<  "The difference between min and max: \t" << *largest - *smallest << '\n';
}

int main ()
{
    const int intCount {getIntCount()};
    std::vector<int> intList{getIntList(intCount)};
    printListStats(intList);
}