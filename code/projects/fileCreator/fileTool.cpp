// used to create multiple files at once, utility tool

#include <iostream>   // standard input output
#include <fstream>    // lib used for file handling
#include <algorithm>  // lib used for searching, sorting, counting etc
#include <string>     // string header
#include <array>      // array header
#include <filesystem> // file system header

// function declarations
int userChoice();

void createFromExistingList();
void createNewFileList();

int main()
{
    int userInput = userChoice();

    // default return is -1, so until a different return is made it keeps repeating
    while (userInput == -1)
    {
        std::cout << "Invalid choice. Please try again.\n";
        userInput = userChoice(); // Ask for input again
    }

    if (userInput == 0)
    {
        createFromExistingList();
    }
    else if (userInput == 1)
    {
        createNewFileList();
    }

    return 0;
}

int userChoice()
{
    std::string userInput = "-1";
    std::string validChoice[] = {"0", "1"};
    // can be expanded later to allow for more options

    int selectionSize = sizeof(validChoice) / sizeof(validChoice[0]);

    std::cout << "Create files with an existing list [0] \n";
    std::cout << "Create a new list to generate files from [1] \n";
    std::cout << "Choose an option: ";

    std::getline(std::cin, userInput); // gets the line user inputs and puts it into string

    int index = -1;

    for (int i = 0; i < selectionSize; i++)
    {
        if (userInput == validChoice[i])
        {
            index = i;
            break;
        }
    }

    return index;
};

void createFromExistingList()
{
    // creates the files based on an existing list

    std::string existingFile;
    std::string folderName;
    std::string fileExtension;
    std::string fileText;
    std::string targetFolder;

    std::cout << "What is the file name containing the list of files to create? \n";
    std::cout << "Example: fileNameList.txt \n";
    std::getline(std::cin, existingFile);

    std::ifstream fileReader(existingFile);
    if (!fileReader.is_open())
    {
        std::cerr << "Error accessing file. \n";
        return;
    }

    std::cout << "Enter the name of the folder for output:\n";
    std::getline(std::cin, folderName);

    std::filesystem::path folderPath(folderName);

    try
    {
        // Create the directory if it doesn't exist
        std::filesystem::create_directory(folderPath);
        std::cout << "Directory created successfully. \n";
    }
    catch (const std::filesystem::filesystem_error &e)
    {
        std::cerr << "Error creating directory: " << e.what() << std::endl;
        return;
    }

    targetFolder = "./" + folderName + "/";

    std::cout << "Enter the file extension (e.g., .cpp): ";
    std::getline(std::cin, fileExtension);

    std::cout << "\nFile creation starting..\n\n";

    while (getline(fileReader, fileText))
    {
        std::cout << fileText << '\n';
        std::ofstream fileCreator(targetFolder + fileText + fileExtension);
        fileCreator.close();
    }

    fileReader.close();
};

void createNewFileList()
{

    std::string fileNames;
    std::string fileExtension;
    std::string numberOfFilesStr;

    std::ofstream createAppendFile("filesToGenerateList.txt", std::ios::app);

    std::cout << "How many files will you be generating?: \n";
    std::cout << "Example: 12 \n";

    std::getline(std::cin, numberOfFilesStr);

    int numberOfFiles = stoi(numberOfFilesStr);

    std::cout << "Input the name of the file to generate? \n";
    std::cout << "Example: bubbleSearch\n";

    for (int i = 0; i < numberOfFiles; i++)
    {
        std::cout << "name of file number" << i + 1 << ": ";
        std::getline(std::cin, fileNames);
        createAppendFile << fileNames << std::endl;
    }

    createAppendFile.close();

    std::cout << "File list created, please select file to open from menu. \n";

    userChoice();
};