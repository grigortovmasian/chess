#include "cchesspieceknight.h"

CChessPieceKnight::CChessPieceKnight(bool isWhite, QGraphicsItem* parent) :
    CChessPiece("knight", isWhite, parent)  {}

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
