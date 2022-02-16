#ifndef REPARATION_H
#define REPARATION_H
#include <QString>
#include "connexion.h"
#include "accueil.h"
#include "reparateur.h"
#include <QPrinter>

class reparation
{
private :
int id_reparation;
int id_equipement;
int id_reparateur;
QString nom;
QString prix;
QString date_livraison;
QString date_reception ;


public:
    reparation();
    reparation(int);//cle primaire
    reparation(int,int,QString,QString,QString,QString);

    int getId_reparation();
    int getId_reparateur();
    QString getNom();
    QString getPrix();
    int getId_equipement();
    QString getDateLivraison ();
    QString getDateReception();


    void setId_reparation(int);
    void setId_reparateur(int);
    void setNom(QString);
    void setId_equipement(int);
    void setDateLivraison(QString);
    void setDateReception(QString);
    void setPrix(QString);

    bool ajouter();
    bool supprimer(int);
    bool modifier(reparation);
    QSqlQueryModel * afficher();
    reparation rehcerche(int);
    int lastId();
    QString recupererNom(int);

    bool verif_numero(QString);
    bool verif_date(QString);
    int mois(int,int);
    void pdf(QString,QString,QString,QString,reparation );
    QVector<double> prix_reparation();
};



#endif // REPARATION_H
