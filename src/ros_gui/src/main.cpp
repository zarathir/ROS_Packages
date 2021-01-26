#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "../include/RobotThread.h"

int main(int argc, char *argv[])
{

    RobotThread robotThread(argc, argv, "gui_command");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext *context = engine.rootContext();

    context->setContextProperty("robotThread", &robotThread);

    const QUrl url(QStringLiteral("qrc:/ui/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
