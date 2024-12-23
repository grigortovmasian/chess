#include "cchesspieceking.h"

CChessPieceKing::CChessPieceKing(const QString& name, QGraphicsItem* parent) :
    CChessPiece(name, parent)  {}

char CChessPieceKing::getSymbol() const {
    return 'K';
}

CChessPieceType CChessPieceKing::getType() const {
    return CChessPieceType::KING;
}

QVector<CBoardPosition> CChessPieceKing::getAllRechablePositions() const {
    QVector<CBoardPosition> ret;
    return ret;
}
