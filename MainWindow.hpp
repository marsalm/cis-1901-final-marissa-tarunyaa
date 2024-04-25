#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVector>
#include "Game.hpp"
using namespace wordle;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QWidget *widget;
    QGridLayout *mainLayout;
    QLineEdit *input;
    QPushButton *submitButton;
    QVector<QVector<QLabel *>> gridLabels;
    Game game;

private slots:
    void onGuessEntered();
    void checkGameOver(int currentRow, const QString &result);
};

#endif // MAINWINDOW_HPP
