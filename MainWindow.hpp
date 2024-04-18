#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include "Game.h"

class MainWindow : public QMainWindow 
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onGuessEntered();

private:
    Game game;
    QLineEdit *input;
    QLabel *resultLabel;
    QGridLayout *layout;
};

#endif // MAINWINDOW_HPP
