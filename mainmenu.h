#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "options.h"
#include "User.h"
#include "offers.h"
#include <QLayout>
QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();
    User *currentUser;
    bool gotUser=0;
    void loadOffers(User *U);
    Offer *lastOffer;
    Offers *of;
    QVector <QPushButton*> Offerss;
private slots:
    void on_OptionsBut_clicked();
    void on_Exit_clicked();
    void set_Fullscreen();
    void set_NoFullscreen();
    void getUser();

    void on_Zaloguj_clicked();

    void on_Zaloguj_2_clicked();

    void on_LogRej_clicked();

    void on_Standard_clicked();

    void on_MojeOf_clicked();

    void on_ReturnfromOffers_clicked();

    void on_LM_clicked();


    void on_Zaloguj_3_clicked();

private:
    Ui::MainMenu *ui;
};
#endif // MAINMENU_H
