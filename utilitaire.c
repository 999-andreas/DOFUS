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
        michel[i].PA = 20;
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

void destroy_tout(BITMAP* skins[4],BITMAP* skins_rouge[4],BITMAP* viseur,BITMAP* dirt,BITMAP* grass,BITMAP* lava,BITMAP* hotbar1,BITMAP* hotbar2,BITMAP* hotbar3,BITMAP* hotbar4,BITMAP* bush,BITMAP* bleu,BITMAP* rouge,BITMAP* orange,BITMAP* suivant,BITMAP* suivantRouge,BITMAP* terrain,BITMAP* buffer,BITMAP* jaune)
{

    destroy_bitmap(skins[0]);
    destroy_bitmap(skins[1]);
    destroy_bitmap(skins[2]);
    destroy_bitmap(skins[3]);
    destroy_bitmap(skins_rouge[0]);
    destroy_bitmap(skins_rouge[1]);
    destroy_bitmap(skins_rouge[2]);
    destroy_bitmap(skins_rouge[3]);
    destroy_bitmap(viseur);
    destroy_bitmap(dirt);
    destroy_bitmap(grass);
    destroy_bitmap(lava);
    destroy_bitmap(hotbar1);
    destroy_bitmap(hotbar2);
    destroy_bitmap(hotbar3);
    destroy_bitmap(hotbar4);
    destroy_bitmap(bush);
    destroy_bitmap(bleu);
    destroy_bitmap(rouge);
    destroy_bitmap(orange);
    destroy_bitmap(suivant);
    destroy_bitmap(suivantRouge);
    destroy_bitmap(terrain);
    destroy_bitmap(jaune);

}
