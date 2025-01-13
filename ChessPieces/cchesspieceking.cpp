#include "cchesspieceking.h"

CChessPieceKing::CChessPieceKing(bool isWhite, QGraphicsItem* parent) :
    CChessPiece("king", isWhite, parent)  {}

char CChessPieceKing::getSymbol() const {
    return 'K';
}

CChessPieceType CChessPieceKing::getType() const {
    return CChessPieceType::KING;
}

PositionVecVec_t CChessPieceKing::getAllRechablePositions(const CBoardPosition& currentPos) const {
    PositionVecVec_t ret;
    unsigned i =  currentPos.getNumber();
    unsigned j =  currentPos.getCharIndex();
    // King have 8 possible possition

    // left up
    PositionVec_t vecLeftUp;
    if (i < 7 && j != 0) {
        vecLeftUp.push_back({i + 1, j - 1});
    }
    ret.append(vecLeftUp);
    // up
    PositionVec_t vecUp;
    if (i < 7) {
        vecUp.push_back({i + 1, j});
    }
    ret.append(vecUp);
    // right up
    PositionVec_t vecRightUp;
    if (i < 7 && j < 7) {
        vecRightUp.push_back({i + 1, j + 1});
    }
    ret.append(vecRightUp);

    // left
    PositionVec_t vecLeft;
    if (j != 0) {
        vecLeft.push_back({i, j - 1});
    }
    ret.append(vecLeft);
    // right
    PositionVec_t vecRight;
    if (j < 7) {
        vecRight.push_back({i, j + 1});
    }
    ret.append(vecRight);

    // left down
    PositionVec_t vecLeftDown;
    if (i != 0 && j != 0) {
        vecLeftDown.push_back({i - 1, j - 1});
    }
    ret.append(vecLeftDown);
    // down
    PositionVec_t vecDown;
    if (i != 0) {
        vecDown.push_back({i - 1, j});
    }
    ret.append(vecDown);
    // right down
    PositionVec_t vecRightDown;
    if (i != 0 && j < 7) {
        vecRightDown.push_back({i - 1, j + 1});
    }
    ret.append(vecRightDown);

    return ret;
}
