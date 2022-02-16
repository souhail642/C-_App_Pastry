#ifndef CONGE_H
#define CONGE_H
#include<QString>
#include<QSqlQueryModel>
#include "smtp1.h"
#include <QPropertyAnimation>
#include "ui_accueil.h"
#include "accueil.h"
#include <QDialog>
#include <QFileDialog>
class conge
{private:
    int cin_employe,idconge;
    QString nature,confirmation,date_depart,date_retour;
public:

    conge();
    conge(int,QString,QString,QString,QString,int);
      conge(QString,QString,QString,QString,int);
    int getcin_employe();
    QString getdate_depart();
    QString getdate_retour();
    QString getnature();
    QString getconfirmation();
    int getidconge();



    //Setters

    void setidconge(int );
    void setcin_employe(int );
    void setdate_depart(QString);
    void setdate_retour(QString);
    void setconfirmation(QString);
    void setnature(QString);


    //CRUD
        bool ajouter();
        QSqlQueryModel * afficher();
        QSqlQueryModel * afficher1();
        QSqlQueryModel * afficher2();
        QSqlQueryModel * afficher11(int);
        bool ajouter11();
        bool supprimer(int);
        bool supprimer1(QString);
        bool modifier();
            int lastIdconge();



};


#endif // CONGE_H
