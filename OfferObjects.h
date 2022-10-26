#ifndef OFFEROBJECTS_H
#define OFFEROBJECTS_H
#include <QPushButton>
#include <QTextStream>
#include <QDateTime>
class Offer: public QPushButton
{
    using QPushButton::QPushButton;
public:
    Offer(const Offer &of);
    void loadOffer(QWidget *parent,QString t, QString o, QString l, QString z1, QString z2, QString z3, float c);
    float cena;
    QString tytul, opis, logo, zdj1, zdj2, zdj3;
    Offer operator=(const Offer &of);
    bool operator!=(const Offer &of);
     QDateTime dateBegin, dateEnd;
};
class LastMinute : public Offer
{
    using Offer::Offer;
public:
    void loadOffer(QWidget *parent,QString t, QString o, QString l, QString z1, QString z2, QString z3, float c, QDateTime date);
    QDateTime dateExpired;
};

#endif // OFFEROBJECTS_H
