#ifndef CLASSWINDOW_H
#define CLASSWINDOW_H

#include <QDialog>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>

class ClassWindow : public QDialog
{
Q_OBJECT

public:
    ClassWindow(QString comment);

public slots:

signals:

private:
    QVBoxLayout* _mainlayout;
        QTextEdit* _classtext;
        QPushButton* _close;

};

#endif // CLASSWINDOW_H
