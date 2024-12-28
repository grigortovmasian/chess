#ifndef CCHESSPIECEPAWN_H
#define CCHESSPIECEPAWN_H

#include "cchesspiece.h"

class CChessPiecePawn : public CChessPiece
{
public:
    CChessPiecePawn(bool isWhite, QGraphicsItem* parent);
    ~CChessPiecePawn() {}

    // methods
    char getSymbol() const override;
    CChessPieceType getType () const override;

    QVector<CBoardPosition> getAllRechablePositions() const override;
};

#endif // CCHESSPIECEPAWN_H
