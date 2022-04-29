#include "header.h"

int main()
{
    BITMAP *joueur;
    allegro_init();
    install_keyboard();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1300,700,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }


    joueur=load_bitmap("joueur.bmp",NULL);


    if (!joueur)// Vérification que l'image est bien chargée
    {
        allegro_message("pas pu trouver/charger mon_image.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }


    blit(joueur,screen,0,0,0,0 , joueur->w, joueur->h);// Affichage de l'image sur l'écran

    // Boucle interactive
    while (!key[KEY_ESC])
    {
        //if (key[KEY_SPACE])
          //  blit(image,screen,0,0, rand()%(SCREEN_W-image->w), rand()%(SCREEN_H-image->h), image->w, image->h);
    }

    return 0;
}

END_OF_MAIN();

/*note :
je sais pas encore comment je vais stocker la position de tout les joueurs,
les infos pour chaque classe et comment vas se presenter le plateau en memoire*/
