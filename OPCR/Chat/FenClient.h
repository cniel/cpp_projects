#ifndef FENCLIENT_H
#define FENCLIENT_H

#include <QMainWindow>
#include <QtNetwork>

#include <QTextEdit>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

class FenClient : public QMainWindow
{
Q_OBJECT

public:
    FenClient();

private:
    void setupUi();

private slots:
    void on_boutonConnexion_clicked();
    void on_boutonEnvoyer_clicked();
    void on_message_returnPressed();
    void donneesRecues();
    void connecte();
    void deconnecte();
    void erreurSocket(QAbstractSocket::SocketError erreur);

private:
    // UI
    QLineEdit* _serveurIP;
    QSpinBox* _port;
    QPushButton* _buttonConnexion;
    QTextEdit* _zoneText;
    QLineEdit* _pseudo;
    QLineEdit* _message;
    QPushButton* _buttonEnvoyer;

    // Gestion
    QTcpSocket* _socket; // serveur
    quint16 _tailleMessage;
};

#endif // FENCLIENT_H
