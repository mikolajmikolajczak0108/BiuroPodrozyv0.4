#include "aboutoffer.h"
#include "ui_aboutoffer.h"
#include <QPalette>
#include <QMessageBox>
#include <QDebug>
#include "data.h"
aboutOffer::aboutOffer(QWidget *parent, Offer *o, User *currentUser) :
    QDialog(parent),
    ui(new Ui::aboutOffer)
{
    ui->setupUi(this);
    editableUser=currentUser;
    passableOffer=o;
    qDebug() << passableOffer->tytul;
    if(parent->isFullScreen()==1)
    {
        this->showFullScreen();
    }
    QPixmap z1(":/Offers/Offers/"+o->zdj1 );
    QPixmap z2(":/Offers/Offers/"+o->zdj2);
    QPixmap z3(":/Offers/Offers/"+o->zdj3 );
    QPixmap z4(":/Offers/Offers/"+o->logo );
    z4.scaled(this->size(), Qt::KeepAspectRatio);
    QPalette backgroundP;
    backgroundP.setBrush(QPalette::Background, z4.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio));
    ui->Tytul->setText(o->tytul);
    ui->Opis->setText(o->opis);
    ui->Cena->setText("Koszt rezerwacji: " + QString::number(o->cena) + "zł");
    ui->zdj1->setPixmap(z1.scaled(0.36*(this->width()),0.38*(this->height()), Qt::KeepAspectRatio));
    ui->zdj2->setPixmap(z2.scaled(0.36*(this->width()),0.38*(this->height()), Qt::KeepAspectRatio));
    ui->zdj3->setPixmap(z3.scaled(0.49*(this->width()),0.48*(this->height()), Qt::KeepAspectRatio));
    this->setPalette(backgroundP);
}

aboutOffer::aboutOffer(QWidget *parent, Offer *o,int isAuto, User *currentUser) :
    QDialog(parent),
    ui(new Ui::aboutOffer)
{
    ui->setupUi(this);
    editableUser=currentUser;
    passableOffer=o;
    qDebug() << passableOffer->tytul;
    if(parent->isFullScreen()==1)
    {
        this->showFullScreen();
    }
    QPixmap z1("D:/Biuro Podrozy/BiuroPodrozy/Offers/"+o->zdj1 );
    QPixmap z2("D:/Biuro Podrozy/BiuroPodrozy/Offers/"+o->zdj2);
    QPixmap z3("D:/Biuro Podrozy/BiuroPodrozy/Offers/"+o->zdj3 );
    QPixmap z4("D:/Biuro Podrozy/BiuroPodrozy/Offers/"+o->logo );
    z4.scaled(this->size(), Qt::KeepAspectRatio);
    QPalette backgroundP;
    backgroundP.setBrush(QPalette::Background, z4.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio));
    ui->Tytul->setText(o->tytul);
    ui->Opis->setText(o->opis);
       ui->Cena->setText("Koszt rezerwacji: " + QString::number(o->cena) + "zł");
    ui->zdj1->setPixmap(z1.scaled(0.36*(this->width()),0.38*(this->height()), Qt::KeepAspectRatio));
    ui->zdj2->setPixmap(z2.scaled(0.36*(this->width()),0.38*(this->height()), Qt::KeepAspectRatio));
    ui->zdj3->setPixmap(z3.scaled(0.49*(this->width()),0.48*(this->height()), Qt::KeepAspectRatio));
    this->setPalette(backgroundP);
}

aboutOffer::aboutOffer(QWidget *parent, User *currentUser, int which): QDialog(parent),ui(new Ui::aboutOffer)
{
    ui->setupUi(this);
    editableUser=currentUser;
    qDebug() << passableOffer->tytul;
    if(parent->isFullScreen()==1)
    {
        this->showFullScreen();
    }
    QPixmap z1(":/Offers/Offers/"+currentUser->userOffers.at(which)->zdj1 );
    QPixmap z2(":/Offers/Offers/"+currentUser->userOffers.at(which)->zdj2);
    QPixmap z3(":/Offers/Offers/"+currentUser->userOffers.at(which)->zdj3 );
    QPixmap z4(":/Offers/Offers/"+currentUser->userOffers.at(which)->logo );
    z4.scaled(this->size(), Qt::KeepAspectRatio);
    QPalette backgroundP;
    backgroundP.setBrush(QPalette::Background, z4.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio));
    ui->Tytul->setText(currentUser->userOffers.at(which)->tytul);
    ui->Opis->setText(currentUser->userOffers.at(which)->opis);
       ui->Cena->setText("Koszt rezerwacji: " + QString::number(currentUser->userOffers.at(which)->cena) + "zł");
    ui->zdj1->setPixmap(z1.scaled(0.36*(this->width()),0.38*(this->height()), Qt::KeepAspectRatio));
    ui->zdj2->setPixmap(z2.scaled(0.36*(this->width()),0.38*(this->height()), Qt::KeepAspectRatio));
    ui->zdj3->setPixmap(z3.scaled(0.49*(this->width()),0.48*(this->height()), Qt::KeepAspectRatio));
    this->setPalette(backgroundP);
}
aboutOffer::aboutOffer(QWidget *parent, User *currentUser,int isAuto, int which): QDialog(parent),ui(new Ui::aboutOffer)
{
    ui->setupUi(this);
    editableUser=currentUser;
    qDebug() << passableOffer->tytul;
    if(parent->isFullScreen()==1)
    {
        this->showFullScreen();
    }
    QPixmap z1(":/Offers/Offers/"+currentUser->userOffers.at(which)->zdj1 );
    QPixmap z2(":/Offers/Offers/"+currentUser->userOffers.at(which)->zdj2);
    QPixmap z3(":/Offers/Offers/"+currentUser->userOffers.at(which)->zdj3 );
    QPixmap z4(":/Offers/Offers/"+currentUser->userOffers.at(which)->logo );
    z4.scaled(this->size(), Qt::KeepAspectRatio);
    QPalette backgroundP;
    backgroundP.setBrush(QPalette::Background, z4.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio));
    ui->Tytul->setText(currentUser->userOffers.at(which)->tytul);
    ui->Opis->setText(currentUser->userOffers.at(which)->opis);
       ui->Cena->setText("Koszt rezerwacji: " + QString::number(currentUser->userOffers.at(which)->cena) + "zł");
    ui->zdj1->setPixmap(z1.scaled(0.36*(this->width()),0.38*(this->height()), Qt::KeepAspectRatio));
    ui->zdj2->setPixmap(z2.scaled(0.36*(this->width()),0.38*(this->height()), Qt::KeepAspectRatio));
    ui->zdj3->setPixmap(z3.scaled(0.49*(this->width()),0.48*(this->height()), Qt::KeepAspectRatio));
    this->setPalette(backgroundP);
}

aboutOffer::~aboutOffer()
{
    delete ui;
}

void aboutOffer::on_return_2_clicked()
{
    this->close();
}

void aboutOffer::on_return_3_clicked()
{
    if (editableUser->Card->cash>=passableOffer->cena)
    {
        if (QMessageBox::question(this, "Do you want to buy "+passableOffer->tytul+"?", "Czy jesteś pewny/a swojej decyzji? Po naciśnięciu klawisza 'potwierdź' obowiązuje /n dwutygodniowy termin złożenia reklamacji.", QMessageBox::Yes, QMessageBox::No)==QMessageBox::Yes)
        {
    Data *setData = new Data(this, passableOffer);
    setData->exec();
    passableOffer=setData->userOffer;
    qDebug() << passableOffer->dateBegin.toString( "dd:MM:yyyy");
    editableUser->userOffers.push_back(passableOffer);
    editableUser->Card->cash-=passableOffer->cena;
    qDebug() << editableUser->Card->cash;
    qDebug() << editableUser->userOffers.at(0)->tytul;
     qDebug() << editableUser->userOffers.at(0)->opis;
      qDebug() << editableUser->userOffers.at(0)->cena;
        }
    }
}
