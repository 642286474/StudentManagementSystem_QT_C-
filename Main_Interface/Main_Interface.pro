QT       += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    caozuo.cpp \
    chaxun.cpp \
    guanli.cpp \
    guanyu.cpp \
    main.cpp \
    main_interface.cpp \
    shanchu.cpp \
    xiugai.cpp \
    yonghuxinxi.cpp \
    zengjia.cpp \
    zhuce.cpp

HEADERS += \
    caozuo.h \
    chaxun.h \
    guanli.h \
    guanyu.h \
    main_interface.h \
    shanchu.h \
    xiugai.h \
    yonghuxinxi.h \
    zengjia.h \
    zhuce.h

FORMS += \
    caozuo.ui \
    chaxun.ui \
    guanli.ui \
    guanyu.ui \
    main_interface.ui \
    shanchu.ui \
    xiugai.ui \
    yonghuxinxi.ui \
    zengjia.ui \
    zhuce.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
