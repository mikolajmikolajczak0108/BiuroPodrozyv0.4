#include "options.h"
#include "ui_options.h"
#include <QApplication>
#include <QMainWindow>
Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
    QPixmap ground(":/Img/Img/beach.jpg");
    QPalette back;
    back.setBrush(this->backgroundRole(), QBrush(ground.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio)));
    this->setPalette(back);
}
 int Options::isFullscreen=0;
Options::~Options()
{
    delete ui;
}


void Options::on_graphicsbut_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Options::on_soundsbut_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Options::on_smthbut_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void Options::on_checkBox_stateChanged(int arg1)
{
    if (isFullscreen==0)
    {
    emit set_Screen();
        isFullscreen=1;
    }
    else
    {
        emit set_Screen2();
        isFullscreen=0;
    }
}
