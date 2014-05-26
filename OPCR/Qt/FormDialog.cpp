#include "FormDialog.h"

FormDialog::FormDialog() : QDialog()
{
    _nom = new QLineEdit;
    _prenom = new QLineEdit;
    _age = new QLineEdit;

    QFormLayout* layout = new QFormLayout;
    layout->addRow("Votre Nom:", _nom);
    layout->addRow("Votre prénom :", _prenom);
    layout->addRow("Votre age :", _age);

    this->setLayout(layout);
}

FormDialog::~FormDialog()
{
    delete _nom;
    delete _prenom;
    delete _age;
}
