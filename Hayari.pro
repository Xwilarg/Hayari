QT       += core gui widgets webengine webenginewidgets

TARGET = Hayari
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++14

SOURCES += \
        src/BrowseWindow.cpp \
        src/main.cpp \
        src/MainWindow.cpp

HEADERS += \
        inc/BrowseWindow.hpp \
        inc/MainWindow.hpp

target.path = .
INSTALLS += target
