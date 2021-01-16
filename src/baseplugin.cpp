#include "baseplugin.h"

BasePlugin::BasePlugin(MainWindow *mainWindow, QObject *parent) : QObject(parent)
{
    this->mainWindow = mainWindow;
}
