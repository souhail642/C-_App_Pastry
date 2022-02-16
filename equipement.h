#ifndef TRANSACTION_H
#define TRANSACTION_H
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
#include "accueil.h"
#include "ui_accueil.h"
#include <QPrinter>
class equipement
{
private :
int id_equipement;
QString nom;
QString prix;
QString marque;
QString caracteristique;
QString date_achat ;
QString etat;

public:
    equipement();
    equipement(int);//cle primaire
    equipement(QString,QString,QString,QString,QString,QString);

    int getId_equipement();
    QString getNom();
    QString getPrix();
    QString getCaracteristique();
    QString getDate_achat ();
    QString getMarque();
    QString getEtat ();


    void setId_equipement(int);
    void setNom(QString);
    void setPrix(QString);
    void setCaracteristique(QString);
    void setDate_achat(QString);
    void setMarque(QString);
    void setEtat(QString);

    bool ajouter();
    bool supprimer(int);
    bool modifier(equipement);
    QSqlQueryModel * afficher();
    equipement rehcerche(int);

    int lastId();

    bool verif_numero(QString numero);
    bool verif_date(QString date_d);
    bool verif_nom(QString ch_nom);
    bool verif_id(QString ch_id);
    QVector<double> prix_equipement();
    QVector<QString> nom_equipement();
    int count();
};

#endif // TRANSACTION_H
