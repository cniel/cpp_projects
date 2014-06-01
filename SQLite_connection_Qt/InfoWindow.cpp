#include "InfoWindow.h"

InfoWindow::InfoWindow()
{
    setupUI();

    Login conn;
    if(!conn.connOpen())
        _connexionlabel->setText("Failed to connect to the database.");
    else
        _connexionlabel->setText("Connected.");

    conn.connCLose();
}


//==================
// SLOTS
//==================
void InfoWindow::on_submit_clicked()
{
    Login conn;
    QString name, surname, username;
    int age,password;
    name = _name->text();
    surname = _surname->text();
    age = _age->text().toInt();
    username = _username->text();
    password = _passwd->text().toInt();

    if(!conn.connOpen())
    {
        _connexionlabel->setText("Failed to open the database");
        return;
    }

    _connexionlabel->setText("Connected");
    QSqlQuery query;
    query.prepare(QString("insert into test values ('%1', '%2', %3, '%4', %5)").arg(name).arg(surname).arg(age).arg(username).arg(password));
    if(query.exec())
    {
        QMessageBox::information(this, "Info", "Data saved successfully.");
    }
    else
        _connexionlabel->setText("Error while query execution..");
    conn.connCLose();
    on_loadtable_clicked();
}

void InfoWindow::on_update_clicked()
{
    if(_rowid->text().isEmpty())
    {
        QMessageBox::critical(this, "Error", "RowID must be passed for an update.");
        return;
    }

    Login conn;
    QString name, surname, username;
    int age,password, rowid;
    rowid = _rowid->text().toInt();
    name = _name->text();
    surname = _surname->text();
    age = _age->text().toInt();
    username = _username->text();
    password = _passwd->text().toInt();

    if(!conn.connOpen())
    {
        _connexionlabel->setText("Failed to open the database");
        return;
    }

    _connexionlabel->setText("Connected");
    QSqlQuery query;
    query.prepare(QString("update test set name='%1', surname='%2', age=%3, username='%4', passwd=%5 WHERE rowid=%6").arg(name).arg(surname).arg(age).arg(username).arg(password).arg(rowid));
    if(query.exec())
    {
        QMessageBox::information(this, "Info", "Data Updated successfully.");
    }
    else
        _connexionlabel->setText("Error while query execution..");
    conn.connCLose();
    on_loadtable_clicked();
}

void InfoWindow::on_delete_clicked()
{
    if(_rowid->text().isEmpty())
    {
        QMessageBox::critical(this, "Error", "RowID must be passed for a delete operation.");
        return;
    }

    Login conn;
    int rowid;
    rowid = _rowid->text().toInt();

    if(!conn.connOpen())
    {
        _connexionlabel->setText("Failed to open the database");
        return;
    }

    _connexionlabel->setText("Connected");
    QSqlQuery query;
    query.prepare(QString("delete from test where rowid=%1").arg(rowid));
    if(query.exec())
    {
        QMessageBox::information(this, "Info", "Data Deleted successfully.");
    }
    else
        _connexionlabel->setText("Error while query execution..");
    conn.connCLose();
    on_loadtable_clicked();
}

void InfoWindow::on_loadtable_clicked()
{
    Login conn;
    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQueryModel* modelList = new QSqlQueryModel;

    if(!conn.connOpen())
        return;
    QSqlQuery* query = new QSqlQuery(conn.db);
    QSqlQuery* query2 = new QSqlQuery(conn.db);
    query->prepare("select rowid,name,surname from test");
    query2->prepare("select name from test");
    query->exec();
    query2->exec();

    model->setQuery(*query);
    _tableview->setModel(model);
    modelList->setQuery(*query2);
    _combobox->setModel(modelList);
    conn.connCLose();
}

void InfoWindow::on_combobox_changed(QString text)
{
    Login conn;
    if(!conn.connOpen())
    {
        QMessageBox::critical(this, "Error", "Failed to open the database.");
        return;
    }

    QString name = _combobox->currentText();
    QSqlQuery* query = new QSqlQuery;
    query->prepare("select rowid, name, surname, age, username from test where name = '"+name+"'");
    if(query->exec())
    {
        while(query->next())
        {
            _rowid->setText(query->value(0).toString());
            _name->setText(query->value(1).toString());
            _surname->setText(query->value(2).toString());
            _age->setText(query->value(3).toString());
            _username->setText(query->value(4).toString());
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", query->lastError().text());
    }

    conn.connCLose();
}

void InfoWindow::on_tableview_activated(QModelIndex const& index)
{
    QString val = _tableview->model()->data(index).toString();

    Login conn;
    if(!conn.connOpen())
    {
        QMessageBox::critical(this, "Error", "Failed to open the database.");
        return;
    }
    QSqlQuery query;
    query.prepare(QString("select rowid, name, surname, age, username from test where rowid=%1 or name = '%1' or surname = '%1' or age = %1").arg(val.toInt()));

    if(query.exec())
    {
        while(query.next())
        {
            _rowid->setText(query.value(0).toString());
            _name->setText(query.value(1).toString());
            _surname->setText(query.value(2).toString());
            _age->setText(query.value(3).toString());
            _username->setText(query.value(4).toString());
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", query.lastError().text());
        QMessageBox::warning(this, "query", QString("select rowid, name, surname, age, username from test where rowid="+val+" or name = '"+val+"' or surname = '"+val+"' or age = %1").arg(val.toInt()));
    }
    conn.connCLose();
}


//==================
// METHODS
//==================
void InfoWindow::setupUI()
{
    QWidget* mainwidget = new QWidget;
    QVBoxLayout* mainlayout = new QVBoxLayout;
    mainwidget->setLayout(mainlayout);
    setCentralWidget(mainwidget);

    QHBoxLayout* form2tablelayout = new QHBoxLayout;
        QFormLayout* formlayout = new QFormLayout;
            _rowid = new QLineEdit;
            _name = new QLineEdit;
            _surname = new QLineEdit;
            _age = new QLineEdit;
            _username = new QLineEdit;
            _passwd = new QLineEdit;
            QWidget* buttonswidget = new QWidget;
            QHBoxLayout* buttonslayout = new QHBoxLayout;
            buttonswidget->setLayout(buttonslayout);
                _submit = new QPushButton("Insert");
                _update = new QPushButton("Update");
                _delete = new QPushButton("Delete");
                connect(_submit, SIGNAL(clicked()), this, SLOT(on_submit_clicked()));
                connect(_update, SIGNAL(clicked()), this, SLOT(on_update_clicked()));
                connect(_delete, SIGNAL(clicked()), this, SLOT(on_delete_clicked()));
                buttonslayout->addWidget(_submit);
                buttonslayout->addWidget(_update);
                buttonslayout->addWidget(_delete);
            formlayout->addRow("RowID: ", _rowid);
            formlayout->addRow("Name: ", _name);
            formlayout->addRow("Surname: ", _surname);
            formlayout->addRow("Age: ", _age);
            formlayout->addRow("Username: ", _username);
            formlayout->addRow("Password: ", _passwd);
            formlayout->addWidget(buttonswidget);

        QVBoxLayout* tablelayout = new QVBoxLayout;
            _tableview = new QTableView;
            connect(_tableview, SIGNAL(activated(QModelIndex)), this, SLOT(on_tableview_activated(QModelIndex)));
            _loadtable = new QPushButton("Load table");
            connect(_loadtable, SIGNAL(clicked()), this, SLOT(on_loadtable_clicked()));
            tablelayout->addWidget(_tableview);
            tablelayout->addWidget(_loadtable);
        _combobox = new QComboBox;
        connect(_combobox, SIGNAL(currentIndexChanged(QString)), this, SLOT(on_combobox_changed(QString)));

    form2tablelayout->addLayout(formlayout);
    form2tablelayout->addLayout(tablelayout);
    form2tablelayout->addWidget(_combobox);

    _connexionlabel = new QLabel;

    mainlayout->addLayout(form2tablelayout);
    mainlayout->addWidget(_connexionlabel);

}
