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

CChessPiece::~CChessPiece() {
    delete _imageGraphicItem;
}

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

void CChessPiece::changeParentItem(QGraphicsItem* parent) {
    _imageGraphicItem->setParentItem(parent);
}

PositionVecVec_t CChessPiece::getAllRechablePositionsRook(const CBoardPosition& currentPos) const {
    PositionVecVec_t ret;
    // Add everything to left.
    PositionVec_t vecLeft;
    for (unsigned i = 0; i < currentPos.getCharIndex(); ++i) {
        vecLeft.append(CBoardPosition(currentPos.getNumber(), i));
    }
    ret.append(vecLeft);

    // Add everything to righ.
    PositionVec_t vecRight;
    for (unsigned i = currentPos.getCharIndex() + 1; i < 8 ; ++i) {
        vecRight.append(CBoardPosition(currentPos.getNumber(), i));
    }
    ret.append(vecRight);

    // Add everything to up.
    PositionVec_t vecUp;
    for (unsigned i = currentPos.getNumber() + 1; i < 8 ; ++i) {
        vecUp.append(CBoardPosition(i, currentPos.getCharIndex()));
    }
    ret.append(vecUp);

    // Add everything to down.
    PositionVec_t vecDown;
    for (unsigned i = 0; i < currentPos.getNumber(); ++i) {
        vecDown.append(CBoardPosition(i, currentPos.getCharIndex()));
    }
    ret.append(vecDown);

    return ret;
}

PositionVecVec_t CChessPiece::getAllRechablePositionsBishop(const CBoardPosition& currentPos) const {
    PositionVecVec_t ret;
    unsigned i = currentPos.getNumber();
    unsigned j = currentPos.getCharIndex();
    Q_ASSERT(i <= 7);
    Q_ASSERT(j <= 7);

    // Add everything to up left.
    PositionVec_t vecUpLeft;
    while (true) {
        if (i == 7) {
          break;
        }
        if (j == 0) {
          break;
        }
        ++i;
        --j;
        vecUpLeft.append(CBoardPosition(i, j));
    }
    ret.append(vecUpLeft);

    // Add everything to up righ.
    PositionVec_t vecUpRigth;
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
        vecUpRigth.append(CBoardPosition(i, j));
    }
    ret.append(vecUpRigth);

    // Add everything to dawn left.
    PositionVec_t vecDawnLeft;
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
        vecDawnLeft.append(CBoardPosition(i, j));
    }
    ret.append(vecDawnLeft);

    // Add everything to down righ.
    PositionVec_t vecDownRight;
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
        vecDownRight.append(CBoardPosition(i, j));
    }
    ret.append(vecDownRight);
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
