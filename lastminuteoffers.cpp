#include "lastminuteoffers.h"
#include "ui_lastminuteoffers.h"
#include "lastminuteoffers.h"
#include "ui_offers.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QVector>
#include "aboutoffer.h"
#include <QDebug>
#include <QPalette>
LMOffers::LMOffers(QWidget *parent, User *currentUser) :
    QDialog(parent),
    ui(new Ui::LastMinuteOffers)
{
    ui->setupUi(this);
    QPixmap ground(":/Img/Img/lastminute.jpg");
    QPalette back;
    back.setBrush(this->backgroundRole(), QBrush(ground.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio)));
    QPixmap ground2(":/Img/Img/lastminute.jpg");
    QPalette back2;
    back2.setBrush(this->backgroundRole(), QBrush(ground2.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio)));
    ui->scrollArea->setPalette(back);
    ui->NONE->setVisible(0);
    ui->NONE_2->setVisible(0);
    toPassUser=currentUser;
    qDebug() <<toPassUser->name;
     qDebug() <<toPassUser->Card->number;
      qDebug() <<toPassUser->Card->PIN;
    if(parent->isFullScreen()==1)
    {
        this->showFullScreen();
        isFullscreen=1;
    }
    makeOffers(this);
}
void LMOffers::makeOffers(QWidget *parent)
{
    Loffers.push_back(ui->LMOff1);
    QFile file(":/Offers/Offers/LastMinute/Oferty.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(parent, "ERROR", "NO SUCH FILE EXISTS", QMessageBox::Ok);
    }
    QTextStream in(&file);
    for (int i=0; i<Loffers.size(); i++)
    {
        Loffers.at(i)->tytul=in.readLine();
       // qDebug() << offers.at(i)->tytul;
        Loffers.at(i)->opis=in.readLine();
        Loffers.at(i)->logo=in.readLine();
        qDebug()<<Loffers.at(i)->logo;
        Loffers.at(i)->zdj1=in.readLine();
        Loffers.at(i)->zdj2=in.readLine();
        Loffers.at(i)->zdj3=in.readLine();
        Loffers.at(i)->cena=in.readLine().toFloat();
        Loffers.at(i)->dateExpired=QDateTime::fromString(in.readLine(), "yyyy:MM:dd");

    }
    QPixmap z4(":/Offers/Offers/"+Loffers.at(0)->logo );
    QPalette pal;
    pal.setBrush(ui->LMOff1->backgroundRole(), QBrush(z4.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio)));
    ui->LMOff1->setFlat(true);
    ui->LMOff1->setAutoFillBackground(true);
    ui->LMOff1->setPalette(pal);
    ui->LMOff1DATE->setText(Loffers.at(0)->dateExpired.toString("dd/MM/yyyy"));
}
LMOffers::~LMOffers()
{
    delete ui;
}

void LMOffers::on_Return_clicked()
{
    this->close();
}

void LMOffers::on_LMOff1_clicked()
{
    aboutOffer *Of1 = new aboutOffer(this, Loffers.at(0), toPassUser);
    Of1->exec();
}
