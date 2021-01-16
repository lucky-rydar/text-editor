#ifndef BASEPLUGIN_H
#define BASEPLUGIN_H

#include <QObject>
#include <QMainWindow>
#include "mainwindow.h"

class BasePlugin : public QObject
{
    Q_OBJECT
public:
    BasePlugin(MainWindow *mainWindow, QObject *parent = nullptr);

    virtual QString getName() = 0;
    virtual QString getVersion() = 0;
    virtual QString getDeveloper() = 0;

    MainWindow* mainWindow;
private:

signals:

};

#endif // BASEPLUGIN_H
