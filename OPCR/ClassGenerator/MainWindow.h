#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QMessageBox>

#include <QPushButton>
#include <QCheckBox>
#include <QDateEdit>

#include <QLineEdit>
#include <QTextEdit>

#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFormLayout>

#include "ClassWindow.h"



class MainWindow : public QWidget
{
Q_OBJECT
public:
    MainWindow();

public slots:
    void dispClassWindow();


signals:

private:
    QGroupBox* _defbox;
        QFormLayout* _deflayout;
            QLineEdit* _name;
            QLineEdit* _motherclass;

    QGroupBox* _optbox;
        QFormLayout* _optlayout;
            QCheckBox* _inclusions;
            QCheckBox* _defconstructor;
            QCheckBox* _gendestructor;

    QGroupBox* _combox;
        QFormLayout* _comlayout;
            QLineEdit* _author;
            QDateEdit* _calendar;
            QTextEdit* _role;

    QHBoxLayout* _buttonslayout;
        QPushButton* _generate;
        QPushButton* _quit;

    QVBoxLayout* _mainlayout;



};

#endif // MAINWINDOW_H
