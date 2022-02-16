#ifndef EVALUATION_H
#define EVALUATION_H
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
class evaluation
{
private :
int id_evaluation;
int performance;
int fiabilite;
int autonomie;
QString commentaire;
QString date_evaluation;
QString cin_employe ;


public:
   evaluation();
     evaluation(int);//cle primaire
     evaluation(int,int,QString,QString,int);
evaluation(QString,QString,int);
    int getId_evaluation() ;
    int getPerformance();

    QString getCin_employe();
    QString getDate_evaluation ();
    QString getCommentaire();
   int getAutonomie ();
      int getFiabilite ();


    void setId_evaluation(int);
    void setPerformance(int);

    void setCin_employe(QString);
    void setCommentaire(QString);
    void setDate_evaluation(QString);
    void setAutonomie(int);
 void setFiabilite(int);
    bool ajouter();
    bool modifier();
    bool supprimer(int);
    bool verif(QString );
    QSqlQueryModel * afficher();
void trie(QTableView* table);
void trie1(QTableView* table);
void trie2(QTableView* table);
void tried(QTableView* table);
    int lastId();

};



#endif // EVALUATION_H
