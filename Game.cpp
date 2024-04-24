#include "Game.hpp"
#include <algorithm> 

Game::Game() : remainingGuesses(6)
{
    hiddenWord = "hello"; 
}

QString Game::processGuess(const QString &guess)
{
    if (guess.length() != hiddenWord.length())
    {
        return "Incorrect length";
    }

    std::string stdGuess = guess.toStdString();
    std::string stdHiddenWord = hiddenWord.toStdString(); // convert hiddenWord to std::string
    std::string result(stdGuess.size(), '_'); 

    // transform stdGuess into result based on matching logic
    std::transform(stdGuess.begin(), stdGuess.end(), stdHiddenWord.begin(), result.begin(),
        [this, &stdHiddenWord](char g, char h) -> char {
            if (g == h)
            {
                return g; // correct letter and position
            }
            else if (stdHiddenWord.find(g) != std::string::npos)
            {
                return '*'; // correct letter, wrong position
            }
            else
            {
                return '_'; // incorrect letter
            }
        });

    remainingGuesses--;
    return QString::fromStdString(result);
}
