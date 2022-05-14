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
    int classe;// 1,2,3 ou 4
    int nbJoueur;
               // la classe definit toute les caracteristiques du joueur (sorts et skin)
    int vivant; // 1 ou 0
    int posx;
    int posy;
    BITMAP *sorti;
}t_joueur;

//inclure les nouveaux fichier .c ici



///utilitaire.c
void setup_allegro();
int cliquer_zone(int x, int y, int tx, int ty);


///map.c
void init_maps(int maps[26][12]);
void init_terrain(BITMAP* terrain, int maps[26][12], BITMAP* dirt, BITMAP* grass, BITMAP* lava);
void refresh_objets(BITMAP* buffer, int maps[26][12],BITMAP* lava, BITMAP* bush, BITMAP* bleu, BITMAP* rouge);
void update_jauge(t_joueur *michel, BITMAP* buffer);
void update_coo(t_joueur* michel, int maps[26][12]);
void update_coo2(t_joueur* michel, int maps[26][12],int nb_joueur,BITMAP* buffer, BITMAP* sorciere, BITMAP * steve2, BITMAP * squelette,BITMAP * zombie,BITMAP* terrain);
void update_bar(t_joueur * playeur, int joueurTour,BITMAP * buffer,BITMAP*bar1,BITMAP*bar2,BITMAP*bar3,BITMAP*bar4);
void affiche_selectSORT(BITMAP*buffer, BITMAP*jaune);
void affichagePersonnage(BITMAP * buffer,BITMAP *sorciere ,BITMAP *steve2, BITMAP *squelette, BITMAP* zombie, t_joueur *michel, int nb_joueur);

///Menu.c
void nbr_joueur(SAMPLE* son);
void classeJ(int choixJ,SAMPLE *son);
void jeux(t_joueur *michel,SAMPLE *son,int nb_joueur);
//mettre les prototypes des nouveaux fichier ici

void affichagePersonnage(BITMAP * buffer,BITMAP *steve1,BITMAP *steve2, BITMAP *steve3, BITMAP* steve4, t_joueur *michel,int nb_joueur);
void menuDEBUT();
void menuFIN(t_joueur *michel,int nb_joueur);

void initialisation(t_joueur* michel,int nb_joueur);
void aleatoirePersonnage(t_joueur *michel,int nb_joueur, int maps[26][12]);
void choixEmplacement(BITMAP * buffer, BITMAP* steve1,BITMAP* steve2, BITMAP* steve3, BITMAP* steve4, int nb_joueur,t_joueur *michel,int maps[26][12]);


#endif // HEADER_H_INCLUDED
