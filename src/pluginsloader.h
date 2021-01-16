#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include <QObject>
#include <QList>
#include <QLibrary>
#include <QDir>
#include <QDebug>
#include <QLibrary>
#include "baseplugin.h"
#include "mainwindow.h"

typedef BasePlugin* (*BasePluginCreator)(QWidget*, QObject*);

class PluginsLoader : public QObject
{
    Q_OBJECT
public:
    explicit PluginsLoader(MainWindow *mainWindow, QObject *parent = nullptr);

public:
    void load();

private:
    QDir pluginsDir;
    QList<BasePlugin*> loadedPlugins;
    MainWindow *mainWindow;

signals:

};

#endif // PLUGINLOADER_H
