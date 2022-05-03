#include "header.h"

void init_maps(int maps[26][14])
{
    int i = 0;
    int j = 0;

    for (i = 0 ;i <26 ; i++)
    {
        for (j = 0 ;j<14 ;j++)
        {
            maps[i][j] = rand()%2;
        }
    }
}

void init_terrain(BITMAP* terrain, int maps[26][14])
{
    int i = 0;
    int j = 0;

    for (i = 0 ;i <26 ; i++)
    {
        for (j = 0 ;j<14 ;j++)
        {

            if(maps[i][j] == 0)
            {
                blit( x, terrain, );
            }
            else if(maps[i][j] == 1)
            {
                blit( x, terrain, );
            }
            else if(maps[i][j] == 2)
            {
                blit( x, terrain, );
            }
        }
    }
}

//faire une fonction qui donne un pixel aleatoirement entre sol, arbre, mur


