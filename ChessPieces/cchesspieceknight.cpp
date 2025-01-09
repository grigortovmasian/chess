#include "cchesspieceknight.h"

CChessPieceKnight::CChessPieceKnight(bool isWhite, QGraphicsItem* parent) :
    CChessPiece("knight", isWhite, parent)  {}

char CChessPieceKnight::getSymbol() const {
    return 'N';
}

CChessPieceType CChessPieceKnight::getType() const {
    return CChessPieceType::KNIGHT;
}

PositionVector_t CChessPieceKnight::getAllRechablePositions(const CBoardPosition& currentPos) const {
    PositionVector_t ret;
    return ret;
}
