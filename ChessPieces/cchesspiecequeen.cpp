#include "cchesspiecequeen.h"

CChessPieceQueen::CChessPieceQueen(const QString& name, QGraphicsItem* parent) :
    CChessPiece(name, parent)  {}

char CChessPieceQueen::getSymbol() const {
    return 'Q';
}

CChessPieceType CChessPieceQueen::getType() const {
    return CChessPieceType::QUEEN;
}

QVector<CBoardPosition> CChessPieceQueen::getAllRechablePositions() const {
    QVector<CBoardPosition> ret;
    return ret;
}
