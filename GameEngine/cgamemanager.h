#ifndef CGAMEMANAGER_H
#define CGAMEMANAGER_H

#include <QVector>
#include <QPair>
#include <QHash>
#include <QGraphicsScene>


#include "cboardposition.h"
#include "ChessPieces/cchesspiece.h"

class CGameManager : public QObject {
    Q_OBJECT;
public:
    CGameManager();
    void init(QGraphicsScene* scene);
    virtual ~CGameManager() {}

    void itemSelected(const QList<QGraphicsItem*>& selectedItems);

private:
    void createBoardCells(QGraphicsScene* scene);
    void createChessPieces();
    void setDefaultColor(QGraphicsRectItem* item, const CBoardPosition& pos);

private:
    // Here I want to correct indexes the way that 0 - 7 vector will be 1 - 8 row
    // And each 0 - 7 index in vectors will be A - H
    QHash<CBoardPosition, QGraphicsRectItem*> _boardItems;
    QHash<QGraphicsRectItem*, CChessPiece*>   _itemToPieceMap;
    // Maps for fast access
    QHash<CChessPiece*, CBoardPosition> _pieceToPosMap;
    PositionVector_t                    _possibleMoves;
    QGraphicsRectItem*                  _currentSelectedItem{nullptr};
};

#endif // CGAMEMANAGER_H
