#include "header.h"

//initialise les valeur de chaque case du terrain
void init_maps(int maps[26][12])
{
    int i = 0;
    int j = 0;
    int proba;

    for (i = 0 ; i <26 ; i++)
    {
        for (j = 0 ; j<12 ; j++)
        {
            proba = rand()%100;

            if(proba<20 && i>1 && i<24 && j>1 )
                maps[i][j] = 3;

            else if(proba <23 && i>1 && i<24 && j>1 )
                maps[i][j] = 2;

            else
                maps[i][j] = rand()%2;
        }
    }
    for(i=0; i<26; i++)
    {
        maps[i][0] = 2;
    }
}

//initialise le terrain en debut de partie
void init_terrain(BITMAP* terrain, int maps[26][12], BITMAP* dirt, BITMAP* grass, BITMAP* lava)
{
    int i = 0;
    int j = 0;

    for (i = 0 ; i <26 ; i++)
    {
        blit(lava, terrain,0,0,(50*i),(0), 50, 50 );
        for (j = 0 ; j<12 ; j++)
        {

            if(maps[i][j] == 0) //dirt
            {
                blit(dirt, terrain,0,0,(50*i),(50*j), 50, 50 );
            }
            else if(maps[i][j] == 1 || maps[i][j] == 3) //sol herbe ou haute herbe
            {
                blit(grass, terrain,0,0,(50*i),(50*j), 50, 50 );
            }
            else if(maps[i][j] == 2) //lave
            {
                blit(lava, terrain,0,0,(50*i),(50*j), 50, 50 );
            }
        }
    }
}

//mise a jour des coo
void update_coo(t_joueur* michel, int maps[26][12])
{

    int i = 0;
    int j = 0;

    for (i = 0 ; i <26 ; i++)
    {
        for (j = 0 ; j<12 ; j++)
        {
            if(cliquer_zone((i*50), (j*50), 50,50) == 1)
            {
                if(maps[i][j] == 2)
                {}
                else
                {
                    michel->posx = i*50;
                    michel->posy = (j*50)-50;
                }

            }
        }
    }
}

//affichage des objets sur la map c�d les element qui sont par dessus tout le reste
void refresh_objets(BITMAP* buffer, int maps[26][12],BITMAP* lava, BITMAP* bush, BITMAP* bleu, BITMAP* rouge, BITMAP* jaune, int etat_hotbar[7])
{
    int i = 0;
    int j = 0;

    for (i = 0 ; i <26 ; i++)
    {
        for (j = 0 ; j<12 ; j++)
        {
            if(maps[i][j] == 3)
            {
                //draw_sprite(buffer, bush, (i*50), (j*50));
            }

            if(cliquer_zone((i*50), (j*50), 50,50) == 2)
            {
                if(maps[i][j] == 2)
                    blit(rouge, buffer,0,0,(50*i),(50*j), 50, 50 );
                else
                    blit(bleu, buffer,0,0,(50*i),(50*j), 50, 50 );

            }
        }
    }

    for(i = 0; i<7; i++)
    {
        if(etat_hotbar[i])
        {
            draw_sprite(buffer,jaune,255+(i*88),605);
        }
    }

}

//mise a jour des jauge de PV PM PA
void update_jauge(t_joueur *michel, BITMAP* buffer)
{
    int i;

    for(i = 0; i<(michel->PV); i++)
    {

        putpixel(buffer, i+110, 610, makecol(52,201,36));
        putpixel(buffer, i+110, 611, makecol(52,201,36));
        putpixel(buffer, i+110, 612, makecol(52,201,36));
        putpixel(buffer, i+110, 613, makecol(52,201,36));
        putpixel(buffer, i+110, 614, makecol(52,201,36));
    }

    for(i = 0; i<(michel->PM); i++)
    {

        putpixel(buffer, i+110, 630, makecol(52,201,36));
        putpixel(buffer, i+110, 631, makecol(52,201,36));
        putpixel(buffer, i+110, 632, makecol(52,201,36));
        putpixel(buffer, i+110, 633, makecol(52,201,36));
        putpixel(buffer, i+110, 634, makecol(52,201,36));
    }

    for(i = 0; i<(michel->PA); i++)
    {

        putpixel(buffer, i+110, 650, makecol(52,201,36));
        putpixel(buffer, i+110, 651, makecol(52,201,36));
        putpixel(buffer, i+110, 652, makecol(52,201,36));
        putpixel(buffer, i+110, 653, makecol(52,201,36));
        putpixel(buffer, i+110, 654, makecol(52,201,36));
    }
}

void affichagePersonnage(BITMAP * buffer, BITMAP* skins[4], t_joueur *michel, int nb_joueur) // AFFICHAGE DU JOUEUR EN FONCTION DU NB DE JOUEUR ET DU TOUR PASSER EN PARAMETRE
{
    int i;

    for(i = 0; i<nb_joueur; i++)
    {
        if(michel[i].PV > 0)
        {
            draw_sprite(buffer, skins[(michel[i].classe)-1], (michel[i].posx), (michel[i].posy));
        }
    }
}
void aleatoirePersonnage(t_joueur *michel,int nb_joueur, int maps[26][12])
{
    int x=0;
    int y=-50;
    int i;

    for(i=0; i<nb_joueur; i++)
    {
        do // boucle si on spawn aléatoirement sur une case de lave
        {
            x = rand()% 25;
            michel[i].posx = x*50;
            y = (rand()% (11-1)+1);
            michel[i].posy = (y*50)-50;
        }
        while(maps[x][y] == 2);
    }
}

void choixEmplacement(BITMAP * buffer, BITMAP* skins[4], int nb_joueur,t_joueur *michel,int maps[26][12], int joueurTour, char nom[4][20])
{
    int choixJoueur=0;
    rest(200);
    time_t choixTemp = time(NULL);
    while ( (time(NULL)-choixTemp) < 10 && (choixJoueur != nb_joueur)) // boucle avec un temps de 10 secondes si le choix de l'emplacement choisis n'est pas égale au nombre de joueur
    {
        if(mouse_b &1) // SI CLICK DETECTER
        {
            if(mouse_x <= 1300 && mouse_x >= 0 && mouse_y <=600 && mouse_y >= 50) // SI MOUSE SE TROUVE DANS LA MAP
            {
                if( maps[mouse_x/50][mouse_y/50] == 2) // on convertie la valeur recu par le click et si c'est sur une salle
                {
                }
                else // SINON ON MET LE JOUEUR SUR L'EMPLACEMENT D'OU IL A CLICKER
                {
                    joueurTour++;
                    update_coo(&michel[choixJoueur], maps);
                    affichagePersonnage(buffer,skins,michel,choixJoueur+1);
                    choixJoueur++;
                    blit(buffer, screen, 0,0,0,0, SCREEN_W, SCREEN_H);
                    rest(100);
                }
            }
        }
        else
        {
            blit(buffer, screen, 0,0,0,0, SCREEN_W, SCREEN_H); // ENSUITE ON AFFICHE L'EMPLACEMENT DU JOUEUR OU IL A CLICKER

        }
        textprintf_ex(buffer,font,600,610,makecol(0,150,255),makecol(2,2,2),"Placer vos joueur !");
        textprintf_ex(buffer,font,650,630,makecol(255,255,0),makecol(2,2,2),"A %s                    ", nom[michel[joueurTour].classe-1]);
        textprintf_ex(buffer,font,1200,650,makecol(255,0,0),makecol(2,2,2),"CHRONO: %d ",10-(time(NULL)-choixTemp));
    }

    if(choixJoueur == nb_joueur)
    {}
    else
    {
        aleatoirePersonnage(michel,nb_joueur,maps); // ON SPAWN LES JOUEURS ALEATOIREMENT SUR LA MAP
    }

}


///SOUS PROGRAMME POUR AFFICHER LA BAR DES SORT DANS LE JEU///

void update_bar(t_joueur * playeur, int joueurTour,BITMAP * buffer,BITMAP*bar1,BITMAP*bar2,BITMAP*bar3,BITMAP*bar4 )
{
    if (playeur[joueurTour].classe==1)///si le joueur a choisie la classe 1
    {
        blit(bar1, buffer, 0,0,250,600,bar1->w, bar1->h);//affichage de la bar de sort pour la classe1;
    }
    if (playeur[joueurTour].classe==2)///si le joueur a choisie la classe 2
    {
        blit(bar2, buffer, 0,0,250,600,bar1->w, bar2->h);//affichage de la bar de sort pour la classe2;
    }
    if (playeur[joueurTour].classe==3)///si le joueur a choisie la classe 3
    {
        blit(bar3, buffer, 0,0,250,600,bar3->w, bar3->h);//affichage de la bar de sort pour la classe3;
    }
    if (playeur[joueurTour].classe==4)///si le joueur a choisie la classe 4
    {
        blit(bar4, buffer, 0,0,250,600,bar4->w, bar4->h);//affichage de la bar de sort pour la classe4;
    }
}


///SOUS PROGRAMME AFFICHER CARRER DE SELECTION DES SORT

void affiche_selectSORT(BITMAP*buffer, BITMAP*jaune, int etat_hotbar[7])
{
    int i;
    int case_actu = 0;///case actuellement choisie
    int b,a;
    for(i = 255; i<801; i +=88)//pour i < au cordonnée , incrémentaion de 88 = taille de chaque cases
    {
        if(cliquer_zone(i, 600, 88,100) == 2)//si on passe la souris sur la case
        {
            draw_sprite(buffer,jaune,i,605);//affiche le carré
        }
        if(cliquer_zone(i, 600, 88,100) == 1)//si on clic que la case
        {

            etat_hotbar[case_actu] = 1;//afficher le carré autour de la casse

            for(b=0; b<case_actu; b++)//effacer les carré après la case selectionné
            {
                etat_hotbar[b]=0;
            }
            for(a=7; a>case_actu; a--)//effacer les carré avant la case selectionné
            {
                etat_hotbar[a]=0;
            }

        }
        case_actu++;//incrémentation
    }
}


void deplacement_case(t_joueur* michel, int maps[26][12],int nb_joueur,int joueurTour,int *bouger,BITMAP *skins[4],BITMAP *buffer,BITMAP *terrain,BITMAP *hotbar1,BITMAP *hotbar2,BITMAP *hotbar3,BITMAP* hotbar4,BITMAP *jaune,int etat_hotbar[7],BITMAP *lava,BITMAP *bush,BITMAP *bleu, BITMAP *rouge)
{
    int i = 0;
    int j = 0;

    int newposx;
    int newposy;

    int deplace=0;
    for (i = 0 ; i <26 ; i++)
    {
        for (j = 0 ; j<12 ; j++)
        {
            if(cliquer_zone((i*50), (j*50), 50,50) == 1)
            {
                if(maps[i][j] == 2) // SI ON CLICK SUR LA LAVE
                {}

                // SI ON CLICK SUR LA CASE DE GAUCHE
                else if ( (i*50 <= michel[joueurTour].posx-50) && (michel[joueurTour].posx <= i*50+50) && ((j-1)*50 == michel[joueurTour].posy) && ((michel[joueurTour].PM) >= 0) && (*bouger != 3))
                {
                    newposx = i*50;  // ON STOP LA POSE EN X
                    while(michel[joueurTour].posx != newposx) // TANT QUE ANCIEN POSX DIFFERENT DE LA NOUVELLE ALORS ON CONTINUE
                    {
                        clear_bitmap(buffer); // EFFACEMENT DE LA DERNIERE POSITION AFIN DE PAS AVOIR PLUSIEUR MEME IMAGE
                        michel[joueurTour].posx = michel[joueurTour].posx -1; // GLISSEMENT DE LA POSX
                        blit(terrain, buffer, 0,0,0,0, terrain->w, terrain->h); // AFFICHGE DU TERRAIN
                        update_bar(michel,joueurTour,buffer, hotbar1,hotbar2, hotbar3,hotbar4);///affichage de la barre des sort dans la map
                        affiche_selectSORT(buffer,jaune, etat_hotbar); // AFFICHAGE DE LA BARRE SORT
                        refresh_objets(buffer, maps, lava, bush, bleu, rouge, jaune, etat_hotbar); // AFFICHE DE TOUT LES DIVERS
                        textprintf_ex(buffer,font,50,610,makecol(255,255,255),-1,"PV: %d", michel[joueurTour].PV);
                        textprintf_ex(buffer,font,50,630,makecol(255,255,255),-1,"PM: %d", michel[joueurTour].PM);
                        textprintf_ex(buffer,font,50,650,makecol(255,255,255),-1,"PA: %d", michel[joueurTour].PA);
                        update_jauge(&michel[joueurTour], buffer);
                        affichagePersonnage(buffer,skins,michel,nb_joueur);
                        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                        rest(1);
                    }
                    (michel[joueurTour].PM)--;
                    deplace++;
                }
                // SI ON CLICK SUR LA CASE DE DROITE
                else if ( (i*50 <= michel[joueurTour].posx+50) && (michel[joueurTour].posx <= i*50-50) && ((j-1)*50 == michel[joueurTour].posy) && ((michel[joueurTour].PM) >= 0) && (*bouger != 3))
                {
                    newposx = i*50;
                    while(michel[joueurTour].posx != newposx)
                    {
                        clear_bitmap(buffer); // EFFACEMENT DE LA DERNIERE POSITION AFIN DE PAS AVOIR PLUSIEUR MEME IMAGE
                        michel[joueurTour].posx = michel[joueurTour].posx +1; // GLISSEMENT DE LA POSX
                        blit(terrain, buffer, 0,0,0,0, terrain->w, terrain->h); // AFFICHGE DU TERRAIN
                        update_bar(michel,joueurTour,buffer, hotbar1,hotbar2, hotbar3,hotbar4);///affichage de la barre des sort dans la map
                        affiche_selectSORT(buffer,jaune, etat_hotbar); // AFFICHAGE DE LA BARRE SORT
                        refresh_objets(buffer, maps, lava, bush, bleu, rouge, jaune, etat_hotbar); // AFFICHE DE TOUT LES DIVERS
                        textprintf_ex(buffer,font,50,610,makecol(255,255,255),-1,"PV: %d", michel[joueurTour].PV);
                        textprintf_ex(buffer,font,50,630,makecol(255,255,255),-1,"PM: %d", michel[joueurTour].PM);
                        textprintf_ex(buffer,font,50,650,makecol(255,255,255),-1,"PA: %d", michel[joueurTour].PA);
                        update_jauge(&michel[joueurTour], buffer);
                        affichagePersonnage(buffer,skins,michel,nb_joueur);
                        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                        rest(1);
                    }
                    (michel[joueurTour].PM)--;
                    deplace++;
                }
                // SI ON CLICK SUR LA CASE AU DESSUS
                else if ( (j*50-50 <= michel[joueurTour].posy-50) && (michel[joueurTour].posy <= j*50) && (i*50 == michel[joueurTour].posx) && ((michel[joueurTour].PM) >= 0) && (*bouger != 3))
                {
                    newposy = (j-1)*50;
                    while(michel[joueurTour].posy != newposy)
                    {
                        clear_bitmap(buffer); // EFFACEMENT DE LA DERNIERE POSITION AFIN DE PAS AVOIR PLUSIEUR MEME IMAGE
                        michel[joueurTour].posy = michel[joueurTour].posy -1; // GLISSEMENT DE LA POSY
                        blit(terrain, buffer, 0,0,0,0, terrain->w, terrain->h); // AFFICHGE DU TERRAIN
                        update_bar(michel,joueurTour,buffer, hotbar1,hotbar2, hotbar3,hotbar4);///affichage de la barre des sort dans la map
                        affiche_selectSORT(buffer,jaune, etat_hotbar); // AFFICHAGE DE LA BARRE SORT
                        refresh_objets(buffer, maps, lava, bush, bleu, rouge, jaune, etat_hotbar); // AFFICHE DE TOUT LES DIVERS
                        textprintf_ex(buffer,font,50,610,makecol(255,255,255),-1,"PV: %d", michel[joueurTour].PV);
                        textprintf_ex(buffer,font,50,630,makecol(255,255,255),-1,"PM: %d", michel[joueurTour].PM);
                        textprintf_ex(buffer,font,50,650,makecol(255,255,255),-1,"PA: %d", michel[joueurTour].PA);
                        update_jauge(&michel[joueurTour], buffer);
                        affichagePersonnage(buffer,skins,michel,nb_joueur);
                        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                        rest(1);
                    }
                    (michel[joueurTour].PM)--;
                    deplace++;
                }
                // SI ON CLICK SUR LA CASE D'EN BAS
                else if ( ( j*50 <= michel[joueurTour].posy+100) && (michel[joueurTour].posy <= j*50-100) && (i*50 == michel[joueurTour].posx) && ((michel[joueurTour].PM) >= 0) && (*bouger != 3))
                {
                    newposy = (j-1)*50;
                    while(michel[joueurTour].posy != newposy)
                    {
                        clear_bitmap(buffer); // EFFACEMENT DE LA DERNIERE POSITION AFIN DE PAS AVOIR PLUSIEUR MEME IMAGE
                        michel[joueurTour].posy = michel[joueurTour].posy +1; // GLISSEMENT DE LA POSX
                        blit(terrain, buffer, 0,0,0,0, terrain->w, terrain->h); // AFFICHGE DU TERRAIN
                        update_bar(michel,joueurTour,buffer, hotbar1,hotbar2, hotbar3,hotbar4);///affichage de la barre des sort dans la map
                        affiche_selectSORT(buffer,jaune, etat_hotbar); // AFFICHAGE DE LA BARRE SORT
                        refresh_objets(buffer, maps, lava, bush, bleu, rouge, jaune, etat_hotbar); // AFFICHE DE TOUT LES DIVERS
                        textprintf_ex(buffer,font,50,610,makecol(255,255,255),-1,"PV: %d", michel[joueurTour].PV);
                        textprintf_ex(buffer,font,50,630,makecol(255,255,255),-1,"PM: %d", michel[joueurTour].PM);
                        textprintf_ex(buffer,font,50,650,makecol(255,255,255),-1,"PA: %d", michel[joueurTour].PA);
                        update_jauge(&michel[joueurTour], buffer);
                        affichagePersonnage(buffer,skins,michel,nb_joueur);
                        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                        rest(1);
                    }
                    (michel[joueurTour].PM)--;
                    deplace++;
                }
                // SINON ON FAIT RIEN
                else {}
            }
        }
    }
    *bouger = *bouger+deplace; // ON INCREMENTE CE POINTEUR AFIN DE POUVOIR QU'IL NE FASSE QUE DE 3 CASE MAX
}


///SOUS PROGRAMME POUR CONTROLER LES POINT DE PA PV PM

void controle_points(t_joueur *michel, int nb_joueur)
{
    int i;

    for(i = 0; i<nb_joueur; i++)//boucle pour parcourir le nombre de joueur
    {
        if(michel[i].PA>40)//si PA du joueur > 20
        {
            michel[i].PA = 40;//mettre PA a 20
        }
        if(michel[i].PA<0)//si PA du joueur <0
        {
            michel[i].PA = 0; //mettre PA a 0
        }

        ///meme chose pour les PM et PV

        if(michel[i].PM>50)
        {
            michel[i].PM = 50;
        }
        if(michel[i].PM<0)
        {
            michel[i].PM = 0;
        }
        if(michel[i].PV>100)
        {
            michel[i].PV = 100;
        }
        if(michel[i].PV<0)
        {
            michel[i].PV = 0;
        }
    }
}

///SOUS PROG POUR INVERSE LES POSITIONS POUR LES SORT

void inverse_pos(t_joueur*michel, int compt, int joueurTour)
{
    int tempPosx=0;//déclare d'une variable entier temporaire en x pour inversé
    int tempPosy=0;//déclare d'une variable entier temporaire en y pour inversé

    tempPosx=michel[compt].posx;
    michel[compt].posx=michel[joueurTour].posx;
    michel[joueurTour].posx=tempPosx;


    tempPosy=michel[compt].posy;
    michel[compt].posy=michel[joueurTour].posy;
    michel[joueurTour].posy=tempPosy;

}




void classementTop(t_joueur *michel, int nb_joueur, int classement[nb_joueur+1],int joueurTour)
{
    int quitter = 0;

    BITMAP *podium;
    BITMAP *classementQuitter;
    BITMAP *classementQuitterRouge;

    BITMAP *steveNormal;
    BITMAP *zombieNormal;
    BITMAP *sorciereNR;
    BITMAP *skeletteNormal;

    BITMAP *steveRoi;
    BITMAP *skeletteRoi;
    BITMAP *zombieRoi;

    BITMAP *buffer;
    BITMAP *viseur;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    SAMPLE *victoire;

    steveNormal = load_bitmap("images/steveNormal.bmp",NULL);
    zombieNormal = load_bitmap("images/zombieNormal.bmp",NULL);
    sorciereNR = load_bitmap("images/sorcierNormal.bmp",NULL);
    skeletteNormal = load_bitmap("images/skeletteNormal.bmp",NULL);

    steveRoi = load_bitmap("images/steveRoi.bmp",NULL);
    skeletteRoi = load_bitmap("images/skeletteRoi.bmp",NULL);
    zombieRoi = load_bitmap("images/zombieRoi.bmp",NULL);

    podium = load_bitmap("images/podium.bmp",NULL);
    viseur = load_bitmap("images/viseur.bmp",NULL);
    classementQuitter = load_bitmap("images/classementQuitter.bmp",NULL);
    classementQuitterRouge = load_bitmap("images/classementQuitterRouge.bmp",NULL);

    victoire = load_sample("victoire.wav");
    play_sample(victoire,50,125,1003,5);
    time_t temps = time(NULL);

    while(time(NULL)-temps < 3000 && quitter != 1)
    {

        blit(podium,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(buffer,viseur,mouse_x-15,mouse_y-5);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        int i =0;
        for(i=0; i<3; i++)  // PERMET D'AFFICHER LE CLASSEMENT DES TOP 3 MEILLEUR JOUEURS
        {
            if(i == 0)
            {
                if (classement[i] == 1)
                {
                    draw_sprite(podium,sorciereNR,575,60);
                }
                else if (classement[i] == 2)
                {
                    draw_sprite(podium,steveRoi,575,88);
                }
                else if(classement[i] == 3)
                {
                    draw_sprite(podium,skeletteRoi,575,88);
                }
                else if(classement[i] == 4)
                {
                    draw_sprite(podium,zombieRoi,575,88);
                }
                else {}
            }
            else if (i == 1)
            {
                if (classement[i] == 1)
                {
                    draw_sprite(podium,sorciereNR,1000,87);
                }
                else if (classement[i] == 2)
                {
                    draw_sprite(podium,steveNormal,1000,125);
                }
                else if(classement[i] == 3)
                {
                    draw_sprite(podium,skeletteNormal,1000,125);
                }
                else if(classement[i] == 4)
                {
                    draw_sprite(podium,zombieNormal,1000,125);
                }
                else {}

            }
            else if (i == 2)
            {
                if (classement[i] == 1)
                {
                    draw_sprite(podium,sorciereNR,145,90);
                }
                else if (classement[i] == 2)
                {
                    draw_sprite(podium,steveNormal,145,105);
                }
                else if(classement[i] == 3)
                {
                    draw_sprite(podium,skeletteNormal,145,105);
                }
                else if(classement[i] == 4)
                {
                    draw_sprite(podium,zombieNormal,145,105);
                }
                else {}

            }
            else {}
        }

        if( mouse_x > 35 && mouse_x < 216 && mouse_y > 25 && mouse_y < 94)
        {
            draw_sprite(podium,classementQuitterRouge,5,5);
            blit(podium,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(buffer,viseur,mouse_x-15,mouse_y-5);
            blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            if(mouse_b&1) // SI ON CLICK SUR JOUER ALORS LANCEMENT DE LA PARTIE ET STOP MUSIQUE DU MENU
            {
                quitter = 1;
            }

            // SINON ON AFFICHE L'IMAGE QUI N'EST PAS EN SURBRILLANCE
        }
        else
        {
            draw_sprite(podium,classementQuitter,5,5);
        }
    }
    destroy_sample(victoire);
    destroy_bitmap(podium);
    destroy_bitmap(steveNormal);
    destroy_bitmap(zombieNormal);
    destroy_bitmap(sorciereNR);
    destroy_bitmap(skeletteNormal);
    destroy_bitmap(steveRoi);
    destroy_bitmap(skeletteRoi);
    destroy_bitmap(zombieRoi);
    destroy_bitmap(classementQuitter);
    destroy_bitmap(classementQuitterRouge);
    destroy_bitmap(viseur);
}


