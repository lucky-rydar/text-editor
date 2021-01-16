#ifndef CUSTOMTABWIDGET_H
#define CUSTOMTABWIDGET_H

#include <QObject>
#include <QTabWidget>
#include <QVector>
#include <QtCore>
#include <QVariant>
#include <QMap>
#include <QLayout>
#include <QMessageBox>
#include "filetab.h"

class CustomTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit CustomTabWidget(QWidget* parent = nullptr);

public:
    void addNamedTab(QString content = "");
    void addFileTab(QFileInfo fileInfo);
    void onCloseRequested(int index);
    void customRemoveTab(int index);
    void renameTab(int index, QString newName);

public:
    QMap<QString, FileTab*> tabByName;

};

#endif // CUSTOMTABWIDGET_H
