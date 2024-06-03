#include <iostream>

int searchArray(int array[], int size, int numberToSearch);

int main()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(numbers) / sizeof(numbers[0]); // calculating the size of the array (calculated by total size of numbers array/size of one number, sizeof(numbers[0]));

    int searchIndex;
    int numberToSearch;

    std::cout << "enter Element to search for: " << "\n";
    std::cin >> numberToSearch;

    searchIndex = searchArray(numbers, size, numberToSearch);

    if (searchIndex == -1)
    {
        std::cout << "Element not found";
    }

    std::cout << "Element found at index: " << searchIndex;

    return 0;
}

int searchArray(int array[], int size, int numberToSearch)
{ // linear search method

    for (int i = 0; i < size; i++)
    {
        if (array[i] == numberToSearch)
        {
            return i;
        }
    }
    return -1; // in programming -1 is used to indicate that an element was not found, it is a sentinel value
}