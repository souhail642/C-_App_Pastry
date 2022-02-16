#ifndef REPARATEUR_H
#define REPARATEUR_H
#include <QString>
#include "connexion.h"
#include "accueil.h"
#include "ui_accueil.h"
class reparateur
{
private :
int id_reparateur;
QString nom;
QString prenom;
QString telephone;
QString email;
QString societe ;
QString specialite;

public:
    reparateur();
    reparateur(int);//cle primaire
    reparateur(QString,QString,QString,QString,QString,QString);

    int getId_reparateur();
    QString getNom();
    QString getPrenom();
    QString getTelephone();
    QString getEmail ();
    QString getSociete();
    QString getSpecialite ();

    void setId_reparateur(int);
    void setNom(QString);
    void setPrenom(QString);
    void setTelephone(QString);
    void setEmail(QString);
    void setSociete(QString);
    void setSpecialite(QString);

    bool ajouter();
    bool supprimer(int);
    bool modifier(reparateur);
    QSqlQueryModel * afficher();
    reparateur rehcerche(int);

    int lastId();
    bool verif_numero(QString);
    bool verif_nom(QString);
     bool verif_email(QString);

};

#endif // REPARATEUR_H

