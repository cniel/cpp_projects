#include <QApplication>

#include "FenPrincipale.h"
#include "Login.h"


int main (int argc, char** argv)
{
    QApplication app(argc, argv);

    Login fen;
    fen.show();

    return app.exec();
}
