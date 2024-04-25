#include "Game.hpp"
#include <QDebug>
#include <fstream>
#include <random>
#include <ctime>
#include <cctype>
#include <vector>
#include <future>
#include <thread>
#include <stdexcept>
using namespace wordle;

// Constructor
Game::Game() : remainingGuessesValue(6)
{
    // loadWords();
    wordLoadFuture = std::async(std::launch::async, &Game::loadWords, this);
    // selectRandomWord();
}

void Game::loadWords()
{
    std::ifstream file("words.txt");
    if (!file)
    {
        throw std::runtime_error("Unable to open words file");
    }
    std::string word;
    while (file >> word)
    {
        words.push_back(word); // adds word to end dynamic array
    }
    file.close();
    if (!words.empty())
    {
        selectRandomWord(); // now it's safe to select a random word
    }
}

void Game::selectRandomWord()
{
    if (!words.empty())
    {
        std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr))); // random-number engine used with a uniform distribution
        std::uniform_int_distribution<int> dist(0, words.size() - 1);    // uniform distribution
        hiddenWord = QString::fromStdString(words[dist(rng)]);
    }
}

QString Game::processGuess(const QString &guess)
{

    if (guess.isEmpty())
    {
        throw std::invalid_argument("Empty guess");
    }

    if (guess.length() != hiddenWord.length())
    {
        throw std::invalid_argument("Incorrect length");
    }

    std::string stdGuess = guess.toLower().toStdString();
    std::string stdHiddenWord = hiddenWord.toLower().toStdString();
    std::string result(stdGuess.size(), '_');

    // Used letters in the hidden word to avoid multiple marking
    std::vector<bool> used(stdHiddenWord.size(), false);

    // First pass with transform: Check for correct letters in the correct positions
    for (size_t i = 0; i < stdGuess.size(); ++i)
    {
        if (stdGuess[i] == stdHiddenWord[i]) // originally, size_t index = &h - &*stdHiddenWord.begin(); // Calculate index
        // was causing segmentation fault because of unsafe pointer arithematic
        {
            used[i] = true;
            result[i] = stdGuess[i]; // Preserves the lowercase letter
        }
    }

    // Second pass: Check for correct letters in incorrect positions
    for (size_t i = 0; i < stdGuess.size(); ++i)
    {
        if (result[i] == '_')
        { // Not correctly guessed
            for (size_t j = 0; j < stdHiddenWord.size(); ++j)
            {
                if (stdGuess[i] == stdHiddenWord[j] && !used[j])
                {
                    used[j] = true;
                    result[i] = '*'; // Mark as correct letter, wrong position
                    break;
                }
            }
        }
    }

    remainingGuessesValue--;
    qDebug() << "Guess Result: " << QString::fromStdString(result);
    return QString::fromStdString(result);
}

void Game::resetGame()
{
    wordLoadFuture.wait(); // Ensure word loading is completed
    if (words.empty())
    {
        throw std::logic_error("No words loaded"); // Throw an exception if no words are loaded
    }
    remainingGuessesValue = 6;
    selectRandomWord();
}

int Game::remainingGuesses() const
{
    return remainingGuessesValue;
}

QString Game::getHiddenWord() const
{
    return hiddenWord;
}

bool Game::wordExists(const QString &word)
{
    std::string lowerWord = word.toLower().toStdString(); // Convert to lower case for comparison
    return std::find(words.begin(), words.end(), lowerWord) != words.end();
}