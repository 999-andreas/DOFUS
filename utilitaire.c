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
        michel[i].PA = 10;
    }
    michel[0].PV = 100;
    michel[1].PV = 70;
    michel[2].PV = 40;
    michel[3].PV = 10;
}

void mise_a_zero(int etat_hotbar[9])
{
    int i;

    for(i = 0; i<9; i++)
    {
        etat_hotbar[i] = 0;
    }
}
