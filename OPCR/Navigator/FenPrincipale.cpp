#include "FenPrincipale.h"

//==============================
//  CONSTRUCTOR
//==============================
FenPrincipale::FenPrincipale()
{
    this->setMinimumSize(400,50);

    creerActions();
    creerMenus();
    creerToolBar();
    creerStatusBar();

    _tabs = new QTabWidget;
    _tabs->addTab(createWebPageTab(tr("http://www.google.com")), "New tab");
    connect(_tabs, SIGNAL(currentChanged(int)), this, SLOT(tabChange(int)));

    setCentralWidget(_tabs);
}

//==============================
//  Methods
//==============================
QWidget* FenPrincipale::createWebPageTab(QString url)
{
    QWidget* page = new QWidget;
    QWebView* pageweb = new QWebView;

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(pageweb);
    layout->setContentsMargins(0,0,0,0);
    page->setLayout(layout);

    if(url.isEmpty())
    {
        pageweb->load(QUrl("http://www.google.com"));
    }
    else
    {
        if(url.left(7) != "http://")
        {
            //url = "http://" + url;
        }
        pageweb->load(QUrl(url));
    }

    // CONNECTEURS de la nouvelle page web
    QObject::connect(pageweb, SIGNAL(titleChanged(QString)), this, SLOT(titleChange(QString)));
    QObject::connect(pageweb, SIGNAL(urlChanged(QUrl)), this, SLOT(urlChange(QUrl)));
    QObject::connect(pageweb, SIGNAL(loadStarted()), statusBar(), SLOT(show()));
    QObject::connect(pageweb, SIGNAL(loadFinished(bool)), statusBar(), SLOT(setHidden(bool)));
    QObject::connect(pageweb, SIGNAL(loadProgress(int)), _loadingBar, SLOT(setValue(int)));

    return page;
}

QWebView* FenPrincipale::currentWebPage()
{
    return _tabs->currentWidget()->findChild<QWebView*>();
}


//==============================
//  basic UI
//==============================
void FenPrincipale::creerActions()
{
    _actionF1 = new QAction("File1.txt", this);

    _actionQuitter = new QAction("Quitter", this);
    _actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
    QObject::connect(_actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    _actionPrev = new QAction("Back", this);
    _actionPrev->setIconText("<-");
    QObject::connect(_actionPrev, SIGNAL(triggered()), this, SLOT(prev()));

    _actionNext = new QAction("Forward", this);
    _actionNext->setIconText("->");
    QObject::connect(_actionNext, SIGNAL(triggered()), this, SLOT(next()));

    _actionStop = new QAction("Stop", this);
    _actionStop->setIconText("X");
    QObject::connect(_actionStop, SIGNAL(triggered()), this, SLOT(stop()));

    _actionReload = new QAction("Reload", this);
    _actionReload->setIconText("↺");
    QObject::connect(_actionReload, SIGNAL(triggered()), this, SLOT(reload()));

    _actionNewTab = new QAction("New Tab", this);
    _actionNewTab->setIconText("+");
    _actionNewTab->setShortcut(QKeySequence("Ctrl+T"));
    QObject::connect(_actionNewTab, SIGNAL(triggered()), this, SLOT(newTab()));

    _actionCloseTab = new QAction("Close Tab", this);
    _actionCloseTab->setIconText("X");
    QObject::connect(_actionCloseTab, SIGNAL(triggered()), this, SLOT(closeTab()));
}

void FenPrincipale::creerMenus()
{
    QMenu* menuFichier = menuBar()->addMenu("Fichier");
        menuFichier->addAction(_actionNewTab);
        menuFichier->addAction(_actionCloseTab);
        menuFichier->addSeparator();
        menuFichier->addAction(_actionQuitter);

    QMenu* menuNavigation = menuBar()->addMenu("Navigation");
        menuNavigation->addAction(_actionPrev);
        menuNavigation->addAction(_actionNext);
        menuNavigation->addAction(_actionReload);
}

void FenPrincipale::creerToolBar()
{
    QToolBar* toolBarFichier = addToolBar("Toolbar fichier");
        toolBarFichier->addAction(_actionPrev);
        toolBarFichier->addAction(_actionNext);
        toolBarFichier->addAction(_actionStop);
        toolBarFichier->addAction(_actionReload);

        toolBarFichier->addSeparator();
        toolBarFichier->addWidget(new QLabel("Tabs:"));
        toolBarFichier->addAction(_actionNewTab);
        toolBarFichier->addAction(_actionCloseTab);
        toolBarFichier->addSeparator();

        QLabel* searchLabel = new QLabel("Search:");
        toolBarFichier->addWidget(searchLabel);

        _adress = new QLineEdit;
        toolBarFichier->addWidget(_adress);

        QPushButton* buttonGo = new QPushButton("Go");
        toolBarFichier->addWidget(buttonGo);
        QObject::connect(buttonGo, SIGNAL(clicked()),this, SLOT(loadWebPage()));
}

void FenPrincipale::creerStatusBar()
{
    _loadingBar = new QProgressBar;
        _loadingBar->setRange(0, 100);
        _loadingBar->setMinimumWidth(this->width());
        statusBar()->setFixedHeight(20);
        statusBar()->addWidget(_loadingBar, 1);
}


//===========================================
// SLOTS
//===========================================
void FenPrincipale::prev()
{
    currentWebPage()->back();
}

void FenPrincipale::next()
{
    currentWebPage()->forward();
}

void FenPrincipale::stop()
{
    currentWebPage()->stop();
}

void FenPrincipale::reload()
{
    currentWebPage()->reload();
}

void FenPrincipale::loadWebPage()
{
    QString url = _adress->text();
    if(!url.isEmpty())
    {
        if(url.left(7) != "http://")
        {
            //url = "http://" + url;
            _adress->setText(url);
        }
        currentWebPage()->load(QUrl(url));
    }
}

void FenPrincipale::newTab()
{
    int newIndex = _tabs->addTab(createWebPageTab(), "newTab");
    _tabs->setCurrentIndex(newIndex);
    _adress->setText("");
    _adress->setFocus();
}

void FenPrincipale::closeTab()
{
    if(_tabs->count() > 1)
    {
        _tabs->removeTab(_tabs->currentIndex());
    }
}

void FenPrincipale::urlChange(QUrl const & url)
{
    _adress->setText(url.toString());
}

void FenPrincipale::titleChange(QString const& title)
{
    QString shortTitle = title;
    if(shortTitle.size() > 40)
    {
        shortTitle = shortTitle.left(40) + "...";
    }
    _tabs->setTabText(_tabs->currentIndex(), shortTitle);
    setWindowTitle(shortTitle + " - Navigator");
}

void FenPrincipale::tabChange(int newTabIndex)
{
    urlChange(currentWebPage()->url());

    QString title = _tabs->widget(newTabIndex)->findChild<QWebView*>()->title();
    if(title.size() > 40)
        title = title.left(40) + "...";
    setWindowTitle(title + " - Navigator");
}
