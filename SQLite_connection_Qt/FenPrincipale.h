#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>

#include <QMessageBox>
#include <QSqlTableModel>
#include <QTableView>
#include <QVBoxLayout>
#include <QPushButton>

class FenPrincipale : public QMainWindow
{
Q_OBJECT
public:
    FenPrincipale();

public slots:
    void ajoutLeo();

private:
    QSqlTableModel* modele;
};

#endif // FENPRINCIPALE_H
