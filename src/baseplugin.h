#ifndef BASEPLUGIN_H
#define BASEPLUGIN_H

#include <QObject>

class BasePlugin : public QObject
{
    Q_OBJECT
public:
    explicit BasePlugin(QWidget *mainWindow, QObject *parent = nullptr);

    virtual QString getName() = 0;
    virtual QString getVersion() = 0;
    virtual QString getDeveloper() = 0;
private:
    QWidget* mainWindow;

signals:

};

#endif // BASEPLUGIN_H
