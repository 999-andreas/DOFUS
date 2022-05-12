#include "header.h"

void jeux(t_joueur *michel,BITMAP *son, int nb_joueur)
{

    int maps[26][12]; //matrice de la map (case de 50 sur 50 pixels)

    //t_joueur* michel;

    //initialisation des coo du joueur

    michel[0].posx = 550;
    michel[0].posy = 350;

    michel[1].posx = 650;
    michel[1].posy = 350;

    michel[2].posx = 850;
    michel[2].posy = 100;

    michel[3].posx = 450;
    michel[3].posy = 250;

    michel[4].posx = 1000;
    michel[4].posy = 500;

    int pv;
    int pa;
    int pm;

    int joueurTour;

    pv = 100;
    pm = 50;
    pa = 25;


    BITMAP* viseur; //utile
    BITMAP* dirt; //utile
    BITMAP* grass; //utile
    BITMAP* lava; //utile
    BITMAP* hotbar; //utile

    BITMAP* steve1;
    BITMAP* steve2;
    BITMAP* steve3;
    BITMAP* steve4;

    BITMAP* bush; //utile
    BITMAP* bleu; //utile
    BITMAP* rouge; //utile
    BITMAP* suivant;
    BITMAP* suivantRouge;

    BITMAP* terrain;
    BITMAP* buffer;

    terrain = create_bitmap(1400, 600);
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    suivant  = load_bitmap("images/suivant2base.bmp",NULL);
    suivantRouge = load_bitmap("images/suivant2.bmp",NULL);
    rouge = load_bitmap("images/rouge.bmp",NULL);
    bleu = load_bitmap("images/bleu.bmp",NULL);
    bush = load_bitmap("images/herbe.bmp", NULL);

    steve1 = load_bitmap("images/steve.bmp", NULL);
    steve2 = load_bitmap("images/steve.bmp", NULL);
    steve3 = load_bitmap("images/steve.bmp", NULL);
    steve4 = load_bitmap("images/steve.bmp", NULL);

    viseur = load_bitmap("images/viseur.bmp", NULL);
    dirt = load_bitmap("images/dirt.bmp", NULL);
    grass = load_bitmap("images/grass.bmp", NULL);
    lava = load_bitmap("images/lava.bmp", NULL);
    hotbar = load_bitmap("images/hotbar.bmp", NULL);

    init_maps(maps);
    init_terrain(terrain, maps, dirt, grass, lava);

    time_t temps = time(NULL);


    while (cliquer_zone(0,0,50, 50)!=1 /*&& (time(NULL)-temps <=5)*/)
    {
        clear_bitmap(buffer);

        // printf("Durée : %d seconde \n",(int) (time(NULL)-temps))

        textprintf_ex(buffer,font,1140,650,makecol(255,255,0),makecol(2,2,2),"CHRONO: %d",15-(time(NULL)-temps));

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //////////////////  PROGRAMME QUI PERMET DE COMPTER LE TEMPS ET A CHAQUE 15 SECONDES SA CHANGE DE JOUEUR QUI JOUE ////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        if(time(NULL)-temps > 15 )    // SYTSTEME DE COMPTAGE DE TEMPS
        {
            joueurTour++;
            temps = time(NULL);

        }
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////// PROGRAMME QUI PERMET DE FAIRE LE SYSTEME DE TOUR DES JOUEURS QUI JOUENT ///////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        if(joueurTour % nb_joueur == 0) // SYSTEME DE JOUEUR POUR LES TOURS
        {
            joueurTour = 0;

        }
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


        //printf("JoueurTour : %d\n",joueurTour);     // DERTERMINER C'EST A QUI DE JOUER
        //printf("C'est au joueur %d de jouer\n",michel[joueurTour].classe); // MEME CHOSE


        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////  PROGRAMME QUI PERMET D'AFFICHER LE BOUTON SUIVANT ET FAIRE UN CONTOUR EN UNE COULEUR SI ON PASSE PAR DESSUS AVEC LA SOURIS ////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        if( mouse_x > 1060 && mouse_x <1290  && mouse_y > 664 && mouse_y < 686)
        {
            draw_sprite(buffer,suivantRouge,1030,630);
            if(mouse_b&1)
            {
                joueurTour++;
                temps = time(NULL);
                rest(200);
            }
            else
            {
            }
        }
        else
        {
            draw_sprite(buffer,suivant,1030,630);
        }
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



        blit(terrain, buffer, 0,0,0,0, terrain->w, terrain->h);//affichage du decor

        update_coo(&michel[joueurTour], maps);//si clique sur une case changement des coo du joueur

        affichagePersonnage(buffer,steve1,steve2,steve3,steve4,michel,nb_joueur);    // AFFICHAGE DU JOUEUR

        refresh_objets(buffer, maps, lava, bush, bleu, rouge);//affichage des objets

        blit(hotbar, buffer, 0,0,250,600,hotbar->w, hotbar->h);// affichage de la hotbar

        //affichage des PV PA PM
        textprintf_ex(buffer,font,50,610,makecol(255,255,255),-1,"PV: ");
        textprintf_ex(buffer,font,50,630,makecol(255,255,255),-1,"PA: ");
        textprintf_ex(buffer,font,50,650,makecol(255,255,255),-1,"PM: ");;

        update_jauge(pv, pm, pa, buffer); //affichage des jauge


        draw_sprite(buffer, viseur, mouse_x-15, mouse_y-5); //affichage de la souris

        blit(buffer, screen, 0,0,0,0, SCREEN_W, SCREEN_H);//affichage final sur l'ecran

    }
    stop_sample(son);
    menuFIN();
}
