#include "header.h"

void jeux()
{
    int maps[26][12]; //matrice de la map (case de 50 sur 50 pixels)

    t_joueur* michel;

    //initialisation des coo du joueur
    michel->posx = 650;
    michel->posy = 350;

    int pv;
    int pa;
    int pm;

    pv = 100;
    pm = 50;
    pa = 25;


    BITMAP* viseur; //utile
    BITMAP* dirt; //utile
    BITMAP* grass; //utile
    BITMAP* lava; //utile
    BITMAP* hotbar; //utile
    BITMAP* steve;
    BITMAP* bush; //utile
    BITMAP* bleu; //utile
    BITMAP* rouge; //utile

    BITMAP* terrain;
    BITMAP* buffer;

    terrain = create_bitmap(1400, 600);
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    rouge = load_bitmap("images/rouge.bmp",NULL);
    bleu = load_bitmap("images/bleu.bmp",NULL);
    bush = load_bitmap("images/herbe.bmp", NULL);
    steve = load_bitmap("images/steve.bmp", NULL);
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

        blit(terrain, buffer, 0,0,0,0, terrain->w, terrain->h);//affichage du decor

        update_coo(michel, maps);//si clique sur une case changement des coo du joueur

        draw_sprite(buffer, steve, (michel->posx), (michel->posy));// affichage du joueur

        refresh_objets(buffer, maps, lava, bush, bleu, rouge);//affichage des objets

        blit(hotbar, buffer, 0,0,250,600,hotbar->w, hotbar->h);// affichage de la hotbar

        //affichage des PV PA PM
        textprintf_ex(buffer,font,50,610,makecol(255,255,255),-1,"PV: ");
        textprintf_ex(buffer,font,50,630,makecol(255,255,255),-1,"PA: ");
        textprintf_ex(buffer,font,50,650,makecol(255,255,255),-1,"PM: ");

        update_jauge(pv, pm, pa, buffer); //affichage des jauge

        draw_sprite(buffer, viseur, mouse_x-10, mouse_y); //affichage de la souris

        blit(buffer, screen, 0,0,0,0, SCREEN_W, SCREEN_H);//affichage final sur l'ecran

    }
}
