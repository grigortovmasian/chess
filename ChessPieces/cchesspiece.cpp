#include "cchesspiece.h"

CChessPiece::CChessPiece(const QString& name,
                         bool isWhite,
                         QGraphicsItem* parent) : _isWhite (isWhite) {
    QString path("..\\PiecesPhotos\\");
    if (isWhite) {
      path.append("white-");
    } else {
        path.append("black-");
    }
    path.append(name);
    path.append(".png");
    QPixmap pk(path);

    _imageGraphicItem = new QGraphicsPixmapItem(pk.scaled(40,40), parent);
}

CChessPiece::~CChessPiece() {}

bool CChessPiece::isPawn() const {
    return getType() == CChessPieceType::PAWN;
}

bool CChessPiece::isBishop() const {
    return getType() == CChessPieceType::BISHOP;
}

bool CChessPiece::isKnight() const {
    return getType() == CChessPieceType::KNIGHT;
}

bool CChessPiece::isRook() const {
    return getType() == CChessPieceType::ROOK;
}

bool CChessPiece::isQueen() const {
    return getType() == CChessPieceType::QUEEN;
}

bool CChessPiece::isKing() const {
    return getType() == CChessPieceType::KING;
}

PositionVector_t CChessPiece::getAllRechablePositionsRook(const CBoardPosition& currentPos) const {
    PositionVector_t ret;
    // Add everything to left.
    for (unsigned i = 0; i < currentPos.getCharIndex(); ++i) {
        ret.append(CBoardPosition(currentPos.getNumber(), i));
    }

    // Add everything to righ.
    for (unsigned i = currentPos.getCharIndex() + 1; i < 8 ; ++i) {
        ret.append(CBoardPosition(currentPos.getNumber(), i));
    }

    // Add everything to up.
    for (unsigned i = currentPos.getNumber() + 1; i < 8 ; ++i) {
        ret.append(CBoardPosition(i, currentPos.getCharIndex()));
    }

    // Add everything to down.
    for (unsigned i = 0; i < currentPos.getNumber(); ++i) {
        ret.append(CBoardPosition(i, currentPos.getCharIndex()));
    }
    return ret;
}

PositionVector_t CChessPiece::getAllRechablePositionsBishop(const CBoardPosition& currentPos) const {
    PositionVector_t ret;
    // Add everything to up left.
    unsigned i = currentPos.getNumber();
    unsigned j = currentPos.getCharIndex();
    Q_ASSERT(i <= 7);
    Q_ASSERT(j <= 7);
    while (true) {
        if (i == 7) {
          break;
        }
        if (j == 0) {
          break;
        }
        ++i;
        --j;
        ret.append(CBoardPosition(i, j));
    }

    // Add everything to up righ.
    i = currentPos.getNumber();
    j = currentPos.getCharIndex();
    while (true) {
        if (i == 7) {
          break;
        }
        if (j == 7) {
          break;
        }
        ++i;
        ++j;
        ret.append(CBoardPosition(i, j));
    }

    // Add everything to dawn left.
    i = currentPos.getNumber();
    j = currentPos.getCharIndex();
    while (true) {
        if (i == 0) {
          break;
        }
        if (j == 0) {
          break;
        }
        --i;
        --j;
        ret.append(CBoardPosition(i, j));
    }

    // Add everything to down righ.
    i = currentPos.getNumber();
    j = currentPos.getCharIndex();
    while (true) {
        if (i == 0) {
          break;
        }
        if (j == 7) {
          break;
        }
        --i;
        ++j;
        ret.append(CBoardPosition(i, j));
    }
    return ret;
}

char getSymbolFromType(const CChessPieceType& type) {
    switch (type) {
    case CChessPieceType::KING: return 'K';
    case CChessPieceType::QUEEN: return 'Q';
    case CChessPieceType::ROOK: return 'R';
    case CChessPieceType::BISHOP: return 'B';
    case CChessPieceType::KNIGHT: return 'N';
    case CChessPieceType::PAWN: return 'P';
    default: Q_ASSERT(false); return '\0';
    }
    return '\0';
}
