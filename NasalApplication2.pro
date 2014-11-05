#-------------------------------------------------
#
# Project created by QtCreator 2014-11-02T22:22:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NasalApplication2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    NasalApplication2.qrc

INCLUDEPATH += C:\\OpenCV-2.3.1\\opencv\\build\\include

#OpneCV libraries
LIBS += -LC:\\OpenCV-2.3.1\\mybuild\\lib\\Debug \
  -lopencv_calib3d231d \
  -lopencv_contrib231d \
  -lopencv_core231d \
  -lopencv_features2d231d \
  -lopencv_flann231d \
  -lopencv_gpu231d \
  -lopencv_highgui231d \
  -lopencv_imgproc231d \
  -lopencv_legacy231d \
  -lopencv_ml231d \
  -lopencv_objdetect231d \
  -lopencv_video231d
# -lopencv_ts231d \
