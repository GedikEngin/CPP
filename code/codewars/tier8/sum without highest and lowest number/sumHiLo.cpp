/*
brief:

Task
Sum all the numbers of a given array ( cq. list ), except the highest and the lowest element ( by value, not by index! ).

The highest or lowest element respectively is a single element at each edge, even if there are more than one with the same value.

Mind the input validation.
*/

#include <vector>
#include <iostream>
using namespace std;

int sum(vector<int> numbers)
{
    if (numbers.size() <= 1)
        return 0;

    int sum = 0;
    int highestNum = numeric_limits<int>::min(); // sets it to be the lowest numeric number possible so every number in array is larger
    int lowestNum = numeric_limits<int>::max();  // sets it to be the highest numeric number possible so every number in array is smaller

    for (const auto &num : numbers)
    {
        std::cout << num << '\n';
        if (num > highestNum)
        {
            highestNum = num;
        }

        if (num < lowestNum)
        {
            lowestNum = num;
        }

        sum += num;
    }

    // std::cout << "highest: " << highestNum;
    // std::cout << "lowest: " << lowestNum;
    return sum - highestNum - lowestNum;
}

int main()
{
    std::cout << sum({5, 6, 7, 8, 10}) << '\n';
    // std::cout << sum({14, 2, 3, 9}) << '\n';
    // std::cout << sum({14, 5, 3, 9}) << '\n';
    return 0;
}

/*

commnuity solutions 1:

#include<vector>
#include <algorithm>

using namespace std;

int sum(vector<int> numbers)
{
    std::sort(numbers.begin(), numbers.end());
    int sum=0;

    for (int i=1; i<numbers.size()-1; i++)
      sum+=numbers[i];

    return sum;
}


uses the sort lib to sort the array in ascending order and discounts the first and last elements when adding them together

#include <vector>
using namespace std;

int sum(vector<int> numbers)
{
    if (numbers.size() < 2) return 0;
    int sum = 0;
    int low = numbers[0], high = numbers[0];
    for (int n : numbers) {
      if (n < low) low = n;
      else if (n > high) high = n;
      sum += n;
    }
    return sum - high - low;
}


sets the highest and lowest values to be a part of the array, and compares them based on that so it will always be a value from the set
*/