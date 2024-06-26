
/*

brief

You were camping with your friends far away from home, but when it's time to go back, you realize that your fuel is running out and the nearest pump is 50 miles away! You know that on average, your car runs on about 25 miles per gallon. There are 2 gallons left.

Considering these factors, write a function that tells you if it is possible to get to the pump or not.

Function should return true if it is possible and false if not.

*/

#include <cstdint> // header for 8, 16, 32, 64 bit integers
#include <iostream>

bool zero_fuel(uint32_t distance_to_pump, uint32_t mpg, uint32_t fuel_left) // bool function taking in 3 params
{
    if (fuel_left * mpg >= distance_to_pump) // simple comparison calc
        return true;
    return false;
}

int main(int argc, char const *argv[])
{
    std::cout << zero_fuel(50, 25, 2);
    std::cout << zero_fuel(60, 10, 4);
    return 0;
}

/* community solution

bool zero_fuel(uint32_t distance_to_pump, uint32_t mpg, uint32_t fuel_left)
{
  return mpg * fuel_left >= distance_to_pump;
}

*/