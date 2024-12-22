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

char getSymbolFromType(const CChessPieceType& type);

class CChessPiece {
public:
    CChessPiece(const QString& name);
    virtual ~CChessPiece();

    virtual char getSymbol() const = 0;
    virtual CChessPieceType getType () const = 0;

    // This function will return all the possible moves
    // Here we only check the indexes to be fit in board cause we don't know the position
    // of other pieces
    // Game Analyzer should analyze each of them to see if the move is possible.
    // for example is there any other figure that block the path to it. or maybe
    // it's check situation and the piece can't move at all.
    virtual QVector<CBoardPosition> getAllRechablePositions() const = 0;

protected:
  QGraphicsPixmapItem* _imageGraphicItem;
  CBoardPosition       _currentPos;
};

#endif // CCHESSPIECE_H
