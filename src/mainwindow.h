#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDialog>
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

    void openFiles();
    void saveCurrentOpenedFile();
private:
    Ui::MainWindow *ui;
    CustomTabWidget *tabs;
};
#endif // MAINWINDOW_H
