/* brief

Sentence Smash
Write a function that takes an array of words and smashes them together into a sentence and returns the sentence. You can ignore any need to sanitize words or add punctuation, but you should add spaces between each word. Be careful, there shouldn't be a space at the beginning or the end of the sentence!

Example
['hello', 'world', 'this', 'is', 'great']  =>  'hello world this is great'

*/

#include <vector>   // vector header
#include <string>   // string header
#include <sstream>  // string stream header
#include <iostream> // input output header

std::string smash(const std::vector<std::string> &words)
// declaring the smash function such that its return type is a string and
// takes in a vector composed of strings labelled words as a dynamic param
{
    {
        if (words.empty()) // checks for edge case for no words
            return "";     // returns empty string if edge case is true

        std::ostringstream oss;
        // creates a string to concatenate the words in the vector to

        for (const auto &word : words)
        // iterates through each word in words and keeps their data type automatic/flexible
        // but prevents them from being altered as a const type
        {
            oss << word << " "; // appends each word into oss (larger string) and adds a blank space as the last character
        }
        std::string result = oss.str(); // sets the larger string as which is a string stream data type to regular string type (into result)
        result.pop_back();              // removes the last item in the result string (a blank space as thats what is added at the end of every word)
        return result;                  // returns result
    }
}

// main function to call smash and test it, not used when submitting the solution
int main()
{
    std::vector<std::string> words = {"hello", "world", "this", "is", "great"};
    std::string sentence = smash(words);
    std::cout << sentence << std::endl;
    return 0;
}

/*
alternative solution from community

std::string smash( const std::vector< std::string >& words ) { // starts the function the same way
  if ( words.empty() ) return {}; // checks if words is empty, returns empty string type back

  std::string sentence; // inits a string var

  for ( const auto& word : words ) sentence += word + ' '; // iterates through words and adds them to sentence with white space

  return sentence.pop_back(), sentence; // pops the last white space and returns sentence
}
*/