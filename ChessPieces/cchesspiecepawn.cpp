#include "cchesspiecepawn.h"

CChessPiecePawn::CChessPiecePawn(bool isWhite, QGraphicsItem* parent) :
    CChessPiece("pawn", isWhite, parent)  {}

char CChessPiecePawn::getSymbol() const {
    return 'P';
}

CChessPieceType CChessPiecePawn::getType() const {
    return CChessPieceType::PAWN;
}

PositionVector_t CChessPiecePawn::getAllRechablePositions(const CBoardPosition& currentPos) const {
    PositionVector_t ret;
    return ret;
}

