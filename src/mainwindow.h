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

};
#endif // MAINWINDOW_H
