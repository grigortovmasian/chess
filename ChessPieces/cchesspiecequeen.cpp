#include "cchesspiecequeen.h"

CChessPieceQueen::CChessPieceQueen(bool isWhite, QGraphicsItem* parent) :
    CChessPiece("queen", isWhite, parent)  {}

char CChessPieceQueen::getSymbol() const {
    return 'Q';
}

CChessPieceType CChessPieceQueen::getType() const {
    return CChessPieceType::QUEEN;
}

PositionVector_t CChessPieceQueen::getAllRechablePositions(const CBoardPosition& currentPos) const {
    PositionVector_t ret;
    ret.append(getAllRechablePositionsRook(currentPos));
    ret.append(getAllRechablePositionsBishop(currentPos));
    return ret;
}
