#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tabs = new CustomTabWidget(this);
    ui->centralwidget->layout()->addWidget(tabs); // TODO the same but with custom QTabWidget
}

MainWindow::~MainWindow()
{
    delete ui;
}

