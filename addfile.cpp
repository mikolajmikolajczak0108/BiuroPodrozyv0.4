#include "addfile.h"
#include "ui_addfile.h"
#include <QFileDialog>
#include <QDebug>
AddFile::AddFile(QWidget *parent, Offer *newOne) :
    QDialog(parent),
    ui(new Ui::AddFile)
{
    ui->setupUi(this);
    this->off=newOne;
    QPixmap ground(":/Img/Img/tlomenu.jpg");
    QPalette back;
    back.setBrush(this->backgroundRole(), QBrush(ground.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio)));
    this->setPalette(back);
}

void AddFile::getTitle()
{
    this->title=ui->tytul->text();
    this->descr=ui->opis->text();
    this->price=ui->cena->text();
}


void AddFile::getLogoPath()
{
    QString path;
    path=QFileDialog::getOpenFileName(this,"Chose .jpg or .png file", "D:/Biuro Podrozy/BiuroPodrozy/Offers", tr("Image Files (*.png *.jpg *.bmp)"));
    for (int i=37; i<path.size(); i++)
    {
    this->logopath += path.at(i);
    }

}

void AddFile::getPhoto1Path()
{
    QString path;
    path=QFileDialog::getOpenFileName(this,"Chose .jpg or .png file", "D:/Biuro Podrozy/BiuroPodrozy/Offers", tr("Image Files (*.png *.jpg *.bmp)"));
    for (int i=37; i<path.size(); i++)
    {
    this->photo1path += path.at(i);
    }

}

void AddFile::getPhoto2Path()
{
    QString path;
    path=QFileDialog::getOpenFileName(this,"Chose .jpg or .png file", "D:/Biuro Podrozy/BiuroPodrozy/Offers", tr("Image Files (*.png *.jpg *.bmp)"));
    for (int i=37; i<path.size(); i++)
    {
    this->photo2path += path.at(i);
    }
}

void AddFile::getPhoto3Path()
{
    QString path;
    path=QFileDialog::getOpenFileName(this,"Chose .jpg or .png file", "D:/Biuro Podrozy/BiuroPodrozy/Offers", tr("Image Files (*.png *.jpg *.bmp)"));
    for (int i=37; i<path.size(); i++)
    {
    this->photo3path += path.at(i);
    }
}

AddFile::~AddFile()
{
    delete ui;
}

void AddFile::on_End_clicked()
{
    getTitle();
    if ((this->title!="")&&(this->descr!="")&&(this->price!="")&&(this->logopath!="")&&(this->photo1path!="")&&(this->photo2path!="")&&(this->photo3path!=""))
    {
        this->off->tytul=this->title;
        this->off->opis=this->descr;
        this->off->logo=this->logopath;
        this->off->zdj1=this->photo1path;
        this->off->zdj2=this->photo2path;
        this->off->zdj3=this->photo3path;
        this->off->cena=this->price.toFloat();

    }
    this->close();
}

void AddFile::on_Logo_clicked()
{
    getLogoPath();
}

void AddFile::on_Zdjcia_clicked()
{
    getPhoto1Path();
    getPhoto2Path();
    getPhoto3Path();
}
