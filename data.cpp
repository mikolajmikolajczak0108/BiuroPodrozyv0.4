#include "data.h"
#include "ui_data.h"
#include <QDebug>
Data::Data(QWidget *parent, Offer * userOffer) :
    QDialog(parent),
    ui(new Ui::Data)
{
    ui->setupUi(this);
    QPixmap ground(":/Img/Img/sky.jpg");
    QPalette back;
    back.setBrush(this->backgroundRole(), QBrush(ground.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio)));
    this->setPalette(back);
    this->userOffer=userOffer;
}


Data::~Data()
{
    delete ui;
}

void Data::on_zatwierdz_clicked()
{
    if ((ui->DzienWpisz->text()!="")&&(ui->DzienWpisz_2->text()!="")&&(ui->MiesiacWpisz->text()!="")&&(ui->MiesiacWpisz_2->text()!="")&&(ui->RokWpisz->text()!="")&&(ui->RokWpisz_2->text()!=""))
    {
        QString dateBegin = ui->RokWpisz->text() + "-" + ui->MiesiacWpisz->text() + "-" + ui->DzienWpisz->text();
        qDebug() <<dateBegin;
        this->userOffer->dateBegin=QDateTime::fromString(dateBegin, "yyyy-MM-dd");
        QString dateEnd = ui->RokWpisz_2->text() + "-" + ui->MiesiacWpisz_2->text() + "-" + ui->DzienWpisz_2->text();
        this->userOffer->dateEnd=QDateTime::fromString(dateEnd, "yyyy-MM-dd");
        qDebug() <<userOffer->dateBegin.toString("dd-MM-yyyy");
        qDebug() <<userOffer->dateEnd.toString("dd-MM-yyyy");
        this->close();
    }

}
