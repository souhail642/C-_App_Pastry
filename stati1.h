#ifndef STATI1_H
#define STATI1_H
#include <QPainter>
#include <QSqlQuery>
#include <QDialog>
#include<QDate>
#include<QDebug>
using namespace std;

namespace Ui {
class stati1;
}

class stati1 : public QDialog
{
    Q_OBJECT

public:
    explicit stati1(QWidget *parent = nullptr);
       int Statistique_partie2() ;
       int Statistique_partie3() ;
       int Statistique1();
       int Statistique2();

void paintEvent2(QPaintEvent *) ;
     void paintEvent(QPaintEvent *) ;
    ~stati1();
private slots:

     void on_pushButton_clicked();

private:
    Ui::stati1 *ui;
};





#endif // STATI1_H
