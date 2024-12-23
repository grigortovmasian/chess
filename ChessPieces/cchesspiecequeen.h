#ifndef CCHESSPIECEQUEEN_H
#define CCHESSPIECEQUEEN_H

#include "cchesspiece.h"

class CChessPieceQueen : public CChessPiece
{
public:
    CChessPieceQueen(const QString& name, QGraphicsItem* parent);
    ~CChessPieceQueen() {}

    // methods
    char getSymbol() const override;
    CChessPieceType getType () const override;

    QVector<CBoardPosition> getAllRechablePositions() const override;
};

#endif // CCHESSPIECEQUEEN_H
