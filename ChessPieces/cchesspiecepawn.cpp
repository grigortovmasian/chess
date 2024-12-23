#include "cchesspiecepawn.h"

CChessPiecePawn::CChessPiecePawn(const QString& name, QGraphicsItem* parent) :
    CChessPiece(name, parent)  {}

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

