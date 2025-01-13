#include "cchesspiecepawn.h"

CChessPiecePawn::CChessPiecePawn(bool isWhite, QGraphicsItem* parent) :
    CChessPiece("pawn", isWhite, parent)  {}

char CChessPiecePawn::getSymbol() const {
    return 'P';
}

CChessPieceType CChessPiecePawn::getType() const {
    return CChessPieceType::PAWN;
}

PositionVecVec_t CChessPiecePawn::getAllRechablePositions(const CBoardPosition& currentPos) const {
    PositionVecVec_t ret;
    // Pawn move is depeneding on it's direction.
    unsigned i =  currentPos.getNumber();
    unsigned j =  currentPos.getCharIndex();

    PositionVec_t vecForward;
    if (isWhitePiece()) {
        if (i < 7) {
          vecForward.push_back({i + 1, j});
        }

        // firt move can be 2 squeres at once
        if (i == 1) {
          vecForward.push_back({i + 2, j});
        }
    } else {
        if (i > 0) {
          vecForward.push_back({i - 1, j});
        }

        // firt move can be 2 squeres at once
        if (i == 6) {
          vecForward.push_back({i - 2, j});
        }
    }
    ret.append(vecForward);
    return ret;
}

