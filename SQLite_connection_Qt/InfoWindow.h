#ifndef INFOWINDOW_H
#define INFOWINDOW_H

#include <QMainWindow>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QSqlQueryModel>
#include <QTableView>
#include <QMessageBox>
#include <QString>

#include "Login.h"

class InfoWindow : public QMainWindow
{
Q_OBJECT

public:
    InfoWindow();
    void setupUI();

public slots:
    void on_submit_clicked();
    void on_update_clicked();
    void on_delete_clicked();
    void on_loadtable_clicked();
    void on_combobox_changed(QString text);
    void on_tableview_activated(QModelIndex const& index);

private:
    // UI
    QLineEdit* _rowid;
    QLineEdit* _name;
    QLineEdit* _surname;
    QLineEdit* _age;
    QLineEdit* _username;
    QLineEdit* _passwd;
    QPushButton* _submit;
    QPushButton* _update;
    QPushButton* _delete;

    QTableView* _tableview;
    QPushButton* _loadtable;
    QComboBox* _combobox;
    QLabel* _connexionlabel;

};

#endif // INFOWINDOW_H
