#include "header.h"


void animm(BITMAP * buffer,BITMAP* skins[4],BITMAP* skins_rouge[4], t_joueur* michel, int nb_joueur ) // AFFICHAGE DU JOUEUR EN FONCTION DU NB DE JOUEUR ET DU TOUR PASSER EN PARAMETRE
{
    int i;

    for(i = 0; i<nb_joueur; i++)
    {
        if(michel[i].PV > 0)
        {
            if(michel[i].toucher>0 && michel[i].toucher<10)
            {
                printf("test\n");
                draw_sprite(buffer, skins_rouge[(michel[i].classe)-1], (michel[i].posx), (michel[i].posy));
                michel[i].toucher -=1;
            }
            else
            {
                draw_sprite(buffer, skins[(michel[i].classe)-1], (michel[i].posx+1), (michel[i].posy));
            }
        }
        else {}
    }
}

void animmms(BITMAP * buffer,BITMAP* skins[4], BITMAP* skins_rouge[4], t_joueur* michel, int nb_joueur) // AFFICHAGE DU JOUEUR EN FONCTION DU NB DE JOUEUR ET DU TOUR PASSER EN PARAMETRE
{
    int i;

    for(i = 0; i<nb_joueur; i++)
    {
        if(michel[i].PV > 0)
        {
            if(michel[i].toucher!=0) // on affiche l'anime de degats pendant 30 tours de l   boucle while principale
            {
                draw_sprite(buffer, skins_rouge[(michel[i].classe)-1], (michel[i].posx), (michel[i].posy));
                michel[i].toucher -=1;
            }
            else
            {
                draw_sprite(buffer, skins[(michel[i].classe)-1], (michel[i].posx-1), (michel[i].posy));
            }
        }
        else {}

    }
}



void Deuxieme_Sort (t_joueur* michel, int joueurTour, int nbjoueur, BITMAP* blanc, BITMAP*buffer, int *etatDEG, int *etatPOT_CP, int *etatFLECHE)
{
    int i,j,k,b;
    int nb;

    ///SORT 2 DE LA CLASSE SORCIERE ///
    if (michel[joueurTour].classe==1)
    {
        for (nb=0; nb<nbjoueur; nb++)///parcourir le nombre de joueur
        {

            for (i=michel[joueurTour].posy; i<michel[joueurTour].posy+300; i=i+50)//parcour de la position en y+ jusqu'a posy+200
            {
                blit(blanc, buffer, 0,0,michel[joueurTour].posx,i, 50,50);//affichage du carre en y+

                if (michel[joueurTour].posy==i)//si le joueur actuelle a les meme position en y que i alors
                    continue;//sort de la boucle

                if (michel[nb].posy==i)///si joueur adverse a les meme position en y que i
                {
                    if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etatDEG!=1))// si le joueur clic sur la zone et que etatDEG != 1
                    {
                        if (michel[joueurTour].PA<10)//si les PA du
                        {
                            continue;//sort de la boucle
                        }
                        michel[nb].PV=michel[nb].PV-13;//le joueur adverse perd 10 PV
                        michel[joueurTour].PA=michel[joueurTour].PA-10;//le joueur adverse perd 6 PA
                        *etatDEG=1; //EPEE PASSE A 1
                        michel[nb].toucher = 30;
                    }
                }
            }


            ///MEME CHOSE POUR LES POSITIONS EN X- X+ Y-//

            for (j=michel[joueurTour].posy; j>michel[joueurTour].posy-250; j=j-50)
            {
                blit(blanc, buffer, 0,0,michel[joueurTour].posx,j, 50,50);
                if (michel[joueurTour].posy==j)
                    continue;

                if (michel[nb].posy==j)
                {
                    if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etatDEG!=2))
                    {
                        if (michel[joueurTour].PA<10)
                        {
                            continue;
                        }
                        michel[nb].PV=michel[nb].PV-13;
                        michel[joueurTour].PA=michel[joueurTour].PA-10;
                        *etatDEG=2;
                        michel[nb].toucher = 30;
                    }
                }
            }
            for (k=michel[joueurTour].posx; k<michel[joueurTour].posx+250; k=k+50)
            {
                blit(blanc, buffer, 0,0,k,michel[joueurTour].posy, 50,50);

                if (michel[joueurTour].posx==k)
                    continue;

                if (michel[nb].posx==k)
                {
                    if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etatDEG!=3))
                    {
                        if (michel[joueurTour].PA<10)
                        {
                            continue;
                        }
                        michel[nb].PV=michel[nb].PV-13;
                        michel[joueurTour].PA=michel[joueurTour].PA-10;
                        *etatDEG=3;
                        michel[nb].toucher = 30;
                    }
                }


            }
            for (b=michel[joueurTour].posx; b>michel[joueurTour].posx-250; b=b-50)
            {
                blit(blanc, buffer, 0,0,b,michel[joueurTour].posy, 50,50);
                if (michel[joueurTour].posx==b)
                    continue;

                if (michel[nb].posx==b)
                {
                    if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etatDEG!=4))
                    {
                        if (michel[joueurTour].PA<10)
                        {
                            continue;
                        }
                        michel[nb].PV=michel[nb].PV-13;
                        michel[joueurTour].PA=michel[joueurTour].PA-10;
                        *etatDEG=4;
                        michel[nb].toucher = 30;
                    }
                }
            }
        }
    }
    ///SORT 2 DE LA CLASSE 2

    if (michel[joueurTour].classe==2)
    {
        int i;
        int j=0;
        int k=0;


        int debutx = ((michel[joueurTour].posx)-150)/50;
        int finx = ((michel[joueurTour].posx)+200)/50;

        int debuty = ((michel[joueurTour].posy)-50)/50;
        int finy = ((michel[joueurTour].posy)+150)/50;

        for (i=0; i<nbjoueur; i++)///BOUCLE incrémentation i jusqu'au nombre de joueur
        {
            for(j = (debutx); j <(finx); j++) //parcourir l'axe des x pour voir s'il y a des adversaires autour du JOUEURTOUR
            {

                for(k = (debuty); k <(finy); k++) //parcourir l'axe des y pour voir s'il y a des adversaires JOUEURTOUR
                {

                    if((michel[joueurTour].posx == j*50) && (michel[joueurTour].posy == k*50))///prend pas en compte le joueurTour
                        continue;
                    blit(blanc, buffer, 0,0,j*50,k*50, 50,50);

                    if(michel[i].posx == j*50 && michel[i].posy == k*50 && michel[i].PV > 0)//si adversaire est autour du joueurTour et les PV de l'adversaire > 0
                    {
                        if ((cliquer_zone(j*50,k*50, 50,50)==1) && (*etatPOT_CP !=1))//si on clic sur un joueur autour et que etat différent de 1
                        {
                            michel[joueurTour].PA -= 15;//- 2 pa pour le JoueurTour

                            *etatPOT_CP = 1;//passage de etat a 1

                            if(rand()%100 >=10)///nombre alea entre 0 et 100 > 10
                            {
                                michel[i].toucher = 30;
                                michel[i].PV -=20;

                            }
                        }
                    }
                }
            }
        }
    }

    ///SORT 2 DE LA CLASSE 3
    int fleche;
    int cont=0;
    if (michel[joueurTour].classe==3)
    {
        for (fleche=0; fleche<nbjoueur; fleche++)///parcour d'un flecheeur jusqu'a le nombre de joueur choisie
        {
            if (fleche==joueurTour)//si flecheeur est égal a la meme valeur du joueur actuelle
            {
                continue;//sort de la boucle
            }

            // blit(blanc, buffer, 0,0,michel[fleche].posx,michel[fleche].posy, 50,50);///affichage du carrer surbrillance blanc

            if( ((michel[fleche].posx > michel[joueurTour].posx+150) || (michel[fleche].posx < michel[joueurTour].posx-150)) || ((michel[fleche].posy > michel[joueurTour].posy+150) || (michel[fleche].posy < michel[joueurTour].posy-150)) )
            {

                    blit(blanc, buffer, 0,0,michel[fleche].posx,michel[fleche].posy, 50,50);///affichage du carrer surbrillance blanc
                    if (cliquer_zone(michel[fleche].posx,michel[fleche].posy,50,50)==1 && *etatFLECHE!=1 )//si tu clic sur un des joueur adverse et etatPOS diff de 1
                    {
                        *etatFLECHE=1;//passage de etatPOS a 1
                        michel[fleche].toucher = 30;
                        michel[joueurTour].PA=michel[joueurTour].PA-4;//joueurtour perd 4 PA
                        michel[fleche].PV=michel[fleche].PV-8;//joueur tour perd 8 PM
                    }


            }
            else
            {
                cont=cont+1;
                textprintf_ex(buffer,font,880,650,makecol(255,0,0),makecol(2,2,2),"%d adversaire(s) trop",cont);
                textprintf_ex(buffer,font,880,660,makecol(255,0,0),makecol(2,2,2),"pret ");
            }
        }
    }
}


