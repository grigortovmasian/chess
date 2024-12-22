#include "cchesspiecerock.h"

CChessPieceRock::CChessPieceRock(const QString& name) : CChessPiece(name)  {}

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
