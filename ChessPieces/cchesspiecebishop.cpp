#include "cchesspiecebishop.h"

CChessPieceBishop::CChessPieceBishop(bool isWhite, QGraphicsItem* parent) :
    CChessPiece("bishop", isWhite, parent)  {}

char CChessPieceBishop::getSymbol() const {
    return 'B';
}

CChessPieceType CChessPieceBishop::getType() const {
    return CChessPieceType::BISHOP;
}

QVector<CBoardPosition> CChessPieceBishop::getAllRechablePositions() const {
    QVector<CBoardPosition> ret;
    return ret;
}
