#include <QGuiApplication>
#include <QIcon>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "period.h"
#include "androidquirks.h"

int main(int argc, char *argv[])
{
    QGuiApplication::setApplicationName(applicationName);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QIcon::setThemeName(applicationName);
    QGuiApplication app(argc, argv);

#ifdef ANDROIDQUIRKS_H
    qInstallMessageHandler(myMessageHandler);
#endif

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    //Create an instance of Period which will be available as Property in main.qml.
    //for this purpose we use the "setContextProperty()" method
    engine.rootContext()->setContextProperty("Period", new Period(&engine));
    qInfo() << Q_FUNC_INFO << " ... Created an instance of the Period Class";

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
