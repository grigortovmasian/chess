QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ChessPieces/cchesspiece.cpp \
    ChessPieces/cchesspiecebishop.cpp \
    ChessPieces/cchesspieceking.cpp \
    ChessPieces/cchesspieceknight.cpp \
    ChessPieces/cchesspiecepawn.cpp \
    ChessPieces/cchesspiecequeen.cpp \
    ChessPieces/cchesspiecerock.cpp \
    GameEngine/cboardposition.cpp \
    GameEngine/cgamemanager.cpp \
    main.cpp \
    chessgamewindow.cpp

HEADERS += \
    ChessPieces/cchesspiece.h \
    ChessPieces/cchesspiecebishop.h \
    ChessPieces/cchesspieceking.h \
    ChessPieces/cchesspieceknight.h \
    ChessPieces/cchesspiecepawn.h \
    ChessPieces/cchesspiecequeen.h \
    ChessPieces/cchesspiecerock.h \
    GameEngine/cboardposition.h \
    GameEngine/cgamemanager.h \
    chessgamewindow.h

FORMS += \
    chessgamewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
