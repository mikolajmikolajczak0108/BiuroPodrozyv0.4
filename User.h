#ifndef USER_H
#define USER_H

#include <QString>
#include <QWidget>
#include <QVector>
#include "OfferObjects.h"
class creditCard
{
    //private:
public:
    QString number, PIN;
    float cash;
    //public:
    creditCard(QWidget *parent, QString username);
    creditCard( const creditCard &card2);
    QString getNumber();
    QString getPIN();
};

class appOperator
{
public:
    QString name, surname, nick, password;
    creditCard * Card;
    bool wasProperlyCreated=1;
    QVector <Offer*> userOffers;
    virtual void saveOffers(QWidget *parent) = 0;
};
class Admin;
class User: public appOperator
{
    //private:

    //public:
public:
    User(QWidget *parent, QString username, QString pass);
    User  operator=(const User &U);
    void saveOffers(QWidget *parent);
    User operator=(const Admin &A);
        bool isAdmin=0;
    //buyOffer(const offer &of);

};
class Admin: public appOperator
{
public:
    Admin(QWidget *parent, QString username, QString pass);
    Admin  operator=(const User &U);
    void saveOffers(QWidget *parent);
};

#endif // USER_H
