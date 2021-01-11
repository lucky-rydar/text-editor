#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->centralwidget->layout()->addWidget(new QTabWidget(this)); // TODO the same but with custom QTabWidget

}

MainWindow::~MainWindow()
{
    delete ui;
}

