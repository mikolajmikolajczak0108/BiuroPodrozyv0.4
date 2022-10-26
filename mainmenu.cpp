#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QLayout>
#include "aboutoffer.h"
#include "lastminuteoffers.h"
#include <QMediaPlayer>
MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    ui->HasloWpiszRej->setEchoMode(QLineEdit::Password);
    ui->NrKartyKredWpiszRej->setEchoMode(QLineEdit::Password);
    ui->PINKartyWpiszRej->setEchoMode(QLineEdit::Password);
    ui->HasloLogWpisz->setEchoMode(QLineEdit::Password);

    QPixmap ground(":/Img/Img/sky.jpg");
    QPalette back;
    back.setBrush(this->backgroundRole(), QBrush(ground.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio)));
    this->setPalette(back);
    QPixmap ground2(":/Img/Img/sky.jpg");
    QPalette back2;
    back.setBrush(this->backgroundRole(), QBrush(ground2.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio)));
    ui->ScrollOffers->setPalette(back);
    ui->MojeOf->setStyleSheet("background-color:grey");
    ui->stackedWidget->setCurrentIndex(0);
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("D:/Biuro Podrozy/BiuroPodrozy/sound/happy-clappy-ukulele.wav"));
    player->setVolume(50);
  //  player->play();
}
extern Options ui;
MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::loadOffers(User *U)
{

    if (this->Offerss.isEmpty())
    {
        QPixmap logo(":/Offers/Offers/"+U->userOffers.at(0)->logo);
        QPalette pal;
        QPushButton *Of = new QPushButton(ui->ScrollOffers);
        Of->setGeometry(10, 20, 421, 81);
        Of->setStyleSheet("QPushButton{font-size: 16px; font-family: Ravie;}");
        Of->setText(U->userOffers.at(0)->tytul);
        pal.setBrush(Of->backgroundRole(), QBrush(logo.scaled(Of->width(), Of->height(), Qt::IgnoreAspectRatio)));
        Of->setFlat(true);
        Of->setAutoFillBackground(true);
        Of->setPalette(pal);
        Of->show();
        Of->setMouseTracking(1);
        Offerss.push_back(Of);
        QLabel *Label = new QLabel(ui->ScrollOffers);
        Label->setGeometry(Of->width() + 50, 20, 421, 81);
        Label->setText(U->userOffers.at(0)->dateBegin.toString("dd-MM-yyyy") + " - " + U->userOffers.at(0)->dateEnd.toString("dd:MM:yyyy"));
        Label->setStyleSheet("font-size: 16px; font-family: Ravie;");
    }
    else
    {
        for (int i=1; i<U->userOffers.size(); i++)
        {

            if((U->userOffers.at(i)->tytul=="Nowy Jork")&&(U->userOffers.at(i)->tytul=="Praga")&&(U->userOffers.at(i)->tytul=="Monako")&&(U->userOffers.at(i)->tytul=="Kozia Wola"))
            {
                QPixmap logo(":/Offers/Offers/"+U->userOffers.at(i)->logo);
                QPalette pal;
                QPushButton *Of = new QPushButton(ui->ScrollOffers);
                Of->setGeometry(Offerss.at(i-1)->x(), Offerss.at(i-1)->y()+121, 421, 81);
                Of->setStyleSheet("QPushButton{font-size: 16px; font-family: Ravie;}");
                Of->setText(U->userOffers.at(i)->tytul);
                pal.setBrush(Of->backgroundRole(), QBrush(logo.scaled(Of->width(), Of->height(), Qt::IgnoreAspectRatio)));
                Of->setFlat(true);
                // Of->setObjectName(U->userOffers.at(i)->tytul);
                Of->setAutoFillBackground(true);
                Of->setPalette(pal);
                Of->show();
                Of->setMouseTracking(1);
                Offerss.push_back(Of);
                QLabel *Label = new QLabel(ui->ScrollOffers);
                Label->setGeometry(Of->width() + 50, Of->y(), 421, 81);
                Label->setText(U->userOffers.at(i)->dateBegin.toString("dd-MM-yyyy") + " - " + U->userOffers.at(i)->dateEnd.toString("dd:MM:yyyy"));
                Label->setStyleSheet("font-size: 16px; font-family: Ravie;");
            }
            else
            {
                QPixmap logo("D:/Biuro Podrozy/BiuroPodrozy/Offers/"+U->userOffers.at(i)->logo);
                QPalette pal;
                QPushButton *Of = new QPushButton(ui->ScrollOffers);
                Of->setGeometry(Offerss.at(i-1)->x(), Offerss.at(i-1)->y()+121, 421, 81);
                Of->setStyleSheet("QPushButton{font-size: 16px; font-family: Ravie;}");
                Of->setText(U->userOffers.at(i)->tytul);
                pal.setBrush(Of->backgroundRole(), QBrush(logo.scaled(Of->width(), Of->height(), Qt::IgnoreAspectRatio)));
                Of->setFlat(true);
                // Of->setObjectName(U->userOffers.at(i)->tytul);
                Of->setAutoFillBackground(true);
                Of->setPalette(pal);
                Of->show();
                Of->setMouseTracking(1);
                Offerss.push_back(Of);
                QLabel *Label = new QLabel(ui->ScrollOffers);
                Label->setGeometry(Of->width() + 50, Of->y(), 421, 81);
                Label->setText(U->userOffers.at(i)->dateBegin.toString("dd-MM-yyyy") + " - " + U->userOffers.at(i)->dateEnd.toString("dd:MM:yyyy"));
                Label->setStyleSheet("font-size: 16px; font-family: Ravie;");
            }
        }
    }

    //   setLayout(ui->verticalLayout_10);
}

void MainMenu::on_OptionsBut_clicked()
{
    Options *opt = new Options(this);
    connect(opt, SIGNAL(set_Screen()), this, SLOT(set_Fullscreen()));
    connect(opt, SIGNAL(set_Screen2()), this, SLOT(set_NoFullscreen()));
    opt->exec();
}


void MainMenu::on_Exit_clicked()
{
    this->close();
}

void MainMenu::set_Fullscreen()
{
    this->showFullScreen();
}

void MainMenu::set_NoFullscreen()
{
    this->showNormal();
}

void MainMenu::getUser()
{

}

void MainMenu::on_Zaloguj_clicked()
{
    User *loginUser;
    loginUser = new User(this, ui->NazwaLogWpisz->text(), ui->HasloLogWpisz->text());
    if (loginUser->wasProperlyCreated==1)
    {
        currentUser=loginUser;
        ui->littleChecker_2->setText("Current User: "+currentUser->nick);
        ui->littleChecker_3->setText("Current User cash: "+QString::number(currentUser->Card->cash));
        ui->stackedWidget->setCurrentIndex(0);
        gotUser=1;
        qDebug() << currentUser->name;
        qDebug() << currentUser->surname;
        qDebug() << currentUser->nick;
        qDebug() << currentUser->password;
        qDebug() << currentUser->Card->number;
        qDebug() << currentUser->Card->PIN;
        qDebug() << currentUser->Card->cash;
    }
}

void MainMenu::on_Zaloguj_2_clicked()
{
    QFile file("D:/Biuro Podrozy/BiuroPodrozy/Users/"+ui->NazwaWpiszRej->text()+".txt");
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "ERROR", "NO SUCH FILE EXISTS", QMessageBox::Ok);
    }
    QTextStream out(&file);

    out << ui->NazwaWpiszRej->text() << endl;
    out << ui->ImieWpiszRej->text()<< endl;
    out << ui->NazwiskoWpiszRej->text()<< endl;
    out << ui->HasloWpiszRej->text()<< endl;
    file.close();
    QFile file2("D:/Biuro Podrozy/BiuroPodrozy/creditCards/"+ui->NazwaWpiszRej->text()+".txt");
    if (!file2.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "ERROR", "NO SUCH FILE EXISTS", QMessageBox::Ok);
    }
    QTextStream outCard(&file2);

    outCard << ui->PINKartyWpiszRej->text()<< endl;
    outCard << ui->NrKartyKredWpiszRej->text()<< endl;
    qsrand(qrand());
    outCard << QString::number(qrand() % ((100000 + 1) - 1) + 1);
    file2.close();
    currentUser = new User(this, ui->NazwaWpiszRej->text(), ui->HasloWpiszRej->text());
    ui->littleChecker_2->setText("Current User: "+currentUser->nick);
    ui->littleChecker_3->setText("Current User cash: "+QString::number(currentUser->Card->cash));
    gotUser=1;
    ui->stackedWidget->setCurrentIndex(0);
}

void MainMenu::on_LogRej_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainMenu::on_Standard_clicked()
{
    if (gotUser==1)
    {
        of = new Offers(this, currentUser, lastOffer);
        of->makeOffers(of);
        of->exec();
        currentUser->saveOffers(this);
        ui->littleChecker_3->setText("Current User cash: "+QString::number(currentUser->Card->cash));
    }
    else
    {
        QMessageBox::warning(this, "Błąd!", "Zaloguj się by przeglądać oferty!");
    }
}

void MainMenu::on_MojeOf_clicked()
{
    if (this->gotUser==1)
    {
        if (currentUser->userOffers.size()>0)
        {
            loadOffers(currentUser);
            loadOffers(currentUser);
            //  loadOffers(currentUser);
            for (int i=0; i<Offerss.size(); i++)
            {
                Offerss.at(i)->setVisible(1);
            }
            ui->stackedWidget->setCurrentIndex(2);
        }
        else
        {
            QMessageBox::warning(this, "Błąd!", "Nie posiadasz żadnych wykupionych ofert!", QMessageBox::Ok);
        }
    }
}

void MainMenu::on_ReturnfromOffers_clicked()
{
    for (int i=0; i<Offerss.size(); i++)
    {
        Offerss.at(i)->setVisible(0);
    }
    ui->stackedWidget->setCurrentIndex(0);
}

void MainMenu::on_LM_clicked()
{
    if (gotUser==1)
    {
        LMOffers *of = new LMOffers(this, currentUser);
        of->exec();
        currentUser->saveOffers(this);
        ui->littleChecker_3->setText("Current User cash: "+QString::number(currentUser->Card->cash));
    }
    else
    {
        QMessageBox::warning(this, "Błąd!", "Zaloguj się by przeglądać oferty!");
    }
}


void MainMenu::on_Zaloguj_3_clicked()
{
    QFile file(":/Texts/serverPass/Pass.txt");
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this, "ERROR", "NO PASSWORD FILE EXISTS", QMessageBox::Ok);
    }
    if (currentUser->nick=="")
    {
        QMessageBox::warning(this, "ERROR", "YOU ARE NOT LOGGED IN!", QMessageBox::Ok);
    }
    else
    {
        QTextStream in(&file);
        QString pass=in.readLine();
        if (ui->KodWpisz->text()==pass)
        {
            Admin adm(this, currentUser->nick, currentUser->password);
            *currentUser=adm;
            ui->stackedWidget->setCurrentIndex(0);
        }
    }
}
