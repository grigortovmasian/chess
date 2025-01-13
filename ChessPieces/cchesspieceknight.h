#ifndef CCHESSPIECEKNIGHT_H
#define CCHESSPIECEKNIGHT_H

#include "cchesspiece.h"

class CChessPieceKnight : public CChessPiece
{
public:
    CChessPieceKnight(bool isWhite, QGraphicsItem* parent);
    ~CChessPieceKnight() {}

    // methods
    char getSymbol() const override;
    CChessPieceType getType () const override;

    PositionVecVec_t getAllRechablePositions(const CBoardPosition& currentPos) const override;
};

#endif // CCHESSPIECEKNIGHT_H
