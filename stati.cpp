#include "stati.h"
#include "ui_stati.h"
#include<iostream>

stati::stati(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stati)
{
    ui->setupUi(this);
}

stati::~stati()
{
    delete ui;
}
int stati::Statistique_partie2()
{    int count=0 ;

    QSqlQuery requete("SELECT * FROM employe ") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
int stati::Statistique_partie3()
{
    QSqlQuery requete("select date_retour from CONGE  ") ;
    QString date;
    QDate d= d.currentDate();
    int jj= d.day();
    int mm =d.month();
    int yy = d.year();
    QString nbjr;
    QChar nbjr1;
     QChar nbjr2;
          QString  nbjrr;
          QChar nbmr1;
           QChar nbmr2;
            QString nbm  ;
          int nbrm ;

          QChar nbyr1;
           QChar nbyr2;
           QChar nbyr3;
            QChar nbyr4;
            QString nbyr;
         int nbry;

  bool ok;
    int nbr;
     int c=0 ;

         while(requete.next())
    {
            date = requete.value(0).toString();
             nbjr= date;
             nbjr1= nbjr[0];
              nbjr2= nbjr[1];
               nbjrr= nbjr1 ;
              nbjrr+= nbjr2;
             nbr = nbjrr.toInt(&ok,10);

             nbmr1= nbjr[3];
              nbmr2= nbjr[4];
               nbm =nbmr1  ;
             nbm += nbmr2;
             nbrm = nbm.toInt(&ok,10);

              nbyr1= nbjr[6];
               nbyr2= nbjr[7];
               nbyr3= nbjr[8];
              nbyr4= nbjr[9];
              nbyr =nbyr1  ;
             nbyr += nbyr2;
             nbyr += nbyr3;
             nbyr += nbyr4;
          nbry = nbyr.toInt(&ok,10);
          qDebug()<<nbrm;
          qDebug()<<nbry;
          qDebug()<<nbr;
          if (nbry > yy)
           {
             c++;
          }
          else if (nbry == yy)
             {
              if (nbrm > mm)
                {
                c++;
                }
              else if (nbrm == mm)
                  {
                      if (nbr > jj)
                       c++;
                 }


             }
}
return c ;
}


/*int stati::Statistique_partie3()
{
    QSqlQuery requete("select * from employe") ;
     int c=0 ;
     while(requete.next())
    {
            c++ ;
    }

return c-Statistique_partie2() ;



}*/

void stati::paintEvent(QPaintEvent *)
{

    int b=Statistique_partie2();
    cout<<b<<endl ;
    int c=Statistique_partie3();
b=b-c;
    cout<<c<<endl ;


        float s2= b*100 ;
        float s3=c*100;
        float nb = b+c ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;

    QPainter painter(this);
    QRectF size=QRectF(150,40,this->width()-300,this->width()-300);

    painter.setBrush(Qt::red);
    painter.drawPie(size,0,16*y);
    ui->label_2->setText("En travail");
    painter.setBrush(Qt::blue);
    painter.drawPie(size,16*y,16*m);
    ui->label_3->setText("En congé");


}


void stati::on_pushButton_clicked()
{
    hide();
}

