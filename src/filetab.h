#ifndef BASETABWIDGET_H
#define BASETABWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QTextEdit>
#include <QFileInfo>
#include <QDebug>
#include <QFileDialog>

class FileTab : public QWidget
{
    Q_OBJECT
public:
    explicit FileTab(QString content = "", QWidget *parent = nullptr);
    FileTab(QFileInfo fileInfo, QWidget* parent = nullptr);

public:
    bool isFileSaved();
    void saveFile();
    void saveFileAs();

public:
    QTextEdit* textEdit;
    QFileInfo fileInfo;

private:
    bool isSaved;

signals:
    void RenameMe(QString name);

};

#endif // CUSTOMTAB_H
