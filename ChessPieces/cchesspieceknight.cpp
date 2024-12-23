#include "cchesspieceknight.h"

CChessPieceKnight::CChessPieceKnight(const QString& name, QGraphicsItem* parent) :
    CChessPiece(name, parent)  {}

char CChessPieceKnight::getSymbol() const {
    return 'N';
}

CChessPieceType CChessPieceKnight::getType() const {
    return CChessPieceType::KNIGHT;
}

QVector<CBoardPosition> CChessPieceKnight::getAllRechablePositions() const {
    QVector<CBoardPosition> ret;
    return ret;
}
