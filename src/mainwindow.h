#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDialog>
#include <QInputDialog>
#include "filetab.h"
#include "customtabwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class PluginsLoader;
class BasePlugin;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    void openFiles();
    void saveCurrentOpenedFile();
    void saveAsCurrentOpenedFile();

public:
    CustomTabWidget *tabs;
    Ui::MainWindow *ui;

private:
    PluginsLoader* pluginsLoader;
};

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

#endif // MAINWINDOW_H
