#include "chat.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QVariant>

chat::chat()
{

}
chat::chat(QString n,QString m,QString t)
{
 message=m;
 nom=n;
 temps=t;
}
bool chat::ajouter(){
int l = lastIdconge();
    QSqlQuery query;
    QString id=QString::number(l);
    query.prepare("INSERT INTO CHAT(nom,message,id_msg,temps) VALUES(:dp,:dr,:ci,:n)");
    query.bindValue(":dp",nom);
    query.bindValue(":dr",message);
    query.bindValue(":ci",id);
    query.bindValue(":n",temps);


    return query.exec();
}
int chat::lastIdconge(){
    int lastIdc=0;
    QSqlQuery qry3 ;
    qry3.prepare("select id_msg from chat");
    if (qry3.exec()){
    while(qry3.next()){
        lastIdc = qry3.value(0).toInt();}
    }
    return lastIdc+1;
}
