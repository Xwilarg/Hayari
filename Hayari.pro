QT       += core gui widgets

TARGET = Hayari
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++11

SOURCES += \
        src/main.cpp \
        src/MainWindow.cpp

HEADERS += \
        inc/MainWindow.hpp

target.path = .
INSTALLS += target
