#include "header.h"

int main()
{
    //BITMAP *joueur;

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
    nbr_joueur();

    return 0;
}

END_OF_MAIN();

/*note :
je sais pas encore comment je vais stocker la position de tout les joueurs,
les infos pour chaque classe et comment vas se presenter le plateau en memoire*/
