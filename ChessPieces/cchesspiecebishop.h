#ifndef CCHESSPIECEBISHOP_H
#define CCHESSPIECEBISHOP_H

#include "cchesspiece.h"

class CChessPieceBishop : public CChessPiece
{
public:
    CChessPieceBishop(bool isWhite, QGraphicsItem* parent);
    ~CChessPieceBishop() {}

    // methods
    char getSymbol() const override;
    CChessPieceType getType () const override;

    PositionVector_t getAllRechablePositions(const CBoardPosition& currentPos) const override;
};

#endif // CCHESSPIECEBISHOP_H
