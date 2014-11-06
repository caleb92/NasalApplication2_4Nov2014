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
        mainwindow.cpp \
    ../../../../stasm4.1.0/stasm/asm.cpp \
    ../../../../stasm4.1.0/stasm/classicdesc.cpp \
    ../../../../stasm4.1.0/stasm/convshape.cpp \
    ../../../../stasm4.1.0/stasm/err.cpp \
    ../../../../stasm4.1.0/stasm/eyedet.cpp \
    ../../../../stasm4.1.0/stasm/eyedist.cpp \
    ../../../../stasm4.1.0/stasm/faceroi.cpp \
    ../../../../stasm4.1.0/stasm/hat.cpp \
    ../../../../stasm4.1.0/stasm/hatdesc.cpp \
    ../../../../stasm4.1.0/stasm/landmarks.cpp \
    ../../../../stasm4.1.0/stasm/misc.cpp \
    ../../../../stasm4.1.0/stasm/pinstart.cpp \
    ../../../../stasm4.1.0/stasm/print.cpp \
    ../../../../stasm4.1.0/stasm/shape17.cpp \
    ../../../../stasm4.1.0/stasm/shapehacks.cpp \
    ../../../../stasm4.1.0/stasm/shapemod.cpp \
    ../../../../stasm4.1.0/stasm/startshape.cpp \
    ../../../../stasm4.1.0/stasm/stasm.cpp \
    ../../../../stasm4.1.0/stasm/stasm_lib.cpp \
    ../../../../stasm4.1.0/stasm/MOD_1/facedet.cpp \
    ../../../../stasm4.1.0/stasm/MOD_1/initasm.cpp

HEADERS  += mainwindow.h \
    ../../../../stasm4.1.0/stasm/asm.h \
    ../../../../stasm4.1.0/stasm/atface.h \
    ../../../../stasm4.1.0/stasm/basedesc.h \
    ../../../../stasm4.1.0/stasm/classicdesc.h \
    ../../../../stasm4.1.0/stasm/convshape.h \
    ../../../../stasm4.1.0/stasm/err.h \
    ../../../../stasm4.1.0/stasm/eyedet.h \
    ../../../../stasm4.1.0/stasm/eyedist.h \
    ../../../../stasm4.1.0/stasm/faceroi.h \
    ../../../../stasm4.1.0/stasm/hat.h \
    ../../../../stasm4.1.0/stasm/hatdesc.h \
    ../../../../stasm4.1.0/stasm/landmarks.h \
    ../../../../stasm4.1.0/stasm/landtab_muct77.h \
    ../../../../stasm4.1.0/stasm/misc.h \
    ../../../../stasm4.1.0/stasm/pinstart.h \
    ../../../../stasm4.1.0/stasm/print.h \
    ../../../../stasm4.1.0/stasm/shape17.h \
    ../../../../stasm4.1.0/stasm/shapehacks.h \
    ../../../../stasm4.1.0/stasm/shapemod.h \
    ../../../../stasm4.1.0/stasm/startshape.h \
    ../../../../stasm4.1.0/stasm/stasm.h \
    ../../../../stasm4.1.0/stasm/stasm_landmarks.h \
    ../../../../stasm4.1.0/stasm/stasm_lib.h \
    ../../../../stasm4.1.0/stasm/stasm_lib_ext.h \
    ../../../../stasm4.1.0/stasm/MOD_1/facedet.h \
    ../../../../stasm4.1.0/stasm/MOD_1/initasm.h

FORMS    += mainwindow.ui

RESOURCES += \
    NasalApplication2.qrc

INCLUDEPATH += C:\\OpenCV-2.3.1\\opencv\\build\\include
INCLUDEPATH += C:\\stasm4.1.0\\stasm

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

OTHER_FILES += \
    ../../../../stasm4.1.0/stasm/MOD_1/README.txt
