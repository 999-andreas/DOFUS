#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <time.h>

//stockage des donn�es du joueur
typedef struct joueur
{
    int PV; // points de vie
    int PA; // points d'attaque
    int PM; // points de mouvement
    int classe;// 1 = sorciere,2 = steve,3 = squelette ou 4 = zombie
    int nbJoueur;
               // la classe definit toute les caracteristiques du joueur (sorts et skin)
    int vivant; // 1 ou 0
    int posx; // position sur l'axe x
    int posy; // position sur l'axe y
    int toucher; // savvoir il est touché ou non

}t_joueur;

typedef struct sorts
{
    int degat;
    int porte_min;
    int porte_max;
    int proba;
}t_sorts;




///utilitaire.c
void setup_allegro();
int cliquer_zone(int x, int y, int tx, int ty);
void initialisation(t_joueur* michel,int nb_joueur);
void mise_a_zero(int etat_hotbar[9]);
int joueur_la(t_joueur* michel, int nb_joueur, int x, int y);
void destroy_tout(BITMAP* skins[4],BITMAP* skins_rouge[4],BITMAP* viseur,BITMAP* dirt,BITMAP* grass,BITMAP* lava,BITMAP* hotbar1,BITMAP* hotbar2,BITMAP* hotbar3,BITMAP* hotbar4,BITMAP* bush,BITMAP* bleu,BITMAP* rouge,BITMAP* orange,BITMAP* suivant,BITMAP* suivantRouge,BITMAP* terrain,BITMAP* buffer,BITMAP* jaune);



///map.c
void init_maps(int maps[26][12]);
void init_terrain(BITMAP* terrain, int maps[26][12], BITMAP* dirt, BITMAP* grass, BITMAP* lava);

void refresh_objets(BITMAP* buffer, int maps[26][12],BITMAP* lava, BITMAP* bush, BITMAP* bleu, BITMAP* rouge, BITMAP* jaune, int etat_hotbar[9]);


void update_jauge(t_joueur *michel, BITMAP* buffer);
void update_coo(t_joueur* michel, int maps[26][12]);

void update_bar(t_joueur * playeur, int joueurTour,BITMAP * buffer,BITMAP*bar1,BITMAP*bar2,BITMAP*bar3,BITMAP*bar4);
void affiche_selectSORT(BITMAP*buffer, BITMAP*jaune, int etat_hotbar[9]);

void affichagePersonnage(BITMAP * buffer, BITMAP* skins[4], t_joueur *michel, int nb_joueur);
void aleatoirePersonnage(t_joueur *michel,int nb_joueur, int maps[26][12]);
void deplacement_case(t_joueur* michel, int maps[26][12],int nb_joueur,int joueurTour,int *bouger,BITMAP *skins[4],BITMAP *buffer,BITMAP *terrain,BITMAP *hotbar1,BITMAP *hotbar2,BITMAP *hotbar3,BITMAP* hotbar4,BITMAP *jaune,int etat_hotbar[7],BITMAP *lava,BITMAP *bush,BITMAP *bleu, BITMAP *rouge);
void choixEmplacement(BITMAP * buffer, BITMAP* skins[4], int nb_joueur,t_joueur *michel,int maps[26][12], int joueurTour, char nom[4][20]);
void controle_points(t_joueur *michel, int nb_joueur );
///CLASSEMENT DES JOUEURS///
void classementTop(t_joueur *michel, int nb_joueur, int classement[nb_joueur+1],int joueurTour);


///Menu.c
void nbr_joueur(SAMPLE* son);
void classeJ(int choixJ,SAMPLE *son);
void jeux(t_joueur *michel,SAMPLE *son,int nb_joueur);
void menuDEBUT();
void menuFIN(t_joueur *michel,int nb_joueur);


///player.c
void animm(BITMAP * buffer,BITMAP* skins[4],BITMAP* skins_rouge[4], t_joueur* michel, int nb_joueur );
void animmms(BITMAP * buffer,BITMAP* skins[4], BITMAP* skins_rouge[4], t_joueur* michel, int nb_joueur);

///ATTAQUE CORPS A CORPS///
void attaque_CAC(t_joueur *michel, int joueurTour,BITMAP*orange,BITMAP*buffer, int nb_joueur, int* etat, int classement[nb_joueur+1],int *joueurEnvie);

///LE PREMIER SORT DE CHAQUE CLASSE///
void attaquePremier_SORT (t_joueur* michel, int joueurTour, int nbjoueur, BITMAP* blanc, BITMAP*buffer,int* etatPOS, int*etatEPEE,int classement[nbjoueur+1],int *joueurEnvie);
void inverse_pos(t_joueur*michel, int compt, int joueurTour);

///LE DEUXIEME SORT DE CHAQUE CLASSE///
void Deuxieme_Sort (t_joueur* michel, int joueurTour, int nbjoueur, BITMAP* blanc, BITMAP*buffer, int *etatDEG, int *etatPOT_CP, int *etatFLECHE,int *etatPOT_LP, int classement[nbjoueur+1],int *joueurEnvie);

///LE TROISIEME SORT DE CHAQUE CLASSE///
void toisieme_SORT(t_joueur* michel, int joueurTour, int nbjoueur, BITMAP* blanc, BITMAP*buffer,int*etatINV2,int*etatFEU);

void attaqueQuatrieme_SORT(t_joueur *michel, int joueurTour,BITMAP*orange,BITMAP*buffer, int nb_joueur, int* etat,int* etat2,int* etat3,int* etat4, int classement[nb_joueur+1],int *joueurEnvie);
void sort_vol_vie(t_joueur *michel, int joueurTour,BITMAP*orange,BITMAP*buffer, int nb_joueur, int* etat, int classement[nb_joueur+1],int *joueurEnvie);
void attaque_zone(t_joueur *michel, int joueurTour,BITMAP*orange,BITMAP*buffer, int nb_joueur, int* etat, int classement[nb_joueur+1],int *joueurEnvie);
void attaque_poison(t_joueur* michel, int joueurTour, int nbjoueur, BITMAP* blanc, BITMAP*buffer,int* etat);
void attaque_epee_celeste(t_joueur* michel, int joueurTour, int nb_joueur, BITMAP* blanc, BITMAP*buffer,int* etat);

//mettre les prototypes des nouveaux fichier ici

//void update_coo2(int ancienI,int ancienJ,int maps[26][12],t_joueur *michel,int joueurTour,int newI);

#endif // HEADER_H_INCLUDED
