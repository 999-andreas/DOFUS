#include "header.h"

void controle_points(t_joueur *michel, int nb_joueur)
{
    int i ;

    for(i = 0; i<nb_joueur; i++)
    {
        if(michel[i].PA>20)
        {
            michel[i].PA = 20;
        }
        if(michel[i].PA<0)
        {
            michel[i].PA = 0;
        }
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

void attaque_CAC(t_joueur *michel, int joueurTour,BITMAP*orange,BITMAP*buffer, int nb_joueur, int* etat)
{
    int i;
    int j=0;
    int k=0;

    int debutx = ((michel[joueurTour].posx)-50)/50;
    int finx = ((michel[joueurTour].posx)+100)/50;

    int debuty = ((michel[joueurTour].posy)-50)/50;
    int finy = ((michel[joueurTour].posy)+150)/50;


    for (i=0; i<nb_joueur; i++)
    {
        for(j = (debutx); j <(finx); j++)
        {

            for(k = (debuty); k <(finy); k++)
            {

                if(michel[i].posx == j*50 && michel[i].posy == k*50)
                {
                    if((michel[joueurTour].posx == j*50) && (michel[joueurTour].posy == k*50))
                        continue;

                    blit(orange, buffer, 0,0,j*50,k*50, 50,50);




                    if ((cliquer_zone(j*50,k*50, 50,50)==1) && (*etat !=1))
                    {
                        michel[joueurTour].PA -= 2;
                        *etat = 1;

                        if(rand()%100 >=10)
                        {
                            michel[i].PV -=5;
                            //affichage rouge + rests
                        }
                    }
                }
            }
        }
    }

}
