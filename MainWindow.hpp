#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "Game.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QWidget *widget;
    QGridLayout *layout;
    QLineEdit *input;
    QLabel *resultLabel;
    QPushButton *playAgainButton;  
    Game game;

private slots:
    void onGuessEntered();
    void onPlayAgainClicked(); 
};

#endif // MAINWINDOW_HPP
