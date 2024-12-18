#ifndef CCHESSPIECE_H
#define CCHESSPIECE_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QVector>

#include "GameEngine/cboardposition.h"

enum CChessPieceType {
    KING = 0,
    QUEEN,
    ROCK,
    BISHOP,
    NIGHT,
    PAWN
};

class CChessPiece {
public:
    CChessPiece(const QString& name);
    virtual ~CChessPiece();

    char getSymbol() const;
    inline CChessPieceType getType () const { return _type; }

    // This function will return all the possible moves
    // Game Analyzer should analyze each of them to see if the move is possible.
    // for example is there any other figure that block the path to it. or maybe
    // it's check situation and the piece can't move at all.
    virtual const QVector<CBoardPosition>& getAllRechablePositions() const = 0;

protected:
  QGraphicsPixmapItem* _imageGraphicItem;
  CBoardPosition       _currentPos;
  CChessPieceType      _type;
};

#endif // CCHESSPIECE_H
