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
    QObject::connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveCurrentOpenedFile);
    QObject::connect(ui->actionSaveAs, &QAction::triggered, this, &MainWindow::saveAsCurrentOpenedFile);
    QObject::connect(ui->actionRename, &QAction::triggered, [=](){
        auto newName = QInputDialog::getText(this, "Rename", "Filename");
        if(!newName.isEmpty())
            tabs->renameTab(tabs->currentIndex(), newName);
    });

    this->pluginsLoader = new PluginsLoader(this, this);
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

void MainWindow::saveCurrentOpenedFile()
{
    qobject_cast<FileTab*>(tabs->widget(tabs->currentIndex()))->saveFile();
}

void MainWindow::saveAsCurrentOpenedFile()
{
    qobject_cast<FileTab*>(tabs->widget(tabs->currentIndex()))->saveFileAs();
}

