#-------------------------------------------------
#
# Project created by QtCreator 2013-01-07T13:23:25
#
#-------------------------------------------------

QT       += core gui

QMAKE_CXXFLAGS += -std=c++0x
LIBS += -lwinmm

#INCLUDEPATH += "C:\\MinGW\\include\\ddk"
#LIBS += "C:\MinGW\\lib\\libkernel32.a"
#win32:LIBS += -lsetupapi
# -lshlwapi

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MicrophoneVolume
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    MixerMicrophoneValue.cpp

HEADERS  += mainwindow.h \
    MixerMicrophoneValue.h

FORMS    += mainwindow.ui
