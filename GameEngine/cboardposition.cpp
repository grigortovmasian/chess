#include "cboardposition.h"

#include <QtGlobal>

CBoardPosition::CBoardPosition(unsigned row, unsigned column) :
    _number(row),
    _charIndex(column) {
}

CBoardPosition::CBoardPosition(const CBoardPosition &other) :
    _number(other._number),
    _charIndex(other._charIndex) {

}

CBoardPosition& CBoardPosition::operator=(const CBoardPosition &other) {
    setNumber(other.getNumber());
    setCharIndex(other.getCharIndex());

    return (*this);
}

unsigned CBoardPosition::getNumber() const {
    return _number;
}

unsigned CBoardPosition::getCharIndex() const {
    return _charIndex;
}

char CBoardPosition::getChar() const {
    Q_ASSERT(_charIndex >= 1 && _charIndex <= 8);
    return char(64 + _charIndex);

}

void CBoardPosition::setNumber(const unsigned& newNumber) {
    _number = newNumber;

}

void CBoardPosition::setCharIndex(const unsigned& newCharIndex) {
    _charIndex = newCharIndex;
}

void CBoardPosition::setNewPosition(const CBoardPosition& newPos) {
    (*this) = newPos;
}

void CBoardPosition::setNewPosition(const unsigned& newNumber, const unsigned& newCharIndex) {
    setNumber(newNumber);
    setCharIndex(newCharIndex);
}

unsigned qHash(const CBoardPosition &pos) {
    return pos.getNumber() * 8 + pos.getCharIndex();
}
