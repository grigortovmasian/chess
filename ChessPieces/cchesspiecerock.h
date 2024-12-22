#ifndef CCHESSPIECEROCK_H
#define CCHESSPIECEROCK_H

#include "cchesspiece.h"

class CChessPieceRock : public CChessPiece
{
public:
    CChessPieceRock(const QString& name);
    ~CChessPieceRock() {}

    // methods
    char getSymbol() const override;
    CChessPieceType getType () const override;

    QVector<CBoardPosition> getAllRechablePositions() const override;
};

#endif // CCHESSPIECEROCK_H
