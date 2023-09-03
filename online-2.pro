QT += quick core websockets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        StompSocket/stompsocket.cpp \
        auth-page/authrorizedmanager.cpp \
        auth-page/base_auth_handler.cpp \
        auth-page/google_auth_handler.cpp \
        auth-page/vk_oauth_handler.cpp \
        game-field/accountactionstrategy.cpp \
        game-field/allplayersmessagestrategy.cpp \
        game-field/card.cpp \
        game-field/cardmovementstrategy.cpp \
        game-field/connectedstrategy.cpp \
        game-field/gameboard-model.cpp \
        game-field/gamecontroller.cpp \
        game-field/network-controller-game-field.cpp \
        game-field/player.cpp \
        game-field/strategy.cpp \
        game-field/strategycontroller.cpp \
        main.cpp \
        room-choose/gamefieldconnecter.cpp \
        room-choose/network-controller-room.cpp \
        room-choose/room.cpp \
        room-choose/roomcontroller.cpp \
        room-choose/roommodel.cpp

RESOURCES += qml.qrc
LIBS += -lqhttpserver
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH += auth-page-view/qml

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



DISTFILES += \
    auth-page/UI/Assets/g+.svg \
    auth-page/UI/Assets/vk.svg \
    auth-page/qml/ResourceProvider/qmldir \
    auth-page/qml/ResourceProvider/qmldir.qml \
    auth-page/qml/StyleSettings/Style.qml \
    auth-page/qml/StyleSettings/qmldir \
    game-field/UI/Assets/2_bybi.png \
    game-field/UI/Assets/rubashka.jpg \
    game-field/UI/Assets/table-1.jpg \
    game-field/UI/Assets/table.jpg \
    game-field/agregators/GameBoard.qml \
    game-field/basic-components/Card.qml \
    game-field/basic-components/Player.qml \
    room-choose-view/main.qml

HEADERS += \
    StompSocket/stompsocket.h \
    auth-page/auth_handler.h \
    auth-page/authrorizedmanager.h \
    auth-page/base_auth_handler.h \
    auth-page/google_auth_handler.h \
    auth-page/vk_oauth_handler.h \
    game-field/accountactionstrategy.h \
    game-field/allplayersmessagestrategy.h \
    game-field/card.h \
    game-field/cardmovementstrategy.h \
    game-field/connectedstrategy.h \
    game-field/gameboard-model.h \
    game-field/gamecontroller.h \
    game-field/network-controller-game-field.h \
    game-field/player.h \
    game-field/strategy.h \
    game-field/strategycontroller.h \
    room-choose/gamefieldconnecter.h \
    room-choose/network-controller-room.h \
    room-choose/room.h \
    room-choose/roomcontroller.h \
    room-choose/roommodel.h \
    screen-manager/global.h
