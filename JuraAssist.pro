#-------------------------------------------------
#
# Project created by QtCreator 2015-09-07T14:35:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JuraAssist
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp \
    mainwindow.cpp

mac {
  HEADERS += ClipboardInterface.h
  OBJECTIVE_SOURCES += ClipboardInterface.mm
  LIBS += -framework Cocoa
}

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

