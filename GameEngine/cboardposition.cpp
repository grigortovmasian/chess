#include "cboardposition.h"

#include <QtGlobal>

CBoardPosition::CBoardPosition() :
    _number(0),
    _charIndex(0) {
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

int CBoardPosition::getNumber() const {
    return _number;
}

int CBoardPosition::getCharIndex() const {
    return _charIndex;
}

char CBoardPosition::getChar() const {
    Q_ASSERT(_charIndex >= 1 && _charIndex <= 8);
    return char(64 + _charIndex);

}

void CBoardPosition::setNumber(const int& newNumber) {
    _number = newNumber;

}

void CBoardPosition::setCharIndex(const int& newCharIndex) {
    _charIndex = newCharIndex;
}

void CBoardPosition::setNewPosition(const CBoardPosition& newPos) {
    (*this) = newPos;
}

void CBoardPosition::setNewPosition(const int& newNumber, const int& newCharIndex) {
    setNumber(newNumber);
    setCharIndex(newCharIndex);
}
