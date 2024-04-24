#ifndef GAME_HPP
#define GAME_HPP

#include <QString>
#include <vector>

class Game
{
public:
    Game();                            // constructor to initialize the game
    QString processGuess(const QString &guess);  // process the user's guess and return feedback
    void resetGame();                  // resets the game to start anew
    int remainingGuesses() const;      // getter for the remaining guesses

private:
    QString hiddenWord;                // the word that needs to be guessed
    int remainingGuessesValue;         // number of remaining guesses
    std::vector<std::string> words;    // vector to hold all possible words

    void loadWords();                  // load words from file
    void selectRandomWord();           // select a random word from the list
};

#endif // GAME_HPP
