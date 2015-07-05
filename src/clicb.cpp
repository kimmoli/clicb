/*
 * Clipboard sample
*/


#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include <QtQml>
#include <QScopedPointer>
#include <QQuickView>
#include <QQmlEngine>
#include <QGuiApplication>
#include <QQmlContext>
#include <QCoreApplication>
#include <QClipboard>
#include <QTimer>

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
        
        QString buffer;

        QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

        if (argc > 1)
        {
            buffer = QString(argv[1]);
            app->clipboard()->setText(buffer);
        }

        QTimer *t = new QTimer();
        t->singleShot(10, app.data(), SLOT(quit()));

        return app->exec();
    }
    else
    {
        printf("höh\n");
    }

    return 0;
}

