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
               // la classe definit toute les caracteristiques du joueur (sorts et skin)
    int vivant; // 1 ou 0
    int posx;
    int posy;
}t_joueur;

//inclure les nouveaux fichier .c ici



///utilitaire.c
void setup_allegro();
int cliquer_zone(int x, int y, int tx, int ty);


///map.c
void init_maps(int maps[26][12]);
void init_terrain(BITMAP* terrain, int maps[26][12], BITMAP* dirt, BITMAP* grass, BITMAP* lava);
void refresh_objets(BITMAP* buffer, int maps[26][12],BITMAP* lava, BITMAP* bush, BITMAP* bleu, BITMAP* rouge);
void update_jauge(int pv, int pm, int pa, BITMAP* buffer);
void update_coo(t_joueur* michel, int maps[26][12]);

///Menu.c
void nbr_joueur(int i);
void classeJ(int choixJ);
void jeux();
void menuDEBUT();
void menuFIN();
//mettre les prototypes des nouveaux fichier ici

///Jeu.c
void jeux();




#endif // HEADER_H_INCLUDED
