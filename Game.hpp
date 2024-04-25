#ifndef GAME_HPP
#define GAME_HPP

#include <QString>
#include <vector>
#include <future>

namespace wordle
{

    class Game
    {
    public:
        Game();                                     // Constructor to initialize the game
        QString processGuess(const QString &guess); // Process the user's guess and return feedback
        void resetGame();                           // Resets the game to start anew
        int remainingGuesses() const;               // Getter for the remaining guesses
        QString getHiddenWord() const;              // Getter for the hidden word
        bool wordExists(const QString &word);       // Check if guessed word exists in words.txt

    private:
        QString hiddenWord;               // The word that needs to be guessed
        int remainingGuessesValue;        // Number of remaining guesses
        std::vector<std::string> words;   // Vector to hold all possible words
        std::future<void> wordLoadFuture; // Future for asynchronous word loading

        void loadWords();        // Load words from file
        void selectRandomWord(); // Select a random word from the list
    };

} // namespace wordle

#endif // GAME_HPP
