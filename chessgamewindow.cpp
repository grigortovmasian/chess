#include "chessgamewindow.h"
#include "ui_chessgamewindow.h"

#include <QAction>
#include <QToolBar>
#include <QWidget>

ChessGameWindow::ChessGameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessGameWindow) {
    ui->setupUi(this);

    setFixedSize({500,500});
}

ChessGameWindow::~ChessGameWindow() {
    delete ui;
}

void ChessGameWindow::createMenuBar() {
    auto newGame = this->menuBar();
    newGame->addMenu("New Game");
}

void ChessGameWindow::createBoard() {
    QWidget* boardWidget = new QWidget(this);
}

