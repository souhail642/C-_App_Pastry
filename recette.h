#ifndef RECETTE_H
#define RECETTE_H


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

class recette
{
private :
int ID_recette;
QString nom;
QString categorie;
int nb_ingredient;
QString description;
int id_produit ;

public:
    recette();
    recette(int);//cle primaire
    recette(QString,QString,int,QString,int);

    int getID_recette();
    QString getnom();
    QString getcategorie();
    int getnb_ingredient();
    QString getdescription();
    int getid_produit ();



    void setID_recette(int);
    void setnom(QString);
    void setcategorie(QString);
    void setdescription(QString);
    void setid_produit(int);
    void setnb_ingredient(int);

    bool ajouter();
    bool modifier(recette);
    bool supprimer(int);
    QSqlQueryModel * afficher();
    bool verif_numero(int);
    bool verif_nom(QString);
    int lastId();
    QSqlQueryModel * cherch_four(QString);
    void Recherche(Ui::accueil *ui);
};


#endif // RECETTE_H
