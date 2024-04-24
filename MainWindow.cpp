#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), game() 
{
    // Main Widget and Layout
    QWidget *widget = new QWidget(this);
    setCentralWidget(widget);
    layout = new QGridLayout(widget);

    // Input for guesses
    input = new QLineEdit();
    QPushButton *submitButton = new QPushButton("Guess");
    resultLabel = new QLabel("Enter your guess:");
    playAgainButton = new QPushButton("Play Again"); 
    playAgainButton->setVisible(false); 

    layout->addWidget(input, 0, 0, 1, 2);
    layout->addWidget(submitButton, 1, 0);
    layout->addWidget(resultLabel, 1, 1);
    layout->addWidget(playAgainButton, 2, 0, 1, 2); // Add to layout

    connect(submitButton, &QPushButton::clicked, this, &MainWindow::onGuessEntered);
    connect(playAgainButton, &QPushButton::clicked, this, &MainWindow::onPlayAgainClicked);
}

void MainWindow::onGuessEntered()
{
    QString guess = input->text();
    QString result = game.processGuess(guess);
    resultLabel->setText(result);
    input->clear();

    if (game.remainingGuesses() <= 0) { 
        playAgainButton->setVisible(true); 
        input->setDisabled(true); 
    }
}

void MainWindow::onPlayAgainClicked()
{
    game.resetGame(); // 
    resultLabel->setText("Enter your guess:");
    playAgainButton->setVisible(false); 
    input->setEnabled(true); 
    input->clear();
}
