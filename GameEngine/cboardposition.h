#ifndef CBOARDPOSITION_H
#define CBOARDPOSITION_H


class CBoardPosition
{
public:
    CBoardPosition();
    CBoardPosition(const CBoardPosition& other);
    CBoardPosition& operator=(const CBoardPosition& other);

    int getNumber() const;
    int getCharIndex() const;
    char getChar() const;

    // set functions
    void setNumber(const int& newNumber);
    void setCharIndex(const int& newCharIndex);
    void setNewPosition(const CBoardPosition& newPos);
    void setNewPosition(const int& newNumber, const int& newCharIndex);

private:
    int _number; // 1 - 8
    int _charIndex; // 1 - 8 for A - H respectivly
};

#endif // CBOARDPOSITION_H
