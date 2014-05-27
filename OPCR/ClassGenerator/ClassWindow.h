#ifndef CLASSWINDOW_H
#define CLASSWINDOW_H

#include <QApplication>
#include <QString>
#include <QRegularExpression>
#include <QMessageBox>
#include <QDialog>
#include <QFileDialog>

#include <QTabWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QTextEdit>
#include <QPushButton>

#include <QFile>
#include <QTextStream>

class ClassWindow : public QDialog
{
Q_OBJECT

public:
    ClassWindow(QString header, QString classname);

public slots:
    void addCppTab();
    void saveCpp();

signals:

private:
    QString _classname;
    QString _headerpath;

    QVBoxLayout* _mainlayout;

    QTabWidget* _tabs;
    QWidget* _tab1;
    QWidget* _tab2;

    QVBoxLayout* _headerlayout;
        QTextEdit* _classtext;
        QPushButton* _savebutton;

    QVBoxLayout* _cpplayout;
        QTextEdit* _cpptext;
        QPushButton* _savebutton2;

    QHBoxLayout* _buttonslayout;
        QPushButton* _close;

};

#endif // CLASSWINDOW_H
