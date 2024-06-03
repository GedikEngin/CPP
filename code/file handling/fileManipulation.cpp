#include <iostream>
#include <fstream>
#include <string>

// ofstream create and write to files
// ifstream read files
// fstream create read write files

int main()
{
    std::ofstream appendFile("filename.txt", std::ios::app); // opening file in append mode

    appendFile << "\ntest demo test!";

    appendFile.close();

    return 0;
}