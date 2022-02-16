#include "accueil.h"
#include "ui_accueil.h"
#include "reparateur.h"
#include "evenement.h"
#include<QMessageBox>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include<QFileDialog>
#include"evaluation.h"
#include"reclamation.h"
#include"stati1.h"
#include"todolist.h"


accueil::accueil(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::accueil)
{


    ui->setupUi(this);

    // test employe ***************************

    Dialog d;
    d.exec();

     // test employe ***************************


    player = new QMediaPlayer(this);
      time=new QTimer();
    movie = new QMovie("C:/Users/ASUS/Desktop/load.gif");
    processLabel = new QLabel(this);
    processLabel->setGeometry(580,490,40,40);
processLabel->setMovie(movie);
     processLabel->setHidden(true);
   // splash->setPixmap(QLabel(processLabel));

    ui->button_profil->setFocus();
    ui->stackedWidget->setCurrentIndex(0);
     ui->valstack->setCurrentIndex(0);
     ui->valstack_2->setCurrentIndex(0);
     ui->valstack_3->setCurrentIndex(0);
    a=0;
   ui->toolBox_4->setCurrentIndex(1);
   ui->toolBox_3->setCurrentIndex(1);
   ui->stackedWidget_7->setCurrentIndex(0);
   ui->stackedWidget_10->setCurrentIndex(0);
   ui->stackedWidget_9->setCurrentIndex(0);

   ui->toolBox_4_2->setCurrentIndex(1);
   ui->toolBox_3_2->setCurrentIndex(1);
   ui->stackedWidget_7_2->setCurrentIndex(0);
   ui->stackedWidget_10_2->setCurrentIndex(0);
   ui->stackedWidget_9_2->setCurrentIndex(0);

   ui->toolBox_3_3->setCurrentIndex(1);
   ui->toolBox_4_3->setCurrentIndex(1);
   ui->stackedWidget_7_3->setCurrentIndex(0);
   ui->stackedWidget_10_3->setCurrentIndex(0);
   ui->stackedWidget_9_3->setCurrentIndex(0);
   a=1;

   ui->tabWidget->setCurrentIndex(0);
           ui->tabWidget_2->setCurrentIndex(0);
           ui->tabWidget_3->setCurrentIndex(0);
           ui->tabWidget_4->setCurrentIndex(0);
           ui->mail_rep->setCurrentIndex(0);

  ui->consulter_eq->setCurrentIndex(0);
           //ctrl sais
        ui->tel_rep->setValidator(new QIntValidator(10000000,100000000,this));

           //;;;;


      /*************** sou    **************/
        ui->tabWidget_7->setCurrentIndex(0);
        ui->tabWidget_5->setCurrentIndex(0);
        ui->tabWidget_6->setCurrentIndex(0);

     /************* farah ******************/
        ui->tabWidget_8->setCurrentIndex(0);
        ui->tabWidget_9->setCurrentIndex(0);
        ui->tabWidget_10->setCurrentIndex(0);
        ui->consulter_eq_3->setCurrentIndex(0);
         ui->valstack_6->setCurrentIndex(0);
          ui->valstack_7->setCurrentIndex(0);
        //for email tab
        connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail1()));
        connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

}

accueil::~accueil()
{
    delete ui;
}

//µµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµ
bool accueil::verif_modif(QString nom,QString nom1,int id)
{
    bool test = false;
    QString stringId = QString::number(id);

    QSqlQuery query;
    QString ms = "select * from "+nom+" where "+nom1+" = "+stringId;
    query.prepare(ms);
    query.addBindValue(nom);
    query.addBindValue(nom1);
    query.addBindValue(stringId);
    query.exec();
     if (query.first()==NULL)
     {
         QMessageBox::information(nullptr, QObject::tr("erreur"),
                     QObject::tr("ID non trouvé.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
     {
         test=true;
     }
     return test;

}
//µµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµ



void accueil::on_button_profil_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->button_client->setEnabled(1);
}

void accueil::on_button_employe_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget_2->setCurrentIndex(1);
}

void accueil::on_button_client_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget_2->setCurrentIndex(2);
}

void accueil::on_button_produit_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget_2->setCurrentIndex(3);
}

void accueil::on_button_equipement_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->stackedWidget_2->setCurrentIndex(4);
    ui->groupBox_21->setHidden(true);
}

void accueil::on_button_fournisseurs_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(5);
}

void accueil::on_button_evenement_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->stackedWidget_2->setCurrentIndex(6);
}



void accueil::on_pushButton_clicked()
{
}







void accueil::on_button_recette_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    ui->stackedWidget_2->setCurrentIndex(7);
}

void accueil::on_button_quitter_clicked()
{
    close();
}





void accueil::on_toolBox_3_currentChanged(int index)
{
    int b=index;
        b=1;

        if (a==1)
         {ui->stackedWidget_9->setCurrentIndex(1);
          ui->stackedWidget_10->setCurrentIndex(1);
          ui->stackedWidget_10->hide();}
}

void accueil::on_toolBox_4_currentChanged(int index)
{
    int b=index;
        b=1;
        if (a==1)
         {ui->stackedWidget_9->setCurrentIndex(1);
          ui->stackedWidget_10->setCurrentIndex(1);
          ui->stackedWidget_10->hide();}


}

void accueil::on_modifier_eq_clicked()
{

  equipement r;
  accueil a;
   bool test = a.verif_modif("EQUIPEMENT","ID_EQUIPEMENT",ui->IDE_mo->text().toInt());
   if (test==true)
   {
    r = r.rehcerche(ui->IDE_mo->text().toInt());
    ui->stackedWidget_7->setCurrentIndex(1);
    ui->nom_m_2->setText(r.getNom());
   // QString stringPrix = QString::number(r.getPrix());
    ui->prix_m_2->setText(r.getPrix());
    ui->marque_m_2->setText(r.getMarque());
    ui->caracteristique_m_2->setText(r.getCaracteristique());  
    ui->etat_m_2->setCurrentText(r.getEtat());}


}

void accueil::on_supprimer_eq_clicked()
{
    equipement s;
    accueil b;
     bool test = b.verif_modif("EQUIPEMENT","ID_EQUIPEMENT",ui->IDEs->text().toInt());
     if (test==true)
     {
    s.supprimer(ui->IDEs->text().toInt());
    ui->tableView->setModel(s.afficher());
    a=0;
    ui->IDEs->setText("");
    ui->toolBox_3->setCurrentIndex(1);
    ui->toolBox_4->setCurrentIndex(1);
    ui->stackedWidget_7->setCurrentIndex(0);
    ui->stackedWidget_9->setCurrentIndex(0);
    ui->stackedWidget_10->setCurrentIndex(0);
    ui->stackedWidget_10->show();
    a=1;}
}

void accueil::on_modifier_valide_m_clicked()
{
     equipement m;
       ui->stackedWidget_7->setCurrentIndex(0);
       m.setNom(ui->nom_m_2->text());
       m.setEtat(ui->etat_m_2->currentText());
       m.setPrix(ui->prix_m_2->text());
       m.setMarque(ui->marque_m_2->text());
       m.setDate_achat("");
       m.setId_equipement(ui->IDE_mo->text().toInt());
       m.setCaracteristique(ui->caracteristique_m_2->text());
       m.modifier(m);
       ui->tableView->setModel(m.afficher());

       //***********************************************
       ui->comboBox_eq->clear();
       ui->comboBox_rep->clear();
       QString id = "id:";
       QString nom = "         nom:";
        QString marque = "         marque:";
       QSqlQuery qry;
       qry.prepare("select ID_EQUIPEMENT,NOM,MARQUE from EQUIPEMENT where etat='en panne' ");
       if(qry.exec())
         {while (qry.next())
        {  QString a ;
               a= id + qry.value(0).toString() + nom + qry.value(1).toString() + marque + qry.value(2).toString();

               ui->comboBox_eq->addItem(a);}}


       //***********************************************
}

void accueil::on_tabWidget_2_currentChanged(int index)
{equipement m;
   ui->tableView->setModel(m.afficher());
}

void accueil::on_ajouter_eq_clicked()
{
    equipement t;

       // t.setId_equipement(ui->lineEdit->text().toInt());
        t.setNom(ui->nom_eqa->text());
        t.setPrix(ui->prix_eqa->text());
        t.setDate_achat(ui->date_eqa->text());
        t.setCaracteristique(ui->caracteristique_eqa->toPlainText());

        t.setMarque(ui->marque_eqa->text());
        t.setEtat(ui->etat_eqa->currentText());
        bool ok;
        ok=t.ajouter();
        if (ok == true)
        {
        ui->valstack_3->setCurrentIndex(1);
        }
    ui->tableView->setModel(t.afficher());
    //***********************************************
    ui->comboBox_eq->clear();
    ui->comboBox_rep->clear();
    QString id = "id:";
    QString nom = "         nom:";
     QString marque = "         marque:";
    QSqlQuery qry;
    qry.prepare("select ID_EQUIPEMENT,NOM,MARQUE from EQUIPEMENT where etat='en panne'");
    if(qry.exec())
      {while (qry.next())
     {  QString a ;
            a= id + qry.value(0).toString() + nom + qry.value(1).toString() + marque + qry.value(2).toString();

            ui->comboBox_eq->addItem(a);}}


    //***********************************************
}

void accueil::on_ajouter_rep_clicked()
{
   reparateur t;

    t.setNom(ui->nom_rep->text());
    t.setPrenom(ui->prenom_rep->text());
    t.setTelephone(ui->tel_rep->text());
    t.setEmail(ui->email_rep->text());

    t.setSociete(ui->societe_rep->text());
    t.setSpecialite(ui->specialite_rep->text());
    bool ok;
    ok= t.ajouter();
    if (ok == true)
    {
    ui->valstack_2->setCurrentIndex(1);
    }
ui->tableView_2->setModel(t.afficher());

//******************************************
ui->comboBox_eq->clear();
ui->comboBox_rep->clear();
QString id1 = "id:";
QString nom1 = "    nom et prénom:";
 QString societe = "    société:";
  QString specialite = "    spécialité:";
QSqlQuery qry1;
qry1.prepare("select ID_REPARATEUR,NOM,PRENOM,SOCIETE,SPECIALITE from REPARATEUR ");
if(qry1.exec())
  {while (qry1.next())
 {  QString b ;
        b= id1 + qry1.value(0).toString() + nom1 + qry1.value(1).toString()+" "+ qry1.value(2).toString() + societe + qry1.value(3).toString()+ specialite + qry1.value(4).toString();

        ui->comboBox_rep->addItem(b);}}
//*******************************************



}

void accueil::on_toolBox_3_2_currentChanged(int index)
{
    int b=index;
        b=1;

        if (a==1)
         {ui->stackedWidget_9_2->setCurrentIndex(1);
          ui->stackedWidget_10_2->setCurrentIndex(1);
          ui->stackedWidget_10_2->hide();}
}

void accueil::on_toolBox_4_2_currentChanged(int index)
{
    int b=index;
        b=1;
        if (a==1)
         {ui->stackedWidget_9_2->setCurrentIndex(1);
          ui->stackedWidget_10_2->setCurrentIndex(1);
          ui->stackedWidget_10_2->hide();}
}

void accueil::on_tabWidget_3_currentChanged(int index)
{
    reparateur m;
       ui->tableView_2->setModel(m.afficher());
}

void accueil::on_modifier_valide_m_2_clicked()
{
    reparateur m;
      ui->stackedWidget_7_2->setCurrentIndex(0);
      m.setNom(ui->nom_m_rep->text());
      m.setPrenom(ui->prenom_m_rep->text());
      m.setTelephone(ui->telephone_m_rep->text());
      m.setEmail(ui->email_m_rep->text());
      m.setId_reparateur(ui->IDE_mo_2->text().toInt());
      m.setSociete(ui->societe_m_rep->text());
       m.setSpecialite(ui->specialite_m_rep->text());
      m.modifier(m);
      ui->tableView_2->setModel(m.afficher());

      //******************************************
      ui->comboBox_eq->clear();
      ui->comboBox_rep->clear();
      QString id1 = "id:";
      QString nom1 = "    nom et prénom:";
       QString societe = "    société:";
        QString specialite = "    spécialité:";
      QSqlQuery qry1;
      qry1.prepare("select ID_REPARATEUR,NOM,PRENOM,SOCIETE,SPECIALITE from REPARATEUR ");
      if(qry1.exec())
        {while (qry1.next())
       {  QString b ;
              b= id1 + qry1.value(0).toString() + nom1 + qry1.value(1).toString()+" "+ qry1.value(2).toString() + societe + qry1.value(3).toString()+ specialite + qry1.value(4).toString();

              ui->comboBox_rep->addItem(b);}}
      //*******************************************
}

void accueil::on_modifier_eq_2_clicked()
{

  reparateur r;
  accueil a;
   bool test = a.verif_modif("REPARATEUR","ID_REPARATEUR",ui->IDE_mo_2->text().toInt());
   if (test==true)
   {
  ui->stackedWidget_7_2->setCurrentIndex(1);
    r = r.rehcerche(ui->IDE_mo_2->text().toInt());
    ui->nom_m_rep->setText(r.getNom());
    ui->prenom_m_rep->setText(r.getPrenom());
   // QString stringTel = QString::number(r.getTelephone());
    ui->telephone_m_rep->setText(r.getTelephone());
    ui->societe_m_rep->setText(r.getSociete());
    ui->specialite_m_rep->setText(r.getSpecialite());
    ui->email_m_rep->setText(r.getEmail());
}
}

void accueil::on_supprimer_eq_2_clicked()
{
    reparateur s;
    accueil b;
     bool test = b.verif_modif("REPARATEUR","ID_REPARATEUR",ui->IDEs_2->text().toInt());
     if (test==true)
     {
    s.supprimer(ui->IDEs_2->text().toInt());
    ui->tableView_2->setModel(s.afficher());
    a=0;
    ui->IDEs_2->setText("");
    ui->toolBox_3_2->setCurrentIndex(1);
    ui->toolBox_4_2->setCurrentIndex(1);
    ui->stackedWidget_7_2->setCurrentIndex(0);
    ui->stackedWidget_9_2->setCurrentIndex(0);
    ui->stackedWidget_10_2->setCurrentIndex(0);
    ui->stackedWidget_10_2->show();
    a=1;}
}

void accueil::on_tabWidget_currentChanged(int index)
{
    ui->comboBox_eq->clear();
    ui->comboBox_rep->clear();
    QString id = "id:";
    QString nom = "         nom:";
     QString marque = "         marque:";
    QSqlQuery qry;
    qry.prepare("select ID_EQUIPEMENT,NOM,MARQUE from EQUIPEMENT where etat ='en panne' ");
    if(qry.exec())
      {while (qry.next())
     {  QString a ;
            a= id + qry.value(0).toString() + nom + qry.value(1).toString() + marque + qry.value(2).toString();

            ui->comboBox_eq->addItem(a);}}

    QString id1 = "id:";
    QString nom1 = "    nom et prénom:";
     QString societe = "    société:";
      QString specialite = "    spécialité:";
    QSqlQuery qry1;
    qry1.prepare("select ID_REPARATEUR,NOM,PRENOM,SOCIETE,SPECIALITE from REPARATEUR ");
    if(qry1.exec())
      {while (qry1.next())
     {  QString b ;
            b= id1 + qry1.value(0).toString() + nom1 + qry1.value(1).toString()+" "+ qry1.value(2).toString() + societe + qry1.value(3).toString()+ specialite + qry1.value(4).toString();

            ui->comboBox_rep->addItem(b);}}


}

void accueil::on_ajouter_rep_2_clicked()
{
    reparation t;

    QString a=ui->comboBox_eq->currentText();
    QString a1=ui->comboBox_rep->currentText();
    QString idString;
    QString idString1;

    idString =a[3];
    idString1 =a1[3];
    if (a[4]!=" ")
    { idString +=  a[4];}
     else
    {idString =a[3]; }
    if (a1[4]!=" ")
    { idString1 +=  a1[4];}
     else
    {idString1 =a1[3]; }
    bool ok;
    int id_e = idString.toInt(&ok,10);
    int id_r = idString1.toInt(&ok,10);
     t.setNom(t.recupererNom(id_e));
   t.setId_equipement(id_e);
     t.setId_reparateur(id_r);
     t.setPrix(ui->prix_reparation->text());
     t.setDateLivraison(ui->dateL_reparation->text());
     t.setDateReception(ui->dateR_reparation->text());
     ok=t.ajouter();

     if (ok == true)
     {
     ui->valstack->setCurrentIndex(1);
     }
 ui->tableView_3->setModel(t.afficher());
}

void accueil::on_toolBox_3_3_currentChanged(int index)
{
    int b=index;
        b=1;

        if (a==1)
         {ui->stackedWidget_9_3->setCurrentIndex(1);
          ui->stackedWidget_10_3->setCurrentIndex(1);
          ui->stackedWidget_10_3->hide();}
}

void accueil::on_toolBox_4_3_currentChanged(int index)
{
    int b=index;
        b=1;
        if (a==1)
         {ui->stackedWidget_9_3->setCurrentIndex(1);
          ui->stackedWidget_10_3->setCurrentIndex(1);
          ui->stackedWidget_10_3->hide();}
}

void accueil::on_modifier_eq_3_clicked()
{

  reparation r;
  accueil a;
  bool test = a.verif_modif("REPARATION","ID_REPARATION",ui->IDE_mo_3->text().toInt());
  if (test==true)
  {
  ui->stackedWidget_7_3->setCurrentIndex(1);
    r = r.rehcerche(ui->IDE_mo_3->text().toInt());
    ui->nom_reparation_m->setText(r.getNom());
    ui->prix_reparation_m->setText(r.getPrix());
    ui->dateL_m->setText(r.getDateLivraison());
    ui->dateR_m->setText(r.getDateReception());
}
}

void accueil::on_supprimer_eq_3_clicked()
{
    reparation s;
    accueil b;
     bool test = b.verif_modif("REPARATION","ID_REPARATION",ui->IDEs_3->text().toInt());
     if (test==true)
     {
    s.supprimer(ui->IDEs_3->text().toInt());
    ui->tableView_3->setModel(s.afficher());
    a=0;
    ui->IDEs_2->setText("");
    ui->toolBox_3_3->setCurrentIndex(1);
    ui->toolBox_4_3->setCurrentIndex(1);
    ui->stackedWidget_7_3->setCurrentIndex(0);
    ui->stackedWidget_9_3->setCurrentIndex(0);
    ui->stackedWidget_10_3->setCurrentIndex(0);
    ui->stackedWidget_10_3->show();
    a=1;}
}

void accueil::on_modifier_valide_m_3_clicked()
{
    reparation m;
      ui->stackedWidget_7_3->setCurrentIndex(0);
      m.setNom(ui->nom_reparation_m->text());
      m.setPrix(ui->prix_reparation_m->text());
      m.setDateLivraison(ui->dateL_m->text());
      m.setDateReception(ui->dateR_m->text());
      m.setId_reparation(ui->IDE_mo_3->text().toInt());

      m.modifier(m);
      ui->tableView_3->setModel(m.afficher());
}

void accueil::on_tabWidget_4_currentChanged(int index)
{  reparation m;
   ui->tableView_3->setModel(m.afficher());
}

void accueil::on_ajouter_rep_4_clicked()
{
    ui->valstack->setCurrentIndex(0);
}

void accueil::on_ajouter_rep_5_clicked()
{
    ui->valstack_2->setCurrentIndex(0);
}

void accueil::on_ajouter_rep_6_clicked()
{
    ui->valstack_3->setCurrentIndex(0);
}

void accueil::on_modifier_valide_m_4_clicked()
{
    accueil::make();
    ui->consulter_eq->setCurrentIndex(1);
}



void   accueil::sendMail()
{


    animation1 = new QPropertyAnimation(ui->mailing,"geometry");
    ui->mailing->setText("envoie") ;
    animation1->setDuration(1000);
    animation1->setStartValue(ui->mailing->geometry());
  //  animation->setEndValue(QRect(200,200,100,50));
    animation1->start();




    reparation r;
    reparateur t;
   QDate d= d.currentDate();
   int jj= d.day();
   int mm =d.month();
   int yy = d.year();
 qDebug()<<jj<<" "<<mm<<" "<<yy;
    r=r.rehcerche(ui->mail->text().toInt());
   t = t.rehcerche(r.getId_reparateur());
  QString msg="Bonjour "+t.getPrenom()+", Je viens par le présent email vous informer qu'il vous reste ";
  QSqlQuery query ;
 bool ok;


   QString nbjr= r.getDateReception();
   QChar nbjr1= nbjr[0];
    QChar nbjr2= nbjr[1];
         QString  nbjrr= nbjr1 ;
   nbjrr+= nbjr2;



   int nbr = nbjrr.toInt(&ok,10);




   QChar nbmr1= nbjr[3];
    QChar nbmr2= nbjr[4];
     QString nbm =nbmr1  ;
   nbm += nbmr2;



   int nbrm = nbm.toInt(&ok,10);
    qDebug()<<nbm;




   QChar nbyr1= nbjr[6];
    QChar nbyr2= nbjr[7];
    QChar nbyr3= nbjr[8];
     QChar nbyr4= nbjr[9];
     QString nbyr =nbyr1  ;
   nbyr += nbyr2;
   nbyr += nbyr3;
   nbyr += nbyr4;



   int nbry = nbyr.toInt(&ok,10);
   int ja = r.mois(nbrm,nbry);
   if (jj>nbr)
   {
     nbr+=ja;
     nbrm-=1;
   }
   if (mm>nbrm)
   {
     nbrm+=12;
     nbry-=1;
   }

  nbr -=jj;
  nbrm -=mm;
   nbry -=yy;





   QString j = QString::number(nbr);
   QString m = QString::number(nbrm);
    QString y = QString::number(nbry);

    if (nbr>0)
    { msg+=j;
       if (nbr==1)
       {
           msg+=" jour";
       }
       else if (nbr>1)
       {
           msg+=" jours";
       }
    }

    if (nbrm>0)
    {


        if (nbry==0)
         {
            msg+= " et ";
        }
        else
        {
            if (nbr>0)
            msg+=", ";
        }

        msg+=m;
        msg+=" mois";

    }

    if (nbry>0)
    {  if ((nbr>0)||(nbrm>0))
          msg+="et ";

        msg+=y;
        msg+=" ans";

    }





   msg+=" avant la date de réception de la machine "+ r.getNom()+".\n informez nous par un email si vous voulez reporter cette date \nCordialement";
   Smtp* smtp = new Smtp("dreamPastryMail@gmail.com","esprit20", "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


        smtp->sendMail("dreamPastryMail@gmail.com", t.getEmail() , "réparation du machine",msg);
}
void   accueil::mailSent(QString status)
{

    if(status == "Message sent")
      {  QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
         ui->mailing->setText("envoyer");
    }


}







void accueil::on_mailing_clicked()
{
    sendMail();

}

void accueil::on_mail_reparation_clicked()
{
    ui->mail_rep->setCurrentIndex(1);
}

void accueil::on_ajouter_rep_7_clicked()
{
     ui->mail_rep->setCurrentIndex(0);
}

void accueil::on_pdf_reparation_clicked()
{
    ui->mail_rep->setCurrentIndex(2);
}

void accueil::on_ajouter_rep_8_clicked()
{
    ui->mail_rep->setCurrentIndex(0);
}

void accueil::on_mailing_2_clicked()
{
    QString str;
       int id = ui->mail_2->text().toInt();
       QString ids =    QString::number(id);
       reparation t;
       reparateur r;

       t= t.rehcerche(id);
       int id1= t.getId_reparateur();
       r=r.rehcerche(id1);
       QString nom=r.getNom();
       QString prenom=r.getPrenom();
        t.pdf(str,ids,nom,prenom,t);
}
void accueil::make()
{
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot->setBackground(QBrush(gradient));

    // create empty bar chart objects:
    QCPBars *regen = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    //QCPBars *nuclear = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    QCPBars *fossil = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders
    //nuclear->setAntialiased(false);
    fossil->setAntialiased(false);
    regen->setStackingGap(1);
    //nuclear->setStackingGap(1);
    fossil->setStackingGap(1);
    // set names and colors:
    fossil->setName("Prix réparation");
    fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    fossil->setBrush(QColor(111, 9, 176));
    //nuclear->setName("Nuclear");
    //nuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    //nuclear->setBrush(QColor(250, 170, 20));
    regen->setName("Prix Equipement");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));
    // stack bars on top of each other:
    //nuclear->moveAbove(fossil);
    regen->moveAbove(fossil);

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    equipement b;
    int i=b.count();
    int j;
    for (j=0;i>j;j++)
      {ticks << j+1;}
    labels =b.nom_equipement();
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->setRange(0, 8);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot->yAxis->setRange(0, 9.68);
    ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
    ui->customPlot->yAxis->setLabel("Milles dinars tunisien / Equipement en panne");
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setLabelColor(Qt::white);
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> fossilData, nuclearData, regenData;
    /*fossilData  << 0.76*10.5 << 0.83*5.5 << 0.84*5.5 << 0.52*5.8 << 0.89*5.2 << 0.90*4.2 << 0.67*11.2;
    nuclearData << 0.08*10.5 << 0.12*5.5 << 0.12*5.5 << 0.40*5.8 << 0.09*5.2 << 0.00*4.2 << 0.07*11.2;
    regenData   << 0.06*10.5 << 0.05*5.5 << 0.04*5.5 << 0.06*5.8 << 0.02*5.2 << 0.07*4.2 << 0.25*11.2;*/

       reparation a;

    fossilData  = a.prix_reparation();
    nuclearData << 0.08*10.5 << 0.12*5.5 << 0.12*5.5 << 0.40*5.8 << 0.09*5.2 << 0.00*4.2 << 0.07*11.2;
    regenData   =b.prix_equipement();

    fossil->setData(ticks, fossilData);
    //nuclear->setData(ticks, nuclearData);
    regen->setData(ticks, regenData);

    // setup legend:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}


void accueil::on_play_music_clicked()
{
    player->setMedia(QUrl("qrc:/img/img/batchbug-sweet-dreams.mp3")) ;
       player->play();
       qDebug() << player->errorString();
}

void accueil::on_stop_music_clicked()
{
    player->stop();
}

void accueil::on_horizontalSlider_sliderMoved(int position)
{
     player->setVolume(position);
}


void accueil::on_ajouter_rep_9_clicked()
{
    ui->consulter_eq->setCurrentIndex(0);
}
/*
void accueil::on_ajouter_rep_10_clicked()
{
 movie->start();
    QString username,password;
    QString role;
        username=ui->username->text();
        password=ui->password->text();
        QSqlQuery qry;
      if(qry.exec("Select * from employe where EMAIL='"+username+"' and password='"+password+"' "))
        { while(qry.next())
            {role= qry.value(7).toString();
            qDebug()<<role;

         if(role=="Admin")
         {
             processLabel->setHidden(false);
                          ui->ajouter_rep_10->setHidden(true);
                           QTimer::singleShot(3100,processLabel,SLOT(close()));
             QTimer::singleShot(3100,ui->groupBox_21,SLOT(close()));
         }
         else
         {  if(role=="Employee")
            { Dialog *dialog= new Dialog;
             processLabel->setHidden(false);
                          ui->ajouter_rep_10->setHidden(true);
               QTimer::singleShot(3100,this,SLOT(close()));
 QTimer::singleShot(3100,dialog,SLOT(show()));}

 }


          } }
     if ((role!="Employee")&&(role!="Admin"))
      {QMessageBox::information(nullptr, QObject::tr("Email ou mdp incorrecte"),
                  QObject::tr("verifier vos données.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);}
}

void accueil::on_ajouter_rep_11_clicked()
{
    close();
}*/


/*********************************************************************************************************************************************
*******************************************************************************************************************************************
****************************Souhail********************************************************
******************************************************************************************************************************************
****************************************************************************************************************************************** */
void accueil::on_ajouter_event_clicked()
{
    /*QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/pc/Desktop/Gestion Event+Recette/Event+Recette/EVENT/untitled/button-3.mp3"));
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }*/
        evenement t;

            t.setNOM_EVENEMENT(ui->lineEdit_nomevent->text());
            t.setTYPE(ui->lineEdit_typeevent->text());
            t.setBUDGET(ui->lineEdit_budgetevent->text().toFloat());
            t.setLIEU(ui->lineEdit_lieuevent->text());

            t.setNOMBRE_INVITE(ui->lineEdit_nbinviteevent->text().toInt());

            t.ajouter();
        ui->tableView_event->setModel(t.afficher());
        ui->valstack_4->setCurrentIndex(1);
}

void accueil::on_tableView_event_activated(const QModelIndex &index)
{
    QString val=ui->tableView_event->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from evenement where id_evenement='"+val+"' " );
        if(qry.exec())
          {while (qry.next())
         { ui->lineEdit_nomevent_2->setText(qry.value(1).toString());
           ui->lineEdit_typeevent_2->setText(qry.value(2).toString());
           ui->lineEdit_budgetevent_2->setText(qry.value(3).toString());
           ui->lineEdit_lieuevent_2->setText(qry.value(4).toString());
           ui->lineEdit_nbinviteevent_2->setText(qry.value(5).toString());
           ui->lineEdit_idevent_2->setText(qry.value(0).toString());


         }
      }

}

void accueil::on_modifier_event_clicked()
{
    int idevenement=ui->lineEdit_idevent_2->text().toInt();
        QString nomevent=ui->lineEdit_nomevent_2->text();
        QString type=ui->lineEdit_typeevent_2->text();
       float budget=ui->lineEdit_budgetevent_2->text().toFloat();
        QString lieu=ui->lineEdit_lieuevent_2->text();
        int nombreinv=ui->lineEdit_nbinviteevent_2->text().toInt();

        evenement e(idevenement,nomevent,type,budget,lieu,nombreinv);
        bool test=e.modifier();
        if (test)
        {
             ui->tableView_event->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject::tr("Modification evenement"),
                                 QObject::tr("evenement modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

}
}

void accueil::on_supprimer_event_clicked()
{
    evenement e;

    e.setID_EVENEMENT(ui->lineEdit_idevent_2->text().toInt());

          bool test=e.supprimer(e.getID_EVENEMENT());
         if (test)
         {

          QMessageBox::information(nullptr,QObject::tr("Supprimer event"),
                                   QObject::tr("event supprimé.\n"
                                               "Click ok to exit."), QMessageBox::Cancel);

        ui->tableView_event->setModel(e.afficher());

         }
}

void accueil::on_chercherfour_clicked()
{

         //  ui->tableView_event->setModel(f.afficher());
}

void accueil::on_tabWidget_6_currentChanged(int index)
{ evenement e;
    ui->tableView_event->setModel(e.afficher());
}

void accueil::on_tri_nom_clicked()
{
    evenement p;

     QTableView* table=ui->tableView_event;

    p.trie3(table);
}

void accueil::on_tri_budget_clicked()
{
    evenement p;

     QTableView* table=ui->tableView_event;

    p.trie2(table);
}

void accueil::on_nb_tri_clicked()
{
    evenement p;

     QTableView* table=ui->tableView_event;

    p.trie(table);
}

void accueil::on_chercherfour_2_clicked()
{
    QString str;
               str.append("<!DOCTYPE html><html lang='en'><head><style>#ipi-table > thead > tr, #ipi-table > thead > tr > td {font-size: .9em;font-weight: 400;background: #51596a;text-transform: uppercase;color: #ffffff;}#ipi-table > tbody > tr > td {max-height: 200px;vertical-align: middle!important;}</style></head><body><div class='container'><div class='row'><div class='col-md-12'><p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  &nbsp; &nbsp; &nbsp; TABLEAU GESTION EVENEMENTS  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;</p></div></div></div><div class='container'><div class='card' id='TableSorterCard'><div class='row'><div class='col-12'><div><table class='table table tablesorter' id='ipi-table'><thead class='thead-dark'><tr><th>ID_EVENEMENT &nbsp; &nbsp;</th><th class='filter-false'>NOM_EVENEMENT &nbsp; &nbsp;</th><th class='filter-false sorter-false'>TYPE &nbsp; &nbsp;</th><th class='filter-false sorter-false'>BUDGET &nbsp; &nbsp;</th><th class='filter-false sorter-false'>LIEU &nbsp; &nbsp;</th><th class='filter-false sorter-false'>NOMBRE INVITES &nbsp; &nbsp;</th></tr></thead><tbody>");




               QSqlQuery* query=new QSqlQuery();
               query->exec("SELECT * FROM EVENEMENT");

               while(query->next())
               {
               str.append("<tr><td>");
               str.append(query->value(0).toString()) ;
               str.append("</td><td>") ;
               str.append(query->value(1).toString());
               str.append("</td><td>") ;
               str.append(query->value(2).toString());
               str.append("</td><td>") ;
               str.append(query->value(3).toString());
               str.append("</td><td>") ;
               str.append(query->value(4).toString());
               str.append("</td><td>") ;
               str.append(query->value(5).toString());
               str.append("</td></td>");



               }
            str.append("</tbody></table></div></div></div></div></body></html>") ;

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

void accueil::stat ()
{
    QCPStatisticalBox *statistical = new QCPStatisticalBox(ui->customPlot_2->xAxis, ui->customPlot_2->yAxis);
    QBrush boxBrush(QColor(60, 60, 255, 100));
    boxBrush.setStyle(Qt::Dense6Pattern); // make it look oldschool
    statistical->setBrush(boxBrush);
   int i=1;
   QSqlQuery query;
   query.prepare("select NOMBRE_INVITE from EVENEMENT order by ID_EVENEMENT ");
   if (query.exec() ){
   while(query.next() ){

      statistical->addData(i, query.value(0).toInt(), query.value(0).toInt(), query.value(0).toInt(), 450, 450);
      i++;
       }
   }
    // specify data:

   /*  statistical->addData(1, 1.1, 1.9, 2.25, 2.7, 4.2);
    statistical->addData(2, 0.8, 1.6, 2.2, 3.2, 4.9, QVector<double>() << 0.7 << 0.34 << 0.45 << 6.2 << 5.84); // provide some outliers as QVector
    statistical->addData(3, 0.2, 0.7, 1.1, 1.6, 2.9);*/

    // prepare manual x axis labels:
    ui->customPlot_2->xAxis->setSubTicks(false);
    ui->customPlot_2->xAxis->setTickLength(0, 4);
    ui->customPlot_2->xAxis->setTickLabelRotation(20);
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    i=1;
    QSqlQuery query1;
    query1.prepare("select NOM_EVENEMENT from EVENEMENT order by ID_EVENEMENT ");
    if (query1.exec() ){
    while(query1.next() ){

       textTicker->addTick(i, query1.value(0).toString());
        i++;
         }
    }



    ui->customPlot_2->xAxis->setTicker(textTicker);

    // prepare axes:
    ui->customPlot_2->yAxis->setLabel(QString::fromUtf8("nombre de places restant "));
    ui->customPlot_2->rescaleAxes();
    ui->customPlot_2->xAxis->scaleRange(1.7, ui->customPlot_2->xAxis->range().center());
    ui->customPlot_2->yAxis->setRange(0, 500);
    ui->customPlot_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

void accueil::on_statistique_event_clicked()
{
    ui->consulter_eq_2->setCurrentIndex(1);
    stat();

}

void accueil::on_ajouter_rep_11_clicked()
{
    ui->consulter_eq_2->setCurrentIndex(0);
}

void accueil::on_ajouter_recette_clicked()
{
    recette t;

       // t.setId_EVENEMENT(ui->lineEdit->text().toInt());
        t.setnom(ui->lineEdit_nomrecette->text());
        t.setcategorie(ui->lineEdit_categorierecette->text());
        t.setnb_ingredient(ui->lineEdit_nbingredientrecette->text().toInt());
        t.setdescription(ui->descriptionrecette->toPlainText());

        t.setid_produit(ui->lineEdit_idproduitrecette->text().toInt());
        t.ajouter();
    ui->tableView_recette->setModel(t.afficher());
    ui->valstack_5->setCurrentIndex(1);
}

void accueil::on_tableView_recette_activated(const QModelIndex &index)
{
    QString val=ui->tableView_recette->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from recette where ID_RECETTE='"+val+"' " );
        if(qry.exec())
          {while (qry.next())
         { ui->lineEdit_nomrecette_2->setText(qry.value(1).toString());
           ui->lineEdit_categorierecette_2->setText(qry.value(2).toString());
           ui->lineEdit_nbingredientrecette_2->setText(qry.value(3).toString());
           ui->lineEdit_descriptionrecette_2->setText(qry.value(4).toString());


           ui->lineEdit_idproduitrecette_2->setText(qry.value(5).toString());
           ui->lineEdit_idrecette_2->setText(qry.value(0).toString());


         }
      }
}

void accueil::on_modifier_recette_clicked()
{
    recette t;

        t.setID_recette(ui->lineEdit_idrecette_2->text().toInt());
        t.setnom(ui->lineEdit_nomrecette_2->text());
        t.setcategorie(ui->lineEdit_categorierecette_2->text());
        t.setnb_ingredient(ui->lineEdit_nbingredientrecette_2->text().toInt());
        t.setdescription(ui->lineEdit_descriptionrecette_2->text());

        t.setid_produit(ui->lineEdit_idproduitrecette_2->text().toInt());
        t.modifier(t);
    ui->tableView_recette->setModel(t.afficher());
}

void accueil::on_supprimer_recette_clicked()
{
    recette s;
    int id = ui->lineEdit_idrecette_2->text().toInt();
    s.supprimer(id);
    ui->tableView_recette->setModel(s.afficher());
}

void accueil::on_tabWidget_7_currentChanged(int index)
{recette s;
    ui->tableView_recette->setModel(s.afficher());
}

void accueil::on_chercherfour_3_clicked()
{
    recette t;
        QString nomm = ui->cher1_2->text();
           ui->tableView_recette->setModel(t.cherch_four(nomm));
}

void accueil::on_cher1_textChanged(const QString &arg1)
{
    evenement f ;

    f.Recherche(ui);
}

void accueil::on_cher1_2_textChanged(const QString &arg1)
{
    recette t;
    t.Recherche(ui);
}

void accueil::on_ajouter_rep_10_clicked()
{
    ui->valstack_4->setCurrentIndex(0);
}

void accueil::on_ajouter_rep_12_clicked()
{
    ui->valstack_5->setCurrentIndex(0);
}

void accueil::on_ajouter_event_2_clicked()
{  bool ok;
    QMediaPlayer * music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/img/img/zapsplat_multimedia_button_click_005_53866.mp3"));
    music->play();
    Employee E;
           // t.setId_Employee(ui->lineEdit->text().toInt());
            E.setnom(ui->nom->text());
            E.setcin(ui->cin->text());
            E.setprenom(ui->prenom->text());
           E.setage(ui->age->text().toInt());
              E.settelephone(ui->tel->text().toInt());
              E.setevaluation(ui->eval->text().toInt());
              QString datenString=ui->datenais->date().toString("dd.MM.yyyy");
              QString datentreString=ui->dateentr->date().toString("dd.MM.yyyy");
              E.setdatenais(datenString);
              qDebug()<<datenString;
              qDebug()<<datentreString;
              E.setdateentr(datentreString);
              E.setemail(ui->email->text());
              qDebug()<<ui->email->text();
             E.setpassword(ui->mdp->text());
              E.setrole(ui->role->currentText());
             E.setspecialite(ui->specialite->text());
             if (E.verif_mail(ui->email->text())==false)
                   {
                       QMessageBox::information(nullptr, QObject::tr("erreur"),
                                   QObject::tr("email invalide.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

                   }
             else if(E.verif_tel_et_cin(ui->cin->text())==false){

                    QMessageBox::critical(nullptr,QObject::tr("Ajouter un employe"),
                                                     QObject::tr("veuillez saisir correctement votre CIN.\n"
                                                                 "Click Cancel to exit ."),QMessageBox::Cancel);
                         }
             else if(E.verif_tel_et_cin(ui->tel->text())==false){

                    QMessageBox::critical(nullptr,QObject::tr("Ajouter un employe"),
                                                     QObject::tr("veuillez saisir correctement votre Numero.\n"
                                                                 "Click Cancel to exit ."),QMessageBox::Cancel);
                         }
             else if(ui->specialite->text()==""){QMessageBox::critical(nullptr,QObject::tr("Ajouter un employe"),
                                                                       QObject::tr("veuillez saisir votre specialite.\n"
                                                                               "Click Cancel to exit ."),QMessageBox::Cancel);}
           else if(E.verif_nom(ui->nom->text())==false||ui->nom->text()=="")
             {

                             QMessageBox::critical(nullptr,QObject::tr("Ajouter un employe"),
                                                              QObject::tr("veuillez saisir correctement votre nom.\n"
                                                                          "Click Cancel to exit ."),QMessageBox::Cancel);
            }
             else if(E.verif_nom(ui->prenom->text())==false||ui->prenom->text()=="")
             {

                             QMessageBox::critical(nullptr,QObject::tr("Ajouter un employe"),
                                                              QObject::tr("veuillez saisir correctement votre prenom.\n"
                                                                          "Click Cancel to exit ."),QMessageBox::Cancel);
            }
            else
             {ok=E.ajouter(); }

             if (ok == true)
             {
             ui->valstack_6->setCurrentIndex(1);
             }
            ui->tableView_employe->setModel(E.afficher());

}

void accueil::on_tableView_employe_activated(const QModelIndex &index)
{
    QString val=ui->tableView_employe->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from Employe where CIN='"+val+"' or nom='"+val+"' or prenom='"+val+"' or evaluation='"+val+"' or dateentr='"+val+"' or specialite='"+val+"'" );
        if(qry.exec())
          {while (qry.next())
         { ui->cin1->setText(qry.value(0).toString());
                ui->cin2->setText(qry.value(0).toString());
           ui->nom1->setText(qry.value(1).toString());
           ui->prenom1->setText(qry.value(2).toString());
           ui->eval1->setText(qry.value(8).toString());
           qDebug()<<ui->eval1->text();

           ui->dateentr1->setDate(qry.value(10).toDate());
           ui->specialite1->setText(qry.value(11).toString());
           qDebug()<<ui->specialite1->text();

         }
      }
}

void accueil::on_modifier_employe_clicked()
{Employee E;
    QMediaPlayer * music=new QMediaPlayer();
        music->setMedia(QUrl("qrc:/img/img/zapsplat_multimedia_button_click_005_53866.mp3"));
        music->play();

        E.setcin(ui->cin1->text());
        qDebug()<<E.getcin();
        E.setnom(ui->nom1->text());
        E.setprenom(ui->prenom1->text());
        E.setevaluation(ui->eval1->text().toInt());
       E.setdateentr(ui->dateentr1->date().toString("dd.MM.yyyy"));
        E.setspecialite(ui->specialite1->text());


            bool test=E.modifier(E,ui->cin2->text());
            if (test)
            {
                 ui->tableView_employe->setModel(E.afficher());
            QMessageBox::information(nullptr,QObject::tr("Modification Employé"),
                                     QObject::tr("Employé modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            }
}

void accueil::on_supprimer_event_2_clicked()
{
    Employee E1;
    //conge c;
    QMediaPlayer * music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
    music->play();
   // E1.setcin(ui->cin1->text());
         qDebug()<< ui->cin1->text();
          bool test=E1.supprimer(ui->cin1->text());
         // bool tesst=c.supprimer1(E1.getcin());
         if (test)
         {

          QMessageBox::information(nullptr,QObject::tr("Supprimer employé"),
                                   QObject::tr("Employé supprimé.\n"
                                               "Click ok to exit."), QMessageBox::Cancel);
        ui->tableView_employe->setModel(E1.afficher());
         }


}

void accueil::on_rech_textChanged(const QString &arg1)
{
    Employee e;
    e.Recherche(ui);
}

void accueil::on_pdf_employe_clicked()
{
    QString str;

           str.append("<html><head></head><body><center><h1>"+QString("Attestation de travail")+"</h1></center>");
           str.append("<p><font size='+3'>") ;



           QString val=ui->cin1->text();

           QSqlQuery* query=new QSqlQuery();
           query->exec("select * from EMPLOYE where CIN='"+val+"'");

           while(query->next())
           {
           str.append("  <b>"+QString("Je soussignée Mme:Braiki Farah")+"</b>"+ QString(",atteste par la présente que Mr/Mme ")+" ");
           str.append(query->value(1).toString()) ;
           str.append(""+QString("né le <div>&nbsp;</div>")+" ") ;
           str.append(query->value(3).toString());
           str.append(""+QString("Titulaire de la CIN N° ")+"<br> ") ;
           str.append(query->value(0).toString());
           str.append(""+QString("délivrée le ")+" ") ;
           str.append(query->value(10).toString());
           str.append(""+QString("est salarié au sein de notre Micro entreprise de Patisserie Dream Pastry comme Patissier(ère) spécialisée en ")+" ") ;
           str.append(query->value(11).toString());
           str.append("</p></font>") ;
           str.append("<hr>") ;
           str.append("<br>") ;
           str.append("<div></div><img src=':/img/img/signature.jpg' width='200' height='200'>");
           str.append("<center><img src=':/img/img/fff.png' width='500' height='400'></center>");




           }
        str.append("</body></html>") ;

        QPrinter printer ;
        printer.setOrientation(QPrinter::Portrait);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4) ;

        QString path=QFileDialog::getSaveFileName(NULL,"Convertir en PDF","..","PDF(*.pdf)");

        if (path.isEmpty()) return ;
        printer.setOutputFileName(path) ;

        QTextDocument doc;
        doc.setHtml(str) ;
        doc.print(&printer);
}



void accueil::on_trie_currentIndexChanged(const QString &arg1)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    QString mot =ui->trie->currentText();
    if(mot=="CIN")
    q.prepare("select * from employe order by CIN ");
    else if(mot=="AGE")
    q.prepare("select * from employe order by AGE ");
    else
        q.prepare("select * from employe order by NOM ");
    q.exec() ;
    modal->setQuery(q);
    ui->tableView_employe->setModel(modal);
}

void accueil::on_tabWidget_9_currentChanged(int index)
{Employee e;
    ui->tableView_employe->setModel(e.afficher());
}

void accueil::on_supprimer_employe_clicked()
{
    Employee E1;
    conge c;
    QMediaPlayer * music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
    music->play();
    E1.setcin(ui->cin1->text());
          bool test=E1.supprimer(ui->cin1->text());
          bool tesst=c.supprimer1(E1.getcin());
         if (test)
         {

          QMessageBox::information(nullptr,QObject::tr("Supprimer employé"),
                                   QObject::tr("Employé supprimé.\n"
                                               "Click ok to exit."), QMessageBox::Cancel);
        ui->tableView_employe->setModel(E1.afficher());
         }

}

void accueil::on_statistique_event_2_clicked()
{
    QMediaPlayer * music=new QMediaPlayer();
        music->setMedia(QUrl("qrc:/sounds/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
        music->play();
       stati s;
       s.exec();
}

void accueil::on_ajouter_rep_13_clicked()
{
    ui->valstack_6->setCurrentIndex(0);
}

void accueil::on_tabWidget_10_currentChanged(int index)
{ conge c;
    ui->tableView_conge_2->setModel(c.afficher1());
    ui->tableView_conge_3->setModel(c.afficher());
    ui->tableView_conge_4->setModel(c.afficher2());
}

void accueil::on_ajouter_conge_clicked()
{   bool ok;
    conge c;
  QMediaPlayer * music=new QMediaPlayer();
  music->setMedia(QUrl("qrc:/sounds/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
  music->play();
  qDebug()<< music->errorString();
         // t.setId_Employee(ui->lineEdit->text().toInt());
          c.setcin_employe(ui->cinemploye_2->currentText().toInt());
          QString date_depart=ui->datedepart->date().toString("dd.MM.yyyy");
          QString date_retour=ui->dateretour->date().toString("dd.MM.yyyy");
          c.setdate_depart(date_depart);
          c.setdate_retour(date_retour);
       c.setconfirmation(ui->confirmation->currentText());
       c.setnature(ui->nature->currentText());
          ok=c.ajouter();
          if (ok == true)
          {
          ui->valstack_7->setCurrentIndex(1);
          }
          ui->tableView_conge_2->setModel(c.afficher1());
          ui->tableView_conge_3->setModel(c.afficher());
          ui->tableView_conge_4->setModel(c.afficher2());

}

void accueil::on_tabWidget_8_currentChanged(int index)
{
    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery();
    query->prepare("Select CIN from EMPLOYE");
    query->exec();
    modal->setQuery(*query);
    ui->cinemploye_2->setModel(modal);
}

void accueil::on_modifier_recette_2_clicked()
{   conge c;
    QMediaPlayer * music=new QMediaPlayer();
        music->setMedia(QUrl("qrc:/sounds/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
        music->play();
     int id=ui->idconge_2->text().toInt();
            QString dp=ui->date_depart_2->text();
            QString dr=ui->date_retour_2->text();
            QString cf=ui->confirmation_2->currentText();
            QString n=ui->nature_2->currentText();


          conge C(dp,dr,cf,n,id);
            bool test=C.modifier();
            if (test)
            {
                 ui->tableView_conge_2->setModel(c.afficher1());
                 ui->tableView_conge_3->setModel(c.afficher());
                 ui->tableView_conge_4->setModel(c.afficher2());
            QMessageBox::information(nullptr,QObject::tr("Modification Congé"),
                                     QObject::tr("Congé modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            }
}

void accueil::on_tableView_conge_2_activated(const QModelIndex &index)
{
    QString val=ui->tableView_conge_2->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from CONGE where confirmation='"+val+"'" );
        if(qry.exec())
          {while (qry.next())
         { ui->idconge_2->setText(qry.value(5).toString());
                ui->confirmation_2->setCurrentText(qry.value(4).toString());
           ui->nature_2->setCurrentText(qry.value(3).toString());
           ui->date_depart_2->setText(qry.value(1).toString());
           ui->date_retour_2->setText(qry.value(2).toString());

         }
      }
}

void accueil::on_supprimer_recette_2_clicked()
{
    conge c;
    QMediaPlayer * music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
    music->play();
    c.setidconge(ui->idconge_2->text().toInt());

          bool test=c.supprimer(c.getidconge());
         if (test)
         {

          QMessageBox::information(nullptr,QObject::tr("Supprimer congé"),
                                   QObject::tr("congé supprimé.\n"
                                               "Click ok to exit."), QMessageBox::Cancel);
        ui->tableView_conge_2->setModel(c.afficher1());
        ui->tableView_conge_3->setModel(c.afficher());
        ui->tableView_conge_4->setModel(c.afficher2());

         }
}

void accueil::on_mail_employe_clicked()
{
    QMediaPlayer * music=new QMediaPlayer();
        music->setMedia(QUrl("qrc:/sounds/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
        music->play();
    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery();
    query->prepare("Select email from EMPLOYE");
    query->exec();
    modal->setQuery(*query);
    ui->rcpt->setModel(modal);
    ui->consulter_eq_3->setCurrentIndex(2);
}

//mailing
void  accueil::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
void   accueil::sendMail1()
{     ui->anim->setText("Sending...") ;
    Smtp* smtp =new Smtp("farah.braiki@esprit.tn","191JFT4636", "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent1(QString)));

    if( !files.isEmpty() )
        smtp->sendMail1("farah.braiki@esprit.tn", ui->rcpt->currentText() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail1("farah.braiki@esprit.tn", ui->rcpt->currentText() , ui->subject->text(),ui->msg->toPlainText());
}
void   accueil::mailSent1(QString status)
{

    if(status == "Message sent")
      //  QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    {animation = new QPropertyAnimation(ui->anim,"geometry");
        ui->anim->setText("Email sent!") ;
        animation->setDuration(1000);
        animation->setStartValue(ui->anim->geometry());
        animation->setEndValue(QRect(200,200,100,50));
        animation->start();
    }
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}




void accueil::on_ajouter_rep_18_clicked()
{
    ui->consulter_eq_3->setCurrentIndex(0);
}

void accueil::on_ajouter_rep_15_clicked()
{

    ui->valstack_7->setCurrentIndex(0);

}

void accueil::on_listeemployee_activated(const QModelIndex &index)
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("c:/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }


        QString val=ui->listeemployee->model()->data(index).toString();
         QSqlQuery query;
          query.prepare("select *  FROM EMPLOYE WHERE cin='"+val+"'  ");
          if(query.exec())
          {while(query.next())


              { ui->cin1_2->setText(query.value(0).toString());

                   ui->email_2->setText(query.value(4).toString());
                  //ui->lineEdit_4->date(query.value(3).toString());

              }

          }
}

void accueil::on_affichageemployee_clicked()
{
    Employee E ;
       ui->listeemployee->setModel(E.afficher());
}



void accueil::on_evaluerbutton_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("c:/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }


        evaluation e;
        if(e.verif(ui->commentaire->toPlainText())==false||ui->commentaire->toPlainText()=="")
                 {

                                 QMessageBox::critical(nullptr,QObject::tr("Ajouter une evaluation"),
                                                                  QObject::tr("veuillez saisir correctement le commentaire.\n"
                                                                              "Click Cancel to exit ."),QMessageBox::Cancel);
                }

            float perf =0;
                    float fiab = 0;
                   float  autonomie=0;
            //performance
           if(ui->faibleperf1_3->isChecked())
           {perf=perf+1;}
           else if (ui->moyenneperf1_3->isChecked())
           {perf=perf+2;}
           else if (ui->excelperf1_3->isChecked())
           {perf=perf+3;}
           if(ui->faibleperf2_3->isChecked())
           {perf=perf+1;}
           else if (ui->moyenneperf2_3->isChecked())
           {perf=perf+2;}
           else if (ui->excelperf2->isChecked())
           {perf=perf+3;}
           e.setPerformance(perf/2);
           //fiabilité
           if(ui->faiblefiab1_3->isChecked())
           {fiab=fiab+1;}
           else if (ui->moyennefiab2_2->isChecked())
           {fiab=fiab+2;}
           else if (ui->excelfiab1_3->isChecked())
           {fiab=fiab+3;}
           if(ui->faiblefiab2->isChecked())
           {fiab=fiab+1;}
           else if (ui->moyennefiab2->isChecked())
           {fiab=fiab+2;}
           else if (ui->excelfiab2_3->isChecked())
           {fiab=fiab+3;}
           if(ui->faiblefiab3->isChecked())
         {fiab=fiab+1;}
           else if (ui->moyennefiab3->isChecked())
           {fiab=fiab+2;}
           else if (ui->excelfiab3->isChecked())
           {fiab=fiab+3;}
           e.setFiabilite(fiab/3);
           //autonomie
           if(ui->faibleauto1_3->isChecked())
           {autonomie=autonomie+1;}
           else if (ui->moyenneauto1->isChecked())
          {autonomie=autonomie+2;}
           else if (ui->excelauto1_3->isChecked())
          {autonomie=autonomie+3;}
           if(ui->faibleauto2_3->isChecked())
           {autonomie=autonomie+1;}
           else if (ui->moyenneauto2->isChecked())
           {autonomie=autonomie+2;}
           else if (ui->excelauto2_3->isChecked())
          {autonomie=autonomie+3;}
           if(ui->faibleauto3_3->isChecked())
          {autonomie=autonomie+1;}
           else if (ui->moyenneauto3->isChecked())
           {autonomie=autonomie+2;}
           else if (ui->excelauto3_3->isChecked())
           {autonomie=autonomie+3;}


     QDate a= QDate::currentDate();
           e.setAutonomie(autonomie/3);
          e.setDate_evaluation(a.toString());
           e.setCommentaire(ui->commentaire->toPlainText());

      e.setCin_employe(ui->cin1_2->text());
          e.ajouter();
          ui->consultereval->setModel(e.afficher());
          ui->anim->setText("Sending...") ;
         Smtp* smtp = new Smtp("rim.chaouch@esprit.tn", "Rim123456789", "smtp.gmail.com", 465);


     smtp->sendMail("rim.chaouch@esprit.tn", ui->email_2->text() , "evaluation" ,"vous avez été évaluer, vous pouvez consulter votre évaluation.");
     animation=new QPropertyAnimation(ui->anim,"geometry");
             ui->anim_2->setText("Email envoyé!");
               animation->setDuration(6000);
               animation->setStartValue(ui->anim->geometry());
               animation->setEndValue(QRect(300,400,300,20));
               animation->start();
}

void accueil::on_consultereval_activated(const QModelIndex &index)
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("c:/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
    if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }


    QString val=ui->consultereval->model()->data(index).toString();
     QSqlQuery query;
      query.prepare("select *  FROM evaluation WHERE ID_evaluation='"+val+"'  ");
      if(query.exec())
      {while(query.next())


          { ui->ide->setText(query.value(0).toString());
               ui->commentaire_2->setText(query.value(4).toString());
              ui->dateEdit->setText(query.value(5).toString());;

          }

      }
}



void accueil::on_supprimeval_clicked()
{
    evaluation e;
        QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("c:/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }


        e.setId_evaluation(ui->ide->text().toInt());

              bool test=e.supprimer(e.getId_evaluation());

            ui->consultereval->setModel(e.afficher());

}

void accueil::on_editeval_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("c:/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
    if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }




        QString commentaire=ui->commentaire_2->toPlainText();
       int  id=ui->ide->text().toInt();


            QString d=ui->dateEdit->text();

           evaluation e(commentaire,d,id);
            bool test=e.modifier();
  ui->consultereval->setModel(e.afficher());
}

void accueil::on_listeeval_clicked()
{evaluation e;
    ui->consultereval->setModel(e.afficher());

}

void accueil::on_trie_2_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("c:/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
       evaluation e;

          QTableView* table=ui->consultereval;

         e.trie2(table);
}

void accueil::on_trie1_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("c:/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
       evaluation e;

          QTableView* table=ui->consultereval;

         e.trie1(table);
}

void accueil::on_trie2_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("c:/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
       evaluation e;

          QTableView* table=ui->consultereval;

         e.trie(table);
}

void accueil::on_affichagereclam_activated(const QModelIndex &index)
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("c:/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }


        QString val=ui->affichagereclam->model()->data(index).toString();
         QSqlQuery query;
          query.prepare("select *  FROM reclamation WHERE ID_reclamation='"+val+"'  ");
          if(query.exec())
          {while(query.next())


              { ui->id_reclam->setText(query.value(0).toString());


              }

          }
}

void accueil::on_afficher_reclam_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("c:/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }


        reclamation r;
            ui->affichagereclam->setModel(r.afficher());
}

void accueil::on_traiter_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("c:/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
    if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }

    int id=ui->id_reclam->text().toInt();
    reclamation r(id);
    bool test=r.modifieretat();
     ui->affichagereclam->setModel(r.afficher());
}

void accueil::on_recherche_clicked()
{
    QSqlQuery q;
        QSqlQueryModel *modal=new QSqlQueryModel();
        QString mot =ui->rech->text();
       q.prepare("select * from reclamation where (Titre LIKE '%"+mot+"%' or cin_employe LIKE '%"+mot+"%' or date_reclamation like '%"+mot+"%' )");

        q.exec() ;
        modal->setQuery(q);
        ui->affichagereclam->setModel(modal);
}

/*
void accueil::on_stat_clicked()
{
    stati1 s;
    s.exec();

}*/

void accueil::on_affichageemployee_2_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("c:/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
       QString id=ui->cin1_2->text();
        Employee e(id);
        bool test=e.modifiereval();
    ui->affichagereclam->setModel(e.afficher());
}
void accueil::on_todolist_clicked()
{
    CToDoList app;
           app.exec();
}
