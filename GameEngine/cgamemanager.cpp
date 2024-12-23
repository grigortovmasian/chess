#include "cgamemanager.h"

#include <QBrush>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include "ChessPieces/cchesspiecebishop.h"
#include "ChessPieces/cchesspieceking.h"
#include "ChessPieces/cchesspieceknight.h"
#include "ChessPieces/cchesspiecepawn.h"
#include "ChessPieces/cchesspiecequeen.h"
#include "ChessPieces/cchesspiecerock.h"

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
        QVector<QGraphicsRectItem*> row;
        for (unsigned j = 0; j < boardSize; ++j) {
            row.push_back(nullptr);
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
          _board[boardSize - i - 1][j] = cell;
        }
    }
}

void CGameManager::createChessPieces() {
    // white
    CChessPieceKing* whiteKing = new CChessPieceKing("white-king",_board[0][4]);

    // black
}
