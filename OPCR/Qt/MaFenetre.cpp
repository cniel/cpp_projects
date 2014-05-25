#include "MaFenetre.h"


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
    _hslider->setGeometry(250, 20, 30, 150);
    _hslider->setRange(250, 600);
    _slider->setValue(400);

    _progress = new QProgressBar(this);
    _progress->setGeometry(10, 100, 200, 30);

    _pBouton = new QPushButton("Reset", this);
    _pBouton->move(10, 300);


    //QObject::connect(_slider, SIGNAL(valueChanged(int)), _progress, SLOT(setValue(int)));
    QObject::connect(_slider, SIGNAL(valueChanged(int)), this, SLOT(setWidth(int)));
    QObject::connect(_hslider, SIGNAL(valueChanged(int)), this, SLOT(setHeight(int)));
    QObject::connect(_slider, SIGNAL(valueChanged(int)), _lcd, SLOT(display(int)));
    QObject::connect(_pBouton, SIGNAL(clicked()), _progress, SLOT(reset()));
    QObject::connect(this, SIGNAL(maxWidth()), qApp, SLOT(aboutQt()));
    QObject::connect(_pBouton, SIGNAL(clicked()), this, SLOT(resetSliders()));
}

MaFenetre::~MaFenetre()
{
    delete _slider;
    delete _lcd;
    delete _progress;
    delete _pBouton;
}



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
