#include "reclamation.h"
#include <QSqlQuery>
#include <QVariant>
#include <QMainWindow>
#include "accueil.h"

#include "ui_accueil.h"
reclamation::reclamation(){}


reclamation::reclamation(int id_reclamation){this->id_reclamation = id_reclamation;}

reclamation::reclamation(QString titre,QString description,QString date_reclamation,QString etat)
{
    this->id_reclamation = lastId();
    this->titre =titre;

    this->description =description;
    this->date_reclamation = date_reclamation;

    this->etat = etat;
}
reclamation::reclamation(QString titre,QString description,QString date_reclamation)
{
    this->id_reclamation = lastId();
    this->titre =titre;

    this->description =description;
    this->date_reclamation = date_reclamation;


}


    int reclamation::getId_reclamation(){return this->id_reclamation;}
    QString reclamation::getTitre(){return this->titre;}

    QString reclamation::getDescription(){return this->description;}
    QString reclamation::getDate_reclamation(){return this->date_reclamation;}
   QString reclamation::getCin_employe(){return this->cin_employe;}
     QString reclamation::getEtat(){return this->etat;}


    void reclamation::setId_reclamation(int id_reclamation){this->id_reclamation=id_reclamation;};
    void reclamation::setTitre(QString titre){this->titre=titre;}

    void reclamation::setDescription(QString  description){this->description = description;}
    void reclamation::setDate_reclamation(QString date_reclamation){this->date_reclamation=date_reclamation;}
    void reclamation::setCin_employe(QString cin_employe) {this->cin_employe =cin_employe;}
    void reclamation::setEtat(QString etat){ this->etat =etat;}

    int reclamation::lastId(){
        int lastId = 0;
        QSqlQuery qry3 ;
        qry3.prepare("select ID_reclamation from reclamation ");
        if (qry3.exec()){
        while(qry3.next()){
            lastId = qry3.value(0).toInt();}
        }
        return lastId+1;
    }


    bool reclamation::ajouter(){
        QSqlQuery query;
       int l = lastId();
        QString stringId = QString::number(this->id_reclamation);

        query.prepare("INSERT INTO RECLAMATION VALUES (?,'non traité', ?, ?,?,'1')");
        query.addBindValue(l);
        query.addBindValue(this->date_reclamation);
         query.addBindValue(this->description);
        query.addBindValue(this->titre);






        return query.exec();
}

    bool reclamation::supprimer(QString titre){
        QSqlQuery query;
        //QString stringId = QString::number(id_reclamation);

        query.prepare("DELETE FROM reclamation WHERE titre=:titre");
      query.bindValue(0,titre);

        return query.exec();
    }
    bool reclamation::modifier()

        {
            QSqlQuery query;

          query.prepare("Update RECLAMATION set titre=:t, DATE_RECLAMATION=:date, DESCRIPTION=:d where TITRE=:t");
          query.bindValue(":t",titre);
          query.bindValue(":date",date_reclamation);

          query.bindValue(":d",description);

          return query.exec();
        }

    bool reclamation::modifieretat()

        {
            QSqlQuery query;
QString id=QString::number(id_reclamation);
          query.prepare("Update RECLAMATION set etat='traité' where id_reclamation=:id_reclamation");
         query.bindValue(":id_reclamation",id);

          return query.exec();
        }

    bool reclamation::verif(QString ch){
        bool test=true;
        int i;
        if(true)
        {
            for(i=0;i<ch.length();i++){
                if(!(((ch[i]>='A')&&(ch[i]<='Z'))||((ch[i]>= 'a')&&(ch[i]<='z')))){
                    test=false;
                    return  test;
            }
        }
      }
        return  test;
    }
QSqlQueryModel * reclamation::afficher(){


    QSqlQueryModel* model   = new QSqlQueryModel();

    model->setQuery("select * from reclamation ");

    model->setHeaderData(0, Qt::Horizontal,QObject::tr("Id_reclamation"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("date_reclamation"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("description"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("titre"));

    model->setHeaderData(5, Qt::Horizontal,QObject::tr("cin_employe"));




    return model;
    }


void reclamation::trie(QTableView* table){

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from reclamation   ORDER BY date_reclamation");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}
void reclamation::recherche(QString mot)
{
    QSqlQuery *query=new QSqlQuery;
     query->prepare("select * from reclamation where (Titre LIKE '%"+mot+"%' or cin_employee LIKE '%"+mot+"%'  )");
      query->exec();
}
