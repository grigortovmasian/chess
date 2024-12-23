#include "cchesspiecerock.h"

CChessPieceRock::CChessPieceRock(const QString& name, QGraphicsItem* parent) :
    CChessPiece(name, parent)  {}

char CChessPieceRock::getSymbol() const {
    return 'R';
}

CChessPieceType CChessPieceRock::getType() const {
    return CChessPieceType::ROCK;
}

QVector<CBoardPosition> CChessPieceRock::getAllRechablePositions() const {
    QVector<CBoardPosition> ret;
    return ret;
}
