#include "header.h"

void jeux(t_joueur *michel,SAMPLE *son,int nb_joueur)
{
    int c=0;
    int classement[nb_joueur+1];
    classement[nb_joueur] = nb_joueur;
    int joueurEnvie = nb_joueur-1;

    int maps[26][12]; //matrice de la map (case de 50 sur 50 pixels)

    int etat_hotbar[7] = {0}; // stock 1 sur le num de la case presses
    int deplacement1 = 0;
    int joueurTour=0; // indique l'indice du jour a qui c'est le tour


    //attaque 1er sort//
    int etat=0; // indique si le joueur a deja attaquer
    int etatPOS=0;
    int etatEPEE=0;

    //attaque 4e sort//
    int etatVOL=0;
    int etatZONE=0;
    int etatPOISON=0;
    int etatCELESTE=0;

    //attaque 2e sort//
    int etatDEG=0;
    int etatPOT_CP=0;
    int etatFLECHE=0;
    int etatPOT_LP=0;

    //attaque 3e sort//
    int etatINV2=0;
    int etatFEU=0;
    int etatPOING=0;

    int premsTour=0;

    char nom[4][20]= {"La Sorciere","Steve", "Squelette", "Zombie"};

    BITMAP* skins[4];
    BITMAP* skins_rouge[4];

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

    skins_rouge[0] = load_bitmap("images/sorciere2.bmp", NULL);
    skins_rouge[1] = load_bitmap("images/steve2.bmp", NULL);
    skins_rouge[2] = load_bitmap("images/squelette2.bmp", NULL);
    skins_rouge[3] = load_bitmap("images/zombie2.bmp", NULL);

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

    //initialisation de la map et du terrain graphique
    init_maps(maps);
    init_terrain(terrain, maps, dirt, grass, lava);
    blit(terrain, buffer, 0,0,0,0, terrain->w, terrain->h);

    //initialisation des elements de la structure joueur
    initialisation(michel,nb_joueur);

    //poser les joueurs sur le terrain
    choixEmplacement(buffer,skins,nb_joueur,michel,maps, joueurTour, nom);


    time_t temps = time(NULL);

    /// boucle principale du jeu ///
    while (cliquer_zone(0,0,50, 50)!=1 && classement[nb_joueur] != 0)
    {
        clear_bitmap(buffer);
        blit(terrain, buffer, 0,0,0,0, terrain->w, terrain->h); //reaffichage du decor


        if(michel[joueurTour].PV <= 0) // pour sauter le tour des morts
        {
            joueurTour++;
        }

        if (classement[nb_joueur] == 1) // on ajoute le gagnant au classement
        {
            classement[0] = michel[joueurTour].classe;
            classement[nb_joueur] = 0;
        }

        if(joueurTour % nb_joueur == 0) // SYSTEME DE TOUR POUR LES JOUEURS
        {
             joueurTour = 0;
        }


        if((time(NULL)-temps > 15 )|| ( mouse_x > 1060 && mouse_x <1290  && mouse_y > 664 && mouse_y < 686 && mouse_b&1))    // passage au tour suivant
        {

            // routine passage de tour
            mise_a_zero(etat_hotbar);
            joueurTour++;
            etat=0;
            etatPOS=0;
            etatEPEE=0;
            etatVOL=0;
            etatZONE=0;
            etatPOISON=0;
            etatCELESTE=0;
            etatDEG=0;
            etatPOT_CP=0;
            etatFLECHE=0;
            etatPOT_LP=0;
            etatINV2=0;
            etatFEU=0;
            etatPOING=0;


            if(joueurTour % nb_joueur == 0) // remise a zero du compteur pour les tours
            {
                joueurTour = 0;
                premsTour = 1; // incrementer au premier tour
            }

            if(premsTour == 1) // si ce n'est pas le premier tour
            {
                michel[joueurTour].PA = michel[joueurTour].PA + 3;
                michel[joueurTour].PM = michel[joueurTour].PM + 1;
            }
            else
            {
            }
            deplacement1 = 0;
            temps = time(NULL);
            rest(200);
        }


        /////////////  PROGRAMME QUI PERMET D'AFFICHER LE BOUTON SUIVANT ET FAIRE UN CONTOUR EN UNE COULEUR SI ON PASSE PAR DESSUS AVEC LA SOURIS ////////
        if( mouse_x > 1060 && mouse_x <1290  && mouse_y > 664 && mouse_y < 686)
        {
            draw_sprite(buffer,suivantRouge,1030,630);
        }
        else
        {
            draw_sprite(buffer,suivant,1030,630);
        }


        blit(terrain, buffer, 0,0,0,0, terrain->w, terrain->h); //reaffichage du decor

        if (etat_hotbar[6]==1)
        {
            deplacement_case(michel,maps,nb_joueur,joueurTour,&deplacement1); //si clique sur une case changement des coo du joueur
        }
        if (etat_hotbar[5]==1)
        {
            attaque_CAC(michel,joueurTour,orange,buffer, nb_joueur, &etat,classement,&joueurEnvie);
        }

        if (etat_hotbar[0]==1 )///sort 1
        {
            attaquePremier_SORT(michel,joueurTour, nb_joueur, orange, buffer, &etatPOS, &etatEPEE);
        }

        if (etat_hotbar[1]==1 )///sort 2
        {
            Deuxieme_Sort(michel,joueurTour, nb_joueur, orange, buffer, &etatDEG, &etatPOT_CP, &etatFLECHE, &etatPOT_LP);
        }

        if (etat_hotbar[2]==1 )///sort 3
        {
           toisieme_SORT(michel,joueurTour, nb_joueur, orange, buffer, &etatINV2, &etatFEU,&etatPOING);
        }

        if(etat_hotbar[3]==1 )///sort 4
        {
            attaqueQuatrieme_SORT(michel,joueurTour,orange,buffer, nb_joueur, &etatVOL,&etatZONE, &etatPOISON, &etatCELESTE, classement,&joueurEnvie);
        }


        if(premsTour == 1)
        {
            textprintf_ex(buffer,font,880,610,makecol(100,255,0),makecol(2,2,2),"%s gagne 3 PA",nom[michel[joueurTour].classe-1]);
            textprintf_ex(buffer,font,880,620,makecol(100,255,0),makecol(2,2,2),"%s gagne 1 PM",nom[michel[joueurTour].classe-1]);
        }


        update_bar(michel,joueurTour,buffer, hotbar1,hotbar2, hotbar3,hotbar4);///affichage de la barre des sort dans la map
        affiche_selectSORT(buffer,jaune, etat_hotbar);

        refresh_objets(buffer, maps, lava, bush, bleu, rouge, jaune, etat_hotbar);//affichage des objets(case surbrillance)

        //affichagePersonnage(buffer,skins, michel,nb_joueur);    // AFFICHAGE DU JOUEUR

        if(c==0)
        {
            animm(buffer,skins,skins_rouge,michel,nb_joueur);
        }
        else if (c==1)
        {
            animmms(buffer,skins,skins_rouge, michel,nb_joueur);

        }

        c=c+1;
        if (c==2)
        {
            c=0;
        }

        controle_points(michel, nb_joueur); // controle des limites de point
        textprintf_ex(buffer,font,1065,630,makecol(0,150,255),makecol(2,2,2),"C'est a %s de JOUER",nom[michel[joueurTour].classe-1]);
        textprintf_ex(buffer,font,1140,650,makecol(255,255,0),makecol(2,2,2),"CHRONO: %d ",15-(time(NULL)-temps));

        //affichage des PV PA PM
        textprintf_ex(buffer,font,50,610,makecol(255,255,255),-1,"PV: %d", michel[joueurTour].PV);
        textprintf_ex(buffer,font,50,630,makecol(255,255,255),-1,"PM: %d", michel[joueurTour].PM);
        textprintf_ex(buffer,font,50,650,makecol(255,255,255),-1,"PA: %d", michel[joueurTour].PA);

        update_jauge(&michel[joueurTour], buffer); //affichage des jauge


        draw_sprite(buffer, viseur, mouse_x-15, mouse_y-5); //affichage de la souris

        blit(buffer, screen, 0,0,0,0, SCREEN_W, SCREEN_H);//affichage final sur l'ecran

    }
    //arret de la musique
    stop_sample(son);

    clear_bitmap(screen);

    //destruction des bitmaps
    destroy_tout(skins,skins_rouge,viseur,dirt,grass,lava, hotbar1, hotbar2,hotbar3, hotbar4, bush,bleu, rouge, orange, suivant,suivantRouge,terrain, buffer,jaune);

    //affichage du classement
    classementTop(michel,nb_joueur,classement,joueurTour);

    //menu de fin
    menuFIN(michel,nb_joueur);
}
