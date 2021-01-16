#include "pluginsloader.h"

PluginsLoader::PluginsLoader(QObject *parent) : QObject(parent)
{
    pluginsDir = QDir("mod");
    if(!pluginsDir.exists())
        pluginsDir.mkpath(".");
}
