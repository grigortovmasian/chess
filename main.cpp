#include "chessgamewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChessGameWindow w;
    w.show();
    return a.exec();
}
