#include "cchesspieceking.h"

CChessPieceKing::CChessPieceKing(bool isWhite, QGraphicsItem* parent) :
    CChessPiece("king", isWhite, parent)  {}

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
