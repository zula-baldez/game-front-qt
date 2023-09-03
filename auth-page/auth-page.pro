QT += quick networkauth

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        authrorizedmanager.cpp \
        base_auth_handler.cpp \
        google_auth_handler.cpp \
        main.cpp \
        vk_oauth_handler.cpp

RESOURCES += qml.qrc
LIBS += -lqhttpserver
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    UI/Assets/g+.svg \
    UI/Assets/vk.svg \
    qml/StyleSettings/Style.qml \
    qml/StyleSettings/qmldir

HEADERS += \
    auth_handler.h \
    authrorizedmanager.h \
    base_auth_handler.h \
    google_auth_handler.h \
    vk_oauth_handler.h
