#include "cchesspiecequeen.h"

CChessPieceQueen::CChessPieceQueen(bool isWhite, QGraphicsItem* parent) :
    CChessPiece("queen", isWhite, parent)  {}

char CChessPieceQueen::getSymbol() const {
    return 'Q';
}

CChessPieceType CChessPieceQueen::getType() const {
    return CChessPieceType::QUEEN;
}

QVector<CBoardPosition> CChessPieceQueen::getAllRechablePositions() const {
    QVector<CBoardPosition> ret;
    return ret;
}
