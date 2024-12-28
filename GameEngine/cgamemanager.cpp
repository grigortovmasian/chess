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

CGameManager::CGameManager() {}

void CGameManager::init(QGraphicsScene* scene) {
    // create 8x8 board cells with nullptr
    initPositionArray();

    // create QGraphicsRectItem cells and assign to correct index
    createBoardCells(scene);

    // Now add pieces on board
    createChessPieces();
}

void CGameManager::initPositionArray() {
    for (unsigned i = 0; i < boardSize; ++i) {
        QVector<QPair<QGraphicsRectItem*, CChessPiece*>> row;
        for (unsigned j = 0; j < boardSize; ++j) {
            row.push_back({nullptr, nullptr});
        }
        _board.push_back(row);
        Q_ASSERT(row.size() == 8);
    }
    Q_ASSERT(_board.size() == 8);
}

void CGameManager::createBoardCells(QGraphicsScene* scene) {
    QColor colorBrown(150, 77, 34);
    QColor colorLighBrown(238, 220, 151);
    for (unsigned i = 0; i < boardSize; ++i) {
        for (unsigned j = 0; j < boardSize; ++j) {
          QGraphicsRectItem* cell = new QGraphicsRectItem(0,0,40,40);
          if ((i + j) % 2 == 1) {
              cell->setBrush(colorBrown);
          } else {
              cell->setBrush(colorLighBrown);
          }
          cell->setPos(j*40, i*40);
          scene->addItem(cell);
          _board[boardSize - i - 1][j].first = cell;
        }
    }
}

void CGameManager::createChessPieces() {
    // white
    bool isWhite = true;
    _board[0][4].second = new CChessPieceKing(isWhite, _board[0][4].first);
    _board[0][3].second = new CChessPieceQueen(isWhite, _board[0][3].first);
    _board[0][0].second = new CChessPieceRook(isWhite, _board[0][0].first);
    _board[0][7].second = new CChessPieceRook(isWhite, _board[0][7].first);
    _board[0][2].second = new CChessPieceBishop(isWhite, _board[0][2].first);
    _board[0][5].second = new CChessPieceBishop(isWhite, _board[0][5].first);
    _board[0][1].second = new CChessPieceKnight(isWhite, _board[0][1].first);
    _board[0][6].second = new CChessPieceKnight(isWhite, _board[0][6].first);
    _board[1][0].second = new CChessPiecePawn(isWhite, _board[1][0].first);
    _board[1][1].second = new CChessPiecePawn(isWhite, _board[1][1].first);
    _board[1][2].second = new CChessPiecePawn(isWhite, _board[1][2].first);
    _board[1][3].second = new CChessPiecePawn(isWhite, _board[1][3].first);
    _board[1][4].second = new CChessPiecePawn(isWhite, _board[1][4].first);
    _board[1][5].second = new CChessPiecePawn(isWhite, _board[1][5].first);
    _board[1][6].second = new CChessPiecePawn(isWhite, _board[1][6].first);
    _board[1][7].second = new CChessPiecePawn(isWhite, _board[1][7].first);

    // black
    _board[7][4].second = new CChessPieceKing(!isWhite, _board[7][4].first);
    _board[7][3].second = new CChessPieceQueen(!isWhite, _board[7][3].first);
    _board[7][0].second = new CChessPieceRook(!isWhite, _board[7][0].first);
    _board[7][7].second = new CChessPieceRook(!isWhite, _board[7][7].first);
    _board[7][2].second = new CChessPieceBishop(!isWhite, _board[7][2].first);
    _board[7][5].second = new CChessPieceBishop(!isWhite, _board[7][5].first);
    _board[7][1].second = new CChessPieceKnight(!isWhite, _board[7][1].first);
    _board[7][6].second = new CChessPieceKnight(!isWhite, _board[7][6].first);
    _board[6][0].second = new CChessPiecePawn(!isWhite, _board[6][0].first);
    _board[6][1].second = new CChessPiecePawn(!isWhite, _board[6][1].first);
    _board[6][2].second = new CChessPiecePawn(!isWhite, _board[6][2].first);
    _board[6][3].second = new CChessPiecePawn(!isWhite, _board[6][3].first);
    _board[6][4].second = new CChessPiecePawn(!isWhite, _board[6][4].first);
    _board[6][5].second = new CChessPiecePawn(!isWhite, _board[6][5].first);
    _board[6][6].second = new CChessPiecePawn(!isWhite, _board[6][6].first);
    _board[6][7].second = new CChessPiecePawn(!isWhite, _board[6][7].first);
}
