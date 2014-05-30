#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QtWebKitWidgets>
#include <QWebView>
#include <QUrl>

#include <QApplication>
#include <QMainWindow>
#include <QStatusBar>

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QWidget>
#include <QTabWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QProgressBar>

#include <QMenu>
#include <QMenuBar>
#include <QToolBar>

#include <QMessageBox>

class FenPrincipale : public QMainWindow
{

Q_OBJECT

public:
    FenPrincipale();

private :
    void creerActions();
    void creerMenus();
    void creerToolBar();
    void creerStatusBar();
    QWebView* currentWebPage();
    QWidget* createWebPageTab(QString url="");


private slots:
    void prev();
    void next();
    void stop();
    void reload();
    void loadWebPage();
    void newTab();
    void closeTab();
    void urlChange(QUrl const& url);
    void titleChange(QString const& title);
    void tabChange(int newTabIndex);


private:
    QTabWidget* _tabs;

    QAction* _actionF1;
    QAction* _actionQuitter;
    QAction* _actionPrev;
    QAction* _actionNext;
    QAction* _actionStop;
    QAction* _actionReload;
    QAction* _actionNewTab;
    QAction* _actionCloseTab;

    QLineEdit* _adress;
    QProgressBar* _loadingBar;

};

#endif // FENPRINCIPALE_H
