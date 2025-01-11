#include "cchesspiecepawn.h"

CChessPiecePawn::CChessPiecePawn(bool isWhite, QGraphicsItem* parent) :
    CChessPiece("pawn", isWhite, parent)  {}

char CChessPiecePawn::getSymbol() const {
    return 'P';
}

CChessPieceType CChessPiecePawn::getType() const {
    return CChessPieceType::PAWN;
}

PositionVector_t CChessPiecePawn::getAllRechablePositions(const CBoardPosition& currentPos) const {
    PositionVector_t ret;
    // Pawn move is depeneding on it's direction.
    unsigned i =  currentPos.getNumber();
    unsigned j =  currentPos.getCharIndex();
    if (isWhitePiece()) {
        if (i < 7) {
          ret.push_back({i + 1, j});
        }

        // firt move can be 2 squeres at once
        if (i == 1) {
          ret.push_back({i + 2, j});
        }
    } else {
        if (i > 0) {
          ret.push_back({i - 1, j});
        }

        // firt move can be 2 squeres at once
        if (i == 6) {
          ret.push_back({i - 2, j});
        }
    }
    return ret;
}

