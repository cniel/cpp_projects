#include "MainWindow.h"

MainWindow::MainWindow()
{
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




  //CONNECTORS
  QObject::connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
}
