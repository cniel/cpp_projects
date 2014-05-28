#include "MainWindow.h"

/*
// SDI
MainWindow::MainWindow()
{
<<<<<<< HEAD
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
=======
<<<<<<< HEAD
    this->setMinimumSize(300,300);

    // QACTIONS
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
=======
  this->setMinimumSize(300,300);

  // QACTIONS
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
>>>>>>> b6a8bb7893d67c6355548b4f00c078bac15528e1




<<<<<<< HEAD
    //CONNECTORS
    QObject::connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
=======
  //CONNECTORS
  QObject::connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
>>>>>>> b6a8bb7893d67c6355548b4f00c078bac15528e1
>>>>>>> aa3a7b238554ae2d0fa300c95e2ccaea1259bc1c
}
