#include "FenPrincipale.h"

FenPrincipale::FenPrincipale()
{
    this->setMinimumSize(300,300);

    // QACTIONS
    QAction* actionF1 = new QAction("File1.txt", this);

    QAction* actionQuitter = new QAction("Quitter", this);
        actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));

    QAction* actionPrev = new QAction("Back", this);
        actionPrev->setIconText("<-");
    QAction* actionNext = new QAction("Forward", this);
        actionNext->setIconText("->");
    QAction* actionStop = new QAction("Stop", this);
        actionStop->setIconText("X");
    QAction* actionReload = new QAction("Reload", this);
        actionReload->setIconText("↺");

    //  MENU
    QMenu* menuFichier = menuBar()->addMenu("Fichier");
        QMenu* submenuRecent = menuFichier->addMenu("Recent Files");
            submenuRecent->addAction(actionF1);
        menuFichier->addAction(actionQuitter);

    QMenu* menuNavigation = menuBar()->addMenu("Navigation");
        menuNavigation->addAction(actionPrev);
        menuNavigation->addAction(actionNext);
        menuNavigation->addAction(actionReload);



    //  TOOLBAR
    QToolBar* toolBarFichier = addToolBar("Toolbar fichier");
        toolBarFichier->addAction(actionPrev);
        toolBarFichier->addAction(actionNext);
        toolBarFichier->addAction(actionStop);
        toolBarFichier->addAction(actionReload);
        toolBarFichier->addSeparator();
        QLabel* searchLabel = new QLabel("Search:");
            toolBarFichier->addWidget(searchLabel);
        QLineEdit* search = new QLineEdit;

            toolBarFichier->addWidget(search);
        QPushButton* buttonGo = new QPushButton("Go");
            toolBarFichier->addWidget(buttonGo);
        toolBarFichier->addSeparator();

    //  STATUS BAR
    QProgressBar* loadingBar = new QProgressBar;
    loadingBar->setRange(0, 100);
    loadingBar->setMinimumWidth(this->width());
    statusBar()->setFixedHeight(20);
    statusBar()->addWidget(loadingBar, 1);

    // WEB
    QWebView* pageWeb = new QWebView(this);
    pageWeb->setGeometry(0,0,200,200);
    this->setCentralWidget(pageWeb);
    pageWeb->load(QUrl("file:///C:/Users/cnl1/Documents/perso/site/index.html"));


    //CONNECTORS
    QObject::connect(actionPrev, SIGNAL(triggered()), pageWeb, SLOT(back()));
    QObject::connect(actionNext, SIGNAL(triggered()), pageWeb, SLOT(forward()));
    QObject::connect(actionStop, SIGNAL(triggered()), pageWeb, SLOT(stop()));
    QObject::connect(actionReload, SIGNAL(triggered()), pageWeb, SLOT(reload()));

    QObject::connect(pageWeb, SIGNAL(loadProgress(int)), loadingBar, SLOT(setValue(int)));
    QObject::connect(pageWeb, SIGNAL(loadFinished(bool)), statusBar(), SLOT(setHidden(bool)));

    QObject::connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
}

