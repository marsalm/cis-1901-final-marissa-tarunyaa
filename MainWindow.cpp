#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) 
{
    // Main Widget and Layout
    QWidget *widget = new QWidget(this);
    setCentralWidget(widget);
    layout = new QGridLayout(widget);

    // Input for guesses
    input = new QLineEdit();
    QPushButton *submitButton = new QPushButton("Guess");
    resultLabel = new QLabel("Enter your guess:");

    layout->addWidget(input, 0, 0, 1, 2);
    layout->addWidget(submitButton, 1, 0);
    layout->addWidget(resultLabel, 1, 1);

    connect(submitButton, &QPushButton::clicked, this, &MainWindow::onGuessEntered);
}

void MainWindow::onGuessEntered() 
{
    QString guess = input->text();
    QString result = game.processGuess(guess);
    resultLabel->setText(result);
    input->clear();
}
