#include "customtab.h"

CustomTab::CustomTab(QWidget *parent) : QWidget(parent)
{
    textEdit = new QTextEdit(this);

    this->setLayout(new QVBoxLayout(this));
    this->layout()->addWidget(textEdit);
}
