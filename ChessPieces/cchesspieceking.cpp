#include "cchesspieceking.h"

CChessPieceKing::CChessPieceKing(bool isWhite, QGraphicsItem* parent) :
    CChessPiece("king", isWhite, parent)  {}

char CChessPieceKing::getSymbol() const {
    return 'K';
}

CChessPieceType CChessPieceKing::getType() const {
    return CChessPieceType::KING;
}

PositionVector_t CChessPieceKing::getAllRechablePositions(const CBoardPosition& currentPos) const {
    PositionVector_t ret;
    return ret;
}
