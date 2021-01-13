#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tabs = new CustomTabWidget(this);
    ui->centralwidget->layout()->addWidget(tabs);

    QObject::connect(ui->actionNew, &QAction::triggered, [=](){ this->tabs->addNamedTab(); });
    QObject::connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openFiles);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFiles()
{
    QStringList filePaths;
    filePaths = QFileDialog::getOpenFileNames(this, "Select file(s) you wnat to open", "", "Any file (*)");
    foreach(auto path, filePaths)
    {
        QFileInfo fileInfo(path);
        this->tabs->addFileTab(fileInfo);
    }
}

