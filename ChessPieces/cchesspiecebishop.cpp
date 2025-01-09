#include "cchesspiecebishop.h"

CChessPieceBishop::CChessPieceBishop(bool isWhite, QGraphicsItem* parent) :
    CChessPiece("bishop", isWhite, parent)  {}

char CChessPieceBishop::getSymbol() const {
    return 'B';
}

CChessPieceType CChessPieceBishop::getType() const {
    return CChessPieceType::BISHOP;
}

PositionVector_t CChessPieceBishop::getAllRechablePositions(const CBoardPosition& currentPos) const {
    PositionVector_t ret;
    ret.append(getAllRechablePositionsBishop(currentPos));
    return ret;
}
