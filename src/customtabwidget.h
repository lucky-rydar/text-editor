#ifndef CUSTOMTABWIDGET_H
#define CUSTOMTABWIDGET_H

#include <QObject>
#include <QTabWidget>
#include <QVector>
#include <QtCore>
#include <QVariant>
#include <QMap>
#include <QLayout>
#include "filetab.h"

class CustomTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit CustomTabWidget(QWidget* parent = nullptr);

    void addNamedTab(QString content = "");
    void addFileTab(QFileInfo fileInfo);


    QMap<QString, FileTab*> tabByName;
};

#endif // CUSTOMTABWIDGET_H
