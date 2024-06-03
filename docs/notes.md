# Notes for CPP

## C++ in 100 Seconds

Statically typed programming language
Higher performance of C, utilizing classes

C programs work with CPP code, as it is a super set
No overhead abstractions, oop patterns like polymorphism, encapsulation and inheritance
Used when dealing with constrained memory demands
Database systems like MySQL and MongoDB use CPP
Used in embedded systems, HMI displays, MCUs etc.
Compiler for OS and VMs use it as well due to their requirements (high performance, low resource overhead)

Users can utilize low level memory and hardware control but also benefit from high level abstract such as smart pointers and classes

Use io stream for non-embedded systems for input and output (terminal operations)

you can overload methods - same method being defined multiple times with different parameters, which is a type of polymorphism

src: https://www.youtube.com/watch?v=MNeX4EGtR5Y

#

## C++ with Bro Code

src: https://www.youtube.com/playlist?list=PLZPZq0r_RZOMHoXIcxze_lP97j2Ase2on

It is a middle level language, used with embedded systems, game graphic engines etc.
As a mid level language, they are human legible, although not to the extent of Python, but easier to interpret than assembly level.

#### namespaces

namespaces allows for the same variable name to be used and redeclared. To use a non-local version of a variable you need to prefix/preseed the version that you want to refer to.
You can specify what namespace is being used and execute code within it. Alternatively you can directly refer to it by specifying the namespace.

std stands for standard
double colon :: is used for scope resolution, specifying where to look for the variable

i.e.

```cpp

namespace first{
    int x = 10;
}

namespace second{
    int x = 20;
}

int main(){
    using std:: cout;
    using std:: string;

    int x = 0;

    std::cout << x // returns 0 as that is what x is defined as locally
    std::cout << first::x // returns 10, as that is what x is in the first name space

    using namespace second;
    std::cout << x // returns 20 as the name space that the code is instructed to use is namespace second

    return 0
}
```

explanation of std (standard):

```cpp
int main(){
    using namespace std; // usually not encouraged
    string name = "Bro Code";
    cout << "hello " << name;
}

// is the same as:

int main(){

    using std::cout; // better alternative
    using std::string;

    string name = "Bro Code";
    cout << "hello " << name;
}

```

#### typedef and type aliases

typedef is a reserved keyword in CPP that is used to create an additional name for a data type to call it by, an alias. It is meant to be used as a new identifier for a data type that already exists, serving to improve readability and reduce possible misspellings.

```cpp

#include "vector.h"

typedef std::vector<std::pair<std::string, int>> pairlist_t
// a very long data type being assigned the alias pairlist_t, where the _t serves as an indication that it is a typedef and the original data type is elsewhere

int main(){
    pairlist_t pairlist; // calling the alias of the longer datatype

    return 0;
}
```

```cpp

typedef std::string text_t

int main(){
    text_t firstName = "engin";

    std::cout << firstName << "\n";
    // this will print out first name, as it is a string but being assigned the alias text_t
}

```

although alias's should be used when there is a clear benefit/reason behind it as opposed to using them just for the sake of it.

#### type conversions

There are 2 types of type conversions, implicit and explicit.

- Implicit is done automatically
- Explicit is expects to be preceded with the new data type

```cpp

int main(){

    int x=3.14;
    std::cout << x; // will return 3 as it is x is an integer

    double x = 3.14;
    std::cout << x; // will return 3.14 as it is x is a double

    std::cout << int(3.14); // will return 3 as it is x is an integer defined explicitly

}

```

#### User inputs in C++

you can take in user inputs from terminal via:

```cpp

int main(){

    std::cout << "What is your name?";
    std::cin >> name; // will take an input for name
    std::cout << "hello " << name << "\n"; // the next line will start on a new line

    // however cin will stop reading after space, so Engin Gedik will be assigned to name as Engin
    // to account for this you can use a standard function:

    std::cout << "What is your name? \n";
    std::getline(std::cin, name);
    std::cout << "hello " << name;

    std::getline(std::cin >> std::ws, name,);
    // extraction operator - eliminates white spaces and new line characters before user input

}

```

#### Switches

Switches are an alternative to multiple else if statements, comparing one value to matching cases
you can match it with different data types such as integers or strings
having a default case means that if the item compared does not exist as a case, it will return the default case

```cpp
int main()
{
   char grade;

   std::cout << "What letter grade?: ";
   std::cin >> grade;

   switch(grade){
      case 'A':
         std::cout << "You did great!";
         break;
      case 'B':
         std::cout << "You did good";
         break;
      case 'C':
         std::cout << "You did okay";
         break;
      case 'D':
         std::cout << "You did not do good";
         break;
      case 'F':
         std::cout << "YOU FAILED!";
         break;
      default:
         std::cout << "Please only enter in a letter grade (A-F)";
   }

   return 0;
}

```

#### Ternary operators

it is another alternative to an if/else statement:
other examples of this exist, in particular with MCU projects that involve led animations

condition? expression1 : expression2

```cpp
int main()
{
    int grade = 75;

    grade>= 60 ? std::cout << "Passed" : std::cout << "Failed";

    int number = 9;
    number % 2 ? std::cout << "ODD" : std::cout << "EVEN";

    bool hungry = true;
    hungry ? std::cout << "You are hungry" : std::cout << "You are full";
}
```

#### Break and continue

break and continues are used in loops to either to skip the rest of the loop iteration or to jump to the next iteration

```cpp
int main()
{
// break = break out of a loop
// continue = skip current iteration

    // will count to 12, and then stop
    for(int i = 1; i <= 20; i++){
        if(i == 13){
            break;
        }
        std::cout << i << '\n';
    }
    return 0;

    // will skip 13 but continue list 1-12, then 14-20
    for(int i = 1; i <= 20; i++){
    if(i == 13){
        continue;
    }
    std::cout << i << '\n';
    }
    return 0;
}

```

#### Overloaded functions

functions can have multiple instances with different parameters, the different parameters are called function signatures

```cpp
void bakePizza();
void bakePizza(std::string topping1);
void bakePizza(std::string topping1, std::string topping2);

int main()
{
    bakePizza(); // will call the bakePizza function that takes in no params
    bakePizza("pepperoni"); // will call the function that has 1 param
    bakePizza("pepperoni", "mushroom"); // will call the function that has 2 params

    return 0;
}

void bakePizza(){
    std::cout << "Here is your pizza!\n";
}

void bakePizza(std::string topping1){
    std::cout << "Here is your " << topping1 << " pizza!\n";
}

void bakePizza(std::string topping1, std::string topping2){
    std::cout << "Here is your " << topping1 << " and " << topping2 << " pizza!\n";
}

```

#### Variable Scopes

local variables are variables that are defined within {}, inside functions mainly, and can only be accessed by the parent function, not externally
global variables can be accessed from anywhere and any function (assuming it is not private or protected)

#### Arrays

data structure that can hold multiple values and be accessed with its index pointer, variable containing variables
indexing starts with 0 and ends with index number - 1

```cpp

int main()
{
    std::string cars[3] = {"Corvette", "Mustang", "Camry"};

    std::cout << cars[0] << '\n';
    std::cout << cars[1] << '\n';
    std::cout << cars[2] << '\n';

    return 0;
}

```

#### sizeof() operator

determines the size if a object, variable, class, data type etc in terms of bytes

```cpp

int main(){

    double age = 20.5;
    std::cout << sizeof(age);
    // prints the size of the age variable

    cars[3] = {"Corvette", "Mustang", "Camry"};
    std::cout << sizeof(cars); // returns the size of the cars array
    std::cout << sizeof(cars/sizeof(std::string)); // returns the number of cars by dividing the size of cars by the size of a string in cars

}

```

#### Array iteration

```cpp
int main(){

    std::string cars[5] = {"Corvette", "Mustang", "Camry", "Camaro", "Hellcat"};

    for(int i = 0; i < sizeof(cars)/sizeof(std::cars[0]); i++){ // starts at 0 and ends at the number of cars (calculated by total size of cars array/size of one car)

        std::cout << cars[i] << '\n';
    }

    int carCount = 0;

    // automatically iterates through array
    for (auto i: cars){
        std::cout << i << "\n";
        carCount++;
    }
    std::cout << carCount;

    std::cout << "length of cars array is: " << end(cars)-begin(cars); // to get the number of elements in cars by subtracting the indexes from one another between the first and last element

    return 0;
}
```

to use array.size() you need to have the array be a cpp structured array as opposed to the generic c type

```cpp
int main(){

    std::array<std::string, 5> cars = {"Corvette", "Mustang", "Camry", "Camaro", "Hellcat"};

    std::cout << "number of elements in cars array is: " << cars.size(); // uses built in method to get the number of elements

    return 0;

}
```

#### Passing arrays to functions

```cpp
#include <iostream>

double getTotal(double prices[], int size); // function declaration


int main(){
    double prices[] = {49.99, 15.05, 70, 400, 8.99}; // initializing the double list
    int size = sizeof(prices)/sizeof(prices[0]); // calculating the size of the array
    double total = getTotal(prices, size); // calling getTotal func to calculate the total

    std::cout << "£" << total; // c output

    return 0;
}

double getTotal(double prices[], int size){

    double total = 0; // local total var

    for (int i = 0; i < size; ++i){ // loop iteration
        total += prices[i]; // concatenates the prices
    }

    return total; // returns total val
}

```

#### searching array for an element

```cpp

#include <iostream>

int searchArray(int array[], int size, int numberToSearch);

int main()
{
    int numbers[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    int size = sizeof(numbers/sizeof(numbers[0]));

    int searchIndex;
    int numberToSearch;

    std::cout << "enter Element to search for: " << "\n";
    std::cin >> numberToSearch;

    index = searchArray(numbers, size, numberToSearch);

    if (numbers[index] == numberToSearch){
        std::cout << "Element found at index: " << index << "\n"; // <<
    }
    else if(index == -1){
        std::cout << "Element not found";
    }

    cout << "Element found at index: " << index;

    return 0
}

int searchArray(int array[], int size, int numberToSearch){ // linear search method

    for(int i = 0; i < size; i++){
    if (array[i] == numberToSearch){
        return i;
        }
    }
    return -1; // in programming -1 is used to indicate that an element was not found, it is a sentinel value
}
```

#

## How C++ Works - The Cherno

Anything that starts with # is a preprocessor instruction. The program preloads it before executing the main code, such as including libs:

```cpp
#include "Arduino.h"
#include "FastLED.h"

// rest of the code
```

Disabling optimization allows for the debugging of the code, but optimization can be controlled via IDE or compiler options.
Header files are not compiled, they are included via the preprocessor statements (#include). Each cpp file is compiled separately, into an .obj file.
To stitch them together, you need to use the linker, putting all the compiled .cpp into .obj files, which is then put together via linker into a singular .exe file.

The error list that is outputted is usually misguiding and can contain misleading information. They might be suitable for smaller programs, but generally should be treated as a overview. For more dedicated and easier to digest errors, relying on the output window would be the better approach.

Every symbol in C++ needs to be defined.

When working with multiple files, it is important to link (linker) the files together, otherwise the compiler/C++ blindly "trusts" the code.

src: https://www.youtube.com/watch?v=SfGuIVzE_Os
