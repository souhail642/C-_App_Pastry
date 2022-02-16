#ifndef CHAT_H
#define CHAT_H
#include<QString>
#include<QSqlQueryModel>

class chat
{private:
    int id_msg;
    QString nom,message,temps;
public:
    chat();
    chat(QString,QString,QString);
    bool ajouter();
    int lastIdconge();
};

#endif // CHAT_H
