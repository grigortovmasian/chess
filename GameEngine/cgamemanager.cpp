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
          cell->setPos(j*40, i*40);
          scene->addItem(cell);
          _boardItems.insert({boardSize - i - 1, j}, cell);
          _itemToPosMap.insert(cell, {boardSize - i - 1, j});
          setDefaultColor(cell, {boardSize - i - 1, j});
        }
    }
}

void CGameManager::createChessPieces() {
    // white
    bool isWhite = true;

    CChessPiece* piece = nullptr;

    CBoardPosition pos(0, 4);
    piece = new CChessPieceKing(isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;
    _itemToPieceMap[_boardItems[pos]] = piece;

    pos = CBoardPosition(0, 3);
    piece = new CChessPieceQueen(isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;
    _itemToPieceMap[_boardItems[pos]] = piece;

    pos = CBoardPosition(0, 0);
    piece = new CChessPieceRook(isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;
    _itemToPieceMap[_boardItems[pos]] = piece;

    pos = CBoardPosition(0, 7);
    piece = new CChessPieceRook(isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;
    _itemToPieceMap[_boardItems[pos]] = piece;

    pos = CBoardPosition(0, 2);
    piece = new CChessPieceBishop(isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;
    _itemToPieceMap[_boardItems[pos]] = piece;

    pos = CBoardPosition(0, 5);
    piece = new CChessPieceBishop(isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;
    _itemToPieceMap[_boardItems[pos]] = piece;

    pos = CBoardPosition(0, 1);
    piece = new CChessPieceKnight(isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;
    _itemToPieceMap[_boardItems[pos]] = piece;

    pos = CBoardPosition(0, 6);
    piece = new CChessPieceKnight(isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;
    _itemToPieceMap[_boardItems[pos]] = piece;

    for (unsigned i = 0 ; i < 8 ; ++i) {
        pos = CBoardPosition(1, i);
        piece = new CChessPiecePawn(isWhite, _boardItems[pos]);
        _pieceToPosMap[piece] = pos;
        _itemToPieceMap[_boardItems[pos]] = piece;
    }

    // black
    pos = CBoardPosition(7, 4);
    piece = new CChessPieceKing(!isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;
    _itemToPieceMap[_boardItems[pos]] = piece;

    pos = CBoardPosition(7, 3);
    piece = new CChessPieceQueen(!isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;
    _itemToPieceMap[_boardItems[pos]] = piece;

    pos = CBoardPosition(7, 0);
    piece = new CChessPieceRook(!isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;
    _itemToPieceMap[_boardItems[pos]] = piece;

    pos = CBoardPosition(7, 7);
    piece = new CChessPieceRook(!isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;
    _itemToPieceMap[_boardItems[pos]] = piece;

    pos = CBoardPosition(7, 2);
    piece = new CChessPieceBishop(!isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;
    _itemToPieceMap[_boardItems[pos]] = piece;

    pos = CBoardPosition(7, 5);
    piece = new CChessPieceBishop(!isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;
    _itemToPieceMap[_boardItems[pos]] = piece;

    pos = CBoardPosition(7, 1);
    piece = new CChessPieceKnight(!isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;
    _itemToPieceMap[_boardItems[pos]] = piece;

    pos = CBoardPosition(7, 6);
    piece = new CChessPieceKnight(!isWhite, _boardItems[pos]);
    _pieceToPosMap[piece] = pos;
    _itemToPieceMap[_boardItems[pos]] = piece;

    for (unsigned i = 0 ; i < 8 ; ++i) {
        pos = CBoardPosition(6, i);
        piece = new CChessPiecePawn(!isWhite, _boardItems[pos]);
        _pieceToPosMap[piece] = pos;
        _itemToPieceMap[_boardItems[pos]] = piece;
    }
}

void CGameManager::setDefaultColor(QGraphicsRectItem* item, const CBoardPosition& pos) {
    if (pos.isBrown()) {
        item->setBrush(colorBrown);
    } else {
        item->setBrush(colorLighBrown);
    }
}

void CGameManager::movePiece(QGraphicsRectItem* newItem) {
    // firt check if spot is open
    CChessPiece* pieceInNewPos = _itemToPieceMap[newItem];
    CChessPiece* currentPiece = _itemToPieceMap[_currentSelectedItem];
    Q_ASSERT(currentPiece);
    if (pieceInNewPos) {
        // capture scenario;
        pieceInNewPos->changeParentItem(nullptr);
        delete pieceInNewPos;
        pieceInNewPos = nullptr;
        _pieceToPosMap.remove(pieceInNewPos);
    }
    // handle internal maps
    currentPiece->changeParentItem(newItem);
    _itemToPieceMap[_currentSelectedItem] = nullptr;
    _itemToPieceMap[newItem] = currentPiece;
    _pieceToPosMap [currentPiece] = _itemToPosMap[newItem];
    _currentMove = !_currentMove;
}

void CGameManager::resetSelectedItem() {
    setDefaultColor(_currentSelectedItem, _itemToPosMap[_currentSelectedItem]);
    _currentSelectedItem = nullptr;
    for (const QVector<CBoardPosition>& posVec : _possibleMoves) {
        for (const CBoardPosition& pos : posVec) {
            setDefaultColor(_boardItems[pos], pos);
        }
    }
    _possibleMoves.clear();
}

bool CGameManager::isSelectedPositionReachable(QGraphicsRectItem* newItem) const {
    Q_ASSERT(newItem);
    for (const QVector<CBoardPosition>& posVec : _possibleMoves) {
        if  (posVec.contains(_itemToPosMap[newItem])) {
            return true;
        }
    }
    return false;
}

void CGameManager::itemSelected(const QList<QGraphicsItem*>& selectedItems) {
    for (QGraphicsItem* item : selectedItems) {
        QGraphicsRectItem* selectedItemCustom = dynamic_cast<QGraphicsRectItem*>(item);
        if (selectedItemCustom) {
            if (_currentSelectedItem) {
                // If we selected the selected item again that's mean we just need to undo the color change
                if (_currentSelectedItem == selectedItemCustom) {
                    resetSelectedItem();
                } else if (isSelectedPositionReachable(selectedItemCustom)) {
                    // okay here we will do the move
                    movePiece(selectedItemCustom);
                    resetSelectedItem();
                } else {
                    // do nothing
                }
                // here we analyze if the selected pos possible destination for selected piece
                // is move possible ? do it else keep it
                // if it's selected object than simply unselect it

            } else {                
                CChessPiece* currentPiece = _itemToPieceMap[selectedItemCustom];
                if (currentPiece && currentPiece->isWhitePiece() == isWhiteMove()) {
                    // there is some piece
                    _currentSelectedItem = selectedItemCustom;
                    selectedItemCustom->setBrush(Qt::green);
                    // Now get possible moves
                    _possibleMoves = currentPiece->getAllRechablePositions(_pieceToPosMap[currentPiece]);
                    // higligth them
                    for (const QVector<CBoardPosition>& posVec : _possibleMoves) {
                        for (const CBoardPosition& pos : posVec) {
                            QGraphicsRectItem* item = _boardItems[pos];
                            item->setBrush(Qt::red);
                        }
                    }
                }
            }
            break;
        }
    }
}
