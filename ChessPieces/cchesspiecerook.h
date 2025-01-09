#ifndef CCHESSPIECEROOK_H
#define CCHESSPIECEROOK_H

#include "cchesspiece.h"

class CChessPieceRook : public CChessPiece
{
public:
    CChessPieceRook(bool isWhite, QGraphicsItem* parent);
    ~CChessPieceRook() {}

    // methods
    char getSymbol() const override;
    CChessPieceType getType () const override;

    PositionVector_t getAllRechablePositions(const CBoardPosition& currentPos) const override;
};

#endif // CCHESSPIECEROOK_H
