#include "ClassWindow.h"

//=================
//  CONSTRUCTOR
//=================
ClassWindow::ClassWindow(QString header, QString classname) : QDialog()
{
    this->setWindowIcon(QIcon(QCoreApplication::applicationDirPath() + "/class.png"));
    this->setMinimumSize(420, 530);

    _classname = classname;

    _mainlayout = new QVBoxLayout;

    _tabs = new QTabWidget;
        // tab1 content
        _headerlayout = new QVBoxLayout;
            _classtext = new QTextEdit;
            _classtext->setText(header);
            _savebutton = new QPushButton("Save and see the source code.");
            _headerlayout->addWidget(_classtext);
            _headerlayout->addWidget(_savebutton);

        // tab2 content
        _cpplayout = new QVBoxLayout;
            _cpptext = new QTextEdit;
            _savebutton2 = new QPushButton("Save");
            _cpplayout->addWidget(_cpptext);
            _cpplayout->addWidget(_savebutton2);

        // populating tabs
        _tab1 = new QWidget;
        _tab2 = new QWidget;
        _tab1->setLayout(_headerlayout);
        _tab2->setLayout(_cpplayout);
        _tabs->addTab(_tab1, "Header");

    QWidget* savewidget = new QWidget;
    _buttonslayout = new QHBoxLayout;

        _close = new QPushButton("Close");
        _buttonslayout->addWidget(_close);
    savewidget->setLayout(_buttonslayout);

    _mainlayout->addWidget(_tabs);
    _mainlayout->addWidget(savewidget);
    this->setLayout(_mainlayout);

    QObject::connect(_savebutton, SIGNAL(clicked()), this, SLOT(addCppTab()));
    QObject::connect(_savebutton2, SIGNAL(clicked()), this, SLOT(saveCpp()));
    QObject::connect(_close, SIGNAL(clicked()), this, SLOT(close()));
}

//=================
//  SLOTS
//=================
void ClassWindow::addCppTab()
{
    _headerpath = QFileDialog::getSaveFileName(this, tr("Save Header"), _classname+".h");

    QString text = "#include \"" + _headerpath + "\"\n\n";
    _cpptext->setText(text);

    QFile file(_headerpath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    out << _classtext->toPlainText();

    _tabs->addTab(_tab2, "Source Code");
    _tabs->setCurrentIndex(1);
}

void ClassWindow::saveCpp()
{
    QRegularExpression re("/(?:.(?!/))+$");
    QString path = _headerpath.remove(re) + "/" + _classname + ".cpp";
    QMessageBox::information(this, "info", path);

    QString cpppath = QFileDialog::getSaveFileName(this, tr("Save Source File"), path);

    QFile file(cpppath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    out << _cpptext->toPlainText();

    this->close();
}
