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
void choixEmplacement(BITMAP * buffer, BITMAP* skins[4], int nb_joueur,t_joueur *michel,int maps[26][12], int joueurTour);

void attaque_CAC(t_joueur *michel, int joueurTour,BITMAP*orange,BITMAP*buffer, int nb_joueur, int* etat);
void attaquePremier_SORT (t_joueur* michel, int joueurTour, int nbjoueur, BITMAP* blanc, BITMAP*buffer);



///Menu.c
void nbr_joueur(SAMPLE* son);
void classeJ(int choixJ,SAMPLE *son);
void jeux(t_joueur *michel,SAMPLE *son,int nb_joueur);
void menuDEBUT();
void menuFIN(t_joueur *michel,int nb_joueur);

///player.c
void controle_points(t_joueur *michel, int nb_joueur );
void attaque_CAC(t_joueur *michel, int joueurTour,BITMAP*orange,BITMAP*buffer, int nb_joueur, int* etat);
void attaquePremier_SORT (t_joueur* michel, int joueurTour, int nbjoueur, BITMAP* blanc, BITMAP*buffer);

//mettre les prototypes des nouveaux fichier ici

//void update_coo2x(int ancienI,int ancienJ,int maps[26][12],t_joueur *michel,int joueurTour,int newI);
void deplacement_case(t_joueur* michel, int maps[26][12],int nb_joueur,int joueurTour, int *bouger);


#endif // HEADER_H_INCLUDED
