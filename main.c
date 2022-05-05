#include "header.h"

int main()
{
    srand(time(NULL));

    int maps[26][12]; //matrice de la map (case de 50 sur 50 pixels)

    int pv;
    int pa;
    int pm;

    pv = 100;
    pm = 50;
    pa = 25;

    BITMAP* viseur;
    BITMAP* dirt;
    BITMAP* grass;
    BITMAP* lava;
    BITMAP* hotbar;
    BITMAP* croix;
    BITMAP* bush;
    BITMAP* bleu;
    BITMAP* rouge;

    BITMAP* terrain;
    BITMAP* buffer;


    setup_allegro();

    terrain = create_bitmap(1400, 600);
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    rouge = load_bitmap("images/rouge.bmp",NULL);
    bleu = load_bitmap("images/bleu.bmp",NULL);
    bush = load_bitmap("images/herbe.bmp", NULL);
    croix = load_bitmap("images/croix.bmp", NULL);
    viseur = load_bitmap("images/viseur.bmp", NULL);
    dirt = load_bitmap("images/dirt.bmp", NULL);
    grass = load_bitmap("images/grass.bmp", NULL);
    lava = load_bitmap("images/lava.bmp", NULL);
    hotbar = load_bitmap("images/hotbar.bmp", NULL);



    init_maps(maps);
    init_terrain(terrain, maps, dirt, grass, lava);

    while (cliquer_zone(0,0,50, 50)!=1)
    {

        clear_bitmap(buffer);

        blit(terrain, buffer, 0,0,0,0, terrain->w, terrain->h);

        refresh_objets(buffer, maps, lava, bush, croix, bleu, rouge);

        blit(hotbar, buffer, 0,0,250,600,hotbar->w, hotbar->h);

        textprintf_ex(buffer,font,50,610,makecol(255,255,255),-1,"PV: ");
        textprintf_ex(buffer,font,50,630,makecol(255,255,255),-1,"PA: ");
        textprintf_ex(buffer,font,50,650,makecol(255,255,255),-1,"PM: ");

        update_jauge(pv, pm, pa, buffer);

        draw_sprite(buffer, viseur, mouse_x-10, mouse_y);

        blit(buffer, screen, 0,0,0,0, SCREEN_W, SCREEN_H);

    }
    //destroy_font(grand);
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
