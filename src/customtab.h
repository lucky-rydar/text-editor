#ifndef BASETABWIDGET_H
#define BASETABWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QTextEdit>
#include <QFileInfo>

class CustomTab : public QWidget
{
    Q_OBJECT
public:
    explicit CustomTab(QString content = "", QWidget *parent = nullptr);
    CustomTab(QFileInfo fileInfo, QWidget* parent = nullptr);

    QTextEdit* textEdit;
    QFileInfo fileInfo;
private:


signals:

};

#endif // CUSTOMTAB_H
