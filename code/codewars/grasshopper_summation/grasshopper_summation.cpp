/*

brief:

Summation
Write a program that finds the summation of every number from 1 to num. The number will always be a positive integer greater than 0. Your function only needs to return the result, what is shown between parentheses in the example below is how you reach that result and it's not part of it, see the sample tests.

For example (Input -> Output):

2 -> 3 (1 + 2)
8 -> 36 (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8)

*/

// sol 1 i came up with - increments from 0 to num

// #include <iostream> // just to view the output from the program

// int summation(int num) // function is declared, returning int type
// {
//     int sum = 0;                   // initializes sum to be equal to 0 so it can be concatenated to
//     for (int i = 1; i <= num; i++) // for i (1) to until i surpasses num, add 1 to i
//         sum += i;                  // sum plus the value of i

//     return sum;
// }

// int main()
// {
//     int output = summation(6);

//     std::cout << output;
//     return 0;
// }

// sol 2 i came up with - goes backwards from num to 0

#include <iostream>

int summation(int num)
{
    int sum = num;
    for (int i = num - 1; i >= 0; i--)
        sum += i;

    return sum;
}

int main()
{
    int output = summation(6);

    std::cout << output;
    return 0;
}

/* community solution:

int summation(int num){
 return num*(num+1)/2;
}

*/