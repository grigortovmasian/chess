#include "cchesspiecerook.h"

CChessPieceRook::CChessPieceRook(bool isWhite, QGraphicsItem* parent) :
    CChessPiece("rook", isWhite, parent)  {}

char CChessPieceRook::getSymbol() const {
    return 'R';
}

CChessPieceType CChessPieceRook::getType() const {
    return CChessPieceType::ROCK;
}

QVector<CBoardPosition> CChessPieceRook::getAllRechablePositions() const {
    QVector<CBoardPosition> ret;
    return ret;
}
