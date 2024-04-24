#include "Game.hpp"
#include <QDebug>
#include <fstream>
#include <random>
#include <ctime>
#include <cctype> 
#include <vector>

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

    std::string stdGuess = guess.toLower().toStdString();
    std::string stdHiddenWord = hiddenWord.toLower().toStdString();
    std::string result(stdGuess.size(), '_');

    // Used letters in the hidden word to avoid multiple marking
    std::vector<bool> used(stdHiddenWord.size(), false);

    // First pass with transform: Check for correct letters in the correct positions
    std::transform(stdGuess.begin(), stdGuess.end(), stdHiddenWord.begin(), result.begin(), 
                   [&](char g, char h) -> char {
                       size_t index = &h - &*stdHiddenWord.begin(); // Calculate index
                       if (g == h) {
                           used[index] = true; // Mark this character as used
                           return std::tolower(g); // Return the uppercase version of g
                       }
                       return '_';
                   });

    // Second pass: Check for correct letters in incorrect positions
    for (size_t i = 0; i < stdGuess.size(); ++i) {
        if (result[i] == '_') { // Not correctly guessed
            for (size_t j = 0; j < stdHiddenWord.size(); ++j) {
                if (stdGuess[i] == stdHiddenWord[j] && !used[j]) {
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
    std::string lowerWord = word.toLower().toStdString();  // Convert to lower case for comparison
    return std::find(words.begin(), words.end(), lowerWord) != words.end();
}