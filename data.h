#ifndef DATA_H
#define DATA_H

#include <QDialog>
#include "OfferObjects.h"
namespace Ui {
class Data;
}

class Data : public QDialog
{
    Q_OBJECT

public:
    explicit Data(QWidget *parent = nullptr, Offer *userOffer=nullptr);
    Offer *userOffer;
    ~Data();

private slots:
    void on_zatwierdz_clicked();

private:
    Ui::Data *ui;
};

#endif // DATA_H
