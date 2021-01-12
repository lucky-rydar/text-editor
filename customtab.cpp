#include "customtab.h"

CustomTab::CustomTab(QString content, QWidget *parent) : QWidget(parent)
{
    textEdit = new QTextEdit(this);

    this->setLayout(new QVBoxLayout(this));
    this->layout()->addWidget(textEdit);

    textEdit->setText(content);
}
