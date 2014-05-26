#include "MaFenetre.h"



//==========================================
//  CONSTRUCTOR
//==========================================
MaFenetre::MaFenetre() : QWidget()
{
    setFixedSize(400, 400);

    _lcd = new QLCDNumber(this);
    _lcd->setSegmentStyle(QLCDNumber::Flat);
    _lcd->move(10, 20);

    _slider = new QSlider(Qt::Horizontal, this);
    _slider->setGeometry(10, 60, 200, 30);
    _slider->setRange(250, 600);
    _slider->setValue(400);

    _hslider = new QSlider(Qt::Vertical, this);
    _hslider->setGeometry(250, 20, 30, 110);
    _hslider->setRange(300, 600);
    _hslider->setValue(400);

    _progress = new QProgressBar(this);
    _progress->setRange(250, 600);
    _progress->setGeometry(10, 100, 200, 30);


    _pBouton = new QPushButton("Reset", this);
    //_pBouton->move(10, 220);

    _askpseudo = new QPushButton("Set Pseudo", this);
    //_askpseudo->move(100, 220);

    _askdir = new QPushButton("Set directory", this);
    //_askdir->move(190, 220);

    _askfile = new QPushButton("file Path", this);
    //_askfile->move(300, 220);

    _askForm = new QPushButton("Formulaire", this);

    QGridLayout* layout = new QGridLayout;
    layout->addWidget(_pBouton, 0, 0);
    layout->addWidget(_askpseudo, 0, 1);
    layout->addWidget(_askdir, 0, 2);
    layout->addWidget(_askfile, 0, 3);

    layout->addWidget(_askForm, 1, 0, 1, 4);


    this->setLayout(layout);

    QObject::connect(this, SIGNAL(maxWidth()), this, SLOT(tellMaxWidthReached()));

    QObject::connect(_slider, SIGNAL(valueChanged(int)), this, SLOT(setWidth(int)));
    QObject::connect(_slider, SIGNAL(valueChanged(int)), _lcd, SLOT(display(int)));
    QObject::connect(_slider, SIGNAL(valueChanged(int)), _progress, SLOT(setValue(int)));

    QObject::connect(_hslider, SIGNAL(valueChanged(int)), this, SLOT(setHeight(int)));

    QObject::connect(_pBouton, SIGNAL(clicked()), this, SLOT(resetSliders()));

    QObject::connect(_askpseudo, SIGNAL(clicked()), this, SLOT(askPseudoBox()));

    QObject::connect(_askdir, SIGNAL(clicked()), this, SLOT(askDirBox()));
    QObject::connect(_askfile, SIGNAL(clicked()), this, SLOT(askFileBox()));



    _form = new QDialog(this);
        QFormLayout* formlay = new QFormLayout;
        formlay->addRow("Votre nom", new QLineEdit(_form));
        formlay->addRow("Votre prenom", new QLineEdit(_form));
        formlay->addRow("Votre age", new QLineEdit(_form));
        _form->setLayout(formlay);

    QObject::connect(_askForm, SIGNAL(clicked()), _form, SLOT(exec()));


}

//==========================================
//  DESTRUCTOR
//==========================================
MaFenetre::~MaFenetre()
{
    delete _slider;
    delete _hslider;
    delete _lcd;
    delete _progress;
    delete _pBouton;
    delete _askdir;
    delete _askpseudo;
    delete _askdir;
    delete _askfile;
    delete _form;
}

//==========================================
//  SLOTS
//==========================================
void MaFenetre::setWidth(int width)
{
    this->setFixedWidth(width);
    if(width == 600)
    {
        emit maxWidth();
    }
}

void MaFenetre::setHeight(int height)
{
    setFixedHeight(height);
}


void MaFenetre::resetSliders()
{
    _slider->setValue(400);
    _hslider->setValue(400);
}

void MaFenetre::tellMaxWidthReached()
{
    int reponse = QMessageBox::information(this, "Largeur max", "Do U Want 2 quit?", QMessageBox::Yes|QMessageBox::No);
    if(reponse == QMessageBox::Yes)
        qApp->quit();
}

void MaFenetre::askPseudoBox()
{
    bool ok = false;
    QString pseudo = QInputDialog::getText(this, "Pseudo", "What is your <strong>pseudo</strong> ?", QLineEdit::Normal, "", &ok);
    if(ok && !pseudo.isEmpty())
    {
        QMessageBox::information(this, pseudo, "Bonjour "+pseudo);
        this->setWindowTitle(pseudo);
    }
    else
        QMessageBox::critical(this, "Error", "No pseudo entered...");
}

void MaFenetre::askDirBox()
{
    QString dir = QFileDialog::getExistingDirectory(this);
    if(!dir.isEmpty())
        _askdir->setToolTip(dir);
}

void MaFenetre::askFileBox()
{
    QString file = QFileDialog::getOpenFileName(this);
    if(!file.isEmpty())
        _askfile->setToolTip(file);
}

void MaFenetre::displayForm()
{
    _form->exec();
}

//==========================================
//  METHODS
//==========================================
