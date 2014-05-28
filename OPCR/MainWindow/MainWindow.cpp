#include "MainWindow.h"

/*
// SDI
MainWindow::MainWindow()
{
    QWidget* zoneCentrale = new QWidget;

        QLineEdit* nom = new QLineEdit;
        QLineEdit* prenom = new QLineEdit;
        QLineEdit* age = new QLineEdit;

        QFormLayout* layout = new QFormLayout;
            layout->addRow("Nom: ", nom);
            layout->addRow("Prénom: ", prenom);
            layout->addRow("Age: ", age);

        zoneCentrale->setLayout(layout);


    setCentralWidget(zoneCentrale);
}
*/

MainWindow::MainWindow()
{
    //  QACTIONS
    QAction* actionF1 = new QAction("File1.txt", this);
    QAction* actionBold = new QAction("Bold", this);
        actionBold->setCheckable(true);
        actionBold->setShortcut(QKeySequence("Ctrl+B"));
        actionBold->setIconText("B");

    QAction* actionQuitter = new QAction("Quitter", this);
        actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
        actionQuitter->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/quitter.png"));


    //  MENU
    QMenu* menuFichier = menuBar()->addMenu("Fichier");
        QMenu* submenuRecent = menuFichier->addMenu("Recent Files");
            submenuRecent->addAction(actionF1);
        menuFichier->addAction(actionQuitter);

    QMenu* menuEdition = menuBar()->addMenu("Edition");
        menuEdition->addAction(actionBold);



    //  TOOLBAR
    QToolBar* toolBarFichier = addToolBar("Toolbar fichier");
        toolBarFichier->addAction(actionQuitter);
        toolBarFichier->addSeparator();
        QLabel* searchLabel = new QLabel("Search:");
            toolBarFichier->addWidget(searchLabel);
        QLineEdit* search = new QLineEdit;
            search->setMaximumWidth(100);
            toolBarFichier->addWidget(search);
        QPushButton* buttonGo = new QPushButton("Go");
            buttonGo->setMaximumWidth(40);
            toolBarFichier->addWidget(buttonGo);
        toolBarFichier->addSeparator();
        toolBarFichier->addAction(actionBold);

  this->setMinimumSize(300,300);


    //  CONNECTORS
    QObject::connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

}
