/*

brief:

Write function bmi that calculates body mass index (bmi = weight / height2).

if bmi <= 18.5 return "Underweight"

if bmi <= 25.0 return "Normal"

if bmi <= 30.0 return "Overweight"

if bmi > 30 return "Obese"

*/

#include <string>
#include <iostream>

std::string bmi(double w, double h)
{
    double bmi = w / (h * h);
    if (bmi <= 18.5)
        return "Underweight";
    else if (bmi <= 25.0)
        return "Normal";
    else if (bmi <= 30.0)
        return "Overweight";
    else
        return "Obese";
}

int main()
{
    std::string result = bmi(80, 1.80);

    std::cout << result;

    return 0;
}

// simple comparison of bmi calculation with bmi's using else if statements
// matched community majority solution