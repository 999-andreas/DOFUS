#include "header.h"




void animm(BITMAP * buffer,BITMAP* skins[4],BITMAP* skins_rouge[4], t_joueur* michel, int nb_joueur ) // AFFICHAGE DU JOUEUR EN FONCTION DU NB DE JOUEUR ET DU TOUR PASSER EN PARAMETRE
{
    int i;

    for(i = 0; i<nb_joueur; i++)
    {
        if(michel[i].toucher>0 && michel[i].toucher<10)
        {
            printf("test\n");
            draw_sprite(buffer, skins_rouge[(michel[i].classe)-1], (michel[i].posx), (michel[i].posy));
            michel[i].toucher -=1;
        }

        draw_sprite(buffer, skins[(michel[i].classe)-1], (michel[i].posx+1), (michel[i].posy));
    }
}


void animmms(BITMAP * buffer,BITMAP* skins[4], BITMAP* skins_rouge[4], t_joueur* michel, int nb_joueur) // AFFICHAGE DU JOUEUR EN FONCTION DU NB DE JOUEUR ET DU TOUR PASSER EN PARAMETRE
{
    int i;

    for(i = 0; i<nb_joueur; i++)
    {
        if(michel[i].toucher!=0)
        {
            draw_sprite(buffer, skins_rouge[(michel[i].classe)-1], (michel[i].posx), (michel[i].posy));
            michel[i].toucher -=1;
        }
        draw_sprite(buffer, skins[(michel[i].classe)-1], (michel[i].posx-1), (michel[i].posy));

    }
}
