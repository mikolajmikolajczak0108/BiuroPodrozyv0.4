#include "offers.h"
#include "ui_offers.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QVector>
#include "aboutoffer.h"
#include <QDebug>
#include <QPalette>
#include <QCursor>
#include <QPoint>
Offers::Offers(QWidget *parent, User *currentUser, Offer *lastOffer) :
    QDialog(parent),
    ui(new Ui::Offers)
{
    ui->setupUi(this);
    QPixmap ground(":/Img/Img/tlomenu.jpg");
    QPalette back;
    back.setBrush(this->backgroundRole(), QBrush(ground.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio)));
    this->setPalette(back);
    QPixmap ground2(":/Img/Img/lastminute.jpg");
    QPalette back2;
    back2.setBrush(this->backgroundRole(), QBrush(ground2.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio)));
    ui->scrollArea->setPalette(back);
    toPassUser=currentUser;
    if(toPassUser->isAdmin==0)
    {
        ui->pushButton->setVisible(0);
    }
    this->lastOffer=lastOffer;
    qDebug() <<toPassUser->name;
    qDebug() <<toPassUser->Card->number;
    qDebug() <<toPassUser->Card->PIN;
    if(parent->isFullScreen()==1)
    {
        this->showFullScreen();
        isFullscreen=1;
    }
    //  connect (this, SIGNAL(mousePressEvent(QMouseEvent*ev)), this, SLOT(on_Clicked()));
}

Offers::~Offers()
{
    delete ui;
}

void Offers::makeOffers(QWidget *parent)
{
    int buff;
    offers.push_back(ui->Off1);
    offers.push_back(ui->Off2);
    offers.push_back(ui->Off3);
    QFile *file = new QFile(":/Offers/Offers/Oferty.txt");
    if (!file->open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(parent, "ERROR", "NO SUCH FILE EXISTS", QMessageBox::Ok);
    }
    QTextStream *in = new QTextStream(file);
    for (int i=0; i<offers.size(); i++)
    {
        offers.at(i)->tytul=in->readLine();
        // qDebug() << offers.at(i)->tytul;
        offers.at(i)->opis=in->readLine();
        offers.at(i)->logo=in->readLine();
        qDebug()<<offers.at(i)->logo;
        offers.at(i)->zdj1=in->readLine();
        offers.at(i)->zdj2=in->readLine();
        offers.at(i)->zdj3=in->readLine();
        offers.at(i)->cena=in->readLine().toFloat();
        buff=i;
        lastOffer=offers.at(i);
    }
    while(in->atEnd()!=1)
    {
        qDebug() <<"cos czytam";
        Offer *newOffer = new Offer(this);
        offers.push_back(newOffer);
        newOffer->tytul=in->readLine();
        // qDebug() << newOffer->tytul;
        newOffer->opis=in->readLine();
        newOffer->logo=in->readLine();
        qDebug()<<newOffer->logo;
        newOffer->zdj1=in->readLine();
        newOffer->zdj2=in->readLine();
        newOffer->zdj3=in->readLine();
        newOffer->cena=in->readLine().toFloat();
        newOffer->setGeometry(offers.at(buff)->x(), offers.at(buff)->y(), offers.at(buff)->width(), offers.at(buff)->height());
        lastOffer=newOffer;
        connect (newOffer, SIGNAL(clicked()), this, SLOT(on_Clicked()));
    }
    file->close();
    QPixmap z4(":/Offers/Offers/"+offers.at(0)->logo );
    QPalette pal;
    pal.setBrush(ui->Off1->backgroundRole(), QBrush(z4.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio)));
    ui->Off1->setFlat(true);
    ui->Off1->setAutoFillBackground(true);
    ui->Off1->setPalette(pal);
    QPixmap z5(":/Offers/Offers/"+offers.at(1)->logo );
    QPalette pal1;
    pal1.setBrush(ui->Off2->backgroundRole(), QBrush(z5.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio)));
    ui->Off2->setFlat(true);
    ui->Off2->setAutoFillBackground(true);
    ui->Off2->setPalette(pal1);
    qDebug() << offers.at(0)->cena;
    qDebug() << offers.at(1)->cena;
    QPixmap z6(":/Offers/Offers/"+offers.at(2)->logo );
    QPalette pal2;
    pal2.setBrush(ui->Off3->backgroundRole(), QBrush(z6.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio)));
    ui->Off3->setFlat(true);
    ui->Off3->setAutoFillBackground(true);
    ui->Off3->setPalette(pal2);
    qDebug() << offers.at(0)->cena;
    qDebug() << offers.at(1)->cena;
    qDebug() << offers.at(2)->cena;
    if (offers.size()>2)
    {
        for (int i=3; i<offers.size(); i++)
        {
            qDebug()<< offers.at(i)->logo;
            QPixmap z4("D:/Biuro Podrozy/BiuroPodrozy/Offers/"+offers.at(i)->logo);
            QPalette pal;
            pal.setBrush(offers.at(i)->backgroundRole(), QBrush(z4.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio)));
            offers.at(i)->setFlat(true);
            offers.at(i)->setAutoFillBackground(true);
            offers.at(i)->setPalette(pal);
            offers.at(i)->sizePolicy().setVerticalPolicy(QSizePolicy::Fixed);
            offers.at(i)->sizePolicy().setHorizontalPolicy(QSizePolicy::Fixed);
            offers.at(i)->setText(offers.at(i)->tytul);
            offers.at(i)->setStyleSheet("QPushButton{font-size: 36px; font-family: Ravie;}");
            ui->verticalLayout_3->addWidget(offers.at(i));
            offers.at(i)->show();
        }
    }
    //  lastOffer=offers.at(2);
}


void Offers::on_Off1_clicked()
{
    aboutOffer *Of1 = new aboutOffer(this, offers.at(0), toPassUser);
    Of1->exec();
}

void Offers::on_Clicked()
{
    QObject *offer = QObject::sender();
    for (int i=0; i<offers.size(); i++)
    {
        if (offer==offers.at(i))
        {
            aboutOffer *Of1 = new aboutOffer(this, offers.at(i), 1,  toPassUser);
            Of1->exec();
        }
    }
}

/*void Offers::mousePressEvent(QMouseEvent *event) //why?
{
   /* qDebug() << "Klikam";
QPoint pos = QCursor::pos();
    for (int i=0; i<offers.size(); i++)
    {
        if ((pos.x()>=offers.at(i)->x())&&(pos.x()<offers.at(i)->x()+offers.at(i)->width())&&(pos.x()<=offers.at(i)->y())&&((pos.x()>=offers.at(i)->y()-offers.at(i)->height())))
        {
            aboutOffer *Of1 = new aboutOffer(this, offers.at(i), toPassUser);
            Of1->exec();
        }
    }
    for (int i=0; i<offers.size(); i++)
    {
        if(offers.at(i)->i())
        {
            aboutOffer *Of1 = new aboutOffer(this, offers.at(i), toPassUser);
            Of1->exec();
        }
    }

}*/

void Offers::on_Off2_clicked()
{
    aboutOffer *Of1 = new aboutOffer(this, offers.at(1), toPassUser);
    Of1->exec();
}

void Offers::on_Off3_clicked()
{
    aboutOffer *Of1 = new aboutOffer(this, offers.at(2), toPassUser);
    Of1->exec();
}

void Offers::on_Return_clicked()
{
    this->close();
}



void Offers::on_pushButton_clicked()
{
    Offer *newOffer = new Offer(this);
    AddFile *newOne = new AddFile(this, newOffer);
    newOne->exec();
    newOffer=newOne->off;
    newOffer->setGeometry(lastOffer->x(), lastOffer->y(), lastOffer->width(), lastOffer->height());
    QPixmap z4("D:/Biuro Podrozy/BiuroPodrozy/Offers/"+newOffer->logo);
    QPalette pal;
    pal.setBrush(newOffer->backgroundRole(), QBrush(z4.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio)));
    newOffer->setFlat(true);
    newOffer->setAutoFillBackground(true);
    newOffer->setPalette(pal);
    newOffer->sizePolicy().setVerticalPolicy(QSizePolicy::Fixed);
    newOffer->sizePolicy().setHorizontalPolicy(QSizePolicy::Fixed);
    newOffer->setText(newOffer->tytul);
    newOffer->setStyleSheet("QPushButton{font-size: 36px; font-family: Ravie;}");
    // ui->verticalLayout_3->addWidget(newOffer);
    //     offers.push_back(newOffer);
    QFile file("D:/Biuro Podrozy/BiuroPodrozy/Offers/Oferty.txt");
    if (!file.open(QFile::ReadWrite | QFile::Text| QFile::Append))
    {
        QMessageBox::warning(this, "ERROR", "CAN'T SAVE USER'S OFFERS", QMessageBox::Ok);
    }
    QTextStream out(&file);
    out<<newOffer->tytul<<endl;
    out<<newOffer->opis<<endl;
    out<<newOffer->logo<<endl;
    out<<newOffer->zdj1<<endl;
    out<<newOffer->zdj2<<endl;
    out<<newOffer->zdj3<<endl;
    out<<newOffer->cena<<endl;
    out.flush();
    file.close();

}
