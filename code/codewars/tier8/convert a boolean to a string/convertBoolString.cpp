/* brief

Implement a function which convert the given boolean value into its string representation.

Note: Only valid inputs will be given.

*/

#include <string>
#include <iostream>

std::string boolean_to_string(bool b)
{
    if (b)
        return "true";
    return "false";
}

int main(int argc, char const *argv[])
{
    std::cout << boolean_to_string(true);
    std::cout << boolean_to_string(false);
    std::cout << boolean_to_string(false);
    std::cout << boolean_to_string(true);
    return 0;
}

/* community solution

#include <string>

std::string boolean_to_string(bool b){
  return b ? "true" : "false"; // ternary operator
}

*/