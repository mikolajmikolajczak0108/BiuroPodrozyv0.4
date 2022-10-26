#ifndef OFFERS_H
#define OFFERS_H

#include <QDialog>
#include "OfferObjects.h"
#include <QVector>
#include "User.h"
#include "addfile.h"
namespace Ui {
class Offers;
}

class Offers : public QDialog
{
    Q_OBJECT

public:
    explicit Offers(QWidget *parent = nullptr, User *currentUser=nullptr, Offer *lastOffer=nullptr);
    ~Offers();
    bool isFullscreen=0;
    void makeOffers(QWidget *parent);
    User *toPassUser;
    QVector <Offer*> offers;
    Offer *lastOffer;
    void on_clicked(Offer *of);
    friend class Admin;
private slots:
    void on_Off1_clicked();
    void on_Clicked();
   // void mousePressEvent(QMouseEvent *ev);
    //void on_Clicked();
    void on_Off2_clicked();
    void on_Off3_clicked();
    void on_Return_clicked();

    void on_pushButton_clicked();

private:
    Ui::Offers *ui;
};


#endif // OFFERS_H
