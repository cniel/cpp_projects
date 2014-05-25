#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QLCDNumber>
#include <QProgressBar>


class MaFenetre : public QWidget
{

Q_OBJECT

public:
    MaFenetre();
    ~MaFenetre();

public slots:
    void setWidth(int width);
    void setHeight(int height);
    void resetSliders();

signals:
    void maxWidth();

private:
    QSlider* _slider;
    QSlider* _hslider;
    QLCDNumber* _lcd;
    QProgressBar* _progress;
    QPushButton* _pBouton;
};

#endif // MAFENETRE_H
