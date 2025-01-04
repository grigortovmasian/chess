#ifndef CHESSGAMEWINDOW_H
#define CHESSGAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "GameEngine/cgamemanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ChessGameWindow; }
QT_END_NAMESPACE

class ChessGameWindow : public QMainWindow {
    Q_OBJECT

public:
    ChessGameWindow(QWidget *parent = nullptr);
    ~ChessGameWindow();

    virtual void mouseReleaseEvent(QMouseEvent *event);

private:
    void createMenuBar();
    void createBoard();
    void createGameManager();

private:
    Ui::ChessGameWindow* _ui;
    CGameManager*        _gameManager{nullptr};
    QGraphicsView*       _boardView{nullptr};
};
#endif // CHESSGAMEWINDOW_H
