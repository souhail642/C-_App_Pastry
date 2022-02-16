#include "reparation.h"
#include <QSqlQuery>
#include <QVariant>

reparation::reparation(){}


reparation::reparation(int id_reparation){this->id_reparation = id_reparation;}

reparation::reparation(int id_reparateur,int id_equipement,QString nom,QString prix,QString date_livraison,QString date_reception)
{
    this->id_reparation = lastId();
    this->nom = nom;
    this->id_equipement =id_equipement;
    this->id_reparateur =id_reparateur;
    this->date_livraison = date_livraison;
    this->date_reception = date_reception;
    this->prix = prix;
}
int getId_reparation();
QString getNom();
int getId_equipement();
int getId_reparateur();
QString getDateLivraison ();
QString getDateReception();
QString getPrix ();

    int reparation::getId_reparation(){return this->id_reparation;}
    QString reparation::getNom(){return this->nom;}
 int reparation::getId_reparateur(){return this->id_reparateur;}
    int reparation::getId_equipement(){return this->id_equipement;}
    QString reparation::getDateLivraison(){return this->date_livraison;}
     QString reparation::getDateReception(){return this->date_reception;}
     QString reparation::getPrix(){return this->prix;}


    void reparation::setId_reparation(int id_reparation){this->id_reparation=id_reparation;};
    void reparation::setNom(QString nom){this->nom=nom;}
    void reparation::setId_reparateur(int id_reparateur){this->id_reparateur = id_reparateur;}
    void reparation::setId_equipement(int  id_equipement){this->id_equipement = id_equipement;}
    void reparation::setDateLivraison(QString date_livraison){this->date_livraison=date_livraison;}
    void reparation::setDateReception(QString date_reception){this->date_reception = date_reception;}
    void reparation::setPrix(QString prix){this->prix =prix;}

    int reparation::lastId(){
        int lastId = 0;
        QSqlQuery qry3 ;
        qry3.prepare("select ID_REPARATION from reparation ");
        if (qry3.exec()){
        while(qry3.next()){
            lastId = qry3.value(0).toInt();}
        }
        return lastId+1;
    }


    bool reparation::ajouter(){
        QSqlQuery query;
       int l = lastId();
       QString stringId = QString::number(l);
       //QString stringP = QString::number(this->prix);
       reparation t;
       bool test_prix,test_dateL,test_dateR;
       test_prix = t.verif_numero(this->prix);
       test_dateL = t.verif_date(this->date_livraison);
       test_dateR = t.verif_date(this->date_reception);

       if (test_prix == false)
       {
           QMessageBox::information(nullptr, QObject::tr("erreur"),
                       QObject::tr("prix invalide.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else if (test_dateL == false)
       {
           QMessageBox::information(nullptr, QObject::tr("erreur"),
                       QObject::tr("date livraison invalide.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }
       else if (test_dateR == false)
       {
           QMessageBox::information(nullptr, QObject::tr("erreur"),
                       QObject::tr("date reception invalide.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }


       else {
        query.prepare("INSERT INTO reparation VALUES (?, ?, ?, ? , ?, ?, ?)");
        query.addBindValue(l);
        query.addBindValue(this->id_equipement);
        query.addBindValue(this->id_reparateur);
        query.addBindValue(this->nom);
        query.addBindValue(this->prix );
        query.addBindValue(this->date_livraison);
        query.addBindValue(this->date_reception);

           }
        return query.exec();
}

    bool reparation::supprimer(int id){
        QSqlQuery query;
        QString stringId = QString::number(id);
        reparation r;
        r=r.rehcerche(id);
        QString stringIde = QString::number(r.getId_equipement());
        query.prepare("DELETE FROM reparation WHERE ID_REPARATION=?");
        query.addBindValue(stringId);
        QSqlQuery edit;
        edit.prepare("update EQUIPEMENT set  ETAT=:ETAT where ID_EQUIPEMENT = :ID");
        edit.bindValue(":ETAT","en marche");
        edit.bindValue(":ID",stringIde);
        edit.exec();
        return query.exec();
    }

    bool reparation::modifier(reparation a){
        QSqlQuery edit;

        reparation t;
        bool test_prix,test_dateL,test_dateR;
        test_prix = t.verif_numero(this->prix);
        test_dateL = t.verif_date(this->date_livraison);
        test_dateR = t.verif_date(this->date_reception);

        if (test_prix == false)
        {
            QMessageBox::information(nullptr, QObject::tr("erreur"),
                        QObject::tr("prix invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (test_dateL == false)
        {
            QMessageBox::information(nullptr, QObject::tr("erreur"),
                        QObject::tr("date livraison invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else if (test_dateR == false)
        {
            QMessageBox::information(nullptr, QObject::tr("erreur"),
                        QObject::tr("date reception invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }


        else {
                          edit.prepare("update reparation set NOM_EQUIPEMENT = :NOM, date_reception = :date_reception, date_livraison=:date_livraison, PRIX_REPARATION=:prix where ID_REPARATION = :ID");

                          edit.bindValue(":ID",a.getId_reparation());
                          edit.bindValue(":NOM",a.getNom());

                          edit.bindValue(":date_reception",a.getDateReception());

                          edit.bindValue(":prix",a.getPrix());
                           edit.bindValue(":date_livraison",a.getDateLivraison());
                              qDebug()<< a.getNom();}
                          return    edit.exec();


    }

QSqlQueryModel * reparation::afficher(){


    QSqlQueryModel* model   = new QSqlQueryModel();

    model->setQuery("select * from reparation");

    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_reparation"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("id_equipement"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("id_reparateur"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("date_livraison"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("date_reception"));

    //model->setHeaderData(7, Qt::Horizontal,QObject::tr("modifier"));


    return model;
    }

reparation reparation::rehcerche(int id)
{  reparation a;
    QString stringId = QString::number(id);
   QSqlQuery query;
   query.prepare("select * from reparation where ID_REPARATION=?");
   query.addBindValue(stringId);
   query.exec();
    query.first();
    a.setNom(query.value(3).toString());
    a.setId_equipement(query.value(1).toInt());
   // a.setNom(query.value(1).toString());
    a.setDateReception(query.value(6).toString());
    a.setId_reparateur(query.value(2).toInt());
    a.setId_reparation(id);
    a.setPrix(query.value(4).toString());
    a.setDateLivraison(query.value(5).toString());


   return a;
}
QString reparation::recupererNom(int id)
{  reparation a;
    QString stringId = QString::number(id);
   QSqlQuery query;
   query.prepare("select NOM from equipement where ID_EQUIPEMENT=?");
   query.addBindValue(stringId);
   query.exec();
    query.first();
   return query.value(0).toString();
}

bool reparation::verif_numero(QString numero)
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



bool reparation::verif_date(QString date_d)
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

int reparation::mois(int m, int y)
{
    if ((y%4)==1)
    {
        if (m==2)
        { return 28;
         }}
        else
        {
            switch (m) {



     case 2:       return 29;
       break;
    case 1 : return 31;
     break;
    case 12 : return 31;
     break;
    case 3 : return 31;
     break;
    case 4 : return 30;
     break;
    case 5 : return 31;
     break;
    case 6 : return 30;
     break;
    case 7 : return 31;
     break;
    case 8 : return 31;
     break;
    case 9 : return 30;
     break;
    case 10 : return 31;
     break;
    case 11 : return 30;
     break;
}
    }

}

void reparation::pdf(QString str,QString ids,QString nom,QString prenom,reparation t)

{
    str.append("<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta name='viewport' content='width=device-width, initial-scale=1.0, shrink-to-fit=no'><title>pdf</title><link rel='stylesheet' href='assets/bootstrap/css/bootstrap.min.css'><link rel='stylesheet' href='assets/css/styles.css'></head><body><h1 style='color: #0065cb;'>&nbsp; &nbsp;Facture&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </h1><img src=':/img/img/pdf_logo.png'  /><hr style='/*border: 4px;*/border-top: 2px solid rgb(0,101,203);'><div class='container'><div class='row'><div class='col-md-6' style='-ms-flex: 0 0 70%;flex: 0 0 70%;max-width: 70%;'></div><div class='col-md-6' style='-ms-flex: 0 0 30%;flex: 0 0 30%;max-width: 30%;'><span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;</span><strong>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;Dream Pastry</strong><p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;343 rue OKBAA IBN NEFAA&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;7000 BIZERTE&nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp; &nbsp;  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;Tel:20285256&nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;&nbsp; &nbsp;  &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;Mail:dreamPastryMail@gmail.com</p></div></div></div><div class='container'><div class='row'><div class='col-md-12'><h3><span style='text-decoration: underline;'>Facture n°") ;
      str.append(ids);
    str.append("</span></h3><strong>Date de livraison :&nbsp;</strong><span>");
    str.append(t.getDateLivraison());
    str.append("</span></div></div></div><div class='container'><div class='row'><div class='col-md-12'><strong>Date de réception :</strong><span>") ;
    str.append(t.getDateReception()) ;
    str.append("</span></div></div></div>") ;

     str.append("<div class='container'><div class='row'><div class='col-md-12'></div></div></div><div class='container'><div class='row'><div class='col-md-12'><p><br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;<br></p></div></div></div><div class='container'><div class='row'><div class='col-md-12'><div class='table-responsive'><table class='table'>") ;
     str.append("<tbody><tr style=' font-size: 18px; color:#ffffff;background-color:#0065cb;'><th><h6>Equipement&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;</h6></th><th><h6>Nom Réparateur&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;</h6></th><th><h6>prix&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; </h6></th></tr>");
      str.append("<tr style='font-size: 15px;' ><td  ><h6>");
      str.append(t.getNom());
      str.append("</h6></td><td><h6>");
       str.append(nom);
       str.append("&nbsp;");
       str.append(prenom);
       str.append("</h6></td><td><h6>");
       str.append(t.getPrix());
       str.append("</h6></td></tr><tr></tr><tr><td></td><td>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;</td><td></td></tr></tbody></table></div></div></div></div>");
       str.append("<div class='container '><div ><div ><h6>TVA non applicable, art. 298B du CGI</h6></div><table><tr ><td>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;&nbsp; &nbsp; &nbsp; &nbsp;&nbsp;  </td><td style=' font-size: 18px;'><div  style=' font-size: 18px; background-color: rgb(0,101,203);'><h2 style=' font-size: 18px; color: rgb(255,255,255);'>Prix à payer :&nbsp;&nbsp;");
       str.append(t.getPrix());
       str.append("&nbsp;TND</h2> </div></td></tr> </div></div>");
       str.append("<div class='container'></div><div class='container'><div class='row'><div class='col-md-12'><p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;</p></div></div></div><div class='container'><div class='row'><div class='col-md-6'></div><div class='col-md-6'><h3>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;signature</h3></div></div></div>");
       str.append("</body></html>");

    QPrinter printer ;
    printer.setOrientation(QPrinter::Portrait);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4) ;

    QString path=QFileDialog::getSaveFileName(NULL,"Convertir a PDF","..","PDF(*.pdf)");

    if (path.isEmpty()) return ;
    printer.setOutputFileName(path) ;

    QTextDocument doc;
    doc.setHtml(str) ;
    doc.print(&printer);
}

QVector<double> reparation::prix_reparation()
{
    QVector<double> a;
    QSqlQuery query;
    query.prepare("select PRIX_REPARATION from REPARATION order by ID_EQUIPEMENT ");

    if (query.exec()){
    while(query.next()){
        a << 0.0009975*query.value(0).toInt();}
    }
     return a;

}
