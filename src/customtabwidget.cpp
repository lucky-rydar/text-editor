#include "customtabwidget.h"

CustomTabWidget::CustomTabWidget(QWidget* parent) : QTabWidget(parent)
{
    setTabsClosable(true);
    setMovable(true);

    addNamedTab();
}

void CustomTabWidget::addNamedTab(QString content)
{
    QString baseName = "new ";

    for (int i = 1; ; i++)
    {
        QString newName = baseName + QString::number(i);
        if(!tabByName.contains(newName))
        {
            FileTab *customTab = new FileTab(content, this);
            this->tabByName.insert(newName, customTab);
            addTab(customTab, newName);

            break;
        }
    }
    this->setCurrentIndex(this->count()-1);
}

void CustomTabWidget::addFileTab(QFileInfo fileInfo)
{
    QString tabName = fileInfo.fileName();

    if(!tabByName.contains(tabName))
    {
        FileTab *customTab = new FileTab(fileInfo, this);
        this->tabByName.insert(tabName, customTab);
        this->addTab(customTab, tabName);
    }
    else
    {
        for(int i = 1; ; i++)
        {
            QString newTabName = tabName + " " + QString::number(i);
            if(!tabByName.contains(newTabName))
            {
                FileTab *customTab = new FileTab(fileInfo, this);
                this->tabByName.insert(newTabName, customTab);
                this->addTab(customTab, newTabName);
            }
        }
    }
    this->setCurrentIndex(this->count()-1);
}
