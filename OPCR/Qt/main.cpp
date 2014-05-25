#include <QApplication>
#include <QPushButton>

int main(int argc, char** argv)
{
             QApplication app(argc, argv);
             QPushButton bouton("Salut!\nLa forme?");

             QFont myFont("Purisa", 10, 50, false);
             myFont.setBold(true);
             myFont.setFixedPitch(true);

             bouton.setFont(myFont);
             bouton.setCursor(Qt::PointingHandCursor);
             bouton.setToolTip("Just to say hello");

             bouton.show();


             return app.exec();
}
