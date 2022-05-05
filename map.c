#include "header.h"

void init_maps(int maps[26][12])
{
    int i = 0;
    int j = 0;

    for (i = 0 ;i <26 ; i++)
    {
        for (j = 0 ;j<12 ;j++)
        {
            if(rand()%100 <10)
                maps[i][j] = 2;
            else
                maps[i][j] = rand()%2;
        }
    }
}

void init_terrain(BITMAP* terrain, int maps[26][12], BITMAP* dirt, BITMAP* grass, BITMAP* arbre)
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
            else if(maps[i][j] == 1 || maps[i][j] == 2) //grass
            {
                blit(grass, terrain,0,0,(50*i),(50*j), 50, 50 );
            }
        }
    }
}

void refresh_objets(BITMAP* terrain, int maps[26][12], BITMAP* arbre)
{
    int i = 0;
    int j = 0;

    for (i = 0 ;i <23 ; i++)
    {
        for (j = 0 ;j<9 ;j++)
        {
            if(maps[i][j] == 2)
            {
                draw_sprite(terrain, arbre, (i*50), (j*50));
            }
        }
    }
}


