#include <QApplication>
#include <QQmlApplicationEngine>

#include <QDir>
#include <QQmlContext>

QString getUserName()
{
    //* Variant #1 : simple
    return QDir().home().dirName();
    // */
    /* Variant #2
    QString name;
    name = qgetenv(“USER”); // get the user name in Linux
    if( name.isEmpty() ){
        name = qgetenv(“USERNAME”); // get the name in Windows
    }
    // */
    //* Variant #3
    // google it: http://qt-project.org/forums/viewthread/11951
    // */
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("LibertaSoft");
    app.setOrganizationDomain("LibertaSoft@QTester");
    app.setApplicationName("QTester");
    app.setApplicationDisplayName("QTester");
    app.setApplicationVersion("0.0.0 Pre-Aplha");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("username", getUserName() );
//    engine.rootContext()->setContextProperty("Database", db );
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    return app.exec();
}
