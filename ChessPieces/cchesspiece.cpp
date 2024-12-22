#include "cchesspiece.h"

CChessPiece::CChessPiece(const QString& name) {
    QString path("C:\\Users\\grigo\\QTProjects\\ChessGame\\PiecesPhotos\\");
    path.append(name);
    QPixmap pk(name);

    _imageGraphicItem = new QGraphicsPixmapItem(pk.scaled(40,40), nullptr);

}

CChessPiece::~CChessPiece() {
    if (_imageGraphicItem) {
        delete _imageGraphicItem;
    }
}

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
