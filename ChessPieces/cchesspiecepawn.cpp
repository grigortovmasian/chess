#include "cchesspiecepawn.h"

CChessPiecePawn::CChessPiecePawn(const QString& name) : CChessPiece(name)  {}

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

