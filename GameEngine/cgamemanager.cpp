#include "cgamemanager.h"

#include <QBrush>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include "ChessPieces/cchesspiecebishop.h"
#include "ChessPieces/cchesspieceking.h"
#include "ChessPieces/cchesspieceknight.h"
#include "ChessPieces/cchesspiecepawn.h"
#include "ChessPieces/cchesspiecequeen.h"
#include "ChessPieces/cchesspiecerook.h"

constexpr unsigned boardSize = 8;

QColor colorBrown(150, 77, 34);
QColor colorLighBrown(238, 220, 151);

CGameManager::CGameManager() {}

void CGameManager::init(QGraphicsScene* scene) {
    // create QGraphicsItem cells and assign to correct index
    createBoardCells(scene);

    // Now add pieces on board
    createChessPieces();
}

void CGameManager::createBoardCells(QGraphicsScene* scene) {
    for (unsigned i = 0; i < boardSize; ++i) {
        for (unsigned j = 0; j < boardSize; ++j) {
          QGraphicsRectItem * cell = new QGraphicsRectItem(0,0,40,40);
          if ((i + j) % 2 == 1) {
              cell->setBrush(colorBrown);
          } else {
              cell->setBrush(colorLighBrown);
          }
          cell->setPos(j*40, i*40);
          scene->addItem(cell);
          _boardItems.insert({boardSize - i - 1, j}, cell);
        }
    }
}

QBrush CGameManager::defaultSelectedColor;

void CGameManager::createChessPieces() {
    // white
    bool isWhite = true;

    CChessPiece* piece = nullptr;

    CBoardPosition pos(0, 4);
    piece = new CChessPieceKing(isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;

    pos = CBoardPosition(0, 3);
    piece = new CChessPieceQueen(isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;

    pos = CBoardPosition(0, 0);
    piece = new CChessPieceRook(isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;

    pos = CBoardPosition(0, 7);
    piece = new CChessPieceRook(isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;

    pos = CBoardPosition(0, 2);
    piece = new CChessPieceBishop(isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;

    pos = CBoardPosition(0, 5);
    piece = new CChessPieceBishop(isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;

    pos = CBoardPosition(0, 1);
    piece = new CChessPieceKnight(isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;

    pos = CBoardPosition(0, 6);
    piece = new CChessPieceKnight(isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;

    for (unsigned i = 0 ; i < 8 ; ++i) {
        pos = CBoardPosition(1, i);
        piece = new CChessPiecePawn(isWhite, _boardItems[pos]);
        _pieceToPosMap[piece] = pos;
    }

    // black
    pos = CBoardPosition(7, 4);
    piece = new CChessPieceKing(!isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;

    pos = CBoardPosition(7, 3);
    piece = new CChessPieceQueen(!isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;

    pos = CBoardPosition(7, 0);
    piece = new CChessPieceRook(!isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;

    pos = CBoardPosition(7, 7);
    piece = new CChessPieceRook(!isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;

    pos = CBoardPosition(7, 2);
    piece = new CChessPieceBishop(!isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;

    pos = CBoardPosition(7, 5);
    piece = new CChessPieceBishop(!isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;

    pos = CBoardPosition(7, 1);
    piece = new CChessPieceKnight(!isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;

    pos = CBoardPosition(7, 6);
    piece = new CChessPieceKnight(!isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;

    for (unsigned i = 0 ; i < 8 ; ++i) {
        pos = CBoardPosition(6, i);
        piece = new CChessPiecePawn(!isWhite, _boardItems[pos]);
        _pieceToPosMap[piece] = pos;
    }
}

void CGameManager::itemSelected(const QList<QGraphicsItem*>& selectedItems) {
    for (QGraphicsItem* item : selectedItems) {
        QGraphicsRectItem* selectedItemCustom = dynamic_cast<QGraphicsRectItem*>(item);
        if (selectedItemCustom) {
            if (_currentSelectedItem) {
                // here we analyze if the selected pos possible destination for selected piece
                // is move possible ? do it else keep it
                // if it's selected object than simply unselect it
                selectedItemCustom->setBrush(defaultSelectedColor);
                _currentSelectedItem = nullptr;
            } else {
                _currentSelectedItem = selectedItemCustom;
                defaultSelectedColor = selectedItemCustom->brush();
                selectedItemCustom->setBrush(Qt::green);
            }
        }
    }
}
