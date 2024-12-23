#include "chessgamewindow.h"
#include "ui_chessgamewindow.h"

#include <QAction>
#include <QToolBar>
#include <QWidget>
#include <QHBoxLayout>

ChessGameWindow::ChessGameWindow(QWidget* parent)
    : QMainWindow(parent)
    , _ui(new Ui::ChessGameWindow) {
    _ui->setupUi(this);

    setFixedSize({500,500});
    createMenuBar();
    createBoard();
    createGameManager();
}

ChessGameWindow::~ChessGameWindow() {
    if (_ui) {
        delete _ui;
    }
    if (_gameManager) {
      delete _gameManager;
    }
}

void ChessGameWindow::createMenuBar() {
    auto newGame = this->menuBar();
    newGame->addMenu("New Game");
}

void ChessGameWindow::createBoard() {
    QGraphicsView* boardView = new QGraphicsView(this);
    this->setCentralWidget(boardView);
    _boardGui = new QGraphicsScene();

    boardView->show();
    boardView->setScene(_boardGui);
}

void ChessGameWindow::createGameManager() {
    _gameManager = new CGameManager();
    _gameManager->init(_boardGui);
}

