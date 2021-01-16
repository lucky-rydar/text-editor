#include "baseplugin.h"

BasePlugin::BasePlugin(QWidget *mainWindow, QObject *parent) : QObject(parent)
{
    this->mainWindow = mainWindow;
}
