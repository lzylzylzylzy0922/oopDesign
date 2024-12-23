QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accountbindingpagelzy.cpp \
    creategrouppagelzy.cpp \
    databaseconnectionlzy.cpp \
    groupformpagelzy.cpp \
    groupitemframelzy.cpp \
    groupmemberquerylzy.cpp \
    infoformpagelzy.cpp \
    infoitemframelzy.cpp \
    main.cpp \
    mainpagelzy.cpp \
    registerpagelzy.cpp \
    searchforcontactslzy.cpp \
    searchpagelzy.cpp \
    tcpconnectionmanager.cpp \
    userdaolzy.cpp \
    utilsLzy.cpp \
    welcomepagelzy.cpp

HEADERS += \
    AccountLzy.h \
    AccountType.h \
    FriendshipLzy.h \
    FriendshipRequestLzy.h \
    GroupLzy.h \
    GroupMemberLzy.h \
    LoginStatusLzy.h \
    Mode.h \
    UserLzy.h \
    UserServiceLzy.h \
    accountbindingpagelzy.h \
    creategrouppagelzy.h \
    databaseconnectionlzy.h \
    groupformpagelzy.h \
    groupitemframelzy.h \
    groupmemberquerylzy.h \
    infoformpagelzy.h \
    infoitemframelzy.h \
    mainpagelzy.h \
    registerpagelzy.h \
    searchforcontactslzy.h \
    searchpagelzy.h \
    tcpconnectionmanager.h \
    userdaolzy.h \
    utilsLzy.h \
    welcomepagelzy.h

FORMS += \
    accountbindingpagelzy.ui \
    creategrouppagelzy.ui \
    groupformpagelzy.ui \
    groupitemframelzy.ui \
    groupmemberquerylzy.ui \
    infoformpagelzy.ui \
    infoitemframelzy.ui \
    mainpagelzy.ui \
    registerpagelzy.ui \
    searchforcontactslzy.ui \
    searchpagelzy.ui \
    welcomepagelzy.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
