#include "reparateur.h"
#include <QSqlQuery>
#include <QVariant>

reparateur::reparateur(){}


reparateur::reparateur(int id_reparateur){this->id_reparateur = id_reparateur;}

reparateur::reparateur(QString nom,QString prenom,QString telephone,QString email,QString societe,QString specialite)
{
    this->id_reparateur = lastId();
    this->nom = nom;
    this->prenom =prenom;
    this->telephone =telephone;
    this->email = email;
    this->societe = societe;
    this->specialite = specialite;
}
int getId_reparateur();
QString getNom();
QString getPrenom();
QString getTelephone();
QString getEmail ();
QString getSociete();
QString getSpecialite ();

    int reparateur::getId_reparateur(){return this->id_reparateur;}
    QString reparateur::getNom(){return this->nom;}
 QString reparateur::getTelephone(){return this->telephone;}
    QString reparateur::getPrenom(){return this->prenom;}
    QString reparateur::getEmail(){return this->email;}
     QString reparateur::getSociete(){return this->societe;}
     QString reparateur::getSpecialite(){return this->specialite;}


    void reparateur::setId_reparateur(int id_reparateur){this->id_reparateur=id_reparateur;};
    void reparateur::setNom(QString nom){this->nom=nom;}
    void reparateur::setTelephone(QString Telephone){this->telephone = Telephone;}
    void reparateur::setPrenom(QString  Prenom){this->prenom = Prenom;}
    void reparateur::setEmail(QString Email){this->email=Email;}
    void reparateur::setSociete(QString Societe){this->societe = Societe;}
    void reparateur::setSpecialite(QString Specialite){this->specialite =Specialite;}

    int reparateur::lastId(){
        int lastId = 0;
        QSqlQuery qry3 ;
        qry3.prepare("select ID_reparateur from reparateur ");
        if (qry3.exec()){
        while(qry3.next()){
            lastId = qry3.value(0).toInt();}
        }
        return lastId+1;
    }


    bool reparateur::ajouter(){
        QSqlQuery query;
       int l = lastId();
        QString stringId = QString::number(this->id_reparateur);
        reparateur t;
        bool test_nom,test_prenom,test_telephone,test_mail,test_societe,test_specialite;
        test_nom = t.verif_nom(this->nom);
        test_prenom = t.verif_nom(this->prenom);
        test_telephone = t.verif_numero(this->telephone);
        test_mail = t.verif_email(this->email);
        test_societe = t.verif_nom(this->societe);
        test_specialite = t.verif_nom(this->specialite);
        if (test_mail == false)
        {
            QMessageBox::information(nullptr, QObject::tr("erreur"),
                        QObject::tr("email invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (test_nom == false)
        {
            QMessageBox::information(nullptr, QObject::tr("erreur"),
                        QObject::tr("nom invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else if (test_prenom == false)
        {
            QMessageBox::information(nullptr, QObject::tr("erreur"),
                        QObject::tr("prenom invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else if (test_telephone == false)
        {
            QMessageBox::information(nullptr, QObject::tr("erreur"),
                        QObject::tr("telephone invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else if (test_societe == false)
        {
            QMessageBox::information(nullptr, QObject::tr("erreur"),
                        QObject::tr("societe invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else if (test_specialite == false)
        {
            QMessageBox::information(nullptr, QObject::tr("erreur"),
                        QObject::tr("specialite invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }


        else {
        query.prepare("INSERT INTO reparateur VALUES (?, ?, ?, ? , ?, ?, ?)");
        query.addBindValue(l);
        query.addBindValue(this->nom);
        query.addBindValue(this->prenom);
        query.addBindValue(this->telephone);
        query.addBindValue(this->email);
        query.addBindValue(this->societe);
        query.addBindValue(this->specialite );
           }
        return query.exec();
}

    bool reparateur::supprimer(int id){
        QSqlQuery query;
        QString stringId = QString::number(id);

        query.prepare("DELETE FROM reparateur WHERE ID_reparateur=?");
        query.addBindValue(stringId);

        return query.exec();
    }

    bool reparateur::modifier(reparateur a){
        QSqlQuery edit;

        reparateur t;
        bool test_nom,test_prenom,test_telephone,test_mail,test_societe,test_specialite;
        test_nom = t.verif_nom(this->nom);
        test_prenom = t.verif_nom(this->prenom);
        test_telephone = t.verif_numero(this->telephone);
        test_mail = t.verif_email(this->email);
        test_societe = t.verif_nom(this->societe);
        test_specialite = t.verif_nom(this->specialite);
        if (test_mail == false)
        {
            QMessageBox::information(nullptr, QObject::tr("erreur"),
                        QObject::tr("email invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (test_nom == false)
        {
            QMessageBox::information(nullptr, QObject::tr("erreur"),
                        QObject::tr("nom invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else if (test_prenom == false)
        {
            QMessageBox::information(nullptr, QObject::tr("erreur"),
                        QObject::tr("prenom invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else if (test_telephone == false)
        {
            QMessageBox::information(nullptr, QObject::tr("erreur"),
                        QObject::tr("telephone invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else if (test_societe == false)
        {
            QMessageBox::information(nullptr, QObject::tr("erreur"),
                        QObject::tr("societe invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else if (test_specialite == false)
        {
            QMessageBox::information(nullptr, QObject::tr("erreur"),
                        QObject::tr("specialite invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }


        else {
                          edit.prepare("update reparateur set NOM = :NOM,TELEPHONE=:Telephone, SOCIETE = :Societe, PRENOM=:Prenom ,EMAIL=:Email, SPECIALITE=:Specialite where ID_reparateur = :ID");

                          edit.bindValue(":ID",a.getId_reparateur());
                          edit.bindValue(":NOM",a.getNom());
                          edit.bindValue(":Telephone",a.getTelephone());
                          edit.bindValue(":Societe",a.getSociete());
                          edit.bindValue(":Prenom",a.getPrenom());
                          edit.bindValue(":Specialite",a.getSpecialite());
                           edit.bindValue(":Email",a.getEmail());
        }
                          return    edit.exec();





    }

QSqlQueryModel * reparateur::afficher(){


    QSqlQueryModel* model   = new QSqlQueryModel();

    model->setQuery("select * from reparateur");

    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_reparateur"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("TELEPHONE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("SOCIETE"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("Specialite"));
    //model->setHeaderData(7, Qt::Horizontal,QObject::tr("modifier"));


    return model;
    }

reparateur reparateur::rehcerche(int id)
{  reparateur a;
    QString stringId = QString::number(id);
   QSqlQuery query;
   query.prepare("select * from reparateur where ID_reparateur=?");
   query.addBindValue(stringId);
   query.exec();
    query.first();
    a.setNom(query.value(1).toString());
    a.setPrenom(query.value(2).toString());
   // a.setNom(query.value(1).toString());
    a.setSociete(query.value(5).toString());
    a.setTelephone(query.value(3).toString());
    a.setId_reparateur(id);
    a.setSpecialite(query.value(6).toString());
    a.setEmail(query.value(4).toString());




   return a;
}


bool reparateur::verif_nom(QString ch_nom){
    bool test=true;
    int i;
    if(true)
    {
        for(i=0;i<ch_nom.length();i++){
            if(!(((ch_nom[i]>='A')&&(ch_nom[i]<='Z'))||((ch_nom[i]>='a')&&(ch_nom[i]<='z'))||(ch_nom[i]==' '))){
                test=false;
                return  test;
        }
    }
  }
    return  test;
}

//
bool reparateur::verif_numero(QString numero)
{

    bool test=true;
    int i;
    if(numero.length()!=8){
       test=false;
       return  test;
    }
    else {
        for(i=0;i<numero.length();i++){
            if(!((numero[i]>='0')&&(numero[i]<='9'))){
                test=false;
                return  test;

        }}
    }
 return test;}

bool reparateur::verif_email(QString email)
{

    bool test=true;
    int i,j;
   int pos1=0;
   int pos2=0;
   bool verif1=false;
   bool verif2=false;
       for(i=0;i<email.length();i++) {
        if (!(((email[i]>='A')&&(email[i]<='Z'))||((email[i]>='a')&&((email[i]<='z')))||((email[i]>='0')&&(email[i]<='9'))||(email[i]=='@')||(email[i]=='.')))
        {
            test=false;



        }


    }

        for(j=0;j<email.length();j++) {
       if ((email[j]=='@')&&(pos1==0))
       {
           pos1=j;
           verif1=true;

       }

       if ((email[j]=='.')&&(pos2==0))
       {
           pos2=j;
           verif2=true;

       }}

       if ((verif1==false)||(verif2==false))
       {
           test=false;
       }





 return test;}
