#include <QApplication>
#include "FenServeur.h"
#include "FenClient.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    FenServeur serveur;
    serveur.show();

    FenClient client;
    client.show();

    return app.exec();
}

