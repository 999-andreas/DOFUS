#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

//stockage des données du joueur
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


///map.c
lecture_fichier(int maps[24][14]);

#endif // HEADER_H_INCLUDED
