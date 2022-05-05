#include "header.h"

int main()
{
    srand(time(NULL));

    int maps[26][12]; //matrice de la map (case de 50 sur 50 pixels)

    BITMAP* viseur;
    BITMAP* dirt;
    BITMAP* grass;
    BITMAP* arbre;
    BITMAP* hotbar;

    BITMAP* terrain;
    BITMAP* buffer;


    setup_allegro();

    terrain = create_bitmap(1400, 600);
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    viseur = load_bitmap("images/viseur.bmp", NULL);
    dirt = load_bitmap("images/dirt.bmp", NULL);
    grass = load_bitmap("images/grass.bmp", NULL);
    arbre = load_bitmap("images/arbre3.bmp", NULL);
    hotbar = load_bitmap("images/hotbar.bmp", NULL);



    init_maps(maps);
    init_terrain(terrain, maps, dirt, grass, arbre);

    while (!cliquer_zone(0,0,50, 50))
    {

        clear_bitmap(buffer);

        blit(terrain, buffer, 0,0,0,0, terrain->w, terrain->h);

        refresh_objets(buffer, maps, arbre);

        blit(hotbar, buffer, 0,0,250,600,hotbar->w, hotbar->h);

        textprintf_ex(buffer,font,50,610,makecol(255,255,255),-1,"PV: %d", 15);
        textprintf_ex(buffer,font,50,630,makecol(255,255,255),-1,"PA: %d", 14);
        textprintf_ex(buffer,font,50,650,makecol(255,255,255),-1,"PM: %d", 13);

        draw_sprite(buffer, viseur, mouse_x-10, mouse_y);

        blit(buffer, screen, 0,0,0,0, SCREEN_W, SCREEN_H);

    }

    return 0;
}
END_OF_MAIN();

/*note :
je sais pas encore comment je vais stocker la position de tout les joueurs,
les infos pour chaque classe et comment vas se presenter le plateau en memoire*/

//faire une fonction zone cliquer //
//faire une fonction pour faire des matrice aleatoire avec une collection de case dans un fichier texte //
//recup ces fichier texte pour les infos de la map et l'affichage //
//faire un giga tableau pour les infos de chaque classe
//peut etre les infos de classe dans un fichier txt ?
//pour que le code soit plus lisible
//faire l'inteface des PV PM PA
//peut etre des jauge ? ca peut etre cool
