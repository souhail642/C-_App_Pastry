#ifndef RECLAMATION_H
#define RECLAMATION_H

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
class reclamation
{
private :
int id_reclamation;
QString titre;
QString description;
QString etat;
QString date_reclamation;
QString cin_employe ;


public:
    reclamation();
     reclamation(int);//cle primaire
     reclamation(QString,QString,QString,QString);
 reclamation(QString,QString,QString);
    int getId_reclamation() ;
    QString getTitre();

    QString getCin_employe();
    QString getDate_reclamation ();
    QString getDescription();
    QString getEtat ();


    void setId_reclamation(int);
    void setTitre(QString);

    void setCin_employe(QString);
    void setDescription(QString);
    void setDate_reclamation(QString);
    void setEtat(QString);

    bool ajouter();
    bool supprimer(QString);
    bool modifier();
   bool modifieretat();
  bool verif(QString );
    QSqlQueryModel * afficher();
void trie(QTableView* table);
void recherche(QString );
    int lastId();

};





#endif // RECLAMATION_H
