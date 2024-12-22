#include "cchesspieceking.h"

CChessPieceKing::CChessPieceKing(const QString& name) : CChessPiece(name)  {}

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
