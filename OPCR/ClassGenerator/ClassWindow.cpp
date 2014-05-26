#include "ClassWindow.h"

ClassWindow::ClassWindow(QString comment) : QDialog()
{
    _mainlayout = new QVBoxLayout;

    _classtext = new QTextEdit;
    _classtext->setText(comment);

    _close = new QPushButton("Close");
    _mainlayout->addWidget(_classtext);
    _mainlayout->addWidget(_close);

    this->setLayout(_mainlayout);
    this->setMinimumSize(420, 530);

    QObject::connect(_close, SIGNAL(clicked()), this, SLOT(close()));
}
