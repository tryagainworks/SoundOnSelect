#-------------------------------------------------
#
# Project created by QtCreator 2016-05-15T21:44:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BirdsForBaby
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myqwidget.cpp \
    myqlabel.cpp \
    clsglobal.cpp

HEADERS  += mainwindow.h \
    myqwidget.h \
    myqlabel.h \
    clsglobal.h

FORMS    += mainwindow.ui

CONFIG +=C++11
QT += multimedia

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
