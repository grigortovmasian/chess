#include "cchesspieceknight.h"

CChessPieceKnight::CChessPieceKnight(bool isWhite, QGraphicsItem* parent) :
    CChessPiece("knight", isWhite, parent)  {}

char CChessPieceKnight::getSymbol() const {
    return 'N';
}

CChessPieceType CChessPieceKnight::getType() const {
    return CChessPieceType::KNIGHT;
}

PositionVector_t CChessPieceKnight::getAllRechablePositions(const CBoardPosition& currentPos) const {
    PositionVector_t ret;
    unsigned i =  currentPos.getNumber();
    unsigned j =  currentPos.getCharIndex();
    // Knight have 8 possible move

    // 1 up 2 left
    if (i < 7 && j > 1) {
        ret.push_back({i + 1, j - 2});
    }
    // 1 up 2 right
    if (i < 7 && j < 6) {
        ret.push_back({i + 1, j + 2});
    }

    // 2 up 1 left
    if (i < 6 && j > 0) {
        ret.push_back({i + 2, j - 1});
    }
    // 2 up 1 right
    if (i < 6 && j < 7) {
        ret.push_back({i + 2, j + 1});
    }

    // 1 down 2 left
    if (i > 0 && j > 1) {
        ret.push_back({i - 1, j - 2});
    }
    // 1 down 2 right
    if (i > 0 && j < 6) {
        ret.push_back({i - 1, j + 2});
    }

    // 2 down 1 left
    if (i > 1 && j > 0) {
        ret.push_back({i - 2, j - 1});
    }
    // 2 down 1 right
    if (i > 1 && j < 7) {
        ret.push_back({i - 2, j + 1});
    }

    return ret;
}
