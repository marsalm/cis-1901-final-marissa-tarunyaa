#include "Game.hpp"
#include <fstream>
#include <random>
#include <ctime>

// Constructor
Game::Game() : remainingGuessesValue(6)
{
    loadWords();
    selectRandomWord();
}

void Game::loadWords()
{
    std::ifstream file("words.txt");
    std::string word;
    while (file >> word)
    {
        words.push_back(word);
    }
    file.close();
}

void Game::selectRandomWord()
{
    if (!words.empty())
    {
        std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr))); // random-number engine used with a uniform distribution
        std::uniform_int_distribution<int> dist(0, words.size() - 1); // uniform distribution
        hiddenWord = QString::fromStdString(words[dist(rng)]);
    }
}

QString Game::processGuess(const QString &guess)
{
    if (guess.length() != hiddenWord.length())
    {
        return "Incorrect length";
    }

    std::string stdGuess = guess.toStdString();
    std::string stdHiddenWord = hiddenWord.toStdString();
    std::string result(stdGuess.size(), '_');

    std::transform(stdGuess.begin(), stdGuess.end(), stdHiddenWord.begin(), result.begin(),
                   [&stdHiddenWord](char g, char h) -> char {
                       if (g == h)
                       {
                           return g;
                       }
                       else if (stdHiddenWord.find(g) != std::string::npos)
                       {
                           return '*';
                       }
                       else
                       {
                           return '_';
                       }
                   });

    remainingGuessesValue--;
    return QString::fromStdString(result);
}

void Game::resetGame()
{
    remainingGuessesValue = 6;
    selectRandomWord();
}

int Game::remainingGuesses() const
{
    return remainingGuessesValue;
}
