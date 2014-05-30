#include "Window.h"

Window::Window()
{
    //exempleDirModel();
    exempleListModel();

}

void Window::exempleDirModel()
{
    QVBoxLayout* layout = new QVBoxLayout;

    QDirModel* modele = new QDirModel;
    QTreeView* treeView = new QTreeView;
    QListView* listView = new QListView;

    treeView->setModel(modele);
    listView->setModel(modele);

    treeView->setRootIndex(modele->index("C:/MinGW"));
    listView->setRootIndex(modele->index("C:"));
    layout->addWidget(treeView);

    setCentralWidget(treeView);
}

void Window::exempleListModel()
{
    /*
    QStringList listePays;
    listePays << "France" << "Espagne" << "Italie" << "Danemark" << "Chine" << "Maroc";
    QStringListModel* modelList = new QStringListModel(listePays);

    QListView* vueList = new QListView;
    vueList->setModel(modelList);
    setCentralWidget(vueList);
    */


    /*
    QStandardItemModel* modelStand = new QStandardItemModel(3, 4);
    QTableView* viewTable = new QTableView;
    viewTable->setModel(modelStand);

    modelStand->setItem(2, 1, new QStandardItem("Salut"));

    setCentralWidget(viewTable);
    */

    QStandardItemModel* modelStand = new QStandardItemModel;
    QStandardItem* lea = new QStandardItem("Léa");
    modelStand->appendRow(lea);

    lea->appendRow(new QStandardItem("21 ans"));

    QTreeView* viewTree = new QTreeView;
    viewTree->setModel(modelStand);

    setCentralWidget(viewTree);


}
