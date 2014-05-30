#include <QApplication>
#include "FenClient.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    FenClient client;
    client.show();

    return app.exec();
}


