#include <QGuiApplication>
#include <QCoreApplication>
#include <QUrl>
#include <QString>
#include <QQuickStyle>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QVector>
#include <QtWebEngine/qtwebengineglobal.h>




int main(int argc, char** argv) {
    QGuiApplication::setOrganizationName("youtube-web.mateo-salta");
    QGuiApplication::setApplicationName("youtube-web.mateo-salta");
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    //QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);

    //qputenv("QTWEBENGINE_CHROMIUM_FLAGS", "");
    
    if (qgetenv("QT_QPA_PLATFORM") == "wayland") {
        qputenv("QT_WAYLAND_SHELL_INTEGRATION", "wl-shell");
        qputenv("QT_SCALE_FACTOR", "1.7");
        qputenv("QT_WEBENGINE_DISABLE_GPU","1");
    }
    
    QGuiApplication app(argc, argv);
    
    QQuickView view;
    view.setFlags(Qt::Window | Qt::WindowTitleHint);
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setColor(Qt::black);
    view.setSource(QUrl("qrc:///app/Main.qml"));
    view.show();
    return app.exec();
}
