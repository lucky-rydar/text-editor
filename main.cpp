#include "src/mainwindow.h"
#include "src/pluginsloader.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    auto pluginLoader = new PluginsLoader(&w);
    pluginLoader->load();

    w.show();

    return a.exec();
}
