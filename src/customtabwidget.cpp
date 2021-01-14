#include "customtabwidget.h"

CustomTabWidget::CustomTabWidget(QWidget* parent) : QTabWidget(parent)
{
    setTabsClosable(true);
    setMovable(true);

    addNamedTab();

    QObject::connect(this, &QTabWidget::tabCloseRequested, this, &CustomTabWidget::onCloseRequested);
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

void CustomTabWidget::onCloseRequested(int index)
{
    if(!qobject_cast<FileTab*>(this->widget(index))->isFileSaved())
    {
        auto reply = QMessageBox::question(this, "Save", "Wanna save this file?", QMessageBox::Yes | QMessageBox::No);

        if(reply == QMessageBox::No)
        {
            this->customRemoveTab(index);
        }
        else if(reply == QMessageBox::Yes)
        {
            qobject_cast<FileTab*>(this->widget(index))->saveFile();
            this->customRemoveTab(index);
        }
    }
    else
    {
        this->customRemoveTab(index);
    }

    if(!this->count())
        this->addNamedTab();
}

void CustomTabWidget::customRemoveTab(int index)
{
    this->tabByName.remove(this->tabText(index));
    this->removeTab(index);
}
