#include "filetab.h"

FileTab::FileTab(QString content, QWidget *parent) : QWidget(parent)
{
    textEdit = new QTextEdit(this);

    this->setLayout(new QVBoxLayout(this));
    this->layout()->addWidget(textEdit);

    textEdit->setText(content);
}

FileTab::FileTab(QFileInfo fileInfo, QWidget *parent) : QWidget(parent)
{
    textEdit = new QTextEdit(this);

    this->setLayout(new QVBoxLayout(this));
    this->layout()->addWidget(textEdit);

    this->fileInfo = fileInfo;

    QFile fileToUpload(fileInfo.absoluteFilePath());
    fileToUpload.open(QFile::ReadOnly);
    this->textEdit->setText(fileToUpload.readAll());
    fileToUpload.close();
}
