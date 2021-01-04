QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    grupypanel.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    pracownikpanel.cpp \
    sqlmodify.cpp \
    sqlmodifykurs.cpp \
    sqlmodifypracownik.cpp \
    startpanel.cpp \
    tableedit_base.cpp \
    tableedit_kursy_pracownik.cpp \
    tableedit_kursy_student.cpp \
    tableedit_pracownik.cpp \
    zajeciapanel.cpp

HEADERS += \
    grupypanel.h \
    login.h \
    mainwindow.h \
    pracownikpanel.h \
    sqlmodify.h \
    sqlmodifykurs.h \
    sqlmodifypracownik.h \
    startpanel.h \
    tableedit_base.h \
    tableedit_kursy_pracownik.h \
    tableedit_kursy_student.h \
    tableedit_pracownik.h \
    zajeciapanel.h

FORMS += \
    grupypanel.ui \
    login.ui \
    pracownikpanel.ui \
    sqlmodify.ui \
    sqlmodifykurs.ui \
    sqlmodifypracownik.ui \
    startpanel.ui \
    tableedit_base.ui \
    tableedit_kursy_pracownik.ui \
    tableedit_kursy_student.ui \
    tableedit_pracownik.ui \
    zajeciapanel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
