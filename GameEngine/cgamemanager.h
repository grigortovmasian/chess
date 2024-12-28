#ifndef CGAMEMANAGER_H
#define CGAMEMANAGER_H

#include "cboardposition.h"
#include <QVector>
#include <QPair>
#include <QGraphicsRectItem>

class CChessPiece;

class CGameManager {
public:
    CGameManager();
    void init(QGraphicsScene* scene);

private:
    void initPositionArray();
    void createBoardCells(QGraphicsScene* scene);
    void createChessPieces();
private:
    // Here I want to correct indexes the way that 0 - 7 vector will be 1 - 8 row
    // And each 0 - 7 index in vectors will be A - H
    QVector<QVector<QPair<QGraphicsRectItem*, CChessPiece*>>> _board;
};

#endif // CGAMEMANAGER_H
