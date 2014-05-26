#ifndef FORMDIALOG_H
#define FORMDIALOG_H

#include <QApplication>
#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QFormLayout>


class FormDialog : public QDialog
{
Q_OBJECT

public:
    FormDialog();
    ~FormDialog();

public slots:

signals:

private:
    QLineEdit *_nom;
    QLineEdit *_prenom;
    QLineEdit *_age;

};

#endif // FORMDIALOG_H
