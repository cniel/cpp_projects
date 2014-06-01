#include "Login.h"
#define _DBPATH_ "C:/Users/Clement/Desktop/data.db"

Login::Login()
{
    setupUI();

    if(!connOpen())
        _label->setText("Failed to connect to the database.");
    else
        _label->setText("Connected.");
}


//=================
// SLOTS
//=================
void Login::on_OK_clicked()
{
    QString username, password;
    username = _username->text();
    password = _passwd->text();

    if(!db.open())
    {
        qDebug() << "Failed to open the database";
        return;
    }

    connOpen();
    QSqlQuery query;
    query.prepare("select * from test where username = '" + username + "' and passwd='" + password + "'");
    if(query.exec())
    {
        int k = 0;
        while(query.next())
        {
            k++;
        }
        if(k == 1)
        {
            _label->setText("username & password are correct.");

            connCLose();
            this->hide();
            InfoWindow* infoWindow = new InfoWindow;
            infoWindow->show();

        }
        if(k > 1)
            _label->setText("Duplicate username & password.");
        if(k < 1)
            _label->setText("username & password are not correct.");
    }
    else
        _label->setText("Error while query execution..");
}


//=================
// METHODS
//=================
bool Login::connOpen()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(_DBPATH_);
    if(!db.open())
    {
        qDebug() << "Failed to connect to the database.";
        return false;
    }
    else
    {
        qDebug() <<  "Connected.";
        return true;
    }
}

void Login::connCLose()
{
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
}

void Login::setupUI()
{
    QVBoxLayout* mainlayout = new QVBoxLayout;
    QWidget* mainWidget = new QWidget;
    mainWidget->setLayout(mainlayout);
    setCentralWidget(mainWidget);

    QHBoxLayout* hlayout = new QHBoxLayout;
        QLabel* picture = new QLabel;
        picture->setMargin(5);
        picture->setPixmap(QPixmap("C:/Users/Clement/Pictures/gravatar.jpg"));
        hlayout->addWidget(picture);
        QGroupBox* signInBox = new QGroupBox("Sign In");
            QFormLayout* signInForm = new QFormLayout;
                _username = new QLineEdit;
                signInForm->addRow("Username: ", _username);
                _passwd = new QLineEdit;
                _passwd->setEchoMode(QLineEdit::Password);
                connect(_passwd, SIGNAL(returnPressed()), this, SLOT(on_OK_clicked()));
                signInForm->addRow("Password: ", _passwd);
                _OK = new QPushButton("Login");
                connect(_OK, SIGNAL(clicked()), this, SLOT(on_OK_clicked()));
                signInForm->addWidget(_OK);
        signInBox->setLayout(signInForm);
        hlayout->addWidget(signInBox);

    _label = new QLabel;

    mainlayout->addLayout(hlayout);
    mainlayout->addWidget(_label);

}
