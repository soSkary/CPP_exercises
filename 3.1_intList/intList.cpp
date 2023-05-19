// Author Oskar Siegfrids
// A program that reads the values of integers from a comma separated file (.csv), stores them in a vector
// and prints stats related to the values.

//A 'test.csv' provided with the repository. Had some problems with MS Excel generated ones,
//as the first value didn't get recognized as a number for some reason...


#include <algorithm>    //for std::min_element, std::max_element & std::sort
#include <fstream>      //for file input
#include <iomanip>      //for manipulating output stream
#include <iostream>
#include <numeric>      //for std::accumulate
#include <limits>       //for std::numeric_limits
#include <string>       //for strings and string manipulation
#include <sstream>      //for std::stringstream
#include <vector>       //for dynamic array to store data


//accepts relative and absolute path
std::string getFilePath()
{
    std::string filePath{};

    while (true)
    {
        std::cout << "Please input the path of file to be read: ";
        std::cin >> filePath;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            return filePath;
    }
}

//read a .csv file, with ';' as the delimiter (European standard)
std::vector<int> readListFromFile(const std::string& filePath)
{
    std::fstream csvFile(filePath, std::ios::in);
    if (csvFile.is_open())
        std::cout << "Opened file: " << filePath << '\n';
    else
        {
            std::cerr << "Couldn't open file: " << filePath << '\n';
            return std::vector<int> { {0} };
        }
    std::vector<int> intList{};
    std::string readLine{};
    
    std::cout << "The values read from " << filePath << ":\n";

    while (std::getline(csvFile, readLine))
    {
        std::stringstream lineStream{ readLine };
        std::string stringValue{};
        while (std::getline(lineStream, stringValue, ';'))
        {
            intList.push_back(std::stoi(stringValue));
            std::cout << stringValue << "; ";
        }
        std::cout << '\n';
        readLine = "";
    }
    if (csvFile.is_open())
    {
        csvFile.close();
        std::cout << "Closed file: " << filePath << "\n\n\n";
    }
    return intList;
}

std::vector<int> getMode(std::vector<int>& intList)
{
    
    int maxCount{ 0 };
    int currentCount{ 0 };
    std::vector<int> maxNumber{ intList.at(0) };        //the number(s) to output needs to be an array, as there could be several modes
    int currentNumber{ intList.at(0) };
    std::vector<int> numbersTested( intList.size() );   //this is to save numbers already tested, to minimize extra looping
    for (int i {0}; i < intList.size(); ++i)
    {
        //Define a case to compare to
        currentNumber = intList.at(i);
        currentCount = 1;
        //Check if the currentNumber hasn't yet been tested for
        if (std::find(numbersTested.begin(), numbersTested.end(), currentNumber) == numbersTested.end())
        {
            for (int j {i+1}; j < intList.size(); ++j)
            {
                if (currentNumber == intList.at(j))
                {
                    ++currentCount;
                }
            }

            //Push back the current number,so it doesn't get tested again
            numbersTested.push_back(currentNumber);
            //If there are more of the currentNumber than of the previous maxNumber,
            //empty vector and current becomes max
            if (currentCount > maxCount)
            {
                maxCount = currentCount;
                maxNumber.clear();
                maxNumber.push_back( currentNumber );
            }
            //If there are as many of the current, as there's of the previous
            //add the current to the vector
            else if (currentCount == maxCount)
            {
                maxNumber.push_back(currentNumber);
            }
        }
    }
    std::sort(maxNumber.begin(), maxNumber.end());
    return maxNumber;
}

int getSum( std::vector<int>& intList )
{
    return { std::accumulate(intList.begin(),intList.end(), 0) };
}
double getAverage( double sum, double size )
{
    return { sum / size };
}
int getMin( std::vector<int>& intList )
{ 
   auto smallest{ std::min_element(intList.begin(), intList.end()) };
   return { *smallest };
}
int getMax( std::vector<int>& intList )
{
     auto largest{ std::max_element( intList.begin(), intList.end()) };
     return { *largest };
}

void printListStats (std::vector<int>& intList)
{
    if (intList.size() == 1)
    {
        std::cout << "The provided list contains only one value: " << intList.at(0) << "\n\n";
    }
    else if (!intList.empty())
    {
        int sum{ getSum( intList ) } ;
        std::cout << "The sum is:\t\t" << sum << '\n';

        std::cout << "The average is:\t\t" << std::fixed << std::setprecision(1) << getAverage(static_cast<double>(sum), static_cast<double>(intList.size())) << '\n';

        std::vector<int> mode{ getMode( intList ) };
        if (mode.size() == 1)
            std::cout << "The mode is:\t\t" << mode.at(0) << '\n';
        else
        {
            std::cout << "The modes are:\t\t";
            for (auto value: mode)
                std::cout << value << ' ';
            std::cout << '\n';
        }
        int smallest{ getMin( intList ) };
        std::cout << "The largest value:\t" << smallest << '\n';

        int largest{ getMax ( intList ) };
        std::cout << "The smallest value:\t" << largest << '\n';

        std::cout <<  "The difference between\nmax and min: \t\t" << largest - smallest << "\n\n";
    }
    else
        std::cerr << "Empty list, can't print stats!\n\n";
}

int main ()
{
    std::string filePath{ getFilePath() };
    std::vector<int> intList { readListFromFile(filePath) };
    printListStats( intList );
}