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

#

#### typedef and type aliases

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
