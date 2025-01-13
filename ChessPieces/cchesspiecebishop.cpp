#include "cchesspiecebishop.h"

CChessPieceBishop::CChessPieceBishop(bool isWhite, QGraphicsItem* parent) :
    CChessPiece("bishop", isWhite, parent)  {}

char CChessPieceBishop::getSymbol() const {
    return 'B';
}

CChessPieceType CChessPieceBishop::getType() const {
    return CChessPieceType::BISHOP;
}

PositionVecVec_t CChessPieceBishop::getAllRechablePositions(const CBoardPosition& currentPos) const {
    PositionVecVec_t ret;
    ret.append(getAllRechablePositionsBishop(currentPos));
    return ret;
}
