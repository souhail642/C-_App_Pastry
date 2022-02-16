QT       += core gui sql network printsupport multimedia serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chat.cpp \
    commentaire.cpp \
    connexion.cpp \
    dialog.cpp \
    employee.cpp \
    equipement.cpp \
    evaluation.cpp \
    evenement.cpp \
    main.cpp \
    accueil.cpp \
    recette.cpp \
    reclamation.cpp \
    reparateur.cpp \
    reparation.cpp \
    smtp.cpp \
    qcustomplot.cpp \
    stati.cpp \
    conge.cpp \
    todolist.cpp

HEADERS += \
    accueil.h \
    chat.h \
    commentaire.h \
    connexion.h \
    dialog.h \
    employee.h \
    equipement.h \
    evaluation.h \
    evenement.h \
    recette.h \
    reclamation.h \
    reparateur.h \
    reparation.h \
    smtp.h \
    qcustomplot.h \
    stati.h \
    conge.h \
    todolist.h

FORMS += \
    accueil.ui \
    dialog.ui \
    stati.ui

libcrypto.so
libssl.so
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc



