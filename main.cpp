#include <QApplication>
#include "MainWindow.hpp"
using namespace wordle;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv); // instance of QApplication
    MainWindow window;            // instance of MainWindow
    window.show();

    // enters event loop
    return app.exec();
}