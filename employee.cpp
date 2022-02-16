#include "employee.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QVariant>

Employee::Employee()
{
cin="";
age=0;
telephone=0;
evaluation=0;
specialite="";
role="";
email="";
password="";
nom="";
prenom="";
datenais="";
dateentr="";

}
Employee:: Employee(QString c)

{
cin=c;}
Employee:: Employee(QString c,QString n,QString p,QString dn,QString e,QString pas,int t,QString r,int ev,int a,QString d,QString s)

{
cin=c;nom=n;prenom=p;password=pas;datenais=dn;dateentr=d;role=r;specialite=s;email=e;age=a;telephone=t;evaluation=ev;}
Employee:: Employee(QString c,QString n,QString p,int ev,QString d,QString s)

{
cin=c;nom=n;prenom=p;dateentr=d;specialite=s;evaluation=ev;}
Employee::Employee(QString c,QString n,QString p,int a,int t,QString pas)
{cin=c;nom=n;prenom=p;password=pas;age=a;telephone=t;}
QString Employee::getcin(){return cin;};
QString Employee::getnom(){return nom;};
QString Employee::getprenom(){return prenom;};
int Employee::getage(){return age;};
QString Employee::getdatenais(){return datenais;};
QString Employee::getdateentr(){return dateentr;};
QString Employee::getspecialite(){return specialite;};
QString Employee::getemail(){return email;};
QString Employee::getpassword(){return password;};
QString Employee::getrole(){return role;};
int Employee::gettelephone(){return telephone;};
int Employee::getevaluation(){return evaluation;};
void Employee::setnom(QString n){nom=n;};
void Employee::setprenom(QString p){prenom=p;};
void Employee::setcin(QString c){cin=c;};
void Employee::setage(int a){age=a;};
void Employee::settelephone(int a){telephone=a;};
void Employee::setevaluation(int ev){evaluation=ev;};
void Employee::setdatenais(QString dn){datenais=dn;};
void Employee::setdateentr(QString de){dateentr=de;};
void Employee::setemail(QString m){email=m;};
void Employee::setpassword(QString p){password=p;};
void Employee::setrole(QString r){role=r;};
void Employee::setspecialite(QString s){specialite=s;};

bool Employee::ajouter(){

    QSqlQuery query;
    QString scin=cin;
    QString sa=QString::number(age);
    QString stel=QString::number(telephone);
    QString seval=QString::number(evaluation);


    query.prepare("INSERT INTO EMPLOYE(cin,nom,prenom,datenais,email,password,telephone,role,evaluation,age,dateentr,specialite) VALUES (:c,:n,:p,:dn,:em,:pwd,:tel,:r,:eval,:a,:d,:s)");
    query.bindValue(":c",scin);
    query.bindValue(":n",nom);
    query.bindValue(":p",prenom);
    query.bindValue(":dn",datenais);
    query.bindValue(":em",email);
    query.bindValue(":pwd",password);
    query.bindValue(":tel",stel);
    query.bindValue(":r",role);
    query.bindValue(":eval",seval);
    query.bindValue(":a",sa);
    query.bindValue(":d",dateentr);
    query.bindValue(":s",specialite);

    return query.exec();
}

bool Employee::supprimer(QString cinn){
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYE WHERE CIN=:cinn");
    query.bindValue(":cinn",cinn);

    return query.exec();
}

bool Employee::modifier(Employee a,QString cin2)
{
    QSqlQuery query;
    QString scin=cin;
    QString seval=QString::number(evaluation);
    qDebug()<< a.getcin();
  query.prepare("Update EMPLOYE set CIN=:c, NOM=:n, PRENOM=:p,EVALUATION=:eval,DATEENTR=:d,SPECIALITE=:s where CIN=:c2");
  query.bindValue(":c",a.getcin());
  query.bindValue(":c2",cin2);
  query.bindValue(":n",a.getnom());
  query.bindValue(":p",a.getprenom());
  query.bindValue(":eval",a.getevaluation());
  query.bindValue(":d",a.getdateentr());
  query.bindValue(":s",a.getspecialite());
  return query.exec();
}
bool Employee::modifier12()
{
    QSqlQuery query;
    QString scin=cin;
    QString a=QString::number(age);
      QString t=QString::number(telephone);
  query.prepare("Update EMPLOYE set CIN=:c, NOM=:n, PRENOM=:p,PASSWORD=:pas,TELEPHONE=:tel,AGE=:ag where CIN=:c");
  query.bindValue(":c",scin);
  query.bindValue(":n",nom);
  query.bindValue(":p",prenom);
  query.bindValue(":pas",password);
  query.bindValue(":tel",t);
  query.bindValue(":ag",a);
  return query.exec();
}
QSqlQueryModel * Employee::afficher(){


QSqlQueryModel* model   = new QSqlQueryModel();

model->setQuery("select * from EMPLOYE");

model->setHeaderData(0, Qt::Horizontal,QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("DATENAIS"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("EMAIL"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("PASSWORD"));
model->setHeaderData(6, Qt::Horizontal,QObject::tr("TELEPHONE"));
model->setHeaderData(7, Qt::Horizontal,QObject::tr("ROLE"));
model->setHeaderData(8, Qt::Horizontal,QObject::tr("EVALUATION"));
model->setHeaderData(9, Qt::Horizontal,QObject::tr("AGE"));
model->setHeaderData(10,Qt::Horizontal,QObject::tr("DATEENTR"));
model->setHeaderData(11, Qt::Horizontal,QObject::tr("SPECIALITE"));


return model;
}
QSqlQueryModel * Employee::afficher11(){


QSqlQueryModel* model   = new QSqlQueryModel();

model->setQuery("select * from EMPLOYE");

model->setHeaderData(0, Qt::Horizontal,QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("DATENAIS"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("EMAIL"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("PASSWORD"));
model->setHeaderData(6, Qt::Horizontal,QObject::tr("TELEPHONE"));
model->setHeaderData(7, Qt::Horizontal,QObject::tr("ROLE"));
model->setHeaderData(8, Qt::Horizontal,QObject::tr("EVALUATION"));
model->setHeaderData(9, Qt::Horizontal,QObject::tr("AGE"));
model->setHeaderData(10,Qt::Horizontal,QObject::tr("DATEENTR"));
model->setHeaderData(11, Qt::Horizontal,QObject::tr("SPECIALITE"));


return model;
}
bool Employee::verif_tel_et_cin(QString numero)
{
    bool test=true;
    int i;
    if(numero.length()!=8){
       test=false;
       return  test;
    }else{
        for(i=0;i<numero.length();i++){
            if(!((numero[i]>='0')||(numero[i]<='9'))){
                test=false;
                return  test;
        }
        }
    }
 return test;
}
bool Employee::verif_nom(QString ch_nom){
    bool test=true;
    int i;
    if(true)
    {
        for(i=0;i<ch_nom.length();i++){
            if(!(ch_nom[i]=='A')&&!(ch_nom[i]=='B')&&!(ch_nom[i]=='C')&&!(ch_nom[i]=='D')&&!(ch_nom[i]=='E')&&!(ch_nom[i]=='F')&&!(ch_nom[i]=='G')&&!(ch_nom[i]=='H')&&!(ch_nom[i]=='I')&&!(ch_nom[i]=='J')&&!(ch_nom[i]=='K')&&!(ch_nom[i]=='L')&&!(ch_nom[i]=='M')&&!(ch_nom[i]=='N')&&!(ch_nom[i]=='O')&&!(ch_nom[i]=='P')&&!(ch_nom[i]=='Q')&&!(ch_nom[i]=='R')&&!(ch_nom[i]=='S')&&!(ch_nom[i]=='T')&&!(ch_nom[i]=='U')&&!(ch_nom[i]=='V')&&!(ch_nom[i]=='W')&&!(ch_nom[i]=='Y')&&!(ch_nom[i]=='Z')&&!(ch_nom[i]=='a')&&!(ch_nom[i]=='b')&&!(ch_nom[i]=='c')&&!(ch_nom[i]=='d')&&!(ch_nom[i]=='e')&&!(ch_nom[i]=='f')&&!(ch_nom[i]=='g')&&!(ch_nom[i]=='h')&&!(ch_nom[i]=='i')&&!(ch_nom[i]=='j')&&!(ch_nom[i]=='k')&&!(ch_nom[i]=='l')&&!(ch_nom[i]=='m')&&!(ch_nom[i]=='n')&&!(ch_nom[i]=='o')&&!(ch_nom[i]=='p')&&!(ch_nom[i]=='q')&&!(ch_nom[i]=='r')&&!(ch_nom[i]=='s')&&!(ch_nom[i]=='t')&&!(ch_nom[i]=='u')&&!(ch_nom[i]=='v')&&!(ch_nom[i]=='w')&&!(ch_nom[i]=='y')&&!(ch_nom[i]=='z')){
                test=false;
                return  test;
        }
    }
    }
    return  test;
}
bool Employee::verif_mail(QString email){

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

void Employee::Recherche(Ui::accueil *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    QString reference =ui->rech->text();
    q.prepare("select * from employe where (CIN LIKE '%"+reference+"%' or NOM LIKE '%"+reference+"%' or PRENOM LIKE '%"+reference+"%' or DATENAIS LIKE '%"+reference+"%' or EMAIL LIKE '%"+reference+"%' or PASSWORD LIKE '%"+reference+"%'  or TELEPHONE LIKE '%"+reference+"%' or ROLE LIKE '%"+reference+"%' or EVALUATION LIKE '%"+reference+"%' or AGE LIKE '%"+reference+"%' or DATEENTR LIKE '%"+reference+"%' or SPECIALITE LIKE '%"+reference+"%'  )");

    if ( q.exec() )
    { modal->setQuery(q);
        ui->tableView_employe->setModel(modal);}
    else
    {
        qWarning( "can't get value" ); }
}
bool Employee::modifiereval()
{
    QSqlQuery query;
QString id=QString(cin);
  query.prepare("update employe SET EVALUATION='1' where cin=:id");
 query.bindValue(":id",id);

  return query.exec();


}
