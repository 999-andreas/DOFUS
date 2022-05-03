#include "header.h"

int main()
{
    srand(time(NULL));

    int maps[26][14]; //matrice de la map (case de 50 sur 50 pixels)

    BITMAP* croix;
    BITMAP* dirt;
    BITMAP* grass;
    BITMAP* arbre;
    BITMAP* hotbar;

    BITMAP* terrain;


    setup_allegro();

    terrain = create_bitmap(SCREEN_W, SCREEN_H);
    croix = load_bitmap("images/croix.bmp", NULL);
    dirt = load_bitmap("images/dirt.bmp", NULL);
    grass = load_bitmap("images/grass.bmp", NULL);
    arbre = load_bitmap("images/arbre3.bmp", NULL);
    hotbar = load_bitmap("images/hotbar.bmp", NULL);



    init_maps(maps);
    init_terrain(terrain, maps, dirt, grass, arbre);
    blit(terrain, screen, 0,0,0,0, SCREEN_W, SCREEN_H);

    refresh_objets(terrain, maps, arbre);
    blit(terrain, screen, 0,0,0,0, SCREEN_W, SCREEN_H);

    blit(hotbar, screen,0,0,250,600, hotbar->w, hotbar->h);
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
