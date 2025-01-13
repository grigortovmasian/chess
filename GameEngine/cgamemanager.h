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

    void makeQueen();
    void movePiece(QGraphicsRectItem* newItem);
    // Here we check is this possible on current possition for example
    // 1. Is there any other piece that blocks your way
    // 2. If your king on check you allow only to cover the way or play by king
    // 3. if you move by your king than make sure than eliminate moves where oposition can check
    // Maybe it will be esier to do it when getting moves from pieces. Or return vector<vector<pos>>
    // in order to block the entire direction if needed.
    void analyzePossibleMovesBasedOnCurrentPosition();
    // Well there are 4 special moves we have and almost all are related with pawn
    // 1. Castle -> Move comnination by King and one of Rook. Both should not be touched before that
    // 2. Pawn capture. they capture diogonaly on their moving direcition
    // 3. Transpassing pawn capture possibility. if my pawn can capture on column 6 and pawn moves directly
    //    from 7 to 5 I can still capture it
    // 4. Pawn promotion.
    void addSpecialMoves();

    void resetSelectedItem();

    bool isWhiteMove() const { return _currentMove; }
    bool isBlackMove() const { return !isWhiteMove(); }

    bool isSelectedPositionReachable(QGraphicsRectItem* newItem) const;


private:
    // Here I want to correct indexes the way that 0 - 7 vector will be 1 - 8 row
    // And each 0 - 7 index in vectors will be A - H
    QHash<CBoardPosition, QGraphicsRectItem*> _boardItems;
    QHash<QGraphicsRectItem*, CBoardPosition> _itemToPosMap;
    QHash<QGraphicsRectItem*, CChessPiece*>   _itemToPieceMap;
    // Maps for fast access
    QHash<CChessPiece*, CBoardPosition> _pieceToPosMap;
    PositionVecVec_t                    _possibleMoves;
    QGraphicsRectItem*                  _currentSelectedItem{nullptr};
    bool                                _currentMove{true};
    bool                                _isWhiteCastlePossible{true};
    bool                                _isBlackCastlePossible{true};
    bool                                _isTranspassingPawnCapturePossible{true};
};

#endif // CGAMEMANAGER_H
