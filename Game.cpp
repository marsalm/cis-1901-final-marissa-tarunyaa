#include "Game.hpp"

Game::Game() : remainingGuesses(6) 
{
    hiddenWord = "hello";  // Hardcoded for demonstration; you should implement a word list
}

QString Game::processGuess(const QString &guess) 
{
    if (guess.length() != hiddenWord.length()) 
    {
        return "Incorrect length";
    }
    // More complex game logic goes here
    return "Processing...";
}
