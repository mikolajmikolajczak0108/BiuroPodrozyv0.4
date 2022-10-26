#ifndef LASTMINUTEOFFERS_H
#define LASTMINUTEOFFERS_H

#include <QDialog>
#include "OfferObjects.h"
#include "mainmenu.h"
#include "offers.h"
#include <QVector>
namespace Ui {
class LastMinuteOffers;
}

class LMOffers : public QDialog
{
    Q_OBJECT

public:
    explicit LMOffers(QWidget *parent = nullptr, User *currentUser=nullptr);
    ~LMOffers();
    bool isFullscreen=0;
    void makeOffers(QWidget *parent);
    User *toPassUser;
    QVector <LastMinute*> Loffers;
private slots:

    void on_Return_clicked();

    void on_LMOff1_clicked();

private:
    Ui::LastMinuteOffers *ui;
};


#endif // LASTMINUTEOFFERS_H
