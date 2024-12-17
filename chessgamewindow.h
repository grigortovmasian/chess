#ifndef CHESSGAMEWINDOW_H
#define CHESSGAMEWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ChessGameWindow; }
QT_END_NAMESPACE

class ChessGameWindow : public QMainWindow
{
    Q_OBJECT

public:
    ChessGameWindow(QWidget *parent = nullptr);
    ~ChessGameWindow();

private:
    void createMenuBar();
    void createBoard();

private:
    Ui::ChessGameWindow *ui;
};
#endif // CHESSGAMEWINDOW_H
