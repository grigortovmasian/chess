#ifndef CCHESSPIECEKING_H
#define CCHESSPIECEKING_H

#include "cchesspiece.h"

class CChessPieceKing : public CChessPiece {
public:
    CChessPieceKing(bool isWhite, QGraphicsItem* parent);
    ~CChessPieceKing() {}

    // methods
    char getSymbol() const override;
    CChessPieceType getType () const override;

   PositionVector_t getAllRechablePositions(const CBoardPosition& currentPos) const override;

};

#endif // CCHESSPIECEKING_H
