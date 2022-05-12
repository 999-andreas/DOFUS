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

//affichage des objets sur la map càd les element qui sont par dessus tout le reste
void refresh_objets(BITMAP* buffer, int maps[26][12],BITMAP* lava, BITMAP* bush, BITMAP* bleu, BITMAP* rouge)
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
                //rajoute que la couleur est rouge quand c'est un obstacle
            }
        }
    }
}

//mise a jour des jauge de PV PM PA
void update_jauge(int pv, int pm, int pa, BITMAP* buffer)
{
    int i;

    for(i = 0; i<(pv); i++)
    {

        putpixel(buffer, i+100, 610, makecol(52,201,36));
        putpixel(buffer, i+100, 611, makecol(52,201,36));
        putpixel(buffer, i+100, 612, makecol(52,201,36));
        putpixel(buffer, i+100, 613, makecol(52,201,36));
        putpixel(buffer, i+100, 614, makecol(52,201,36));
    }

    for(i = 0; i<(pm); i++)
    {

        putpixel(buffer, i+100, 630, makecol(52,201,36));
        putpixel(buffer, i+100, 631, makecol(52,201,36));
        putpixel(buffer, i+100, 632, makecol(52,201,36));
        putpixel(buffer, i+100, 633, makecol(52,201,36));
        putpixel(buffer, i+100, 634, makecol(52,201,36));
    }

    for(i = 0; i<(pa); i++)
    {

        putpixel(buffer, i+100, 650, makecol(52,201,36));
        putpixel(buffer, i+100, 651, makecol(52,201,36));
        putpixel(buffer, i+100, 652, makecol(52,201,36));
        putpixel(buffer, i+100, 653, makecol(52,201,36));
        putpixel(buffer, i+100, 654, makecol(52,201,36));
    }
}

//mise à jour des coo d'un joueur si clique sur une case
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

void affichagePersonnage(BITMAP * buffer,BITMAP *sorciere,BITMAP *steve2, BITMAP *squelette, BITMAP* zombie, t_joueur *michel, int nb_joueur) // AFFICHAGE DU JOUEUR EN FONCTION DU NB DE JOUEUR ET DU TOUR PASSER EN PARAMETRE
{
    int i;

    for(i = 0; i<nb_joueur; i++)
    {

        if(i==0)
        {
            if (michel[0].classe==1)
            {
                draw_sprite(buffer, sorciere, (michel[0].posx), (michel[0].posy));
            }
            if (michel[0].classe==2)
            {
                draw_sprite(buffer, steve2, (michel[0].posx), (michel[0].posy));

            }
            if (michel[0].classe==3)
            {
                draw_sprite(buffer, squelette, (michel[0].posx), (michel[0].posy));
            }
            if (michel[0].classe==4)
            {
                draw_sprite(buffer, zombie, (michel[0].posx), (michel[0].posy));
            }
        }

        if(i==1)
        {

            if (michel[1].classe==1)
            {
                draw_sprite(buffer, sorciere, (michel[1].posx), (michel[1].posy));

            }
            if (michel[1].classe==2)
            {
                draw_sprite(buffer, steve2, (michel[1].posx), (michel[1].posy));

            }
            if (michel[1].classe==3)
            {
                draw_sprite(buffer, squelette, (michel[1].posx), (michel[1].posy));
            }
            if (michel[1].classe==4)
            {
                draw_sprite(buffer, zombie, (michel[1].posx), (michel[1].posy));
            }
        }

        if(i==2)
        {
            if (michel[2].classe==1)
            {
                draw_sprite(buffer, sorciere, (michel[2].posx), (michel[2].posy));

            }
            if (michel[2].classe==2)
            {
                draw_sprite(buffer, steve2, (michel[2].posx), (michel[2].posy));
            }
            if (michel[2].classe==3)
            {
                draw_sprite(buffer, squelette, (michel[2].posx), (michel[2].posy));
            }
            if (michel[2].classe==4)
            {
                draw_sprite(buffer, zombie, (michel[2].posx), (michel[2].posy));
            }
        }
        if(i==3)
        {
            if (michel[3].classe==1)
            {
                draw_sprite(buffer, sorciere, (michel[3].posx), (michel[3].posy));
            }
            if (michel[3].classe==2)
            {

                draw_sprite(buffer, steve2, (michel[3].posx), (michel[3].posy));
            }
            if (michel[3].classe==3)
            {
                draw_sprite(buffer, squelette, (michel[3].posx), (michel[3].posy));
            }
            if (michel[3].classe==4)
            {
                draw_sprite(buffer, zombie, (michel[3].posx), (michel[3].posy));
            }
        }
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


void affiche_selectSORT(BITMAP*buffer, BITMAP*jaune)
{

    ///sort1///
    if ( mouse_x > 250 && mouse_x < 340 && mouse_y > 600 && mouse_y < 700)
    {
        draw_sprite(buffer,jaune,255,605);
    }

    ///sort 2///
    if ( mouse_x > 345 && mouse_x < 435 && mouse_y > 600 && mouse_y < 700)
    {
        draw_sprite(buffer,jaune,345,605);
    }
    ///sort 3 ///
    if ( mouse_x > 440 && mouse_x < 525 && mouse_y > 600 && mouse_y < 700)
    {
        draw_sprite(buffer,jaune,430,605);
    }
    ///sort 4///
    if ( mouse_x > 525 && mouse_x < 610 && mouse_y > 600 && mouse_y < 700)
    {
        draw_sprite(buffer,jaune,520,605);
    }
    ///case5//
    if ( mouse_x > 613 && mouse_x < 697 && mouse_y > 600 && mouse_y < 700)
    {
        draw_sprite(buffer,jaune,605,605);
    }
    ///case attaque corps a coprs///
    if ( mouse_x > 700 && mouse_x < 787 && mouse_y > 600 && mouse_y < 700)
    {
        draw_sprite(buffer,jaune,695,605);
    }
    ///case déplacer ///
    if ( mouse_x > 787 && mouse_x < 873 && mouse_y > 600 && mouse_y < 700)
    {
        draw_sprite(buffer,jaune,783,605);
    }
    ///case 8///
    if ( mouse_x > 877 && mouse_x < 963 && mouse_y > 600 && mouse_y < 700)
    {
        draw_sprite(buffer,jaune,870,605);
    }
    ///case9///
    if ( mouse_x > 967 && mouse_x < 1053 && mouse_y > 600 && mouse_y < 700)
    {
        draw_sprite(buffer,jaune,957,605);
    }
}
