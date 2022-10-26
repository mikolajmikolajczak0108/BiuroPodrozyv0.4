#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>
#include "mainmenu.h"
namespace Ui {
class Options;
}

class Options : public QDialog
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = nullptr);
    static int isFullscreen;
    ~Options();

signals:
       void set_Screen();
       void set_Screen2();
private slots:

    void on_graphicsbut_clicked();

    void on_soundsbut_clicked();

    void on_smthbut_clicked();


    void on_checkBox_stateChanged(int arg1);

private:
    Ui::Options *ui;
};

#endif // OPTIONS_H
