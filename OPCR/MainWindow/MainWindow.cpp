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
    // MENU
    QMenu* menuFichier = menuBar()->addMenu("&Fichier");
    QMenu* menuEdit = menuBar()->addMenu("&Edition");
    QMenu* menuAffichage = menuBar()->addMenu("&Affichage");

    QMenu* fichiersRecents = menuFichier->addMenu("Recent files");
        // Pointeurs QAction déclarés pour utiliser les actions plus tard (dans des slots p.ex)
        QAction* act1 = fichiersRecents->addAction("File1.txt");
        QAction* act2 = fichiersRecents->addAction("file 2.txt");
        QAction* act3 = fichiersRecents->addAction("File3.txt");

    QAction* actionQuitter = new QAction("&Quitter", this);
        actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
        menuFichier->addAction(actionQuitter);

    //Option "Gras" (Checkable)
    QAction* actionGras = new QAction("&Gras", this);
        actionGras->setCheckable(true);
        menuEdit->addAction(actionGras);


    // CONTENU DE LA FENETRE
    QMdiArea* zoneCentrale = new QMdiArea;

    QTextEdit* f1 = new QTextEdit;
    QTextEdit* f2 = new QTextEdit;

    // garder les pointeurs pour une suppression des sous-fenetres
    QMdiSubWindow* subf1 = zoneCentrale->addSubWindow(f1);
    QMdiSubWindow* subf2 = zoneCentrale->addSubWindow(f2);

    setCentralWidget(zoneCentrale);

    QObject::connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
}
