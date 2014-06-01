#include "FenPrincipale.h"

FenPrincipale::FenPrincipale()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("C:/Users/Clement/Desktop/data.db");
    db.setUserName("root");
    db.setPassword("");

    if(!db.open())
    {
        QMessageBox::critical(this, "Erreur de connection", "Impossible de se connecter.");
    }
    else
    {
        QMessageBox::information(this, "Connection", "Connexion établie.");
    }
    modele = new QSqlTableModel;
    modele->setTable("test");
    modele->select();

    QTableView* vueTable = new QTableView;
    vueTable->setModel(modele);

    QPushButton* ajoutLeo = new QPushButton("Ajout Leo");

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(ajoutLeo);
    layout->addWidget(vueTable);
    QWidget* zoneCentrale = new QWidget;
    zoneCentrale->setLayout(layout);



    setCentralWidget(zoneCentrale);


    QObject::connect(ajoutLeo, SIGNAL(clicked()), this, SLOT(ajoutLeo()));
}


void FenPrincipale::ajoutLeo()
{
    QSqlQuery query;
    query.prepare("Delete from test where nom='Leo'");
    query.exec();
    modele->select();
}


