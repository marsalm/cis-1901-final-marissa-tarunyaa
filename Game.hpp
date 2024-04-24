#ifndef GAME_HPP
#define GAME_HPP

#include <QString>
#include <vector>

class Game
{
public:
    Game();
    QString processGuess(const QString &guess);

private:
    QString hiddenWord;
    int remainingGuesses;
};

#endif // GAME_HPP
