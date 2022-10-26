#ifndef ADDFILE_H
#define ADDFILE_H

#include <QDialog>
#include "OfferObjects.h"
#include "offers.h"
namespace Ui {
class AddFile;
}

class AddFile : public QDialog
{
    Q_OBJECT

public:
    explicit AddFile(QWidget *parent = nullptr, Offer *newOne=nullptr);
    QString title, descr, price, logopath, photo1path, photo2path, photo3path;
    Offer *off;
    void getTitle();
    void getLogoPath();
    void getPhoto1Path();
    void getPhoto2Path();
    void getPhoto3Path();
    ~AddFile();

private slots:
    void on_End_clicked();

    void on_Logo_clicked();

    void on_Zdjcia_clicked();

private:
    Ui::AddFile *ui;
};

#endif // ADDFILE_H
