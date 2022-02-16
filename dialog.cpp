#include "dialog.h"
#include "ui_dialog.h"
#include"reclamation.h"
#include"evaluation.h"
#include"commentaire.h"
#include<QFontDialog>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{//Dialog::makePlot();
    ui->setupUi(this);
    Connection c;
    bool test=c.createconnect();
    ui->button_profil->setFocus();
    ui->stackedWidget->setCurrentIndex(0);
    ui->tabWidget_10->setCurrentIndex(0);




}

void Dialog::on_button_profil_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->button_client->setEnabled(1);
}

void Dialog::on_button_employe_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget_2->setCurrentIndex(1);
}

void Dialog::on_button_client_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget_2->setCurrentIndex(2);
}

void Dialog::on_button_produit_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget_2->setCurrentIndex(3);
}

void Dialog::on_button_equipement_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->stackedWidget_2->setCurrentIndex(4);


}

void Dialog::on_button_fournisseurs_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(5);
}

void Dialog::on_button_evenement_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->stackedWidget_2->setCurrentIndex(6);

}



void Dialog::on_pushButton_clicked()
{
}







void Dialog::on_button_recette_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    ui->stackedWidget_2->setCurrentIndex(7);
}

void Dialog::on_button_quitter_clicked()
{
    close();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_ajouter_conge_employe_clicked()
{
    conge c;
  QMediaPlayer * music=new QMediaPlayer();
  music->setMedia(QUrl("qrc:/sounds/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
  music->play();

         // t.setId_Employee(ui->lineEdit->text().toInt());
          c.setcin_employe(ui->lineEditc->text().toInt());
          QString date_depart=ui->datedepart_2->date().toString("dd.MM.yyyy");
          QString date_retour=ui->dateretour_2->date().toString("dd.MM.yyyy");
          c.setdate_depart(date_depart);
          c.setdate_retour(date_retour);
       c.setnature(ui->nature_3->currentText());
          c.ajouter11();
          ui->tableView_conge_2->setModel(c.afficher11(c.getcin_employe()));

}

void Dialog::on_tabWidget_10_currentChanged(int index)
{  conge c;
    ui->tableView_conge_2->setModel(c.afficher11(c.getcin_employe()));
}

void Dialog::on_reclamer_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("qrc:/sounds/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }


        reclamation r;

           // t.setId_equipement(ui->lineEdit->text().toInt());
            r.setTitre(ui->titre->text());
            QDate a= QDate::currentDate();


            r.setDate_reclamation(a.toString());
            r.setDescription(ui->desc->toPlainText());



            if(r.verif(ui->desc->toPlainText())==false||ui->desc->toPlainText()=="")
                     {

                                     QMessageBox::critical(nullptr,QObject::tr("Ajouter une reclamation"),
                                                                      QObject::tr("veuillez saisir correctement la  description.\n"
                                                                                  "Click Cancel to exit ."),QMessageBox::Cancel);
                    }
            if(r.verif(ui->titre->text())==false||ui->titre->text()=="")
                     {

                                     QMessageBox::critical(nullptr,QObject::tr("Ajouter une reclamation"),
                                                                      QObject::tr("veuillez saisir correctement le titre.\n"
                                                                                  "Click Cancel to exit ."),QMessageBox::Cancel);
                    }
            r.ajouter();
        ui->afficherreclam->setModel(r.afficher());
}

void Dialog::on_pushButton_6_clicked()//afficher reclam
{     reclamation r;
      ui->afficherreclam->setModel(r.afficher());
}

void Dialog::on_afficherreclam_activated(const QModelIndex &index)
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("qrc:/sounds/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }


        QString val=ui->afficherreclam->model()->data(index).toString();
         QSqlQuery query;
          query.prepare("select *  FROM reclamation WHERE ID_reclamation='"+val+"'  ");
          if(query.exec())
          {while(query.next())


              { ui->titre2->setText(query.value(4).toString());
                   ui->desc2->setText(query.value(3).toString());
                  ui->datereclam->setText(query.value(2).toString());

              }

          }
}

void Dialog::on_supprimreclam_clicked()
{
    reclamation r;
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("qrc:/sounds/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
    if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }


    r.setTitre(ui->titre2->text());

          bool test=r.supprimer(r.getTitre());

        ui->afficherreclam->setModel(r.afficher());



}

void Dialog::on_editreclam_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("qrc:/sounds/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
    if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }


        QString titre=ui->titre2->text();
            QString desc=ui->desc2->toPlainText();

            QString d=ui->datereclam->text();

          reclamation r(titre,desc,d);
            bool test=r.modifier();
  ui->afficherreclam->setModel(r.afficher());


}

void Dialog::on_affichemploye_activated(const QModelIndex &index)
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("c:/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }


        QString val=ui->affichemploye->model()->data(index).toString();
         QSqlQuery query;
          query.prepare("select *  FROM EMPLOYE WHERE cin='"+val+"'  ");
          if(query.exec())
          {while(query.next())


              {

 ui->emp->setText(query.value(0).toString());


              }

          }
}

void Dialog::on_empeval_clicked()
{ Employee e;
      ui->affichemploye->setModel(e.afficher());
}

void Dialog::on_voirevaluation_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("qrc:/sounds/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
    if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }

    QSqlQuery* qury=new QSqlQuery();
    qury->exec("select * from EMPLOYE where CIN='1'");
     QSqlQuery query;
      query.prepare("select *  FROM evaluation WHERE cin_employe='1'  ");
     //int  fiabilite=query.value(3).toInt();
     //int autonomie=query.value(1).toInt();
      //int performance=query.value(2).toInt();
      if(query.exec())
      {while(query.next()and qury->next())


          {

              ui->prenom->setText(qury->value(1).toString());
              ui->nom->setText(qury->value(2).toString());







             if(query.value(3).toInt()<2)

      {ui->fiabilite->setText("*Fiabilité");}

            if(query.value(2).toInt()<2)

      {ui->performance->setText("*Performance");}
             if(query.value(1).toInt()<2)

      {ui->autonomie->setText("*autonomie");}
float a=(query.value(1).toFloat()+query.value(2).toFloat()+query.value(3).toFloat())/3;

if(a==1)
{ui->augmentation->setText("vous aurez un prime de un salaire ");
}
        else  if(a>1 && a<=2)
         {ui->augmentation->setText("vous aurez une augmentation de 10%");
         ui->prime->setText("et un prime de deux salaire");
}


      else if(a>2 && a<=3)
      {ui->augmentation->setText("vous aurez une augmentation de 20%");
      ui->prime->setText("et un prime de trois salaire");}



     qDebug()<<a;


          }}
}

void Dialog::on_pdf_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("qrc:/sounds/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }


        QString str;
                   str.append("<html><head></head><body><center>"+QString("Resultat de l'evaluation "));

                   str.append("</center>") ;


                   QSqlQuery* qury=new QSqlQuery();
     //QString val=ui->cin->text();


                   QSqlQuery* query=new QSqlQuery();
                    //query->exec("select * from EMPLOYE where CIN='"+val+"'");
                    query->exec("select * from EMPLOYE where CIN='1'");
                    qury->exec("select * from evaluation where cin_employe='1'");
                   while(query->next()and qury->next())
                   { float a=(qury->value(1).toFloat()+qury->value(2).toFloat()+qury->value(3).toFloat())/3;
                       QString salaire;
                       if(a==1)
                       {
                           salaire="un";

                           }
                               else  if(a>1 && a<=2)
                                {salaire="deux";
                     }


                             else if(a>2 && a<=3)
                             {salaire="trois";
    }

    str.append("<p>"+QString("Bravo chér(e) ")) ;
                       str.append(query->value(1).toString());
                       str.append("   ");
                       str.append(query->value(2).toString());
    str.append("  vous aurez un prime de  ");
    str.append(salaire);
    str.append("  salaires ""</p>");
    str.append("<p>""Merci de contacter le service financier""</p>");
    str.append(" --------------------------------------------------------------------------------------------------------------");
    str.append("<filedset>");
    str.append("<p>""Voici votre chéque ""</p>");
    str.append("<p>""  chéque personel                                                         Num:____" "</p>");
    str.append("<p>"" payer à l 'ordre de __________Evaluation___________""</p>");
    str.append("<p>" "Montant_________________");
    str.append(salaire);
    str.append("  _______salaires""</p>");
    str.append("<p>""à___");
    str.append(query->value(1).toString());
    str.append("   ");
    str.append(query->value(2).toString());
    str.append("_______Date___________");
    str.append("______________09/04/2021_____________""</p>");
    str.append("                                                                                                  " " Signature");
    str.append("</filedset>");
















                   }

                str.append("</body></html>") ;

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





                QPrinter *p=new QPrinter();
                QPrintDialog dialog(p,this);
                if(dialog.exec()== QDialog::Rejected)
                {
                    return;
                }


}
/*
void Dialog::makePlot()
{ // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
   ui->customPlot->setBackground(QBrush(gradient));
    // create empty bar chart objects:
    QCPBars *fossil = new QCPBars(ui->customPlot->xAxis,ui->customPlot->yAxis);
    //fossil->setAntialiased(false);
    //regen->setStackingGap(1);
   // nuclear->setStackingGap(1);
    //fossil->setStackingGap(1);
    // set names and colors:
   // fossil->setName("");
    fossil->setPen(QPen(QColor(250, 170, 20).lighter(150)));;
    fossil->setBrush(QColor(250, 170, 20));
    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 ;
    labels << "Performance" << "Discipline" << "Autonomie" ;
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
   ui->customPlot->yAxis->setRange(0, 3);
   ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
   ui->customPlot->yAxis->setLabel("evaluation annuelle ");
   ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
   ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
   ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
   ui->customPlot->yAxis->grid()->setSubGridVisible(true);
   ui->customPlot->yAxis->setTickLabelColor(Qt::white);
   ui->customPlot->yAxis->setLabelColor(Qt::white);
   ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
   ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
evaluation e;

QSqlQuery query;
 query.prepare("select *  FROM evaluation WHERE cin_employe='1'  ");

 if(query.exec())
 {while(query.next())
     {
        int perf=query.value(2).toInt();
         int aut=query.value(1).toInt();
         int fiab=query.value(3).toInt();

    // Add data:
    QVector<double> fossilData;
    fossilData  << perf << fiab  << aut ;
   // nuclearData << 0.08*10.5 << 0.12*5.5 << 0.12*5.5 << 0.40*5.8 << 0.09*5.2 << 0.00*4.2 << 0.07*11.2;
    //regenData   << 0.06*10.5 << 0.05*5.5 << 0.04*5.5 << 0.06*5.8 << 0.02*5.2 << 0.07*4.2 << 0.25*11.2;
    fossil->setData(ticks, fossilData);
   // nuclear->setData(ticks, nuclearData);
    //regen->setData(ticks, regenData);
}}
    // setup legend:
   ui->customPlot->legend->setVisible(true);
   ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
   ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
   ui->customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
   ui->customPlot->legend->setFont(legendFont);
   ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);}*/


void Dialog::on_afficherlesavis_clicked()
{
    commentaire c;
      ui->listecomm->setModel(c.afficher());
}

void Dialog::on_listecomm_activated(const QModelIndex &index)
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("qrc:/sounds/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }


        QString val=ui->listecomm->model()->data(index).toString();
         QSqlQuery query;
          query.prepare("select *  FROM commentaire WHERE id='"+val+"'  ");
          if(query.exec())
          {while(query.next())


              { ui->emp->setText(query.value(2).toString());

                  ui->comm->setText(query.value(1).toString());
ui->lineEditid->setText(query.value(0).toString());
              }

          }

}

void Dialog::on_ajoucomm_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("qrc:/sounds/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }


       commentaire c;

           c.setId(ui->lineEditid->text().toInt());

            c.setDescription(ui->comm->toPlainText());
            c.setCin_employe(ui->emp->text());



            if(c.verif(ui->desc->toPlainText())==false||ui->comm->toPlainText()=="")
                     {

                                     QMessageBox::critical(nullptr,QObject::tr("Ajouter une reclamation"),
                                                                      QObject::tr("veuillez saisir correctement la  description.\n"
                                                                                  "Click Cancel to exit ."),QMessageBox::Cancel);
                    }

            c.ajouter();
        ui->listecomm->setModel(c.afficher());
}

void Dialog::on_editcomm_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("qrc:/sounds/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
    if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }

    QString desc=ui->comm->toPlainText();
    int id=ui->lineEditid->text().toInt();



  commentaire c(desc,id);
    bool test=c.modifier();
ui->listecomm->setModel(c.afficher());
qDebug()<<desc;
}

void Dialog::on_suppcomm_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("qrc:/sounds/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
    commentaire c;
    c.setId(ui->lineEditid->text().toInt());

          bool test=c.supprimer(c.getId());

        ui->listecomm->setModel(c.afficher());
}
/******************/
void Dialog::on_sendchat_clicked()
{
    QMediaPlayer * music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/sound/zapsplat_multimedia_button_click_005_53866.mp3"));
    music->play();
    QString nom=ui->name->text();
    QString msg=ui->msg_2->toPlainText();
    QDateTime d=d.currentDateTime();
     QString temps=d.toString("dd.MM.yyyy.hh:mm");
  chat c(nom,msg,temps);
  c.ajouter();
    ui->textBrowser->clear();
  QSqlQuery query;
  query.prepare("SELECT * FROM CHAT");
  QString l;
  if (query.exec()){
  while(query.next()){
   l="<"+query.value(0).toString()+"> "+query.value(1).toString()+"                       "+query.value(3).toString();
   ui->textBrowser->append(l);
   qDebug()<<l;}}

}

void Dialog::on_pushButton_3_clicked()
{
    ui->textBrowser->clear();
    QSqlQuery query;
    query.prepare("SELECT * FROM CHAT");
    QString l;
    if (query.exec()){
    while(query.next()){
     l="<"+query.value(0).toString()+"> "+query.value(1).toString()+"                      "+query.value(3).toString();
     ui->textBrowser->append(l);
     qDebug()<<l;
    }
    }

}

void Dialog::on_font_2_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Times", 12), this);
    if (ok) {
        ui->label_2->setFont(font);
        ui->label->setFont(font);
        ui->label_14->setFont(font);
        ui->label_15->setFont(font);
        ui->label_18->setFont(font);
        ui->label_19->setFont(font);
        ui->label_20->setFont(font);
        ui->label_16->setFont(font);
        ui->label_13->setFont(font);
        ui->label_12->setFont(font);

        ui->nom->setFont(font);
        ui->prenom->setFont(font);
        ui->prime->setFont(font);
        ui->augmentation->setFont(font);
        ui->performance->setFont(font);

        ui->autonomie->setFont(font);
        ui->fiabilite->setFont(font);





        ui->label_nomR_50->setFont(font);
        ui->label_nomR_51->setFont(font);
        ui->label_nomR_52->setFont(font);
          ui->label_nomR_53->setFont(font);
            ui->label_49->setFont(font);

              ui->label_50->setFont(font);
                ui->label_AjEq_22->setFont(font);
                  ui->label_AjEq_24->setFont(font);
                    ui->label_AjEq_26->setFont(font);
                      ui->label_AjEq_28->setFont(font);
                        ui->label_AjEq_29->setFont(font);
                          ui->label_AjEq_30->setFont(font);
    } else {
       return;
    }
}
