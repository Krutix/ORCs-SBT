include(src/Src.pri)

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += console

DEFINES += QT_DEPRECATED_WARNINGS

QMAKE_LFLAGS_RELEASE += -static -static-libgcc

VERSION = 1.0.3.1
QMAKE_TARGET_COMPANY = ORCs cast
QMAKE_TARGET_PRODUCT = ORCs SBT
QMAKE_TARGET_COPYRIGHT = Andrey Krutikhin
QMAKE_TARGET_DESCRIPTION = Scoreboard tool for valorant
RC_ICONS = resurces/SMOrc_icon.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resurces.qrc
