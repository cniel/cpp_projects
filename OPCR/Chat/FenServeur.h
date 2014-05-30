#ifndef FENSERVEUR_H
#define FENSERVEUR_H

#include <QApplication>
#include <QMainWindow>
#include <QtNetwork>
#include <QDataStream>
#include <QList>

#include <QVBoxLayout>

#include <QPushButton>
#include <QLabel>

class FenServeur : public QMainWindow
{
Q_OBJECT
public:
    FenServeur();

private:
    void sendToAll(const QString &txt);

private slots:
    void newConnection();
    void receiveData();
    void clientDeco();


private:
    QLabel* _infoServeur;
    QPushButton* _buttonClose;

    QTcpServer* _serveur;
    QList<QTcpSocket *> _clients;
    quint16 _tailleMessage;
};

#endif
