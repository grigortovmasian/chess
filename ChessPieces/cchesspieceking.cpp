#include "cchesspieceking.h"

CChessPieceKing::CChessPieceKing(bool isWhite, QGraphicsItem* parent) :
    CChessPiece("king", isWhite, parent)  {}

char CChessPieceKing::getSymbol() const {
    return 'K';
}

CChessPieceType CChessPieceKing::getType() const {
    return CChessPieceType::KING;
}

PositionVector_t CChessPieceKing::getAllRechablePositions(const CBoardPosition& currentPos) const {
    PositionVector_t ret;
    unsigned i =  currentPos.getNumber();
    unsigned j =  currentPos.getCharIndex();
    // King have 8 possible possition
    // left up
    if (i < 7 && j != 0) {
        ret.push_back({i + 1, j - 1});
    }
    // up
    if (i < 7) {
        ret.push_back({i + 1, j});
    }
    // right up
    if (i < 7 && j < 7) {
        ret.push_back({i + 1, j + 1});
    }

    // left
    if (j != 0) {
        ret.push_back({i, j - 1});
    }
    // right
    if (j < 7) {
        ret.push_back({i, j + 1});
    }

    // left down
    if (i != 0 && j != 0) {
        ret.push_back({i - 1, j - 1});
    }
    // down
    if (i != 0) {
        ret.push_back({i - 1, j});
    }
    // right down
    if (i != 0 && j < 7) {
        ret.push_back({i - 1, j + 1});
    }

    return ret;
}
