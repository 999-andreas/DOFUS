#include "header.h"

//initialise les valeur de chaque case du terrain
void init_maps(int maps[26][12])
{
    int i = 0;
    int j = 0;
    int proba;

    for (i = 0 ;i <26 ; i++)
    {
        for (j = 0 ;j<12 ;j++)
        {
            proba = rand()%100;

            if(proba<20 && i>1 && i<24 && j>1 )
                maps[i][j] = 3;

            else if(proba <30 && i>1 && i<24 && j>1 )
                maps[i][j] = 2;

            else
                maps[i][j] = rand()%2;

            printf("%d  | proba :%d\n", maps[i][j], proba );
        }
    }
}

void init_terrain(BITMAP* terrain, int maps[26][12], BITMAP* dirt, BITMAP* grass, BITMAP* lava)
{
    int i = 0;
    int j = 0;

    for (i = 0 ;i <26 ; i++)
    {
        for (j = 0 ;j<12 ;j++)
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

void refresh_objets(BITMAP* buffer, int maps[26][12],BITMAP* lava, BITMAP* bush, BITMAP* croix, BITMAP* bleu, BITMAP* rouge)
{
    int i = 0;
    int j = 0;

    for (i = 0 ;i <26 ; i++)
    {
        for (j = 0 ;j<12 ;j++)
        {
            if(maps[i][j] == 3)
            {
                draw_sprite(buffer, bush, (i*50), (j*50));
            }

            if(cliquer_zone((i*50), (j*50) , 50,50) == 2)
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


