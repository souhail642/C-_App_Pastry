#ifndef ACCUEIL_H
#define ACCUEIL_H
#include "equipement.h"
#include "reparateur.h"
#include "reparation.h"
#include "evenement.h"
#include "recette.h"
#include "employee.h"
#include "stati.h"
#include "conge.h"
#include "dialog.h"
#include <QMainWindow>
#include <QPrinter>
#include "smtp.h"
//#include "smtp1.h"
#include <QMediaPlayer>
#include <QPropertyAnimation>
#include <QSplashScreen>
#include <QTimer>
#include <QMessageBox>
#include <QStyleFactory>
QT_BEGIN_NAMESPACE
namespace Ui { class accueil; }
QT_END_NAMESPACE

class accueil : public QMainWindow
{
    Q_OBJECT

public:
    accueil(QWidget *parent = nullptr);
    ~accueil();


private slots:
void stat();
void make();
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

    void on_toolBox_3_currentChanged(int index);

    void on_toolBox_4_currentChanged(int index);

    void on_modifier_eq_clicked();

    void on_supprimer_eq_clicked();

    void on_modifier_valide_m_clicked();

    void on_tabWidget_2_currentChanged(int index);

    void on_ajouter_eq_clicked();

    void on_ajouter_rep_clicked();

    void on_toolBox_3_2_currentChanged(int index);

    void on_toolBox_4_2_currentChanged(int index);

    void on_tabWidget_3_currentChanged(int index);

    void on_modifier_valide_m_2_clicked();

    void on_modifier_eq_2_clicked();

    void on_supprimer_eq_2_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_ajouter_rep_2_clicked();

    void on_toolBox_3_3_currentChanged(int index);

    void on_toolBox_4_3_currentChanged(int index);

    void on_modifier_eq_3_clicked();

    void on_supprimer_eq_3_clicked();

    void on_modifier_valide_m_3_clicked();

    void on_tabWidget_4_currentChanged(int index);

    void on_ajouter_rep_4_clicked();

    void on_ajouter_rep_5_clicked();

    void on_ajouter_rep_6_clicked();

    void on_modifier_valide_m_4_clicked();
    void sendMail();

        void mailSent(QString);


        void on_mailing_clicked();

        void on_mail_reparation_clicked();

        void on_ajouter_rep_7_clicked();

        void on_pdf_reparation_clicked();

        void on_ajouter_rep_8_clicked();

        void on_mailing_2_clicked();

        void on_play_music_clicked();

        void on_stop_music_clicked();

        void on_horizontalSlider_sliderMoved(int position);

        void on_ajouter_rep_9_clicked();

       // void on_ajouter_rep_10_clicked();

       // void on_ajouter_rep_11_clicked();

        void on_ajouter_event_clicked();

        void on_tableView_event_activated(const QModelIndex &index);

        void on_modifier_event_clicked();

        void on_supprimer_event_clicked();

        void on_chercherfour_clicked();

        void on_tabWidget_6_currentChanged(int index);

        void on_tri_nom_clicked();

        void on_tri_budget_clicked();

        void on_nb_tri_clicked();

        void on_chercherfour_2_clicked();

        void on_statistique_event_clicked();

        void on_ajouter_rep_11_clicked();

        void on_ajouter_recette_clicked();

        void on_tableView_recette_activated(const QModelIndex &index);

        void on_modifier_recette_clicked();

        void on_supprimer_recette_clicked();

        void on_tabWidget_7_currentChanged(int index);

        void on_chercherfour_3_clicked();

        void on_cher1_textChanged(const QString &arg1);

        void on_cher1_2_textChanged(const QString &arg1);

        void on_ajouter_rep_10_clicked();

        void on_ajouter_rep_12_clicked();

        void on_ajouter_event_2_clicked();

        void on_tableView_employe_activated(const QModelIndex &index);

        void on_modifier_employe_clicked();

        void on_supprimer_event_2_clicked();

        void on_rech_textChanged(const QString &arg1);

        void on_pdf_employe_clicked();



        void on_trie_currentIndexChanged(const QString &arg1);

        void on_tabWidget_9_currentChanged(int index);

        void on_supprimer_employe_clicked();

        void on_statistique_event_2_clicked();

        void on_ajouter_rep_13_clicked();

        void on_tabWidget_10_currentChanged(int index);

        void on_ajouter_conge_clicked();

        void on_tabWidget_8_currentChanged(int index);

        void on_modifier_recette_2_clicked();

        void on_tableView_conge_2_activated(const QModelIndex &index);

        void on_supprimer_recette_2_clicked();

        void on_mail_employe_clicked();

        void sendMail1();
        void mailSent1(QString);
        void browse();
        void on_ajouter_rep_18_clicked();

        void on_ajouter_rep_15_clicked();

        void on_listeemployee_activated(const QModelIndex &index);

        void on_affichageemployee_clicked();


        void on_evaluerbutton_clicked();

        void on_consultereval_activated(const QModelIndex &index);


        void on_supprimeval_clicked();

        void on_editeval_clicked();

        void on_listeeval_clicked();

        void on_trie_2_clicked();

        void on_trie1_clicked();

        void on_trie2_clicked();

        void on_affichagereclam_activated(const QModelIndex &index);

        void on_afficher_reclam_clicked();

        void on_traiter_clicked();

        void on_recherche_clicked();



       // void on_stat_clicked();

        void on_affichageemployee_2_clicked();
        void on_todolist_clicked();

private:
    Ui::accueil *ui;

     QPropertyAnimation *animation;
     QPropertyAnimation *animation1;
     int a;
     QMediaPlayer* player;
     QSplashScreen *splash = new QSplashScreen;
     QMovie *movie ;
     QLabel *processLabel;
     QTimer *time;
      QStringList files;
     bool verif_modif(QString,QString,int);


};
#endif // ACCUEIL_H
