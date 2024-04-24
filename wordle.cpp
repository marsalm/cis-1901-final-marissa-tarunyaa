#include <iostream>
#include <string>
#include <cctype>

const std::string SECRET_WORD = "apple"; // The secret word to guess
const int MAX_TRIES = 6;                 // Maximum number of tries

void printGuessResult(const std::string &guess)
{
    std::string result = "";

    for (int i = 0; i < guess.size(); ++i)
    {
        if (guess[i] == SECRET_WORD[i])
        {
            result += guess[i]; // Correct letter and position
        }
        else if (SECRET_WORD.find(guess[i]) != std::string::npos)
        {
            result += '*'; // Correct letter, wrong position
        }
        else
        {
            result += '_'; // Incorrect letter
        }
    }

    std::cout << result << std::endl;
}
