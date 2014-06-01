#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlQuery>
#include <QtDebug>
#include <QFileInfo>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QGroupBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

#include "InfoWindow.h"

class Login : public QMainWindow
{
    Q_OBJECT
public:
    Login();
    void setupUI();
    bool connOpen();
    void connCLose();

    //DB
    QSqlDatabase db;

signals:

public slots:
    void on_OK_clicked();

private:
    //UI
    QLabel* _label;
    QLineEdit* _username;
    QLineEdit* _passwd;
    QPushButton* _OK;


};

#endif // LOGIN_H
