#include "cchesspiecepawn.h"

CChessPiecePawn::CChessPiecePawn(bool isWhite, QGraphicsItem* parent) :
    CChessPiece("pawn", isWhite, parent)  {}

char CChessPiecePawn::getSymbol() const {
    return 'P';
}

CChessPieceType CChessPiecePawn::getType() const {
    return CChessPieceType::PAWN;
}

QVector<CBoardPosition> CChessPiecePawn::getAllRechablePositions() const {
    QVector<CBoardPosition> ret;
    return ret;
}

