#ifndef __MAINWINDOW_HPP__
#define __MAINWINDOW_HPP__

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include "game.hpp"

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
