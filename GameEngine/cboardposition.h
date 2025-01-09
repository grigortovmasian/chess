#ifndef CBOARDPOSITION_H
#define CBOARDPOSITION_H

class CBoardPosition {
public:
    CBoardPosition(unsigned row = 0, unsigned column = 0);
    CBoardPosition(const CBoardPosition& other);
    CBoardPosition& operator=(const CBoardPosition& other);

    unsigned getNumber() const;
    unsigned getCharIndex() const;
    char getChar() const;

    bool isBrown() const { return  _color; }
    bool isLightBrown() const { return  !_color; }

    // set functions
    void setNumber(const unsigned& newNumber);
    void setCharIndex(const unsigned& newCharIndex);
    void setNewPosition(const CBoardPosition& newPos);
    void setNewPosition(const unsigned& newNumber, const unsigned& newCharIndex);

    bool operator==(const CBoardPosition& other) const {
      return _number == other._number && _charIndex == other._charIndex;
    }

private:
    unsigned _number; // 1 - 8
    unsigned _charIndex; // 1 - 8 for A - H respectivly
    bool     _color{false};
};

unsigned qHash(const CBoardPosition& pos);

#endif // CBOARDPOSITION_H
