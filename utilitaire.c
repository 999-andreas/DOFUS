#include "header.h"

//initialisation des trucs allegro
void setup_allegro()
{
    allegro_init();
    install_keyboard();
    install_mouse();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1300,700,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    show_mouse(screen);
}

//test si une zone defini est parcourue par la souris ou cliquer
int cliquer_zone(int x, int y, int tx, int ty)
{
    if(mouse_x>=x && mouse_x<=(x+tx) && mouse_y>=y && mouse_y<= (y+ty))
    {
        if(mouse_b & 1)
        {
            return 1; // la zone est cliquer
        }
        return 2; //la zone est seulement parcourue par la souris
    }
    return 0;
}

void initialisation(t_joueur* michel,int nb_joueur)
{
    int i;
    for(i=0; i<nb_joueur; i++)
    {
        michel[i].PV = 100;
        michel[i].PM = 50;
        michel[i].PA = 40;
        michel[i].toucher = 0;
        printf("Joueur %d : %d PV %d PM %d PA\n",i,michel[i].PV,michel[i].PM,michel[i].PA);
    }
}

void mise_a_zero(int etat_hotbar[9])
{
    int i;

    for(i = 0; i<9; i++)
    {
        etat_hotbar[i] = 0;
    }
}

//a enlever
int joueur_la(t_joueur* michel, int nb_joueur, int x, int y)
{
    int i;
    for(i= 0; i<nb_joueur; i++)
    {
        if(michel[i].posx == x && michel[i].posy == y)
        {
            printf("test\n");
            return 1;
        }
    }
    return 0;
}
