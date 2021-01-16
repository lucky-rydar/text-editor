#include "pluginsloader.h"

PluginsLoader::PluginsLoader(QWidget *mainWindow, QObject *parent) : QObject(parent)
{
    pluginsDir = QDir("mod");
    if(!pluginsDir.exists())
        pluginsDir.mkpath(".");

    this->mainWindow = mainWindow;
}

void PluginsLoader::load()
{
    auto pluginsList = this->pluginsDir.entryList(QStringList() << "*.dll", QDir::Files);
    foreach(auto filename, pluginsList)
    {
        QFileInfo fi(pluginsDir.path() + "/" + filename);
        QLibrary plugin(fi.absoluteFilePath());
        plugin.load();


        BasePluginCreator pluginCreator = (BasePluginCreator)plugin.resolve("pluginCreator");
        if(pluginCreator)
            this->loadedPlugins.push_back(pluginCreator(this->mainWindow, this));

        plugin.unload();
    }

}
