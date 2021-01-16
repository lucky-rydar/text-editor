#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include <QObject>
#include <QList>
#include <QLibrary>
#include <QDir>
#include <QDebug>
#include <QLibrary>
#include "baseplugin.h"

typedef BasePlugin* (*BasePluginCreator)(QWidget*, QObject*);

class PluginsLoader : public QObject
{
    Q_OBJECT
public:
    explicit PluginsLoader(QWidget *mainWindow, QObject *parent = nullptr);

public:
    void load();

private:
    QDir pluginsDir;
    QList<BasePlugin*> loadedPlugins;
    QWidget *mainWindow;

signals:

};

#endif // PLUGINLOADER_H
