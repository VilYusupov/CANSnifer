TEMPLATE = app
TARGET = CANSnifer
QT += core \
    gui
HEADERS += handlers/TemperatureHandler.h \
    handlers/iDataParser.h \
    handlers/AbsPositionHandler.h \
    handlers/ManupulatorPositionsHandler.h \
    iMsgHandler.h \
    Logger.h \
    LoggerMessage.h \
    cansnifer.h \
    CanOperator.h
SOURCES += handlers/TemperatureHandler.cpp \
    handlers/AbsPositionHandler.cpp \
    handlers/ManupulatorPositionsHandler.cpp \
    Logger.cpp \
    LoggerMessage.cpp \
    CANMSG.cpp \
    CANMSGRequest.cpp \
    CanOperator.cpp \
    main.cpp \
    cansnifer.cpp
FORMS += cansnifer.ui
RESOURCES += 
LIBS += "release/vs_can_api.dll"
