#include <iostream>
#include <string>
#include <cctype> 

const std::string SECRET_WORD = "apple";  // The secret word to guess
const int MAX_TRIES = 6;                  // Maximum number of tries

void printGuessResult(const std::string& guess) 
{
    std::string result = "";

    for (int i = 0; i < guess.size(); ++i) 
    {
        if (guess[i] == SECRET_WORD[i]) 
        {
            result += guess[i]; // Correct letter and position
        } else if (SECRET_WORD.find(guess[i]) != std::string::npos) 
        {
            result += '*'; // Correct letter, wrong position
        } else 
        {
            result += '_'; // Incorrect letter
        }
    }

    std::cout << result << std::endl;
}

int main() 
{
    std::string guess;
    int tries = 0;

    std::cout << "Welcome to Wordle in C++!" << std::endl;
    while (tries < MAX_TRIES) {
        std::cout << "Enter your guess (" << tries + 1 << "/" << MAX_TRIES << "): ";
        std::cin >> guess;

        // Manually convert guess to lowercase 
        for (char &c : guess) 
        {
            c = std::tolower(static_cast<unsigned char>(c)); // Convert each character to lowercase
        }

        if (guess.length() != SECRET_WORD.length()) 
        {
            std::cout << "Please enter a five-letter word." << std::endl;
            continue;
        }

        printGuessResult(guess);

        if (guess == SECRET_WORD) 
        {
            std::cout << "Congratulations! You've guessed the word!" << std::endl;
            break;
        }

        tries++;
    }

    if (tries == MAX_TRIES) 
    {
        std::cout << "Sorry, you've run out of tries. The word was: " << SECRET_WORD << std::endl;
    }

    return 0;
}
