QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

DEFINES += QT_DEPRECATED_WARNINGS

QMAKE_LFLAGS_RELEASE += -static -static-libgcc

VERSION = 1.0.3.1
QMAKE_TARGET_COMPANY = ORCs cast
QMAKE_TARGET_PRODUCT = ORCs SBT
QMAKE_TARGET_COPYRIGHT = Andrey Krutikhin
QMAKE_TARGET_DESCRIPTION = Scoreboard tool for valorant
RC_ICONS = resurces/SMOrc_icon.ico

SOURCES += \
    about.cpp \
    buttons.cpp \
    filecontrol.cpp \
    main.cpp \
    mainwindow.cpp \
    mwindow.cpp \
    texteditor.cpp

HEADERS +=

FORMS += \
    about.ui \
    mainwindow.ui \
    texteditor.ui

TRANSLATIONS += \
    Val_Scoreboard_Tool_en.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resurces.qrc
