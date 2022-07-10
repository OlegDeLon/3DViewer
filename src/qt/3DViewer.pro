QT       += core gui
include(../../QTGifimage-master/src/gifimage/qtgifimage.pri)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT += widgets opengl openglwidgets
#LIBS +=-lopengl32 -lglu32

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#DEFINES += GL_SILENCE_DEPRECATION

SOURCES += \
    ../afini.c \
    geometry.cpp \
    main.cpp \
    mainwindow.cpp \
    ../parse.c \
    ../s21_matrix.c \
    widget.cpp

HEADERS += \
    ../afini.h \
    geometry.h \
    mainwindow.h \
    ../parse.h \
    ../s21_matrix.h \
    widget.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../QtGifImage-master/src/gifimage/qtgifimage.pri \
    ashader.vsh \
    cube_norm.obj \
    fshader.fsh \
    fshader.glsl \
    vshader.glsl \
    vshader.glsl \
    vshader.vsh

RESOURCES += \
    fshader.qrc \
    fshader.qrc \
    vshader.qrc
