#include "header.h"

int main()
{
    int maps[26][14]; //matrice de la map (case de 50 sur 50 pixels)

    BITMAP* croix;
    BITMAP* sol;
    BITMAP* arbre;

    BITMAP* terrain;


    setup_allegro();

    croix = load_bitmap("images/croix.bmp", NULL);

    blit(croix, screen,0,0,0,0,SCREEN_W, SCREEN_H);

    while (!cliquer_zone(0,0,croix->w, croix->h))
    {

    }

    return 0;
}
END_OF_MAIN();

/*note :
je sais pas encore comment je vais stocker la position de tout les joueurs,
les infos pour chaque classe et comment vas se presenter le plateau en memoire*/

//faire une fonction zone cliquer //
//faire une fonction pour faire des matrice aleatoire avec une collection de case dans un fichier texte
//recup ces fichier texte pour les infos de la map et l'affichage
//faire un giga tableau pour les infos de chaque classe
//peut etre les infos de classe dans un fichier txt ?
//pour que le code soit plus lisible
