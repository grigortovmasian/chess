#include "chessgamewindow.h"
#include "ui_chessgamewindow.h"

#include <QAction>
#include <QToolBar>
#include <QWidget>
#include <QHBoxLayout>
#include <QTransform>
#include <QMouseEvent>
#include <QPointF>

ChessGameWindow::ChessGameWindow(QWidget* parent)
    : QMainWindow(parent)
    , _ui(new Ui::ChessGameWindow) {
    _ui->setupUi(this);

    setFixedSize({500,500});
    createMenuBar();
    createBoard();
    createGameManager();
    grabMouse();
}

ChessGameWindow::~ChessGameWindow() {
    if (_ui) {
        delete _ui;
    }
    if (_gameManager) {
      delete _gameManager;
    }
}

void ChessGameWindow::mouseReleaseEvent(QMouseEvent* event) {
   QMainWindow::mouseReleaseEvent(event);
   QPointF scenePos = _boardView->mapToScene(event->pos());
   // Add offset to center the mouse and get correct object
   // TODO understand how to get graphcis item and not piece picture
   scenePos.setY(scenePos.y() - 20);
   QList<QGraphicsItem*> items = _boardView->scene()->items(scenePos);
   _gameManager->itemSelected(items);
}

void ChessGameWindow::createMenuBar() {
    auto newGame = this->menuBar();
    newGame->addMenu("New Game");
}
void ChessGameWindow::createBoard() {
    _boardView = new QGraphicsView(this);
    this->setCentralWidget(_boardView);
    QGraphicsScene* boardGui = new QGraphicsScene();

    _boardView->show();
    _boardView->setScene(boardGui);
}

void ChessGameWindow::createGameManager() {
    _gameManager = new CGameManager();
    _gameManager->init(_boardView->scene());
}

