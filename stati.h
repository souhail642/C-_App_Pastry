#ifndef STATI_H
#define STATI_H
#include <QPainter>
#include <QSqlQuery>
#include <QDialog>
#include<QDate>
#include<QDebug>
using namespace std;

namespace Ui {
class stati;
}

class stati : public QDialog
{
    Q_OBJECT

public:
    explicit stati(QWidget *parent = nullptr);
       int Statistique_partie2() ;
       int Statistique_partie3() ;
       int Statistique1();
       int Statistique2();

void paintEvent2(QPaintEvent *) ;
     void paintEvent(QPaintEvent *) ;
    ~stati();
private slots:

     void on_pushButton_clicked();

private:
    Ui::stati *ui;
};

#endif // STATI_H
/*void stati::on_pushButton_clicked()
{
    hide();


}*/
