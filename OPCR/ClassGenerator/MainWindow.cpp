#include "MainWindow.h"

//=================
// CONSTRUCTOR
//=================
MainWindow::MainWindow() : QWidget()
{
    this->setWindowIcon(QIcon(QCoreApplication::applicationDirPath() + "/class.png"));

    // MAIN LAYOUT
    _mainlayout = new QVBoxLayout;

    //------------------------------
    // Layout 1 : Definition Layout
    //------------------------------
    _defbox = new QGroupBox;
    _defbox->setTitle("Definition");
        _deflayout = new QFormLayout;
            _name = new QLineEdit;
            _motherclass = new QLineEdit;
            _deflayout->addRow("Name", _name);
            _deflayout->addRow("Mother Class", _motherclass);
    _defbox->setLayout(_deflayout);
    _mainlayout->addWidget(_defbox);

    //-----------------------------
    // Layout 2 : Options Layout
    //-----------------------------
    _optbox = new QGroupBox;
    _optbox->setTitle("Options");
        _optlayout = new QFormLayout;
            QHBoxLayout* inclusionslayout = new QHBoxLayout;
                _inclusions = new QCheckBox("Prevent multiple insertions : ");
                _inclusionsedition = new QLineEdit;
                _inclusionsedition->setEnabled(false);
            inclusionslayout->addWidget(_inclusions);
            inclusionslayout->addWidget(_inclusionsedition);

            _defconstructor = new QCheckBox("Generate default constructor");
            _gendestructor = new QCheckBox("Generate destructor");

            _optlayout->addItem(inclusionslayout);
            _optlayout->addWidget(_defconstructor);
            _optlayout->addWidget(_gendestructor);
    _optbox->setLayout(_optlayout);
    _mainlayout->addWidget(_optbox);

    //-----------------------------
    // Layout 3 : Comments Layout
    //-----------------------------
    _combox = new QGroupBox;
    _combox->setTitle("Comments");
    _combox->setCheckable(true);
    _combox->setChecked(false);
        _comlayout = new QFormLayout;
            _author = new QLineEdit;
            _calendar = new QDateEdit;
            _role = new QTextEdit;
            _calendar->setDateTime(QDateTime::currentDateTime());
            _comlayout->addRow("Author", _author);
            _comlayout->addRow("Creation date", _calendar);
            _comlayout->addRow("Class role", _role);
    _combox->setLayout(_comlayout);
    _mainlayout->addWidget(_combox);

    //-----------------------------
    // Layout 4 : Buttons Layout
    //-----------------------------
    _buttonslayout = new QHBoxLayout;
        _generate = new QPushButton("Generate !");
        _quit = new QPushButton("Quit");
        _buttonslayout->addWidget(_generate);
        _buttonslayout->addWidget(_quit);
    _mainlayout->addLayout(_buttonslayout);


    this->setLayout(_mainlayout);

    QObject::connect(_name, SIGNAL(textChanged(QString)), this, SLOT(editInclusions(QString)));
    QObject::connect(_inclusions, SIGNAL(clicked(bool)), _inclusionsedition, SLOT(setEnabled(bool)));
    QObject::connect(_generate, SIGNAL(clicked()), this, SLOT(dispClassWindow()));
    QObject::connect(_quit, SIGNAL(clicked()), qApp, SLOT(quit()));

}

//===================
// SLOTS
//===================
void MainWindow::dispClassWindow()
{
    if(_name->text().isEmpty())
    {
        QMessageBox::critical(this, "Empty Name", "You must enter at least a class Name !");
    }
    else
    {
        QString classtext;
        QString cpptext;

        // HEADER TEXT
        if(_combox->isChecked())
            classtext += ("/*\nAuthor: "+_author->text() + "\nCreation date: "+_calendar->text() + "\n\nRole:\n"+_role->toPlainText() +"\n\nCreated thanks to ClassGenerator, by cniel.\n*/\n\n");

        bool inclOK = (_inclusions->isChecked());
        if(inclOK)
            classtext += ("#ifndef "+ _inclusionsedition->text() +"\n#define "+ _inclusionsedition->text() +"\n\n");

        classtext += ("class "+_name->text());

        if(!_motherclass->text().isEmpty())
            classtext += (" : public "+_motherclass->text());

        classtext += "\n{\npublic:\n";

        if(_defconstructor->isChecked())
            classtext += ("\t"+_name->text()+"();\n");

        if(_gendestructor->isChecked())
            classtext += ("\t~"+_name->text()+"();\n");

        classtext += "\nprotected:\n\nprivate:\n\n";

        classtext += "\n};";

        if(inclOK)
            classtext += "\n\n#endif";

        //CPP TEXT
        cpptext = _name->text();

        ClassWindow window(classtext, cpptext);
        window.exec();
    }
}


void MainWindow::editInclusions(QString text)
{
    if(!text.isEmpty())
    {
        text = text.trimmed();
        text = text.toUpper();
        text += "_H";
    }
    _inclusionsedition->setText(text);
}
