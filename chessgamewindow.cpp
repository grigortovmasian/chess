#include "chessgamewindow.h"
#include "ui_chessgamewindow.h"

#include <QAction>
#include <QToolBar>
#include <QWidget>
#include <QGraphicsRectItem>
#include <QHBoxLayout>
#include <QBrush>

ChessGameWindow::ChessGameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessGameWindow) {
    ui->setupUi(this);

    setFixedSize({500,500});
    createMenuBar();
    createBoard();
}

ChessGameWindow::~ChessGameWindow() {
    delete ui;
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

    QColor colorBrown(150, 77, 34);
    QColor colorLighBrown(238, 220, 151);
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
          QGraphicsRectItem* rec = new QGraphicsRectItem(0,0,40,40);
          if ((i + j) % 2 == 1) {
              rec->setBrush(colorBrown);
          } else {
              rec->setBrush(colorLighBrown);
          }
          rec->setPos(j*40, i*40);
          _boardGui->addItem(rec);
      }
    }
}

