#ifndef CCHESSPIECEBISHOP_H
#define CCHESSPIECEBISHOP_H

#include "cchesspiece.h"

class CChessPieceBishop : public CChessPiece
{
public:
    CChessPieceBishop(const QString& name);
    ~CChessPieceBishop() {}

    // methods
    char getSymbol() const override;
    CChessPieceType getType () const override;

    QVector<CBoardPosition> getAllRechablePositions() const override;
};

#endif // CCHESSPIECEBISHOP_H
