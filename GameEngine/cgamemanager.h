#ifndef CGAMEMANAGER_H
#define CGAMEMANAGER_H

#include <QVector>
#include <QPair>
#include <QHash>
#include <QGraphicsScene>


#include "cboardposition.h"

class CChessPiece;

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

private:
    // Here I want to correct indexes the way that 0 - 7 vector will be 1 - 8 row
    // And each 0 - 7 index in vectors will be A - H
    QHash<CBoardPosition, QGraphicsRectItem*> _boardItems;
    // Maps for fast access
    QHash<CChessPiece*, CBoardPosition> _pieceToPosMap;
    QGraphicsItem*                      _currentSelectedItem{nullptr};
    static QBrush                       defaultSelectedColor;
};

#endif // CGAMEMANAGER_H
