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

            else if(proba <30 && i>1 && i<24 && j>1 )
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

    for(i=0 ; i<26; i++)
    {
        blit(lava, terrain,0,0,(50*i),(0), 50, 50 );

    }
}

//affichage des objets sur la map c�d les element qui sont par dessus tout le reste
void refresh_objets(BITMAP* buffer, int maps[26][12],BITMAP* lava, BITMAP* bush, BITMAP* bleu, BITMAP* rouge, BITMAP* jaune, int etat_hotbar[9])
{
    int i = 0;
    int j = 0;

    for (i = 0 ; i <26 ; i++)
    {
        for (j = 0 ; j<12 ; j++)
        {
            if(maps[i][j] == 3)
            {
                draw_sprite(buffer, bush, (i*50), (j*50));
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

    for(i = 0; i<9; i++)
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

        putpixel(buffer, i+100, 610, makecol(52,201,36));
        putpixel(buffer, i+100, 611, makecol(52,201,36));
        putpixel(buffer, i+100, 612, makecol(52,201,36));
        putpixel(buffer, i+100, 613, makecol(52,201,36));
        putpixel(buffer, i+100, 614, makecol(52,201,36));
    }

    for(i = 0; i<(michel->PM); i++)
    {

        putpixel(buffer, i+100, 630, makecol(52,201,36));
        putpixel(buffer, i+100, 631, makecol(52,201,36));
        putpixel(buffer, i+100, 632, makecol(52,201,36));
        putpixel(buffer, i+100, 633, makecol(52,201,36));
        putpixel(buffer, i+100, 634, makecol(52,201,36));
    }

    for(i = 0; i<(michel->PA); i++)
    {

        putpixel(buffer, i+100, 650, makecol(52,201,36));
        putpixel(buffer, i+100, 651, makecol(52,201,36));
        putpixel(buffer, i+100, 652, makecol(52,201,36));
        putpixel(buffer, i+100, 653, makecol(52,201,36));
        putpixel(buffer, i+100, 654, makecol(52,201,36));
    }
}

//mise � jour des coo d'un joueur si clique sur une case
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

void affichagePersonnage(BITMAP * buffer, BITMAP* skins[4], t_joueur *michel, int nb_joueur) // AFFICHAGE DU JOUEUR EN FONCTION DU NB DE JOUEUR ET DU TOUR PASSER EN PARAMETRE
{
    int i;

    for(i = 0; i<nb_joueur; i++)
    {
        if(i==0)
        {
            draw_sprite(buffer, skins[(michel[0].classe)-1], (michel[0].posx), (michel[0].posy));
        }

        if(i==1)
        {
            draw_sprite(buffer, skins[(michel[1].classe)-1], (michel[1].posx), (michel[1].posy));
        }

        if(i==2)
        {
            draw_sprite(buffer, skins[(michel[2].classe)-1], (michel[2].posx), (michel[2].posy));
        }
        if(i==3)
        {
            draw_sprite(buffer, skins[(michel[3].classe)-1], (michel[3].posx), (michel[3].posy));
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
        do
        {
            x = rand()% 25;
            michel[i].posx = x*50;
            y = (rand()% (11-1)+1);
            michel[i].posy = (y*50)-50;
        }
        while(maps[x][y] == 2);


    }
    printf("Joueur 1 : x->%d , y->%d\n",michel[0].posx,michel[0].posy);
    printf("Joueur 2 : x->%d , y->%d\n",michel[1].posx,michel[1].posy);
    printf("Joueur 3 : x->%d , y->%d\n",michel[2].posx,michel[2].posy);
    printf("Joueur 4 : x->%d , y->%d\n",michel[3].posx,michel[3].posy);

}

void choixEmplacement(BITMAP * buffer, BITMAP* skins[4], int nb_joueur,t_joueur *michel,int maps[26][12])
{
    int choixJoueur=0;
    rest(100);
    time_t choixTemp = time(NULL);
    while ( (time(NULL)-choixTemp) < 10 && (choixJoueur != nb_joueur))
    {
        if(mouse_b &1)
        {
            update_coo(&michel[choixJoueur], maps);
            affichagePersonnage(buffer,skins,michel,choixJoueur+1);
            choixJoueur++;
            blit(buffer, screen, 0,0,0,0, SCREEN_W, SCREEN_H);
            rest(100);

        }
        else
        {
            blit(buffer, screen, 0,0,0,0, SCREEN_W, SCREEN_H);

        }
    }

    if(choixJoueur == nb_joueur)
    {}
    else
    {
        aleatoirePersonnage(michel,nb_joueur,maps);
    }

}


void update_bar(t_joueur * playeur, int joueurTour,BITMAP * buffer,BITMAP*bar1,BITMAP*bar2,BITMAP*bar3,BITMAP*bar4 )
{
    if (playeur[joueurTour].classe==1)
    {
        blit(bar1, buffer, 0,0,250,600,bar1->w, bar1->h);
    }
    if (playeur[joueurTour].classe==2)
    {
        blit(bar2, buffer, 0,0,250,600,bar1->w, bar2->h);
    }
    if (playeur[joueurTour].classe==3)
    {
        blit(bar3, buffer, 0,0,250,600,bar3->w, bar3->h);
    }
    if (playeur[joueurTour].classe==4)
    {
        blit(bar4, buffer, 0,0,250,600,bar4->w, bar4->h);
    }
}


void affiche_selectSORT(BITMAP*buffer, BITMAP*jaune, int etat_hotbar[9])
{
    int i;
    int case_actu = 0;
    int b,a;
    for(i = 255; i<966; i +=88)
    {

        if(cliquer_zone(i, 600, 88,100) == 2)
        {
            draw_sprite(buffer,jaune,i,605);
        }

        if(cliquer_zone(i, 600, 88,100) == 1)
        {
            etat_hotbar[case_actu] = 1;
            for(b=0;b<case_actu;b++)
            {
                etat_hotbar[b]=0;
            }
            for(a=9;a>case_actu;a--)
            {
                etat_hotbar[a]=0;
            }

        }
        case_actu++;
    }
}
