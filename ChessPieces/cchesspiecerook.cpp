#include "cchesspiecerook.h"

CChessPieceRook::CChessPieceRook(bool isWhite, QGraphicsItem* parent) :
    CChessPiece("rook", isWhite, parent)  {}

char CChessPieceRook::getSymbol() const {
    return 'R';
}

CChessPieceType CChessPieceRook::getType() const {
    return CChessPieceType::ROOK;
}

PositionVecVec_t CChessPieceRook::getAllRechablePositions(const CBoardPosition& currentPos) const {
    PositionVecVec_t ret;
    ret.append(getAllRechablePositionsRook(currentPos));
    return ret;
}
