#ifndef CCHESSPIECE_H
#define CCHESSPIECE_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QVector>

#include "GameEngine/cboardposition.h"

using PositionVector_t = QVector<CBoardPosition>;

enum CChessPieceType {
    KING = 0,
    QUEEN,
    ROOK,
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

    bool isPawn() const;
    bool isBishop() const;
    bool isKnight() const;
    bool isRook() const;
    bool isQueen() const;
    bool isKing() const;

    // This function will return all the possible moves
    // Here we only check the indexes to be fit in board cause we don't know the position
    // of other pieces
    // Game Analyzer should analyze each of them to see if the move is possible.
    // for example is there any other figure that block the path to it. or maybe
    // it's check situation and the piece can't move at all.
    virtual PositionVector_t getAllRechablePositions(const CBoardPosition& currentPos) const = 0;

protected:
    PositionVector_t getAllRechablePositionsRook(const CBoardPosition& currentPos) const;
    PositionVector_t getAllRechablePositionsBishop(const CBoardPosition& currentPos) const;

    QGraphicsPixmapItem* _imageGraphicItem;
    bool                 _isWhite{true};
};

#endif // CCHESSPIECE_H
