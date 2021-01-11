#ifndef BASETABWIDGET_H
#define BASETABWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QTextEdit>

class CustomTab : public QWidget
{
    Q_OBJECT
public:
    explicit CustomTab(QWidget *parent = nullptr);
    QTextEdit* textEdit;
private:

signals:

};

#endif // CUSTOMTAB_H
