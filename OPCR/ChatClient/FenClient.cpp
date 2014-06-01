#include "FenClient.h"

#define _PORT_ 57000

FenClient::FenClient()
{
    setupUi();

    _socket = new QTcpSocket(this);
    connect(_socket, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    connect(_socket, SIGNAL(connected()), this, SLOT(connecte()));
    connect(_socket, SIGNAL(disconnected()), this, SLOT(deconnecte()));
    connect(_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erreurSocket(QAbstractSocket::SocketError)));

    _tailleMessage = 0;
}

//=============
// SLOTS
//=============
void FenClient::on_boutonConnexion_clicked()
{
    _zoneText->append("<em>Tentative de connexion en cours...</em>");
    _buttonConnexion->setEnabled(false);

    _socket->abort(); //désactivation des connexions précédentes s'il y en a.
    _socket->connectToHost(_serveurIP->text(), _port->value()); // Connexion au serveur demandé.
}

void FenClient::on_boutonEnvoyer_clicked()
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    QString message = "<strong>" + _pseudo->text() + "</strong> : " + _message->text();
    out << (quint16) 0;
    out << message;
    out.device()->seek(0);
    out << (quint16)(paquet.size() - sizeof(quint16));

    _socket->write(paquet);
    _message->clear();
    _message->setFocus();
}

void FenClient::on_message_returnPressed()
{
    on_boutonEnvoyer_clicked();
}

void FenClient::donneesRecues()
{
    QDataStream in(_socket);

    if(_tailleMessage == 0)
    {
        if(_socket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> _tailleMessage;
    }

    if(_socket->bytesAvailable() < _tailleMessage)
        return;

    QString messageRecu;
    in >> messageRecu;

    _zoneText->append(messageRecu);

    _tailleMessage = 0;
}

void FenClient::connecte()
{
    _zoneText->append("<em>Connexion réussie !</em>");
    _buttonConnexion->setEnabled(true);
}

void FenClient::deconnecte()
{
    _zoneText->append("<em>Déconnecté du seveur.</em>");
}

void FenClient::erreurSocket(QAbstractSocket::SocketError erreur)
{
    switch(erreur)
    {
        case QAbstractSocket::HostNotFoundError:
            _zoneText->append("<em>Erreur : le serveur n'a pas pu être trouvé.</em>");
            break;
        case QAbstractSocket::ConnectionRefusedError:
            _zoneText->append("<em>Erreur : le seveur a refusé la connexion.</em>");
            break;
        case QAbstractSocket::RemoteHostClosedError:
            _zoneText->append("<em>Erreur : le serveur a coupé a connexion.</em>");
            break;
        default:
            _zoneText->append("<em>Erreur : " + _socket->errorString() + ".</em>");
    }

    _buttonConnexion->setEnabled(true);
}


//=============
// Methods
//=============
void FenClient::setupUi()
{
    QWidget* mainwidget = new QWidget;
    QVBoxLayout* mainlayout = new QVBoxLayout;
    mainwidget->setLayout(mainlayout);
    setCentralWidget(mainwidget);

    QHBoxLayout* serveurLayout = new QHBoxLayout;
    QLabel* serveurLabel = new QLabel("IP du serveur : ");
    _serveurIP = new QLineEdit;
    QLabel* portLabel = new QLabel("Port du serveur : ");
    _port = new QSpinBox;
    _port->setAccelerated(true);
    _port->setRange(1, 100000);
    _port->setValue(_PORT_);
    _buttonConnexion = new QPushButton("Connexion");
    connect(_buttonConnexion, SIGNAL(clicked()), this, SLOT(on_boutonConnexion_clicked()));
    serveurLayout->addWidget(serveurLabel);
    serveurLayout->addWidget(_serveurIP);
    serveurLayout->addWidget(portLabel);
    serveurLayout->addWidget(_port);
    serveurLayout->addWidget(_buttonConnexion);

    _zoneText = new QTextEdit;

    QGridLayout* userlayout = new QGridLayout;
    QLabel* pseudoLabel = new QLabel("Pseudo : ");
    _pseudo = new QLineEdit;
    QLabel* messageLabel = new QLabel("Message : ");
    _message = new QLineEdit;
    connect(_message, SIGNAL(returnPressed()), this, SLOT(on_message_returnPressed()));
    _buttonEnvoyer = new QPushButton("Envoyer");
    connect(_buttonEnvoyer, SIGNAL(clicked()), this, SLOT(on_boutonEnvoyer_clicked()));
    userlayout->addWidget(pseudoLabel, 0, 0, 1, 1);
    userlayout->addWidget(_pseudo, 0, 1, 1, 2);
    userlayout->addWidget(messageLabel, 0, 3, 1, 1);
    userlayout->addWidget(_message, 0, 4, 1, 5);
    userlayout->addWidget(_buttonEnvoyer, 0, 9, 1, 1);

    mainlayout->addLayout(serveurLayout);
    mainlayout->addWidget(_zoneText);
    mainlayout->addLayout(userlayout);
}
