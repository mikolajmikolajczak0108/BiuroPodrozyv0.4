#include "OfferObjects.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QString>
#include "aboutoffer.h"
Offer::Offer(const Offer &of)
{
    this->tytul=of.tytul;
    this->opis=of.opis;
    this->logo=of.logo;
    this->zdj1=of.zdj1;
    this->zdj2=of.zdj2;
    this->zdj3=of.zdj3;
    this->cena=of.cena;
}

void Offer::loadOffer(QWidget *parent, QString t, QString o, QString l, QString z1, QString z2, QString z3, float c)
{
    connect (this, SIGNAL(mousePressEvent ( QMouseEvent * event )), this, SLOT(getOffer()));
    this->tytul=t;
    this->opis=o;
    this->logo=l;
    this->zdj1=z1;
    this->zdj2=z2;
    this->zdj3=z3;
    this->cena=c;
}

Offer Offer::operator=(const Offer &of)
{
    this->tytul=of.tytul;
    this->opis=of.opis;
    this->logo=of.logo;
    this->zdj1=of.zdj1;
    this->zdj2=of.zdj2;
    this->zdj3=of.zdj3;
    this->cena=of.cena;
    return *this;
}

bool Offer::operator!=(const Offer &of)
{
    if (this->logo==of.logo)
    {
        return 0;
    }
    else
        return 1;
}



void LastMinute::loadOffer(QWidget *parent, QString t, QString o, QString l, QString z1, QString z2, QString z3, float c, QDateTime date)
{
    this->tytul=t;
    this->opis=o;
    this->logo=l;
    this->zdj1=z1;
    this->zdj2=z2;
    this->zdj3=z3;
    this->cena=c;
    this->dateExpired=date;
}
