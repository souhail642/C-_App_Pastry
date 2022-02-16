#ifndef COMMENTAIRE_H
#define COMMENTAIRE_H


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
class commentaire
{
private :
int id;
QString cin_employe;
QString description;



public:
   commentaire();
    commentaire(int);//cle primaire
commentaire(QString,int);

    int getId() ;
    QString getDescription();

    QString getCin_employe();



    void setId(int);

    void setDescription(QString);
    void setCin_employe(QString);


    bool ajouter();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * afficher();

  bool verif(QString );

    int lastId();


};
#endif // COMMENTAIRE_H
