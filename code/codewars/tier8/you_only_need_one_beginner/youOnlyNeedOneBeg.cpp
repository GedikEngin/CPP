/*

brief:

You will be given an array a and a value x. All you need to do is check whether the provided array contains the value.

Array can contain numbers or strings. X can be either.

Return true if the array contains the value, false if not.

*/

#include <vector>
#include <string>
#include <iostream>

bool check(const std::vector<std::string> &seq, const std::string &elem)
{

    for (const auto &it : seq) // iterates through the sequence with using i as the iterator
    {
        if (it == elem) // if iterator is equal to element specified
        {
            return true; // return true
        }
    }
    return false; // if it doesn't match it has to be false so return false
}

int main(int argc, char const *argv[])
{
    std::cout << check({"a", "b", "c"}, "f");
    return 0;
}

/* community solutions:

using std find:

#include <vector>
#include <string>

bool check(const std::vector<std::string>& seq, const std::string& elem) {
    return std::find(seq.begin(), seq.end(), elem) != seq.end();
}


using short hand syntax:
bool check(const std::vector<std::string>& seq, const std::string& elem) {
  for(auto i:seq) if(i==elem)return 1;
  return 0;
}

*/