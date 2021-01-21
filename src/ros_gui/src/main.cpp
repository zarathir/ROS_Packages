#include <QGuiApplication>
#include <QQmlApplicationEngine>
//#include <QQmlContext>

//#include "appcore.h"

int main(int argc, char *argv[])
{

    //AppCore appCore;

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    //QQmlContext *context = engine.rootContext();

    //context->setContextProperty("appCore", &appCore);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}