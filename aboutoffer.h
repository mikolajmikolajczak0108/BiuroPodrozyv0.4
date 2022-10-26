#ifndef ABOUTOFFER_H
#define ABOUTOFFER_H

#include <QDialog>
#include "OfferObjects.h"
#include "User.h"
namespace Ui {
class aboutOffer;
}

class aboutOffer : public QDialog
{
    Q_OBJECT

public:
    explicit aboutOffer(QWidget *parent = nullptr, Offer *o = nullptr, User *currentUser=nullptr);
     explicit aboutOffer(QWidget *parent = nullptr, Offer *o = nullptr,int isAuto=0, User *currentUser=nullptr);
    explicit aboutOffer(QWidget *parent = nullptr, User *currentUser=nullptr, int which=0);
      explicit aboutOffer(QWidget *parent = nullptr, User *currentUser=nullptr,int isAuto=0, int which=0);
    User *editableUser;
    Offer *passableOffer;
    ~aboutOffer();
private slots:
    void on_return_2_clicked();

    void on_return_3_clicked();

private:
    Ui::aboutOffer *ui;
};

#endif // ABOUTOFFER_H
