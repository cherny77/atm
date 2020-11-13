QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    atm.cpp \
    card.cpp \
    cardmenuview.cpp \
    cardsview.cpp \
    loginview.cpp \
    main.cpp \
    mainwindow.cpp \
    withdrawrechargeview.cpp

HEADERS += \
    atm.h \
    card.h \
    cardmenuview.h \
    cardsview.h \
    loginview.h \
    mainwindow.h \
    withdrawrechargeview.h

FORMS += \
    cardmenuview.ui \
    cardsview.ui \
    loginview.ui \
    mainwindow.ui \
    withdrawrechargeview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
