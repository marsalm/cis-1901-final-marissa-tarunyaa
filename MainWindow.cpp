#include "MainWindow.hpp"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), game()
{
    // Main Widget and Layout
    widget = new QWidget(this);
    setCentralWidget(widget);
    mainLayout = new QGridLayout(widget);

    // Create the grid for displaying guesses
    gridLabels.resize(6);  // 6 rows for guesses
    for (int i = 0; i < 6; ++i) {
        gridLabels[i].resize(5);  // Each row has 5 letters
        for (int j = 0; j < 5; ++j) {
            gridLabels[i][j] = new QLabel(" ");
            gridLabels[i][j]->setStyleSheet("border: 1px solid black; width: 40px; height: 40px; text-align: center;");
            gridLabels[i][j]->setFont(QFont("Arial", 24, QFont::Bold));
            gridLabels[i][j]->setAlignment(Qt::AlignCenter);
            mainLayout->addWidget(gridLabels[i][j], i, j);
        }
    }

    // Input for guesses
    input = new QLineEdit();
    input->setMaxLength(5);  // Limit input to 5 characters
    submitButton = new QPushButton("Guess");
    mainLayout->addWidget(input, 6, 0, 1, 4); // Place input at the bottom
    mainLayout->addWidget(submitButton, 6, 4); // Submit button next to the input

    connect(submitButton, &QPushButton::clicked, this, &MainWindow::onGuessEntered);
}

void MainWindow::onGuessEntered()
{
    QString guess = input->text().toUpper();
    if (guess.length() != 5) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a 5-letter word.");
        return;
    }
    QString result = game.processGuess(guess.toLower()); // Make sure to pass the guess in lower case
    input->clear();

    // Display the result on the grid
    static int currentRow = 0;
    if (currentRow < 6) {
        for (int i = 0; i < 5; ++i) {
            gridLabels[currentRow][i]->setText(guess[i]);  // Display the guessed letter in uppercase

            if (result[i].toLatin1() == guess[i].toLower().toLatin1()) {
                gridLabels[currentRow][i]->setStyleSheet("background-color: green; color: white; border: 1px solid black;");
            } else if (result[i] == '*') {
                gridLabels[currentRow][i]->setStyleSheet("background-color: yellow; color: black; border: 1px solid black;");
            } else {
                gridLabels[currentRow][i]->setStyleSheet("background-color: gray; color: white; border: 1px solid black;");
            }
        }
        ++currentRow;
    }

    checkGameOver(currentRow, result);
}

void MainWindow::checkGameOver(int currentRow, const QString& result) {
    if (currentRow >= 6 || !result.contains('_')) {
        input->setDisabled(true);
        submitButton->setDisabled(true);

        if (!result.contains('_')) {
            QMessageBox::information(this, "Congratulations!", "You've guessed the word!");
        } else {
            QString message = "The word was " + game.getHiddenWord() + ". Try again!";
            QMessageBox::information(this, "Game Over", message);
        }
    }
}
