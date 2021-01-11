#include "customtabwidget.h"

CustomTabWidget::CustomTabWidget(QWidget* parent) : QTabWidget(parent)
{
    setTabsClosable(true);
    setMovable(true);

    addNamedTab();
}

void CustomTabWidget::addNamedTab()
{
    QString baseName = "new ";

    for (int i = 1; ; i++)
    {
        QString newName = baseName + QString::number(i);
        if(!tabByName.contains(newName))
        {
            CustomTab *customTab = new CustomTab(this);
            this->tabByName.insert(newName, customTab);
            addTab(customTab, newName);

            break;
        }
    }
}
