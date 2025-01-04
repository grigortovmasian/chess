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

char getSymbolFromType(const CChessPieceType& type) {
    switch (type) {
    case CChessPieceType::KING: return 'K';
    case CChessPieceType::QUEEN: return 'Q';
    case CChessPieceType::ROCK: return 'R';
    case CChessPieceType::BISHOP: return 'B';
    case CChessPieceType::KNIGHT: return 'N';
    case CChessPieceType::PAWN: return 'P';
    default: Q_ASSERT(false); return '\0';
    }
    return '\0';
}
