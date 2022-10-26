#include <QFile>
#include <QFileDialog>
#include "User.h"
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include "addfile.h"
creditCard::creditCard(QWidget *parent, QString username)
{
    QFile file("D:/Biuro Podrozy/BiuroPodrozy/creditCards/"+username+".txt");
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(parent, "ERROR", "NO SUCH FILE EXISTS", QMessageBox::Ok);
    }
    QTextStream in(&file);
    this->number=in.readLine();
    this->PIN=in.readLine();
    in.setRealNumberNotation(QTextStream::FixedNotation);
    this->cash=in.readLine().toFloat();
    file.close();
}

creditCard::creditCard( const creditCard &card2)
{
    this->PIN=card2.PIN;
    this->cash=card2.cash;
    this->number=card2.number;
}

User::User(QWidget *parent, QString username, QString pass)
{
    QFile file("D:/Biuro Podrozy/BiuroPodrozy/Users/"+username+".txt");
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(parent, "ERROR", "NO SUCH FILE EXISTS", QMessageBox::Ok);
    }
    QTextStream in(&file);

    this->nick=in.readLine();
    this->name=in.readLine();
    this->surname=in.readLine();
    this->password=in.readLine();
    try {
            if (this->password!=pass)
            {
                bool err=0;
                throw err;
            }
    }  catch (bool er) {
        QMessageBox::warning(parent, "ERROR!", "WRONG PASSWORD!", QMessageBox::Ok);
        wasProperlyCreated=0;
    }

    file.close();

    Card = new creditCard(parent, this->nick);
    QFile file2("D:/Biuro Podrozy/BiuroPodrozy/Users/"+this->nick+"Offers.txt");
    if (!file2.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(parent, "ERROR", "CAN'T READ USER'S OFFERS", QMessageBox::Ok);
    }
    QFile file3("D:/Biuro Podrozy/BiuroPodrozy/Offers/Oferty.txt");
    if (!file3.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(parent, "ERROR", "CAN'T READ USER'S OFFERS", QMessageBox::Ok);
    }
    QTextStream out(&file3);
   int iter=0;
    QString t, o, l, z1, z2, z3;
    float c;
    while (file2.atEnd()!=1)
    {
        t=file3.readLine();
        if (this->userOffers.isEmpty()==0)
        {
            if ((file2.readLine()==t)&&(t!=this->userOffers.at(iter)->tytul))
            {
                Offer * of = new Offer(parent);
                t.chop(1);
                o=file3.readLine();
                o.chop(1);
                qDebug() << o;
                l=file3.readLine();
                l.chop(1);
                qDebug() << l;
                z1=file3.readLine();
                z1.chop(1);
                qDebug() << z1;
                z2=file3.readLine();
                z2.chop(1);
                qDebug() << z2;
                z3=file3.readLine();
                z3.chop(1);
                qDebug() << z3;
                c=file3.readLine().toFloat();
                of->loadOffer(parent,t, o,l,z1, z2, z3, c );
                this->userOffers.push_back(of);
                iter++;
            }
        }
        else
        {
            if (file2.readLine()==t)
            {
                Offer * of = new Offer(parent);
                t.chop(1);
                o=file3.readLine();
                o.chop(1);
                qDebug() << o;
                l=file3.readLine();
                l.chop(1);
                qDebug() << l;
                z1=file3.readLine();
                z1.chop(1);
                qDebug() << z1;
                z2=file3.readLine();
                z2.chop(1);
                qDebug() << z2;
                z3=file3.readLine();
                z3.chop(1);
                qDebug() << z3;
                c=file3.readLine().toFloat();
                of->loadOffer(parent,t, o,l,z1, z2, z3, c );
                this->userOffers.push_back(of);
               // iter++;
            }
        }

    }
    file2.close();
    file3.close();
}

User User::operator=(const User &U)
{
    this->name=U.name;
    this->nick=U.nick;
    this->surname=U.surname;
    this->password=U.password;
    this->Card= new creditCard(*U.Card);
    return *this;
}

void User::saveOffers(QWidget *parent)
{
    QFile file("D:/Biuro Podrozy/BiuroPodrozy/Users/"+this->nick+"Offers.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(parent, "ERROR", "CAN'T SAVE USER'S OFFERS", QMessageBox::Ok);
    }
    QTextStream out(&file);
    for (int i=0; i<this->userOffers.size(); i++)
    {
    out << this->userOffers.at(i)->tytul;
    out <<endl;
    }
        out.flush();
    file.close();
}

Admin::Admin(QWidget *parent, QString username, QString pass)
{
    QFile file("D:/Biuro Podrozy/BiuroPodrozy/Users/"+username+".txt");
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(parent, "ERROR", "NO SUCH FILE EXISTS", QMessageBox::Ok);
    }
    QTextStream in(&file);

    this->nick=in.readLine();
    this->name=in.readLine();
    this->surname=in.readLine();
    this->password=in.readLine();
    try {
            if (this->password!=pass)
            {
                bool err=0;
                throw err;
            }
    }  catch (bool er) {
        QMessageBox::warning(parent, "ERROR!", "WRONG PASSWORD!", QMessageBox::Ok);
        wasProperlyCreated=0;
    }

    file.close();

    Card = new creditCard(parent, this->nick);
    QFile file2("D:/Biuro Podrozy/BiuroPodrozy/Users/"+this->nick+"Offers.txt");
    if (!file2.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(parent, "ERROR", "CAN'T READ USER'S OFFERS", QMessageBox::Ok);
    }
    QFile file3("D:/Biuro Podrozy/BiuroPodrozy/Offers/Oferty.txt");
    if (!file3.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(parent, "ERROR", "CAN'T READ USER'S OFFERS", QMessageBox::Ok);
    }
    QTextStream out(&file3);
   int iter=0;
    QString t, o, l, z1, z2, z3;
    float c;
    while (file2.atEnd()!=1)
    {
        t=file3.readLine();
        if (this->userOffers.isEmpty()==0)
        {
            if ((file2.readLine()==t)&&(t!=this->userOffers.at(iter)->tytul))
            {
                Offer * of = new Offer(parent);
                t.chop(1);
                o=file3.readLine();
                o.chop(1);
                qDebug() << o;
                l=file3.readLine();
                l.chop(1);
                qDebug() << l;
                z1=file3.readLine();
                z1.chop(1);
                qDebug() << z1;
                z2=file3.readLine();
                z2.chop(1);
                qDebug() << z2;
                z3=file3.readLine();
                z3.chop(1);
                qDebug() << z3;
                c=file3.readLine().toFloat();
                of->loadOffer(parent,t, o,l,z1, z2, z3, c );
                this->userOffers.push_back(of);
                iter++;
            }
        }
        else
        {
            if (file2.readLine()==t)
            {
                Offer * of = new Offer(parent);
                t.chop(1);
                o=file3.readLine();
                o.chop(1);
                qDebug() << o;
                l=file3.readLine();
                l.chop(1);
                qDebug() << l;
                z1=file3.readLine();
                z1.chop(1);
                qDebug() << z1;
                z2=file3.readLine();
                z2.chop(1);
                qDebug() << z2;
                z3=file3.readLine();
                z3.chop(1);
                qDebug() << z3;
                c=file3.readLine().toFloat();
                of->loadOffer(parent,t, o,l,z1, z2, z3, c );
                this->userOffers.push_back(of);
               // iter++;
            }
        }

    }
    file2.close();
    file3.close();
}

Admin Admin::operator=(const User &U)
{
    this->name=U.name;
    this->nick=U.nick;
    this->surname=U.surname;
    this->password=U.password;
    this->Card= new creditCard(*U.Card);
    return *this;
}

void Admin::saveOffers(QWidget *parent)
{
    QFile file("D:/Biuro Podrozy/BiuroPodrozy/Users/"+this->nick+"Offers.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(parent, "ERROR", "CAN'T SAVE USER'S OFFERS", QMessageBox::Ok);
    }
    QTextStream out(&file);
    for (int i=0; i<this->userOffers.size(); i++)
    {
    out << this->userOffers.at(i)->tytul;
    out <<endl;
    }
        out.flush();
        file.close();
}
 User User::operator=(const Admin &A)
 {
     this->name=A.name;
     this->nick=A.nick;
     this->surname=A.surname;
     this->password=A.password;
     this->Card= new creditCard(*A.Card);
     this->isAdmin=1;
     return *this;
 }




