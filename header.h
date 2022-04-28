#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

//stockage des donn�es du joueur
typedef struct joueur
{
    int PV; // points de vie
    int PA; // points d'attaque
    int PM; // points de mouvement
    int classe;// 1,2,3 ou 4
               // la classe definit toute les caracteristiques du joueur (sorts et skin)
    int vivant; // 1 ou 0
}t_joueur;

#include "utilitaire.c"
//inclure les nouveaux fichier .c ici

///utilitaire.c
void setup_allegro();


///fichier.c
//mettre les prototypes des nouveaux fichier ici


#endif // HEADER_H_INCLUDED
