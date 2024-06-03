## CPP code snippets to help keep track through different stages

```cpp
#include <iostream>
#include <fstream>

int main()
{
    // create an object of type fstream

    std::fstream fileHandler;

    fileHandler.open("testt.txt"); // opening file

    fileHandler << "sample text"; // file has to be in the same folder as the output to let it access it

    fileHandler.close(); // to close file

    return 0;
}
```

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // create an object of type fstream

    std::fstream fileHandler;

    fileHandler.open("testt.txt");

    // fileHandler << "sample text3"; // to write into it

    if (!fileHandler.is_open())
    {
        std::cerr << "error opening file \n";
        return 1;
    }

    std::cout << "File opened properly \n";

    std::string line;

    std::cout << "File Content: \n";
    while (getline(fileHandler, line))
    {
        std::cout << line << std::endl;
    }

    fileHandler.close();

    return 0;
}

```

creates file but does not write to it

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main()
{

    std::fstream fileHandler;

    fileHandler.open("testt.txt", std::fstream::in | std::fstream::out | std::fstream::app);

    if (!fileHandler.is_open())
    {
        std::cerr << "error opening file \n";
        return 1;
    }

    std::cout << "File opened properly \n";

    std::string line;

    std::cout << "File Content: \n";

    while (getline(fileHandler, line))
    {
        std::cout << line << std::endl;
    }

    // pointer to the end of the file

    fileHandler.seekg(0, fileHandler.end);

    fileHandler << "sample text1\n";
    fileHandler << "sample text2\n";
    fileHandler << "sample text3\n";

    fileHandler.close();

    return 0;
}

```

to create file with content using ofstream - ofstream is used to create and write into file

```cpp
#include <iostream>
#include <fstream>
#include <string>

// ofstream create and write to files
// ifstream read files
// fstream create read write files

int main()
{
    // Create and open a text file
    std::ofstream MyFile("filename.txt");

    // Write to the file
    MyFile << "Files can be tricky, but it is fun enough!";

    // Close the file
    MyFile.close();
}
```

creating reading appending reading file:

```cpp

#include <iostream>
#include <fstream>
#include <string>

// ofstream create and write to files
// ifstream read files
// fstream create read write files

int main()
{
    // // Create and open a text file
    std::ofstream createFile("filename.txt");

    // // Write to the file
    createFile << "Files can be tricky, but it is fun enough!";

    // // Close the file
    createFile.close();

    // Create a text string, which is used to output the text file
    std::string myText;

    // Read from the text file
    std::ifstream readFile("filename.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(readFile, myText))
    {
        // Output the text from the file
        std::cout << myText;
    }

    // Close the file
    readFile.close();

    std::ofstream appendFile("filename.txt", std::ios::app); // opening file in append mode

    appendFile << "\ntest demo test!";

    appendFile.close();

    return 0;
}

```
