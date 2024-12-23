#ifndef CCHESSPIECEKNIGHT_H
#define CCHESSPIECEKNIGHT_H

#include "cchesspiece.h"

class CChessPieceKnight : public CChessPiece
{
public:
    CChessPieceKnight(const QString& name, QGraphicsItem* parent);
    ~CChessPieceKnight() {}

    // methods
    char getSymbol() const override;
    CChessPieceType getType () const override;

    QVector<CBoardPosition> getAllRechablePositions() const override;
};

#endif // CCHESSPIECEKNIGHT_H
