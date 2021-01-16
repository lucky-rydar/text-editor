#include "baseplugin.h"

BasePlugin::BasePlugin(QMainWindow *mainWindow, QObject *parent) : QObject(parent)
{
    this->mainWindow = mainWindow;
}
