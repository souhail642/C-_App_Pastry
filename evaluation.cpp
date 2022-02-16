#include "evaluation.h"
#include <QSqlQuery>
#include <QVariant>

evaluation::evaluation(){}


evaluation::evaluation(int id_evaluation){this->id_evaluation = id_evaluation;}

evaluation::evaluation(int fiabilite,int performance,QString commentaire,QString date_evaluation,int autonomie)
{
    this->id_evaluation = lastId();
    this->fiabilite = fiabilite;
    this->performance =performance;
    this->commentaire =commentaire;
    this->date_evaluation = date_evaluation;
    this->autonomie = autonomie;

}

evaluation::evaluation(QString commentaire,QString date_evaluation,int id_evaluation)
{
    this->id_evaluation =id_evaluation;
    this->commentaire =commentaire;
    this->date_evaluation = date_evaluation;


}

    int evaluation::getId_evaluation(){return this->id_evaluation;}
  int evaluation::getFiabilite(){return this->fiabilite;}

    int evaluation::getPerformance(){return this->performance;}
    QString evaluation::getCommentaire(){return this->commentaire;}
     QString evaluation::getDate_evaluation(){return this->date_evaluation;}
     int evaluation::getAutonomie(){return this->autonomie;}
     QString evaluation::getCin_employe(){return this->cin_employe;}


    void evaluation::setId_evaluation(int id_evaluation){this->id_evaluation=id_evaluation;};
    void evaluation::setFiabilite(int fiabilite){this->fiabilite=fiabilite;}
    void evaluation::setPerformance(int performance){this->performance = performance;}
    void evaluation::setCommentaire(QString  commentaire){this->commentaire = commentaire;}
    void evaluation::setDate_evaluation(QString date_evaluation){this->date_evaluation=date_evaluation;}
    void evaluation::setAutonomie(int autonomie){this->autonomie = autonomie;}
    void evaluation::setCin_employe(QString cin_employe){this->cin_employe =cin_employe;}

    int evaluation::lastId(){
        int lastId = 0;
        QSqlQuery qry3 ;
        qry3.prepare("select ID_evaluation from evaluation ");
        if (qry3.exec()){
        while(qry3.next()){
            lastId = qry3.value(0).toInt();}
        }
        return lastId+1;
    }
    bool evaluation::verif(QString ch){
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

    bool evaluation::ajouter(){
        QSqlQuery query;
       int l = lastId();
        QString stringId = QString::number(this->id_evaluation);

        query.prepare("INSERT INTO EVALUATION VALUES (?, ?, ?, ? , ?, ?, ?)");
        query.addBindValue(l);
            query.addBindValue(this->autonomie);
                query.addBindValue(this->performance);
        query.addBindValue(this->fiabilite);

        query.addBindValue(this->commentaire);
        query.addBindValue(this->date_evaluation);
 query.addBindValue(this->cin_employe);


        return query.exec();
}

    bool evaluation::supprimer(int id_evaluation){
        QSqlQuery query;
        //QString stringId = QString::number(id_reclamation);

        query.prepare("DELETE FROM evaluation WHERE id_evaluation=:id_evaluation");
      query.bindValue(0,id_evaluation);

        return query.exec();
    }
    bool evaluation::modifier()

            {
                QSqlQuery query;
QString id=QString::number(id_evaluation);
              query.prepare("Update evaluation set commentaire=:c, date_evaluation=:date where id_evaluation=:id_evaluation");
              query.bindValue(":id_evaluation",id);
              query.bindValue(":c",commentaire);
              query.bindValue(":date",date_evaluation);



              return query.exec();
            }

QSqlQueryModel * evaluation::afficher(){


    QSqlQueryModel* model   = new QSqlQueryModel();

    model->setQuery("select * from evaluation");

    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_evaluation"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Autonomie"));

    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Performance"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("Discipline"));

     model->setHeaderData(4, Qt::Horizontal,QObject::tr("Commentaire"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("Date_evaluation"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("Cin_employe"));



    return model;
    }

void evaluation::trie(QTableView* table){

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from evaluation ORDER BY fiabilite");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}
void evaluation::trie1(QTableView* table){

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from evaluation ORDER BY autonomie");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}
void evaluation::trie2(QTableView* table){

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from evaluation ORDER BY performance");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}
void evaluation::tried(QTableView* table){

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from evaluation ORDER BY date_evaluation");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}

