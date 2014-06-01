#include "FenServeur.h"

#define _PORT_ 57000 //remplacer 57000 par RANDOM pour un port au hasard
#define _RANDOM_ 0

FenServeur::FenServeur()
{
    //  Widgets
    setWindowTitle("Chat - Serveur");
    QVBoxLayout* layout = new QVBoxLayout;
    QWidget* mainWidget = new QWidget;
    mainWidget->setLayout(layout);

    _infoServeur = new QLabel();
    _buttonClose = new QPushButton("Close");
    connect(_buttonClose, SIGNAL(clicked()), qApp, SLOT(quit()));
    layout->addWidget(_infoServeur);
    layout->addWidget(_buttonClose);

    setCentralWidget(mainWidget);

    // Serveur
    _serveur = new QTcpServer(this);
    if (!_serveur->listen(QHostAddress::Any, _PORT_))
    {
        _infoServeur->setText("Le serveur n'a pas pu être démarré. Raison:\n" + _serveur->errorString());
    }
    else
    {
        _infoServeur->setText("Le serveur est démarré sur le port " + QString::number(_serveur->serverPort()) + ".\nDes clients peuvent maintenant se connecter.");
        connect(_serveur, SIGNAL(newConnection()), this, SLOT(newConnection()));
    }
    _tailleMessage = 0;
}

//========================
//  SLOTS
//========================
void FenServeur::newConnection()
{
    sendToAll("Un nouveau client s'est connecté.");

    /*Chaque client est représenté par un QTcpSocket. Pour récupérer la socket correspondant
     * au nouveau client qui vient de se connecter, on appelle la méthode nextPendingConnection()
     * du QTcpServer. Cette méthode retourne la QTcpSocket du nouveau client.*/
    QTcpSocket* newClient = _serveur->nextPendingConnection();
    _clients << newClient;

    connect(newClient, SIGNAL(readyRead()), this, SLOT(receiveData()));
    connect(newClient, SIGNAL(disconnected()), this, SLOT(clientDeco()));
}

void FenServeur::receiveData()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket *>(sender());
    if(socket == 0)
        return;

    //flux de données pour lire le contenu de la socket
    QDataStream in(socket);
    if(_tailleMessage == 0) //taille message encore inconnue -> on essaie de la récupérer
    {
        if(socket->bytesAvailable() < (int)sizeof(quint16)) //on a pas reçu la taille du message
            return;
        in >> _tailleMessage; // si la taile de message est reçue, on la récupère.
    }
    //On récupère alors le message en lui-même.
    if(socket->bytesAvailable() < _tailleMessage)
        return; // si le message n'est pas encore complet, on ne le récupère pas, on réessaiera au prochain socket reçu.

    QString message;
    in >> message;  // le message est entièrement reçu -> on le récupère.

    sendToAll(message); // on evoit le message à tout le monde.
    _tailleMessage = 0; // remise à zéro de la variable pour le prochain message.

    // Si la méthode s'execute jusqu'au bout, c'est qu'on a reçu le message en entier.
}

void FenServeur::clientDeco()
{
    sendToAll("Un client vient de se déconnecter.");

        QTcpSocket* socket = qobject_cast<QTcpSocket *>(sender());
        if(socket == 0)
            return;

        _clients.removeOne(socket); // supression du client dans la liste
        socket->deleteLater();      // suppression de l'objet correspondant au client. Later car si on fait un delete "tout simple", le signal BUG car il ne se termine pas.
}


//=======================
//  Methods
//=======================
void FenServeur::sendToAll(QString const& txt)
{
    QByteArray paquet;
    QDataStream out(&paquet,QIODevice::WriteOnly);

    out << (quint16) 0; // réservation de la place pour écrire la taille
    out << txt;         // ajout du message à la suite
    out.device()->seek(0); // replacement au début du paquet
    out << (quint16)(paquet.size() - sizeof(quint16)); // longueur du message écrase le 0.

    // envoi à tous les clients connectés (ceux présents dans la liste)
    for (int i=0; i<_clients.size(); i++)
    {
        _clients[i]->write(paquet);
    }
}
