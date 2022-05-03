#include "header.h"

void init_maps(int maps[26][14])
{
    int i = 0;
    int j = 0;

    for (i = 0 ;i <26 ; i++)
    {
        for (j = 0 ;j<14 ;j++)
        {
            maps[i][j] = rand()%3;
        }
    }
}

void init_terrain(BITMAP* terrain, int maps[26][14], BITMAP* dirt, BITMAP* grass, BITMAP* arbre)
{
    int i = 0;
    int j = 0;

    for (i = 0 ;i <26 ; i++)
    {
        for (j = 0 ;j<14 ;j++)
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

void refresh_objets(BITMAP* terrain, int maps[26][14], BITMAP* arbre)
{
    int i = 0;
    int j = 0;

    for (i = 0 ;i <26 ; i++)
    {
        for (j = 0 ;j<14 ;j++)
        {
            if(maps[i][j] == 2 && ((rand()%100)<= 25) )
            {
                draw_sprite(terrain, arbre, (i*50), (j*50));
            }
        }
    }
}

//faire une fonction qui donne un pixel aleatoirement entre sol, arbre, mur


