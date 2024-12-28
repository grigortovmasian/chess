#ifndef CCHESSPIECEQUEEN_H
#define CCHESSPIECEQUEEN_H

#include "cchesspiece.h"

class CChessPieceQueen : public CChessPiece
{
public:
    CChessPieceQueen(bool isWhite, QGraphicsItem* parent);
    ~CChessPieceQueen() {}

    // methods
    char getSymbol() const override;
    CChessPieceType getType () const override;

    QVector<CBoardPosition> getAllRechablePositions() const override;
};

#endif // CCHESSPIECEQUEEN_H
