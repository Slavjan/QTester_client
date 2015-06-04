TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp

DISTFILES += \
    main.qml \
    Content/Welcome.qml \
    Content/Testing/Process.qml \
    Content/Testing/Configure.qml \
    Content/Testing/AnswerForms/RadioForm.qml \
    Content/Testing/AnswerForms/CheckForm.qml \
    Content/Testing/AnswerForms/TextForm.qml \
    Content/Testing/AnswerForms/RegexpForm.qml \
    Content/User.js

# Additional import path used to resolve QML modules in Qt Creator's code model
#QML_IMPORT_PATH = .

# Default rules for deployment.
#include(deployment.pri)

RESOURCES += \
    qml.qrc
