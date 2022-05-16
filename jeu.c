#include "header.h"

void jeux(t_joueur *michel,SAMPLE *son,int nb_joueur)
{

    int maps[26][12]; //matrice de la map (case de 50 sur 50 pixels)

    int etat_hotbar[9] = {0}; // stock 1 sur le num de la case presse
    int joueurTour;

    BITMAP* skins[4];

    BITMAP* viseur; //utile
    BITMAP* dirt; //utile
    BITMAP* grass; //utile
    BITMAP* lava; //utile

    BITMAP* hotbar1;
    BITMAP* hotbar2;
    BITMAP* hotbar3;
    BITMAP* hotbar4;

    BITMAP* bush; //utile
    BITMAP* bleu; //utile
    BITMAP* rouge; //utile
    BITMAP* orange;
    BITMAP* suivant;
    BITMAP* suivantRouge;

    BITMAP* terrain;
    BITMAP* buffer;

    BITMAP* jaune;

    terrain = create_bitmap(1400, 600);
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    suivant  = load_bitmap("images/suivant2base.bmp",NULL);
    suivantRouge = load_bitmap("images/suivant2.bmp",NULL);

    skins[0] = load_bitmap("images/sorciere.bmp", NULL);
    skins[1] = load_bitmap("images/steve.bmp", NULL);
    skins[2] = load_bitmap("images/squelette.bmp", NULL);
    skins[3] = load_bitmap("images/zombie.bmp", NULL);

    hotbar1 = load_bitmap("images/hotbar1.bmp", NULL);
    hotbar2 = load_bitmap("images/hotbar2.bmp", NULL);
    hotbar3 = load_bitmap("images/hotbar3.bmp", NULL);
    hotbar4 = load_bitmap("images/hotbar4.bmp", NULL);

    viseur = load_bitmap("images/viseur.bmp", NULL);
    jaune = load_bitmap("images/jaune.bmp", NULL);
    rouge = load_bitmap("images/rouge.bmp",NULL);
    bleu = load_bitmap("images/bleu.bmp",NULL);
    orange = load_bitmap("images/orange.bmp",NULL);

    dirt = load_bitmap("images/dirt.bmp", NULL);
    grass = load_bitmap("images/grass.bmp", NULL);
    lava = load_bitmap("images/lava.bmp", NULL);
    bush = load_bitmap("images/herbe.bmp", NULL);


    init_maps(maps);
    init_terrain(terrain, maps, dirt, grass, lava);
    blit(terrain, buffer, 0,0,0,0, terrain->w, terrain->h);


    choixEmplacement(buffer,skins,nb_joueur,michel,maps);

    initialisation(michel,nb_joueur);

    time_t temps = time(NULL);


    while (cliquer_zone(0,0,50, 50)!=1)
    {
        clear_bitmap(buffer);

        // printf("Dur�e : %d seconde \n",(int) (time(NULL)-temps))

        textprintf_ex(buffer,font,1080,630,makecol(0,150,255),makecol(2,2,2),"C'est au joueur %d de JOUER",joueurTour+1);
        textprintf_ex(buffer,font,1140,650,makecol(255,255,0),makecol(2,2,2),"CHRONO: %d ",15-(time(NULL)-temps));

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //////////////////  PROGRAMME QUI PERMET DE COMPTER LE TEMPS ET A CHAQUE 15 SECONDES SA CHANGE DE JOUEUR QUI JOUE ////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        if(time(NULL)-temps > 15 )    // SYTSTEME DE COMPTAGE DE TEMPS
        {
            mise_a_zero(etat_hotbar);
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
                mise_a_zero(etat_hotbar);
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

        if (etat_hotbar[6]==1)
        {
            update_coo(&michel[joueurTour], maps);//si clique sur une case changement des coo du joueur
        }
        if (etat_hotbar[5]==1)
        {
          attaque_CAC(michel,joueurTour,orange,buffer);
        }

        update_bar(michel,joueurTour,buffer, hotbar1,hotbar2, hotbar3,hotbar4);///affichage de la barre des sort dans la map
        affiche_selectSORT(buffer,jaune, etat_hotbar);
        affichagePersonnage(buffer,skins,michel,nb_joueur);    // AFFICHAGE DU JOUEUR


        refresh_objets(buffer, maps, lava, bush, bleu, rouge, jaune, etat_hotbar);//affichage des objets




        //affichage des PV PA PM
        textprintf_ex(buffer,font,50,610,makecol(255,255,255),-1,"PV: ");
        textprintf_ex(buffer,font,50,630,makecol(255,255,255),-1,"PA: ");
        textprintf_ex(buffer,font,50,650,makecol(255,255,255),-1,"PM: ");

        update_jauge(&michel[joueurTour], buffer); //affichage des jauge


        draw_sprite(buffer, viseur, mouse_x-15, mouse_y-5); //affichage de la souris

        blit(buffer, screen, 0,0,0,0, SCREEN_W, SCREEN_H);//affichage final sur l'ecran

    }
    stop_sample(son);
    menuFIN(michel,nb_joueur);
}
