#ifndef CHESSGAMEWINDOW_H
#define CHESSGAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class ChessGameWindow; }
QT_END_NAMESPACE

class ChessGameWindow : public QMainWindow {
    Q_OBJECT

public:
    ChessGameWindow(QWidget *parent = nullptr);
    ~ChessGameWindow();

private:
    void createMenuBar();
    void createBoard();

private:
    Ui::ChessGameWindow *ui;
    QGraphicsScene*     _boardGui{nullptr};
};
#endif // CHESSGAMEWINDOW_H
