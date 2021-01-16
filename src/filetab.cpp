#include "filetab.h"

FileTab::FileTab(QString content, QWidget *parent) : QWidget(parent)
{
    textEdit = new QTextEdit(this);

    this->setLayout(new QVBoxLayout(this));
    this->layout()->addWidget(textEdit);

    textEdit->setText(content);

    this->isSaved = false;

    connect(this->textEdit, &QTextEdit::textChanged, [=](){ this->isSaved = false; });
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

    this->isSaved = true;

    connect(this->textEdit, &QTextEdit::textChanged, [=](){ this->isSaved = false; });
}

bool FileTab::isFileSaved()
{
    return this->isSaved;
}

void FileTab::saveFile()
{
    if(!this->fileInfo.absoluteFilePath().isEmpty())
    {
        QFile fileToSave(this->fileInfo.absoluteFilePath());
        fileToSave.open(QIODevice::ReadWrite | QIODevice::Truncate);
        fileToSave.write(textEdit->toPlainText().toUtf8());
        fileToSave.close();
    }
    else
    {
        saveFileAs();
    }

    this->isSaved = true;
}

void FileTab::saveFileAs()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save");
    QFileInfo fi(filePath);
    if(fi.exists())
    {
        QFile fileToSaveAs(filePath);
        fileToSaveAs.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::ExistingOnly);
        fileToSaveAs.write(this->textEdit->toPlainText().toUtf8());
        fileToSaveAs.close();
    }
    else
    {
        QFile fileToSaveAs(filePath);
        fileToSaveAs.open(QIODevice::ReadWrite | QIODevice::NewOnly);
        fileToSaveAs.write(this->textEdit->toPlainText().toUtf8());
        fileToSaveAs.close();
    }

    this->fileInfo = fi;
    this->isSaved = true;

    emit RenameMe(fileInfo.fileName());
}
