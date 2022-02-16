#include "accueil.h"
#include "dialog.h"
#include <QApplication>
#include <QMessageBox>

#include "connexion.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    accueil w;
    Connection c;
    bool test=c.createconnect();
    bool test1;
    test1=test;
    w.show();






    return a.exec();
}
