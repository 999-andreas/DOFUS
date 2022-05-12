#ifndef SOUS_PROGRAMME_H_INCLUDED
#define SOUS_PROGRAMME_H_INCLUDED
#endif // SOUS_PROGRAMME_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <time.h>

void menuDEBUT();
void menuFIN();
void affichagePersonnage(BITMAP * buffer,BITMAP *steve1 ,BITMAP *steve2, BITMAP *steve3, BITMAP* steve4, t_joueur *michel,int joueurTour);
void animstate(BITMAP * buffer,BITMAP *steve1,BITMAP *steve2, BITMAP *steve3, BITMAP* steve4, t_joueur *michel,int joueurTour);
