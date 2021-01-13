#ifndef BASETABWIDGET_H
#define BASETABWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QTextEdit>
#include <QFileInfo>

class FileTab : public QWidget
{
    Q_OBJECT
public:
    explicit FileTab(QString content = "", QWidget *parent = nullptr);
    FileTab(QFileInfo fileInfo, QWidget* parent = nullptr);

    QTextEdit* textEdit;
    QFileInfo fileInfo;
private:


signals:

};

#endif // CUSTOMTAB_H
