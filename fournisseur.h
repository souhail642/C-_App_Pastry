#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQueryModel>
#include<QString>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include<QFileInfo>
#include<QMessageBox>
#include<QSqlQueryModel>
#include<QDebug>
#include<QFileDialog>
#include<QDialog>
#include<QtCore>
#include <QObject>
#include<QtGui>
#include "connexion.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
class fournisseur
{
    int ID_FOURNISSEUR;
     QString NOM;
     QString PRENOM;
     QString EMAIL;
     int TELEPHONE;
     QString SPECIALITE;
public:
    fournisseur();
    fournisseur(int);//cle primaire
    fournisseur(QString,QString,int,QString,QString);

    int getID_FOURNISSEUR();
    QString getNOM();
    QString getPRENOM();
    int getTELEPHONE();
    QString getEMAIL ();
    QString getSPECIALITE ();


    void setID_FOURNISSEUR(int);
    void setNOM(QString);
    void setPRENOM(QString);
    void setTELEPHONE(int);
    void setEMAIL(QString);
    void setSPECIALITE(QString);

    bool ajouter();
    bool supprimer(int);
    bool modifier(fournisseur);
    QSqlQueryModel * afficher();
    //fournisseur rehcerche(int);
    bool verif_nom(QString ch_nom);
    bool verif_mail(QString ch_nom);
    int lastId();
};

#endif // FOURNISSEUR_H
