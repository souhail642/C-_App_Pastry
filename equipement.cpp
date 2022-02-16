#include "equipement.h"
#include <QSqlQuery>
#include <QVariant>
#include <QMessageBox>
equipement::equipement(){}


equipement::equipement(int id_equipement){this->id_equipement = id_equipement;}

equipement::equipement(QString NOM,QString prix,QString caracteristique,QString date_achat,QString marque,QString etat)
{
    this->id_equipement = lastId();
    this->nom = NOM;
    this->prix =prix;
    this->caracteristique =caracteristique;
    this->date_achat = date_achat;
    this->marque = marque;
    this->etat = etat;
}
int getId_equipement();
QString getNom();
QString getPrix();
QString getCaracteristique();
QString getDate_achat ();
QString getMarque();
QString getEtat ();

    int equipement::getId_equipement(){return this->id_equipement;}
    QString equipement::getNom(){return this->nom;}
    QString equipement::getPrix(){return this->prix;}
    QString equipement::getCaracteristique(){return this->caracteristique;}
    QString equipement::getDate_achat(){return this->date_achat;}
     QString equipement::getMarque(){return this->marque;}
     QString equipement::getEtat(){return this->etat;}


    void equipement::setId_equipement(int id_equipement){this->id_equipement=id_equipement;};
    void equipement::setNom(QString nom){this->nom=nom;}
    void equipement::setPrix(QString prix){this->prix = prix;}
    void equipement::setCaracteristique(QString  caracteristique){this->caracteristique = caracteristique;}
    void equipement::setDate_achat(QString date_achat){this->date_achat=date_achat;}
    void equipement::setMarque(QString marque){this->marque = marque;}
    void equipement::setEtat(QString etat){this->etat =etat;}

    int equipement::lastId(){
        int lastId = 0;
        QSqlQuery qry3 ;
        qry3.prepare("select ID_EQUIPEMENT from EQUIPEMENT ");
        if (qry3.exec()){
        while(qry3.next()){
            lastId = qry3.value(0).toInt();}
        }
        return lastId+1;
    }


    bool equipement::ajouter(){
        QSqlQuery query;
       int l = lastId();
        QString stringId = QString::number(this->id_equipement);

        equipement t;
        bool test_nom,test_prix,test_marque,test_date;
        test_nom = t.verif_nom(this->nom);
        test_prix= t.verif_numero(this->prix);
        test_marque=  t.verif_nom(this->marque);

        test_date=t.verif_date(this->date_achat);;
        qDebug()<<test_prix;
        if (test_nom == false)
        {
            QMessageBox::information(nullptr, QObject::tr("erreur"),
                        QObject::tr("nom invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (test_prix == false)
        {
            QMessageBox::information(nullptr, QObject::tr("erreur"),
                        QObject::tr("prix invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else if (test_marque == false)
        {
            QMessageBox::information(nullptr, QObject::tr("erreur"),
                        QObject::tr("marque invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }

        else if (test_date == false)
        {
            QMessageBox::information(nullptr, QObject::tr("erreur"),
                        QObject::tr("date achat invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }


       else {
        query.prepare("INSERT INTO EQUIPEMENT VALUES (?, ?, ?, ? , ?, ?, ?)");
        query.addBindValue(l);
        query.addBindValue(this->nom);
        query.addBindValue(this->prix);
        query.addBindValue(this->caracteristique);
        query.addBindValue(this->date_achat);
        query.addBindValue(this->marque);
        query.addBindValue(this->etat );
      }
        return query.exec();
}

    bool equipement::supprimer(int id){
        QSqlQuery query;
        QString stringId = QString::number(id);

        query.prepare("DELETE FROM EQUIPEMENT WHERE ID_EQUIPEMENT=?");
        query.addBindValue(stringId);

        return query.exec();
    }

    bool equipement::modifier(equipement a){
        QSqlQuery edit;
        equipement t;
        bool test_nom,test_prix,test_marque;
        test_nom = t.verif_nom(this->nom);
        test_prix= t.verif_numero(this->prix);
        test_marque=  t.verif_nom(this->marque);


        qDebug()<<test_prix;
        if (test_nom == false)
        {
            QMessageBox::information(nullptr, QObject::tr("erreur"),
                        QObject::tr("nom invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (test_prix == false)
        {
            QMessageBox::information(nullptr, QObject::tr("erreur"),
                        QObject::tr("prix invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else if (test_marque == false)
        {
            QMessageBox::information(nullptr, QObject::tr("erreur"),
                        QObject::tr("marque invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }


        else {

                          edit.prepare("update EQUIPEMENT set NOM = :NOM,PRIX=:PRIX, MARQUE = :MARQUE, CARACTERISTIQUE=:CARACTERISTIQUE , ETAT=:ETAT where ID_EQUIPEMENT = :ID");

                          edit.bindValue(":ID",a.getId_equipement());
                          edit.bindValue(":NOM",a.getNom());
                          edit.bindValue(":PRIX",a.getPrix());
                          edit.bindValue(":MARQUE",a.getMarque());
                          edit.bindValue(":CARACTERISTIQUE",a.getCaracteristique());
                          edit.bindValue(":ETAT",a.getEtat());}
                          return    edit.exec();


    }

QSqlQueryModel * equipement::afficher(){


    QSqlQueryModel* model   = new QSqlQueryModel();

    model->setQuery("select * from EQUIPEMENT");

    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_EQUIPEMENT"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRIX"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("CARACTERISTIQUE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("DATE_ACHAT"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("MARQUE"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("modifier"));


    return model;
    }

equipement equipement::rehcerche(int id)
{  equipement a;
    QString stringId = QString::number(id);
   QSqlQuery query;
   query.prepare("select * from EQUIPEMENT where ID_EQUIPEMENT=?");
   query.addBindValue(stringId);
   query.exec();
    query.first();
    a.setNom(query.value(1).toString());
    a.setPrix(query.value(2).toString());
    a.setMarque(query.value(3).toString());
    a.setCaracteristique(query.value(5).toString());
    a.setId_equipement(id);
    a.setEtat(query.value(6).toString());
    a.setDate_achat("");
   return a;
}


bool equipement::verif_nom(QString ch_nom){
    bool test=true;
    int i;
    if(true)
    {
        for(i=0;i<ch_nom.length();i++){
            if(!(((ch_nom[i]>='A')&&(ch_nom[i]<='Z'))||((ch_nom[i]>='a')&&(ch_nom[i]<='z'))||(ch_nom[i]<=' '))){
                test=false;
                return  test;
        }
    }
  }
    return  test;
}


bool equipement::verif_date(QString date_d)
{

    bool test=true;
    int i;
    if(date_d.length()!=10){
       test=false;
       return  test;
    }

         else{
       for(i=1;i<date_d.length()+1;i++){
            if(!((date_d[1]>='0')&&(date_d[1]<='9'))&&(!((date_d[2]>='0')&&(date_d[2]<='9'))) && (!((date_d[4]>='0')&&(date_d[4]<='9'))) && (!((date_d[5]>='0')&&(date_d[5]<='9'))) && (!((date_d[7]>='0')&&(date_d[7]<='9'))) && (!((date_d[8]>='0')&&(date_d[8]<='9'))) && (!((date_d[9]>='0')&&(date_d[9]<='9'))) && (!((date_d[10]>='0')&&(date_d[10]<='9')))&&(!((date_d[3]=='/')&&(date_d[6]<='/')))){
                test=false;
               return  test;
        }
        }
   }

 return test;}

//
bool equipement::verif_numero(QString numero)
{

    bool test=true;
    int i;
        for(i=0;i<numero.length();i++){
            if(!(((numero[i]>='0')&&(numero[i]<='9'))||(numero[i]=='.'))){
                test=false;
                return  test;

        }
    }
 return test;}

QVector<double> equipement::prix_equipement()
{
    QVector<double> a;
    QSqlQuery query;
    query.prepare("select PRIX from EQUIPEMENT WHERE etat = 'en panne' order by ID_EQUIPEMENT ");
    QSqlQuery query1;
    query1.prepare("select PRIX_REPARATION from REPARATION order by ID_EQUIPEMENT ");

    if (query.exec() && query1.exec()){
    while(query.next() && query1.next()){
        a << 0.0009975*(query.value(0).toInt() - query1.value(0).toInt());}
    }

 return a;
}

QVector<QString> equipement::nom_equipement()
{   QVector<QString> a;
    QSqlQuery query;
    query.prepare("select NOM from EQUIPEMENT WHERE etat = 'en panne' order by ID_EQUIPEMENT ");
    if (query.exec() ){
    while(query.next() ){
         a << query.value(0).toString();}
    }
    return a;
}
int equipement::count()
{  QSqlQuery query;
    int i=0;
    query.prepare("select NOM from EQUIPEMENT WHERE etat = 'en panne' order by ID_EQUIPEMENT ");
    if (query.exec() ){
    while(query.next() ){
         i++;}
    }
    return i;
}
