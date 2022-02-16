#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "equipement.h"
#include "reparateur.h"
#include "reparation.h"
#include "evenement.h"
#include "recette.h"
#include "employee.h"
#include "stati.h"
#include "conge.h"
#include "connexion.h"
#include <QPrinter>
#include "smtp.h"
//#include "smtp1.h"
#include <QMediaPlayer>
#include <QPropertyAnimation>
#include <QSplashScreen>
#include <QTimer>
#include <QMessageBox>
#include <QStyleFactory>
#include"chat.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:


    void on_button_profil_clicked();

    void on_button_employe_clicked();

    void on_button_equipement_clicked();

    void on_pushButton_clicked();

    void on_button_client_clicked();

    void on_button_produit_clicked();

    void on_button_fournisseurs_clicked();

    void on_button_evenement_clicked();

    void on_button_recette_clicked();

    void on_button_quitter_clicked();

    void on_ajouter_conge_employe_clicked();

    void on_tabWidget_10_currentChanged(int index);

    void on_reclamer_clicked();

    void on_pushButton_6_clicked();

    void on_afficherreclam_activated(const QModelIndex &index);

    void on_supprimreclam_clicked();

    void on_editreclam_clicked();

    void on_affichemploye_activated(const QModelIndex &index);

    void on_empeval_clicked();

    void on_voirevaluation_clicked();

    void on_pdf_clicked();
 // void makePlot();
    void on_afficherlesavis_clicked();

    void on_listecomm_activated(const QModelIndex &index);

    void on_ajoucomm_clicked();

    void on_editcomm_clicked();

    void on_suppcomm_clicked();
    /***************/
    void on_sendchat_clicked();

    void on_pushButton_3_clicked();


    void on_font_2_clicked();

private:
    Ui::Dialog *ui;
    int a;
    QTimer *time;
};

#endif // DIALOG_H
