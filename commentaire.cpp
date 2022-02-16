#include "commentaire.h"
#include <QSqlQuery>
#include <QVariant>
#include <QMainWindow>
#include "accueil.h"

#include "ui_accueil.h"
commentaire::commentaire(){}


commentaire::commentaire(int id){this->id= id;}

commentaire::commentaire(QString description,int id)
{
    this->id= lastId();


    this->description =description;

}


    int commentaire::getId(){return this->id;}

    QString commentaire::getDescription(){return this->description;}

   QString commentaire::getCin_employe(){return this->cin_employe;}



    void commentaire::setId(int id){this->id=id;};

    void commentaire::setDescription(QString  description){this->description = description;}

    void commentaire::setCin_employe(QString cin_employe) {this->cin_employe =cin_employe;}


    int commentaire::lastId(){
        int lastId = 0;
        QSqlQuery qry3 ;
        qry3.prepare("select ID from commentaire");
        if (qry3.exec()){
        while(qry3.next()){
            lastId = qry3.value(0).toInt();}
        }
        return lastId+1;
    }


    bool commentaire::ajouter(){
        QSqlQuery query;
       int l = lastId();
        QString stringId = QString::number(this->id);

        query.prepare("INSERT INTO commentaire VALUES (?, ?,?)");
        query.addBindValue(l);

         query.addBindValue(this->description);
        query.addBindValue(this->cin_employe);






        return query.exec();
}

    bool commentaire::supprimer(int  id){
        QSqlQuery query;
        //QString stringId = QString::number(id);

        query.prepare("DELETE FROM commentaire WHERE id=:id");
      query.bindValue(0,id);

        return query.exec();
    }
    bool commentaire::modifier()

        {
            QSqlQuery query;
QString ids=QString::number(id);
          query.prepare("Update commentaire set  description=:d where id=:id");


  query.bindValue(":id",ids);
          query.bindValue(":d",description);

          return query.exec();
        }



    bool commentaire::verif(QString ch){
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
QSqlQueryModel * commentaire::afficher(){


    QSqlQueryModel* model   = new QSqlQueryModel();

    model->setQuery("select * from commentaire  ");

    model->setHeaderData(0, Qt::Horizontal,QObject::tr("Id"));

      model->setHeaderData(1, Qt::Horizontal,QObject::tr("description"));




    model->setHeaderData(2, Qt::Horizontal,QObject::tr("cin_employe"));




    return model;
    }

