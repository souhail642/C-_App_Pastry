#include "recette.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include<QMessageBox>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>

recette::recette(){}


recette::recette(int ID_recette){this->ID_recette = ID_recette;}

recette::recette(QString nom,QString categorie,int nb_ingredient,QString description,int id_produit)
{
    this->ID_recette = lastId();
    this->nom = nom;
    this->categorie =categorie;
    this->nb_ingredient =nb_ingredient;
    this->description = description;
    this->id_produit = id_produit;

}
int getID_recette();
QString getnom();
int getcategorie();
int getnb_ingredient();
QString getdescription ();
QString getid_produit();


    int recette::getID_recette(){return this->ID_recette;}
    QString recette::getnom(){return this->nom;}
    QString recette::getcategorie(){return this->categorie;}
    int recette::getnb_ingredient(){return this->nb_ingredient;}
    QString recette::getdescription(){return this->description;}
     int recette::getid_produit(){return this->id_produit;}


    void recette::setID_recette(int ID_recette){this->ID_recette=ID_recette;};
    void recette::setnom(QString nom){this->nom=nom;}
    void recette::setcategorie(QString categorie){this->categorie = categorie;}
    void recette::setnb_ingredient(int  nb_ingredient){this->nb_ingredient = nb_ingredient;}
    void recette::setdescription(QString description){this->description=description;}
    void recette::setid_produit(int id_produit){this->id_produit = id_produit;}

    int recette::lastId(){
        int lastId = 0;
        QSqlQuery qry3 ;
        qry3.prepare("select ID_recette from recette ");
        if (qry3.exec()){
        while(qry3.next()){
            lastId = qry3.value(0).toInt();}
        }
        return lastId+1;
    }


    bool recette::ajouter(){
        QSqlQuery query;
        recette t;
       int l = lastId();
       bool test_nom,test_categorie,test_nb,test_desc,test_pr;
       test_nom = t.verif_nom(this->nom);
       test_categorie = t.verif_nom(this->categorie);
       test_nb = t.verif_numero(this->nb_ingredient);

       test_desc = t.verif_nom(this->description);
       test_pr = t.verif_numero(this->id_produit);
        if (test_nom == false)
       {
           QMessageBox::information(nullptr, QObject::tr("erreur"),
                       QObject::tr("nom invalide.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }
       else if (test_categorie == false)
       {
           QMessageBox::information(nullptr, QObject::tr("erreur"),
                       QObject::tr("categorie invalide.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }
       else if (test_nb == false)
       {
           QMessageBox::information(nullptr, QObject::tr("erreur"),
                       QObject::tr("nombre ingredient invalide.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }
       else if (test_desc == false)
       {
           QMessageBox::information(nullptr, QObject::tr("erreur"),
                       QObject::tr("description invalide.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }
       else if (test_pr == false)
       {
           QMessageBox::information(nullptr, QObject::tr("erreur"),
                       QObject::tr("id produit invalide.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }


       else {
        query.prepare("INSERT INTO recette VALUES (?,?, ?, ?, ? , ?)");
        query.addBindValue(l);
        query.addBindValue(this->nom);
        query.addBindValue(this->categorie);
        query.addBindValue(this->nb_ingredient);
        query.addBindValue(this->description);
        query.addBindValue(this->id_produit);
       }
        return query.exec();
}

    bool recette::supprimer(int ID_recette){
        QSqlQuery query;
        QString stringId = QString::number(ID_recette);

        query.prepare("DELETE FROM recette WHERE ID_recette=?");
        query.addBindValue(stringId);

        return query.exec();
    }

QSqlQueryModel * recette::afficher(){


    QSqlQueryModel* model   = new QSqlQueryModel();

    model->setQuery("select * from recette");

    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_recette"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("categorie"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("id_produit"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("description"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("nb_ingredient"));
   // model->setHeaderData(6, Qt::Horizontal,QObject::tr("modifier"));

   /* ui->tableView->resizeColumnToContents(0);
       ui->tableView->resizeColumnToContents(1);
       ui->tableView->resizeColumnToContents(2);
       ui->tableView->resizeColumnToContents(3);
       ui->tableView->resizeColumnToContents(4);
          ui->tableView->resizeColumnToContents(5);
          ui->tableView->resizeColumnToContents(6); */

    return model;
    }

bool recette::modifier(recette a){
    QSqlQuery edit;


                      edit.prepare("update recette set ID_recette = :ID_recette,nom=:nom,categorie=:categorie, nombre_ingredient = :nb_ingredient, description=:description , id_produit=:ETAT where ID_recette = :ID");

                      edit.bindValue(":ID",a.getID_recette());
                      edit.bindValue(":ID_recette",a.getID_recette());
                      edit.bindValue(":nom",a.getnom());
                      edit.bindValue(":categorie",a.getcategorie());
                      edit.bindValue(":nb_ingredient",a.getnb_ingredient());
                      edit.bindValue(":description",a.getdescription());
                      edit.bindValue(":ETAT",a.getid_produit());
                      return    edit.exec();


}

bool recette::verif_nom(QString ch_nom){
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
bool recette::verif_numero(int numero)
{

    bool test=true;
    int i;
    QString numero1 = QString::number(numero);
      qDebug()<<numero1;

      if((numero1[0]=='0')){
          test=false;
          return  test;

  }


        for(i=1;i<numero1.length();i++){
            if(!((numero1[i]>='0')&&(numero1[i]<='9'))){
                test=false;
                return  test;

        }
    }
 return test;}
QSqlQueryModel *recette::cherch_four(QString nomm)
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from recette where Categorie='"+nomm+"'");

        model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_recette"));
        model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal,QObject::tr("categorie"));
        model->setHeaderData(5, Qt::Horizontal,QObject::tr("id_produit"));
        model->setHeaderData(4, Qt::Horizontal,QObject::tr("description"));
        model->setHeaderData(3, Qt::Horizontal,QObject::tr("nb_ingredient"));


    return model;
}

void recette::Recherche(Ui::accueil *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    QString reference =ui->cher1_2->text();
    q.prepare("select * from recette where (ID_RECETTE LIKE '%"+reference+"%' or NOM LIKE '%"+reference+"%' or CATEGORIE LIKE '%"+reference+"%' or NOMBRE_INGREDIENT LIKE '%"+reference+"%' or DESCRIPTION LIKE '%"+reference+"%' or ID_PRODUIT LIKE '%"+reference+"%' )");

    if ( q.exec() )
    { modal->setQuery(q);
        ui->tableView_recette->setModel(modal);}
    else
    {
        qWarning( "can't get value" ); }
}
