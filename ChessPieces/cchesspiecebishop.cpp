#include "cchesspiecebishop.h"

CChessPieceBishop::CChessPieceBishop(const QString& name, QGraphicsItem* parent) :
    CChessPiece(name, parent)  {}

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
