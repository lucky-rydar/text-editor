#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include <QObject>
#include <QList>
#include <QLibrary>
#include <QDir>

class PluginsLoader : public QObject
{
    Q_OBJECT
public:
    explicit PluginsLoader(QObject *parent = nullptr);

private:
    QDir pluginsDir;
signals:

};

#endif // PLUGINLOADER_H
