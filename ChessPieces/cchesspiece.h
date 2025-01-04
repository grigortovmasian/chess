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
    KNIGHT,
    PAWN
};

char getSymbolFromType(const CChessPieceType& type);

class CChessPiece {
public:
    CChessPiece(const QString& name, bool isWhite, QGraphicsItem* parent);
    virtual ~CChessPiece();

    virtual char getSymbol() const = 0;
    virtual CChessPieceType getType () const = 0;
    bool isBlackPiece() const { return !_isWhite; }
    bool isWhitePiece() const { return _isWhite; }

    // This function will return all the possible moves
    // Here we only check the indexes to be fit in board cause we don't know the position
    // of other pieces
    // Game Analyzer should analyze each of them to see if the move is possible.
    // for example is there any other figure that block the path to it. or maybe
    // it's check situation and the piece can't move at all.
    virtual QVector<CBoardPosition> getAllRechablePositions() const = 0;

protected:
  QGraphicsPixmapItem* _imageGraphicItem;
  bool                 _isWhite{true};
};

#endif // CCHESSPIECE_H
