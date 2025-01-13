#include "cchesspieceknight.h"

CChessPieceKnight::CChessPieceKnight(bool isWhite, QGraphicsItem* parent) :
    CChessPiece("knight", isWhite, parent)  {}

char CChessPieceKnight::getSymbol() const {
    return 'N';
}

CChessPieceType CChessPieceKnight::getType() const {
    return CChessPieceType::KNIGHT;
}

PositionVecVec_t CChessPieceKnight::getAllRechablePositions(const CBoardPosition& currentPos) const {
    PositionVecVec_t ret;
    unsigned i =  currentPos.getNumber();
    unsigned j =  currentPos.getCharIndex();
    // Knight have 8 possible move

    // 1 up 2 left
    PositionVec_t vec1U2L;
    if (i < 7 && j > 1) {
        vec1U2L.push_back({i + 1, j - 2});
    }
    ret.append(vec1U2L);

    // 1 up 2 right
    PositionVec_t vec1U2R;
    if (i < 7 && j < 6) {
        vec1U2R.push_back({i + 1, j + 2});
    }
    ret.append(vec1U2R);

    // 2 up 1 left
    PositionVec_t vec2U1L;
    if (i < 6 && j > 0) {
        vec2U1L.push_back({i + 2, j - 1});
    }
    ret.append(vec2U1L);
    // 2 up 1 right
    PositionVec_t vec2U1R;
    if (i < 6 && j < 7) {
        vec2U1R.push_back({i + 2, j + 1});
    }
    ret.append(vec2U1R);

    // 1 down 2 left
    PositionVec_t vec1D2L;
    if (i > 0 && j > 1) {
        vec1D2L.push_back({i - 1, j - 2});
    }
    ret.append(vec1D2L);
    // 1 down 2 right
    PositionVec_t vec1D2R;
    if (i > 0 && j < 6) {
        vec1D2R.push_back({i - 1, j + 2});
    }
    ret.append(vec1D2R);

    // 2 down 1 left
    PositionVec_t vec2D1L;
    if (i > 1 && j > 0) {
        vec2D1L.push_back({i - 2, j - 1});
    }
    ret.append(vec2D1L);
    // 2 down 1 right
    PositionVec_t vec2D1R;
    if (i > 1 && j < 7) {
        vec2D1R.push_back({i - 2, j + 1});
    }
    ret.append(vec2D1R);

    return ret;
}
