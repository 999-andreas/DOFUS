#include "header.h"

// AFFICHAGE DU JOUEUR EN FONCTION DU NB DE JOUEUR ET DU TOUR PASSER EN PARAMETRE
void animm(BITMAP * buffer,BITMAP* skins[4],BITMAP* skins_rouge[4], t_joueur* michel, int nb_joueur )
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

// AFFICHAGE DU JOUEUR EN FONCTION DU NB DE JOUEUR ET DU TOUR PASSER EN PARAMETRE
void animmms(BITMAP * buffer,BITMAP* skins[4], BITMAP* skins_rouge[4], t_joueur* michel, int nb_joueur)
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

///sous programme ATTAQUE CORPS A COPRS ///
void attaque_CAC(t_joueur *michel, int joueurTour,BITMAP*orange,BITMAP*buffer, int nb_joueur, int* etat, int classement[nb_joueur+1],int *joueurEnvie)
{
    int i;
    int j=0;
    int k=0;
    SAMPLE *degatSteve;
    SAMPLE *degatZombie;
    SAMPLE *degatSkeleton;
    SAMPLE *degatSorciere;
    SAMPLE *esquive;
    SAMPLE *mort;

    int debutx = ((michel[joueurTour].posx)-50)/50;
    int finx = ((michel[joueurTour].posx)+100)/50;

    int debuty = ((michel[joueurTour].posy)-50)/50;
    int finy = ((michel[joueurTour].posy)+150)/50;

    degatSteve = load_sample("degat_steve.wav");
    degatZombie = load_sample("degat_zombie.wav");
    degatSkeleton = load_sample("degat_skeleton.wav");
    degatSorciere = load_sample("degat_villagoie.wav");
    esquive = load_sample("esquive.wav");
    mort = load_sample("MORT.wav");

    for (i=0; i<nb_joueur; i++)///BOUCLE incr�mentation i jusqu'au nombre de joueur
    {
        for(j = (debutx); j <(finx); j++) //parcourir l'axe des x pour voir s'il y a des adversaires autour du JOUEURTOUR
        {

            for(k = (debuty); k <(finy); k++) //parcourir l'axe des y pour voir s'il y a des adversaires JOUEURTOUR
            {

                if(michel[i].posx == j*50 && michel[i].posy == k*50 && michel[i].PV > 0)//si adversaire est autour du joueurTour et les PV de l'adversaire > 0
                {
                    if((michel[joueurTour].posx == j*50) && (michel[joueurTour].posy == k*50))///prend pas en nbe le joueurTour
                        continue;

                    blit(orange, buffer, 0,0,j*50,k*50, 50,50);///AFFICHAGE DES CARRES SURBRILLANCE




                    if ((cliquer_zone(j*50,k*50, 50,50)==1) && (*etat !=1))//si on clic sur un joueur autour et que etat diff�rent de 1
                    {
                        michel[joueurTour].PA -= 2;//- 2 pa pour le JoueurTour

                        *etat = 1;//passage de etat a 1

                        if(rand()%100 >=10)///nombre alea entre 0 et 100 > 10
                        {
                            michel[i].toucher = 30;

                            printf("avant: %d\n",michel[i].PV);
                            michel[i].PV -=5;
                            printf("apres: %d\n",michel[i].PV);

                            //sons des degats
                            if(michel[i].classe == 1 && michel[i].PV > 0)///si la classe est 1 alors c'est sorciere et que le joueur n'est pas mort (0PV)
                            {
                                play_sample(degatSorciere,200,125,1003,0);//joue un son de degat sorciere
                            }
                            else if(michel[i].classe == 2 && michel[i].PV > 0)///si la classe est 2 alors c'est steve et que le joueur n'est pas mort (0PV)
                            {
                                play_sample(degatSteve,200,125,1003,0);//joue un son de degat steve
                            }
                            else if (michel[i].classe == 3 && michel[i].PV > 0)///si la classe est 3 alors c'est squelette et que le joueur n'est pas mort (0PV)
                            {
                                play_sample(degatSkeleton,200,125,1003,0);//joue un son de degat squelette
                            }
                            else if (michel[i].classe == 4 && michel[i].PV > 0)///si la classe est 4 alors c'est zombie et que le joueur n'est pas mort (0PV)
                            {
                                play_sample(degatZombie,1000,125,1003,0);//joue un son de degat Zombie
                            }


                            if(michel[i].PV <= 0)
                            {
                                play_sample(mort,200,125,1003,0);
                                classement[*joueurEnvie] = michel[i].classe;
                                classement[nb_joueur] = (classement[nb_joueur])-1;
                                *joueurEnvie = *joueurEnvie -1;
                            }
                            else  {}
                        }
                        else
                        {
                            play_sample(esquive,200,125,1003,0);//joue un son esquive quand alea est <10
                        }
                    }
                }
            }
        }
    }


}


///sous programme premier sort des classes///

void attaquePremier_SORT (t_joueur* michel, int joueurTour, int nbjoueur, BITMAP* blanc, BITMAP*buffer,int* etatPOS, int*etatEPEE,int classement[nbjoueur+1],int *joueurEnvie)
{
    int i,j,k,b;
    int nb;

    SAMPLE *mort;
    SAMPLE *esquive;
    SAMPLE *coup_epee;

    mort = load_sample("MORT.wav");
    esquive = load_sample("esquive.wav");
    coup_epee = load_sample("coup_epee.wav");


///Si la classe du joueur = 1, 2 ou 4///
    ///Sort coup d'epee DE LA CLASSE 1 2 3 ///

    if (michel[joueurTour].classe==1 || michel[joueurTour].classe==2 || michel[joueurTour].classe==4 )
    {
        for (nb=0; nb<nbjoueur; nb++)///parcourir le nombre de joueur
        {

            for (i=michel[joueurTour].posy; i<michel[joueurTour].posy+200; i=i+50)//parcour de la position en y+ jusqu'a posy+200
            {
                blit(blanc, buffer, 0,0,michel[joueurTour].posx,i, 50,50);//affichage du carre en y+

                if (michel[joueurTour].posy==i)//si le joueur actuelle a les meme position en y que i alors
                    continue;//sort de la boucle

                if (michel[nb].posy==i)///si joueur adverse a les meme position en y que i
                {
                    if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etatEPEE!=1))// si le joueur clic sur la zone et que etatepee != 1
                    {
                        if (michel[joueurTour].PA<6)//si les PA du
                        {
                            continue;//sort de la boucle
                        }
                        michel[joueurTour].PA=michel[joueurTour].PA-6;//le joueur adverse perd 6 PA
                        *etatEPEE=1; //EPEE PASSE A 1
                        if(rand()%100 >= 10)
                        {
                            michel[nb].PV=michel[nb].PV-10;//le joueur adverse perd 10 PV
                            michel[nb].toucher = 30;

                            play_sample(coup_epee,80,125,1003,0);

                            if(michel[nb].PV <= 0)
                            {
                                play_sample(mort,200,125,1003,0);
                                classement[*joueurEnvie] = michel[nb].classe;
                                classement[nbjoueur] = (classement[nbjoueur])-1;
                                *joueurEnvie = *joueurEnvie -1;
                            }

                        }
                        else
                        {
                            play_sample(esquive,200,125,1003,0);
                        }
                    }
                }
            }


            ///MEME CHOSE POUR LES POSITIONS EN X- X+ Y-//

            for (j=michel[joueurTour].posy; j>michel[joueurTour].posy-150; j=j-50)
            {
                blit(blanc, buffer, 0,0,michel[joueurTour].posx,j, 50,50);
                if (michel[joueurTour].posy==j)
                    continue;

                if (michel[nb].posy==j)
                {
                    if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etatEPEE!=1))
                    {
                        if (michel[joueurTour].PA<10)
                        {
                            continue;
                        }

                        michel[joueurTour].PA=michel[joueurTour].PA-6;//le joueur adverse perd 6 PA
                        *etatEPEE=1; //EPEE PASSE A 1

                        if(rand()%100 >= 10)
                        {
                            michel[nb].PV=michel[nb].PV-10;//le joueur adverse perd 10 PV
                            michel[nb].toucher = 30;

                            play_sample(coup_epee,80,125,1003,0);

                            if(michel[nb].PV <= 0)
                            {
                                play_sample(mort,200,125,1003,0);
                                classement[*joueurEnvie] = michel[nb].classe;
                                classement[nbjoueur] = (classement[nbjoueur])-1;
                                *joueurEnvie = *joueurEnvie -1;
                            }

                        }
                        else
                        {
                            play_sample(esquive,200,125,1003,0);
                        }
                    }
                }
            }
            for (k=michel[joueurTour].posx; k<michel[joueurTour].posx+150; k=k+50)
            {
                blit(blanc, buffer, 0,0,k,michel[joueurTour].posy, 50,50);

                if (michel[joueurTour].posx==k)
                    continue;

                if (michel[nb].posx==k)
                {
                    if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etatEPEE!=1))
                    {
                        if (michel[joueurTour].PA<10)
                        {
                            continue;
                        }
                        michel[joueurTour].PA=michel[joueurTour].PA-6;//le joueur adverse perd 6 PA
                        *etatEPEE=1; //EPEE PASSE A 1
                        if(rand()%100 >= 10)
                        {
                            michel[nb].PV=michel[nb].PV-10;//le joueur adverse perd 10 PV
                            michel[nb].toucher = 30;

                            play_sample(coup_epee,80,125,1003,0);

                            if(michel[nb].PV <= 0)
                            {
                                play_sample(mort,200,125,1003,0);
                                classement[*joueurEnvie] = michel[nb].classe;
                                classement[nbjoueur] = (classement[nbjoueur])-1;
                                *joueurEnvie = *joueurEnvie -1;
                            }

                        }
                        else
                        {
                            play_sample(esquive,200,125,1003,0);
                        }
                    }
                }


            }
            for (b=michel[joueurTour].posx; b>michel[joueurTour].posx-150; b=b-50)
            {
                blit(blanc, buffer, 0,0,b,michel[joueurTour].posy, 50,50);
                if (michel[joueurTour].posx==b)
                    continue;

                if (michel[nb].posx==b)
                {
                    if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etatEPEE!=1))
                    {
                        if (michel[joueurTour].PA<10)
                        {
                            continue;
                        }
                        michel[joueurTour].PA=michel[joueurTour].PA-6;//le joueur adverse perd 6 PA
                        *etatEPEE=1; //EPEE PASSE A 1

                        if(rand()%100 >= 10)
                        {
                            michel[nb].PV=michel[nb].PV-10;//le joueur adverse perd 10 PV
                            michel[nb].toucher = 30;

                            play_sample(coup_epee,80,125,1003,0);

                            if(michel[nb].PV <= 0)
                            {
                                play_sample(mort,200,125,1003,0);
                                classement[*joueurEnvie] = michel[nb].classe;
                                classement[nbjoueur] = (classement[nbjoueur])-1;
                                *joueurEnvie = *joueurEnvie -1;
                            }

                        }
                        else
                        {
                            play_sample(esquive,200,125,1003,0);
                        }
                    }
                }
            }
        }
    }
    ///sort 1  classe squellette : inversement de position///
    int compt=0;
    if (michel[joueurTour].classe==3)///SI la classe == 3
    {
        for (compt=0; compt<nbjoueur; compt++)///parcour d'un compteur jusqu'a le nombre de joueur choisie
        {
            if (compt==joueurTour)//si compteur est �gal a la meme valeur du joueur actuelle
            {
                continue;//sort de la boucle
            }
            if(michel[compt].PV > 0)
            {
                blit(blanc, buffer, 0,0,michel[compt].posx,michel[compt].posy, 50,50);///affichage du carrer surbrillance blanc
            }

            if (michel[joueurTour].PA<5)
            {
                textprintf_ex(buffer,font,880,650,makecol(255,0,0),makecol(2,2,2),"vous avez pas assez");
                textprintf_ex(buffer,font,880,660,makecol(255,0,0),makecol(2,2,2),"de PA");
            }
            if (michel[joueurTour].PM<10)
            {
                textprintf_ex(buffer,font,880,650,makecol(255,0,0),makecol(2,2,2),"vous avez pas assez");
                textprintf_ex(buffer,font,880,660,makecol(255,0,0),makecol(2,2,2),"de PM");
            }
            if (cliquer_zone(michel[compt].posx,michel[compt].posy,50,50)==1 && *etatPOS!=1  && michel[joueurTour].PA>5 && michel[joueurTour].PM>10 )//si tu clic sur un des joueur adverse et etatPOS diff de 1
            {
                *etatPOS=1;//passage de etatPOS a 1
                michel[joueurTour].PA=michel[joueurTour].PA-5;//joueurtour perd 5 PA
                michel[joueurTour].PM=michel[joueurTour].PM-10;//joueur tour perd 10 PM
                if(rand()%100 >= 10)
                {
                    inverse_pos(michel,compt,joueurTour);//APPELLE DU SOUS PROG pour invers� les positions
                    play_sample(esquive,50,125,1003,0);
                }
                else
                {
                    play_sample(esquive,200,125,1003,0);//joue un son esquive quand alea est <10
                }

            }
        }
    }
}


void Deuxieme_Sort (t_joueur* michel, int joueurTour, int nbjoueur, BITMAP* blanc, BITMAP*buffer, int *etatDEG, int *etatPOT_CP, int *etatFLECHE,int *etatPOT_LP, int classement[nbjoueur+1],int *joueurEnvie)
{
    int i,j,k,b;
    int nb;

    ///SORT 2 DE LA CLASSE 1 ///
    SAMPLE *potion;
    SAMPLE *fleche1;
    SAMPLE *mort;
    SAMPLE *esquive;

    potion = load_sample("potion.wav");
    fleche1 = load_sample("fleche.wav");
    esquive = load_sample("esquive.wav");
    mort = load_sample("MORT.wav");

    ///SORT 2 DE LA CLASSE SORCIERE : POTION DE DEGAT ///
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

                        michel[joueurTour].PA=michel[joueurTour].PA-8;//le joueur adverse perd 6 PA
                        *etatDEG=1; //EPEE PASSE A 1

                        if(rand()%100 >= 10)
                        {
                            michel[nb].PV=michel[nb].PV-12;//le joueur adverse perd 10 PV
                            michel[nb].toucher = 30;

                            play_sample(potion,80,125,1003,0);

                            if(michel[nb].PV <= 0)
                            {
                                play_sample(mort,200,125,1003,0);
                                classement[*joueurEnvie] = michel[nb].classe;
                                classement[nbjoueur] = (classement[nbjoueur])-1;
                                *joueurEnvie = *joueurEnvie -1;
                            }

                        }
                        else
                        {
                            play_sample(esquive,200,125,1003,0);
                        }
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
                        michel[joueurTour].PA=michel[joueurTour].PA-8;
                        *etatDEG=2;
                        if(rand()%100 >= 10)
                        {
                            michel[nb].PV=michel[nb].PV-12;
                            michel[nb].toucher = 30;


                            play_sample(potion,80,125,1003,0);

                            if(michel[nb].PV <= 0)
                            {
                                play_sample(mort,200,125,1003,0);
                                classement[*joueurEnvie] = michel[nb].classe;
                                classement[nbjoueur] = (classement[nbjoueur])-1;
                                *joueurEnvie = *joueurEnvie -1;
                            }

                        }
                        else
                        {
                            play_sample(esquive,200,125,1003,0);
                        }
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

                        michel[joueurTour].PA=michel[joueurTour].PA-8;
                        *etatDEG=3;
                        if(rand()%100 >= 10)
                        {
                            michel[nb].PV=michel[nb].PV-200;
                            michel[nb].toucher = 30;
                            play_sample(potion,80,125,1003,0);

                            if(michel[nb].PV <= 0)
                            {
                                play_sample(mort,200,125,1003,0);
                                classement[*joueurEnvie] = michel[nb].classe;
                                classement[nbjoueur] = (classement[nbjoueur])-1;
                                *joueurEnvie = *joueurEnvie -1;
                            }

                        }
                        else
                        {
                            play_sample(esquive,200,125,1003,0);
                        }
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
                        michel[joueurTour].PA=michel[joueurTour].PA-8;
                        *etatDEG=4;
                        if(rand()%100 >= 10)
                        {
                            michel[nb].PV=michel[nb].PV-12;
                            michel[nb].toucher = 30;
                            play_sample(potion,80,125,1003,0);

                            if(michel[nb].PV <= 0)
                            {
                                play_sample(mort,200,125,1003,0);
                                classement[*joueurEnvie] = michel[nb].classe;
                                classement[nbjoueur] = (classement[nbjoueur])-1;
                                *joueurEnvie = *joueurEnvie -1;
                            }

                        }
                        else
                        {
                            play_sample(esquive,200,125,1003,0);
                        }
                    }
                }
            }
        }
    }
    ///SORT 2 DE LA CLASSE STEVE : POTION DE DEGAT COURT PORTEE ///

    if (michel[joueurTour].classe==2)
    {
        int i;
        int j=0;
        int k=0;


        int debutx = ((michel[joueurTour].posx)-150)/50;
        int finx = ((michel[joueurTour].posx)+200)/50;

        int debuty = ((michel[joueurTour].posy)-50)/50;
        int finy = ((michel[joueurTour].posy)+150)/50;

        for (i=0; i<nbjoueur; i++)///BOUCLE incr�mentation i jusqu'au nombre de joueur
        {
            for(j = (debutx); j <(finx); j++) //parcourir l'axe des x pour voir s'il y a des adversaires autour du JOUEURTOUR
            {

                for(k = (debuty); k <(finy); k++) //parcourir l'axe des y pour voir s'il y a des adversaires JOUEURTOUR
                {

                    if((michel[joueurTour].posx == j*50) && (michel[joueurTour].posy == k*50))///prend pas en compte le joueurTour
                        continue;
                    blit(blanc, buffer, 0,0,j*50,k*50, 50,50);

                    if (michel[joueurTour].PA<5)
                    {
                        textprintf_ex(buffer,font,880,650,makecol(255,0,0),makecol(2,2,2),"vous avez pas assez");
                        textprintf_ex(buffer,font,880,660,makecol(255,0,0),makecol(2,2,2),"de PA");
                        continue;
                    }
                    if(michel[i].posx == j*50 && michel[i].posy == k*50 && michel[i].PV > 0 && michel[joueurTour].PA>5)//si adversaire est autour du joueurTour et les PV de l'adversaire > 0
                    {

                        if ((cliquer_zone(j*50,k*50, 50,50)==1) && (*etatPOT_CP !=1))//si on clic sur un joueur autour et que etat diff�rent de 1
                        {
                            michel[joueurTour].PA -= 5;//- 2 pa pour le JoueurTour

                            *etatPOT_CP = 1;//passage de etat a 1

                            if(rand()%100 >= 10)
                            {
                                michel[i].toucher = 30;
                                michel[i].PV -=15;
                                play_sample(potion,80,125,1003,0);

                                if(michel[i].PV <= 0)
                                {
                                    play_sample(mort,200,125,1003,0);
                                    classement[*joueurEnvie] = michel[i].classe;
                                    classement[nbjoueur] = (classement[nbjoueur])-1;
                                    *joueurEnvie = *joueurEnvie -1;
                                }

                            }
                            else
                            {
                                play_sample(esquive,200,125,1003,0);
                            }
                        }
                    }
                }
            }
        }
    }

    ///SORT 2 DE LA CLASSE SQUELETTE : FLECHE
    int fleche;
    int cont=0;
    if (michel[joueurTour].classe==3)
    {
        for (fleche=0; fleche<nbjoueur; fleche++)///parcour d'un flecheeur jusqu'a le nombre de joueur choisie
        {
            if (fleche==joueurTour)//si flecheeur est �gal a la meme valeur du joueur actuelle
            {
                continue;//sort de la boucle
            }

            // blit(blanc, buffer, 0,0,michel[fleche].posx,michel[fleche].posy, 50,50);///affichage du carrer surbrillance blanc

            if( ((michel[fleche].posx > michel[joueurTour].posx+150) || (michel[fleche].posx < michel[joueurTour].posx-150)) || ((michel[fleche].posy > michel[joueurTour].posy+150) || (michel[fleche].posy < michel[joueurTour].posy-150)) )
            {
                if(michel[fleche].PV > 0)
                {
                    blit(blanc, buffer, 0,0,michel[fleche].posx,michel[fleche].posy, 50,50);///affichage du carrer surbrillance blanc
                }

                if (cliquer_zone(michel[fleche].posx,michel[fleche].posy,50,50)==1 && *etatFLECHE!=1 && michel[joueurTour].PA>8 && michel[fleche].PV>14)//si tu clic sur un des joueur adverse et etatPOS diff de 1
                {
                    *etatFLECHE=1;//passage de etatPOS a 1
                    michel[joueurTour].PA=michel[joueurTour].PA-8;//joueurtour perd 4 PA

                    if(rand()%100 >= 10)
                    {
                        michel[fleche].PV=michel[fleche].PV-14;//joueur tour perd 8 PM
                        michel[fleche].toucher = 30;
                        play_sample(fleche1,80,125,1003,0);

                        if(michel[fleche].PV <= 0)
                        {
                            play_sample(mort,200,125,1003,0);
                            classement[*joueurEnvie] = michel[fleche].classe;
                            classement[nbjoueur] = (classement[nbjoueur])-1;
                            *joueurEnvie = *joueurEnvie -1;
                        }

                    }
                    else
                    {
                        play_sample(esquive,200,125,1003,0);
                    }
                }
                else
                {
                    textprintf_ex(buffer,font,880,670,makecol(255,0,0),makecol(2,2,2),"vous avez pas assez");
                    textprintf_ex(buffer,font,880,680,makecol(255,0,0),makecol(2,2,2),"de PA ");
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

    ///SORT 2 DE LA CLASSE ZOMBIE : POTION DE DEGAT LONG PORTEE

    if (michel[joueurTour].classe==4)
    {
        int a=0;
        int j=0;
        int k=0;


        int debutx = ((michel[joueurTour].posx)-200)/50;
        int finx = ((michel[joueurTour].posx)+250)/50;

        int debuty = ((michel[joueurTour].posy)-150)/50;
        int finy = ((michel[joueurTour].posy)+200)/50;

        for (a=0; a<nbjoueur; a++)///BOUCLE incr�mentation i jusqu'au nombre de joueur
        {
            for(j = (debutx); j <(finx); j++) //parcourir l'axe des x pour voir s'il y a des adversaires autour du JOUEURTOUR
            {

                for(k = (debuty); k <(finy); k++) //parcourir l'axe des y pour voir s'il y a des adversaires JOUEURTOUR
                {

                    if((michel[joueurTour].posx == j*50) && (michel[joueurTour].posy == k*50))///prend pas en compte le joueurTour
                        continue;

                    if(((j*50>michel[joueurTour].posx-150) && (j*50<michel[joueurTour].posx+150))&&((k*50>michel[joueurTour].posy-150) && (k*50<michel[joueurTour].posy+150)))///prend pas en compte le joueurTour
                        continue;

                    blit(blanc, buffer, 0,0,j*50,k*50, 50,50);

                    if (michel[joueurTour].PA<8)
                    {
                        textprintf_ex(buffer,font,880,650,makecol(255,0,0),makecol(2,2,2),"vous avez pas assez");
                        textprintf_ex(buffer,font,880,660,makecol(255,0,0),makecol(2,2,2),"de PA");
                        continue;
                    }

                    if(michel[a].posx == j*50 && michel[a].posy == k*50 && michel[a].PV > 0 && michel[joueurTour].PA>15 )//si adversaire est autour du joueurTour et les PV de l'adversaire > 0
                    {
                        if ((cliquer_zone(j*50,k*50, 50,50)==1) && (*etatPOT_LP !=1))//si on clic sur un joueur autour et que etat diff�rent de 1
                        {
                            michel[joueurTour].PA -= 8;//- 2 pa pour le JoueurTour

                            *etatPOT_LP = 1;//passage de etat a 1
                            if(rand()%100 >= 10)
                            {
                                michel[a].toucher = 30;
                                michel[a].PV -=15;
                                play_sample(potion,80,125,1003,0);

                                if(michel[fleche].PV <= 0)
                                {
                                    play_sample(mort,200,125,1003,0);
                                    classement[*joueurEnvie] = michel[a].classe;
                                    classement[nbjoueur] = (classement[nbjoueur])-1;
                                    *joueurEnvie = *joueurEnvie -1;
                                }

                            }
                            else
                            {
                                play_sample(esquive,200,125,1003,0);
                            }
                        }
                    }
                }
            }
        }
    }
}


void toisieme_SORT(t_joueur* michel, int joueurTour, int nbjoueur, BITMAP* blanc, BITMAP*buffer, int*etatINV2, int*etatFEU, int *etatBOOM,int* etatPoing,int classement[nbjoueur+1],int *joueurEnvie)
{

    SAMPLE *mort;
    SAMPLE *esquive;
    SAMPLE *missile;
    SAMPLE *flecheEnflammer;

    esquive = load_sample("esquive.wav");
    mort = load_sample("MORT.wav");
    missile = load_sample("missile.wav");
    flecheEnflammer = load_sample("fuse_feu.wav");

    ///3E SORT DE LA CLASSE 1: inversement de position
    if (michel[joueurTour].classe==1)
    {
        int nb=0;
        for (nb=0; nb<nbjoueur; nb++)///parcour d'un nbeur jusqu'a le nombre de joueur choisie
        {
            if (nb==joueurTour)//si nbeur est �gal a la meme valeur du joueur actuelle
            {
                continue;//sort de la boucle
            }

            blit(blanc, buffer, 0,0,michel[nb].posx,michel[nb].posy, 50,50);///affichage du carrer surbrillance blanc

            if (michel[joueurTour].PA<5)
            {
                textprintf_ex(buffer,font,880,650,makecol(255,0,0),makecol(2,2,2),"vous avez pas assez");
                textprintf_ex(buffer,font,880,660,makecol(255,0,0),makecol(2,2,2),"de PA");
                continue;
            }
            if (michel[joueurTour].PM<10)
            {
                textprintf_ex(buffer,font,880,650,makecol(255,0,0),makecol(2,2,2),"vous avez pas assez");
                textprintf_ex(buffer,font,880,660,makecol(255,0,0),makecol(2,2,2),"de PM");
                continue;
            }

            if (cliquer_zone(michel[nb].posx,michel[nb].posy,50,50)==1 && *etatINV2!=1 && michel[joueurTour].PA>5 && michel[joueurTour].PM>10)//si tu clic sur un des joueur adverse et etatPOS diff de 1
            {
                *etatINV2=1;//passage de etatPOS a 1
                michel[joueurTour].PA=michel[joueurTour].PA-5;//joueurtour perd 5 PA

                if(rand()%100 >= 10)
                {
                    michel[nb].toucher = 30;
                    michel[joueurTour].PM=michel[joueurTour].PM-10;//joueur tour perd 10 PM
                    inverse_pos(michel,nb,joueurTour);//APPELLE DU SOUS PROG pour invers� les positions
                    play_sample(esquive,80,125,1003,0);
                }
                else
                {
                    play_sample(esquive,200,125,1003,0);
                }
            }
        }
    }

    ///3E SORT DE LA CLASSE 2 : COUP DE POING///

    if (michel[joueurTour].classe==2)
    {
        attaque_poison(michel,joueurTour, nbjoueur, blanc, buffer, etatPoing,classement,joueurEnvie);

    }

    ///3E SORT DE LA CLASSE 3 : FLECHE EN FEU

    if (michel[joueurTour].classe==3)
    {
        int feu;
        int plus;
        if (michel[joueurTour].classe==3)
        {
            for (feu=0; feu<nbjoueur; feu++)///parcour d'un flecheeur jusqu'a le nombre de joueur choisie
            {
                if (feu==joueurTour)//si flecheeur est �gal a la meme valeur du joueur actuelle
                {
                    continue;//sort de la boucle
                }

                if( ((michel[feu].posx > michel[joueurTour].posx+350) || (michel[feu].posx < michel[joueurTour].posx-350)) || ((michel[feu].posy > michel[joueurTour].posy+350) || (michel[feu].posy < michel[joueurTour].posy-350)) )
                {

                    if(michel[feu].PV > 0)
                    {
                        blit(blanc, buffer, 0,0,michel[feu].posx,michel[feu].posy, 50,50);///affichage du carrer surbrillance blanc
                    }
                    if (michel[joueurTour].PA<10)
                    {
                        textprintf_ex(buffer,font,880,650,makecol(255,0,0),makecol(2,2,2),"vous avez pas assez");
                        textprintf_ex(buffer,font,880,660,makecol(255,0,0),makecol(2,2,2),"de PA");
                        continue;
                    }

                    if (cliquer_zone(michel[feu].posx,michel[feu].posy,50,50)==1 && *etatFEU!=1 )//si tu clic sur un des joueur adverse et etatPOS diff de 1
                    {
                        *etatFEU=1;//passage de etatPOS a 1
                        michel[feu].toucher = 30;
                        michel[joueurTour].PA=michel[joueurTour].PA-10;//joueurtour perd 4 PA

                        if(rand()%100 >= 10)
                        {
                            michel[feu].PV=michel[feu].PV-20;//joueur tour perd 8 PM
                            michel[feu].toucher = 30;
                            play_sample(flecheEnflammer,80,125,1003,0);

                            if(michel[feu].PV <= 0)
                            {
                                play_sample(mort,200,125,1003,0);
                                classement[*joueurEnvie] = michel[feu].classe;
                                classement[nbjoueur] = (classement[nbjoueur])-1;
                                *joueurEnvie = *joueurEnvie -1;
                            }

                        }
                        else
                        {
                            play_sample(esquive,200,125,1003,0);
                        }

                    }


                }
                else
                {
                    plus=plus+1;
                    textprintf_ex(buffer,font,880,650,makecol(255,0,0),makecol(2,2,2),"%d adversaire(s) trop",plus);
                    textprintf_ex(buffer,font,880,660,makecol(255,0,0),makecol(2,2,2),"pret ");
                }
            }
        }


    }

    ///sort 3 de la classe Zombie : effet missile
    int boom=0;

    if (michel[joueurTour].classe==4)
    {
        for (boom=0; boom<nbjoueur; boom++)///parcour d'un flecheeur jusqu'a le nombre de joueur choisie
        {
            if (boom==joueurTour)//si flecheeur est �gal a la meme valeur du joueur actuelle
            {
                continue;//sort de la boucle
            }

            if(michel[boom].PV > 0)
            {
                blit(blanc, buffer, 0,0,michel[boom].posx,michel[boom].posy, 50,50);///affichage du carrer surbrillance blanc
            }
            if (michel[joueurTour].PA<15)
            {
                textprintf_ex(buffer,font,880,650,makecol(255,0,0),makecol(2,2,2),"vous avez pas assez");
                textprintf_ex(buffer,font,880,660,makecol(255,0,0),makecol(2,2,2),"de PA");
                continue;
            }

            if (cliquer_zone(michel[boom].posx,michel[boom].posy,50,50)==1 && *etatBOOM!=1 )//si tu clic sur un des joueur adverse et etatPOS diff de 1
            {

                *etatBOOM=1;//passage de etatPOS a 1
                michel[joueurTour].PA=michel[joueurTour].PA-15;//joueurtour perd 4 PA

                if(rand()%100 >= 10)
                {
                    michel[boom].PV=michel[boom].PV-30;//joueur tour perd 8 PM
                    michel[boom].toucher = 30;
                    play_sample(missile,80,125,1003,0);

                    if(michel[boom].PV <= 0)
                    {
                        play_sample(mort,200,125,1003,0);
                        classement[*joueurEnvie] = michel[boom].classe;
                        classement[nbjoueur] = (classement[nbjoueur])-1;
                        *joueurEnvie = *joueurEnvie -1;
                    }

                }
                else
                {
                    play_sample(esquive,200,125,1003,0);
                }
            }
        }
    }

}

///sous programme quatrieme sort des classes///
void attaqueQuatrieme_SORT(t_joueur *michel, int joueurTour,BITMAP*orange,BITMAP*buffer, int nb_joueur, int* etat,int* etat2,int* etat3,int* etat4, int classement[nb_joueur+1],int *joueurEnvie)
{
    switch(michel[joueurTour].classe)
    {
    case 1:
    {
        attaque_poison(michel,joueurTour, nb_joueur, orange, buffer, etat3,classement,joueurEnvie);
        break;
    }

    case 2:
    {
        attaque_epee_celeste(michel,joueurTour, nb_joueur, orange, buffer, etat4,classement,joueurEnvie);
        break;
    }

    case 3: //classe 3
    {
        sort_vol_vie(michel,joueurTour,orange,buffer, nb_joueur, etat,classement,joueurEnvie);
        break;
    }


    case 4: //classe 4
    {
        attaque_zone(michel,joueurTour,orange,buffer, nb_joueur, etat2,classement,joueurEnvie);

        break;
    }
    }
}

//le joueur qui lance, gagne les pv de degats qu'il a inflige
void sort_vol_vie(t_joueur *michel, int joueurTour,BITMAP*orange,BITMAP*buffer, int nb_joueur, int* etat, int classement[nb_joueur+1],int *joueurEnvie)
{
    int i,j,k;
    SAMPLE *degatSteve;
    SAMPLE *degatZombie;
    SAMPLE *degatSkeleton;
    SAMPLE *degatSorciere;
    SAMPLE *esquive;
    SAMPLE *mort;

    int debutx = ((michel[joueurTour].posx)-100)/50;
    int finx = ((michel[joueurTour].posx)+150)/50;

    int debuty = ((michel[joueurTour].posy)-100)/50;
    int finy = ((michel[joueurTour].posy)+200)/50;

    degatSteve = load_sample("degat_steve.wav");
    degatZombie = load_sample("degat_zombie.wav");
    degatSkeleton = load_sample("degat_skeleton.wav");
    degatSorciere = load_sample("degat_villagoie.wav");
    esquive = load_sample("esquive.wav");
    mort = load_sample("MORT.wav");

    for (i=0; i<nb_joueur; i++)
    {
        for(j = (debutx); j <(finx); j++)
        {

            for(k = (debuty); k <(finy); k++)
            {
                blit(orange, buffer, 0,0,j*50,k*50, 50,50);
                if(michel[i].posx == j*50 && michel[i].posy == k*50 && michel[i].PV > 0)
                {
                    if((michel[joueurTour].posx == j*50) && (michel[joueurTour].posy == k*50))
                        continue;

                    blit(orange, buffer, 0,0,j*50,k*50, 50,50);

                    if (michel[joueurTour].PA < 5)
                    {
                        textprintf_ex(buffer,font,880,650,makecol(255,0,0),makecol(2,2,2),"vous avez pas assez");
                        textprintf_ex(buffer,font,880,660,makecol(255,0,0),makecol(2,2,2),"de PA");
                        continue;
                    }
                    if ((cliquer_zone(j*50,k*50, 50,50)==1) && (*etat !=1))
                    {
                        michel[joueurTour].PA -= 5;

                        *etat = 1;

                        if(rand()%100 >=10) // 10% de chance de raté
                        {
                            michel[i].toucher = 30;


                            michel[i].PV -=10; // ennemis perd 10 PV
                            michel[joueurTour].PV +=10; //gagne 10 PV


                            //sons des degats
                            if(michel[i].classe == 1 && michel[i].PV > 0)
                            {
                                play_sample(degatSorciere,200,125,1003,0);
                            }
                            else if(michel[i].classe == 2 && michel[i].PV > 0)
                            {
                                play_sample(degatSteve,200,125,1003,0);
                            }
                            else if (michel[i].classe == 3 && michel[i].PV > 0)
                            {
                                play_sample(degatSkeleton,200,125,1003,0);
                            }
                            else if (michel[i].classe == 4 && michel[i].PV > 0)
                            {
                                play_sample(degatZombie,1000,125,1003,0);
                            }


                            if(michel[i].PV <= 0)
                            {
                                play_sample(mort,200,125,1003,0);
                                classement[*joueurEnvie] = michel[i].classe;
                                classement[nb_joueur] = (classement[nb_joueur])-1;
                                *joueurEnvie = *joueurEnvie -1;
                            }
                            else  {}
                        }
                        else //si le coup est raté
                        {
                            play_sample(esquive,200,125,1003,0);
                        }
                    }
                }
            }
        }
    }

}

//sort courte porter permettant de frapper tout les enemis a proximité
void attaque_zone(t_joueur *michel, int joueurTour,BITMAP*orange,BITMAP*buffer, int nb_joueur, int* etat, int classement[nb_joueur+1],int *joueurEnvie)
{

    SAMPLE *esquive;
    SAMPLE *mort;
    SAMPLE *coup_epee;

    esquive = load_sample("esquive.wav");
    mort = load_sample("MORT.wav");
    coup_epee = load_sample("coup_epee.wav");
        ///sort 3 de la classe Zombie : effet missile
    int boom=0;

    if (michel[joueurTour].classe==4)
    {
        for (boom=0; boom<nb_joueur; boom++)///parcour d'un flecheeur jusqu'a le nombre de joueur choisie
        {
            if (boom==joueurTour)//si flecheeur est �gal a la meme valeur du joueur actuelle
            {
                continue;//sort de la boucle
            }

            if(michel[boom].PV > 0)
            {
                blit(orange, buffer, 0,0,michel[boom].posx,michel[boom].posy, 50,50);///affichage du carrer surbrillance blanc
            }
            if (michel[joueurTour].PA<10)
            {
                textprintf_ex(buffer,font,880,650,makecol(255,0,0),makecol(2,2,2),"vous avez pas assez");
                textprintf_ex(buffer,font,880,660,makecol(255,0,0),makecol(2,2,2),"de PA");
                continue;
            }

            if (cliquer_zone(michel[boom].posx,michel[boom].posy,50,50)==1 && *etat!=1 )//si tu clic sur un des joueur adverse et etatPOS diff de 1
            {

                *etat=1;//passage de etatPOS a 1
                michel[joueurTour].PA=michel[joueurTour].PA-10;//joueurtour perd 4 PA

                if(rand()%100 >= 10)
                {
                    michel[boom].PV=michel[boom].PV-15;//joueur tour perd 8 PM
                    michel[boom].toucher = 30;
                    play_sample(coup_epee,80,125,1003,0);

                    if(michel[boom].PV <= 0)
                    {
                        play_sample(mort,200,125,1003,0);
                        classement[*joueurEnvie] = michel[boom].classe;
                        classement[nb_joueur] = (classement[nb_joueur])-1;
                        *joueurEnvie = *joueurEnvie -1;
                    }

                }
                else
                {
                    play_sample(esquive,200,125,1003,0);
                }
            }
        }
    }

}


//sort tres courte porte permettant de frapper une personne
void attaque_poison(t_joueur* michel, int joueurTour, int nb_joueur, BITMAP* blanc, BITMAP*buffer,int* etat,int classement[nb_joueur+1],int *joueurEnvie)
{
    int nb,i,j,k,b;

    SAMPLE *esquive;
    SAMPLE *mort;
    SAMPLE *potion;
    SAMPLE *poing;

    esquive = load_sample("esquive.wav");
    mort = load_sample("MORT.wav");
    potion = load_sample("potion.wav");
    poing = load_sample("frappe.wav");

    for (nb=0; nb<nb_joueur; nb++)///parcourir le nombre de joueur
    {

        for (i=michel[joueurTour].posy; i<michel[joueurTour].posy+100; i=i+50)//parcour de la position en y+ jusqu'a posy+200
        {
            blit(blanc, buffer, 0,0,michel[joueurTour].posx,i, 50,50);//affichage du carre en y+

            if (michel[joueurTour].posy==i)//si le joueur actuelle a les meme position en y que i alors
                continue;//sort de la boucle

            if (michel[nb].posy==i)///si joueur adverse a les meme position en y que i
            {
                if (michel[joueurTour].PA<10)//si les PA du
                {
                    textprintf_ex(buffer,font,880,650,makecol(255,0,0),makecol(2,2,2),"vous avez pas assez");
                    textprintf_ex(buffer,font,880,660,makecol(255,0,0),makecol(2,2,2),"de PA");
                    continue;//sort de la boucle
                }
                if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etat!=1))// si le joueur clic sur la zone et que etatepee != 1
                {

                    if(michel[joueurTour].classe == 2)
                    {
                        play_sample(poing,80,125,1003,0);
                    }
                    else if (michel[joueurTour].classe == 1)
                    {
                        play_sample(potion,80,128,1003,0);
                    }
                    if(rand()%100>10)
                    {
                        michel[nb].PV=michel[nb].PV-25;//le joueur adverse perd 10 PV
                        michel[joueurTour].PA=michel[joueurTour].PA-10;//le joueur adverse perd 6 PA
                        michel[nb].toucher = 30;
                        play_sample(poing,80,125,1003,0);
                        printf("POING\n");

                        if(michel[nb].PV <= 0) // si le joueur meurt
                        {
                            play_sample(mort,200,125,1003,0);
                            classement[*joueurEnvie] = michel[nb].classe;
                            classement[nb_joueur] = (classement[nb_joueur])-1;
                            *joueurEnvie = *joueurEnvie -1;
                        }
                    }
                    else
                    {
                        play_sample(esquive,200,125,1003,0);
                    }
                    *etat=1; //etat a 1

                }
            }
        }


        ///MEME CHOSE POUR LES POSITIONS EN X- X+ Y-//

        for (j=michel[joueurTour].posy; j>michel[joueurTour].posy-100; j=j-50)
        {
            blit(blanc, buffer, 0,0,michel[joueurTour].posx,j, 50,50);
            if (michel[joueurTour].posy==j)
                continue;

            if (michel[nb].posy==j)
            {
                if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etat!=1))
                {
                    if (michel[joueurTour].PA<10)
                    {
                        textprintf_ex(buffer,font,880,650,makecol(255,0,0),makecol(2,2,2),"vous avez pas assez");
                        textprintf_ex(buffer,font,880,660,makecol(255,0,0),makecol(2,2,2),"de PA");
                        continue;
                    }

                    if(michel[joueurTour].classe == 2)
                    {
                        play_sample(poing,80,125,1003,0);
                    }
                    else if (michel[joueurTour].classe == 1)
                    {
                        play_sample(potion,80,128,1003,0);
                    }

                    if(rand()%100>10)
                    {
                        michel[nb].PV=michel[nb].PV-25;//le joueur adverse perd 10 PV
                        michel[joueurTour].PA=michel[joueurTour].PA-10;//le joueur adverse perd 6 PA
                        michel[nb].toucher = 30;
                        play_sample(potion,80,125,1003,0);


                        if(michel[nb].PV <= 0) // si le joueur meurt
                        {
                            play_sample(mort,200,125,1003,0);
                            classement[*joueurEnvie] = michel[nb].classe;
                            classement[nb_joueur] = (classement[nb_joueur])-1;
                            *joueurEnvie = *joueurEnvie -1;
                        }
                    }
                    else
                    {
                        play_sample(esquive,200,125,1003,0);
                    }
                    *etat=1;
                }
            }
        }
        for (k=michel[joueurTour].posx; k<michel[joueurTour].posx+100; k=k+50)
        {
            blit(blanc, buffer, 0,0,k,michel[joueurTour].posy, 50,50);

            if (michel[joueurTour].posx==k)
                continue;

            if (michel[nb].posx==k)
            {
                if (michel[joueurTour].PA<10)
                {
                    textprintf_ex(buffer,font,880,650,makecol(255,0,0),makecol(2,2,2),"vous avez pas assez");
                    textprintf_ex(buffer,font,880,660,makecol(255,0,0),makecol(2,2,2),"de PA");
                    continue;
                }
                if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etat!=1))
                {


                    if(michel[joueurTour].classe == 2)
                    {
                        play_sample(poing,80,125,1003,0);
                    }
                    else if (michel[joueurTour].classe == 1)
                    {
                        play_sample(potion,80,128,1003,0);
                    }

                    if(rand()%100>10)
                    {
                        michel[nb].PV=michel[nb].PV-25;//le joueur adverse perd 10 PV
                        michel[joueurTour].PA=michel[joueurTour].PA-10;//le joueur adverse perd 6 PA
                        michel[nb].toucher = 30;
                        play_sample(potion,80,125,1003,0);

                        if(michel[nb].PV <= 0) // si le joueur meurt
                        {
                            play_sample(mort,200,125,1003,0);
                            classement[*joueurEnvie] = michel[nb].classe;
                            classement[nb_joueur] = (classement[nb_joueur])-1;
                            *joueurEnvie = *joueurEnvie -1;
                        }
                    }
                    else
                    {
                        play_sample(esquive,200,125,1003,0);
                    }
                    *etat=1;
                }
            }


        }
        for (b=michel[joueurTour].posx; b>michel[joueurTour].posx-100; b=b-50)
        {
            blit(blanc, buffer, 0,0,b,michel[joueurTour].posy, 50,50);
            if (michel[joueurTour].posx==b)
                continue;

            if (michel[nb].posx==b)
            {
                if (michel[joueurTour].PA<10)
                {
                    textprintf_ex(buffer,font,880,650,makecol(255,0,0),makecol(2,2,2),"vous avez pas assez");
                    textprintf_ex(buffer,font,880,660,makecol(255,0,0),makecol(2,2,2),"de PA");
                    continue;
                }
                if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etat!=1))
                {


                    if(michel[joueurTour].classe == 2)
                    {
                        play_sample(poing,80,125,1003,0);
                    }
                    else if (michel[joueurTour].classe == 1)
                    {
                        play_sample(potion,80,128,1003,0);
                    }

                    if(rand()%100>10)
                    {
                        michel[nb].PV=michel[nb].PV-25;//le joueur adverse perd 10 PV
                        michel[joueurTour].PA=michel[joueurTour].PA-10;//le joueur adverse perd 6 PA
                        michel[nb].toucher = 30;
                        play_sample(potion,80,125,1003,0);

                        if(michel[nb].PV <= 0) // si le joueur meurt
                        {
                            play_sample(mort,200,125,1003,0);
                            classement[*joueurEnvie] = michel[nb].classe;
                            classement[nb_joueur] = (classement[nb_joueur])-1;
                            *joueurEnvie = *joueurEnvie -1;
                        }
                    }
                    else
                    {
                        play_sample(esquive,200,125,1003,0);
                    }
                    *etat=1;
                }
            }
        }
    }
}


//attaque long porté vers le haut, le bas, et les deux cotés
void attaque_epee_celeste(t_joueur* michel, int joueurTour, int nb_joueur, BITMAP* blanc, BITMAP*buffer,int* etat,int classement[nb_joueur+1],int *joueurEnvie)
{
    int nb,i,j,k,b;


    SAMPLE *degatSteve;
    SAMPLE *degatZombie;
    SAMPLE *degatSkeleton;
    SAMPLE *degatSorciere;
    SAMPLE *esquive;
    SAMPLE *mort;
    SAMPLE *epee;

    degatSteve = load_sample("degat_steve.wav");
    degatZombie = load_sample("degat_zombie.wav");
    degatSkeleton = load_sample("degat_skeleton.wav");
    degatSorciere = load_sample("degat_villagoie.wav");
    esquive = load_sample("esquive.wav");
    mort = load_sample("MORT.wav");
    epee = load_sample("coup_epee.wav");

    for (nb=0; nb<nb_joueur; nb++)///parcourir le nombre de joueur
    {

        for (i=michel[joueurTour].posy; i<michel[joueurTour].posy+300; i=i+50)//parcour de la position en y+ jusqu'a posy+200
        {
            blit(blanc, buffer, 0,0,michel[joueurTour].posx,i, 50,50);//affichage du carre en y+

            if (michel[joueurTour].posy==i)//si le joueur actuelle a les meme position en y que i alors
                continue;//sort de la boucle

            if (michel[nb].posy==i)///si joueur adverse a les meme position en y que i
            {
                if (michel[joueurTour].PA<9)//si les PA du
                    {
                        textprintf_ex(buffer,font,880,650,makecol(255,0,0),makecol(2,2,2),"vous avez pas assez");
                        textprintf_ex(buffer,font,880,660,makecol(255,0,0),makecol(2,2,2),"de PA");
                        continue;//sort de la boucle
                    }

                if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etat!=1))// si le joueur clic sur la zone et que etatepee != 1
                {

                    if(rand()%100>10)
                    {
                        michel[nb].PV=michel[nb].PV-18;//le joueur adverse perd 10 PV
                        michel[joueurTour].PA=michel[joueurTour].PA-9;//le joueur adverse perd 6 PA
                        michel[nb].toucher = 30;
                        play_sample(epee,80,125,1003,0);

                        //sons des degats
                        if(michel[nb].classe == 1 && michel[nb].PV > 0)
                        {
                            play_sample(degatSorciere,200,125,1003,0);
                        }
                        else if(michel[nb].classe == 2 && michel[nb].PV > 0)
                        {
                            play_sample(degatSteve,200,125,1003,0);
                        }
                        else if (michel[nb].classe == 3 && michel[nb].PV > 0)
                        {
                            play_sample(degatSkeleton,200,125,1003,0);
                        }
                        else if (michel[nb].classe == 4 && michel[nb].PV > 0)
                        {
                            play_sample(degatZombie,1000,125,1003,0);
                        }
                        if(michel[nb].PV <= 0) // si le joueur meurt
                        {
                            play_sample(mort,200,125,1003,0);
                            classement[*joueurEnvie] = michel[nb].classe;
                            classement[nb_joueur] = (classement[nb_joueur])-1;
                            *joueurEnvie = *joueurEnvie -1;
                        }
                    }
                    else
                    {
                        play_sample(esquive,200,125,1003,0);
                    }
                    *etat=1; //etat a 1

                }
            }
        }


        ///MEME CHOSE POUR LES POSITIONS EN X- X+ Y-//

        for (j=michel[joueurTour].posy; j>michel[joueurTour].posy-300; j=j-50)
        {
            blit(blanc, buffer, 0,0,michel[joueurTour].posx,j, 50,50);
            if (michel[joueurTour].posy==j)
                continue;

            if (michel[nb].posy==j)
            {
                if (michel[joueurTour].PA<9)
                    {
                        textprintf_ex(buffer,font,880,650,makecol(255,0,0),makecol(2,2,2),"vous avez pas assez");
                        textprintf_ex(buffer,font,880,660,makecol(255,0,0),makecol(2,2,2),"de PA");
                        continue;
                    }
                if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etat!=1))
                {

                    if(rand()%100>10)
                    {
                        michel[nb].PV=michel[nb].PV-18;//le joueur adverse perd 10 PV
                        michel[joueurTour].PA=michel[joueurTour].PA-9;//le joueur adverse perd 6 PA
                        michel[nb].toucher = 30;
                        play_sample(epee,80,125,1003,0);

                        //sons des degats
                        if(michel[nb].classe == 1 && michel[nb].PV > 0)
                        {
                            play_sample(degatSorciere,200,125,1003,0);
                        }
                        else if(michel[nb].classe == 2 && michel[nb].PV > 0)
                        {
                            play_sample(degatSteve,200,125,1003,0);
                        }
                        else if (michel[nb].classe == 3 && michel[nb].PV > 0)
                        {
                            play_sample(degatSkeleton,200,125,1003,0);
                        }
                        else if (michel[nb].classe == 4 && michel[nb].PV > 0)
                        {
                            play_sample(degatZombie,1000,125,1003,0);
                        }
                        if(michel[nb].PV <= 0) // si le joueur meurt
                        {
                            play_sample(mort,200,125,1003,0);
                            classement[*joueurEnvie] = michel[nb].classe;
                            classement[nb_joueur] = (classement[nb_joueur])-1;
                            *joueurEnvie = *joueurEnvie -1;
                        }
                    }
                    else
                    {
                        play_sample(esquive,200,125,1003,0);
                    }
                    *etat=1;
                }
            }
        }
        for (k=michel[joueurTour].posx; k<michel[joueurTour].posx+300; k=k+50)
        {
            blit(blanc, buffer, 0,0,k,michel[joueurTour].posy, 50,50);

            if (michel[joueurTour].posx==k)
                continue;

            if (michel[nb].posx==k)
            {
                if (michel[joueurTour].PA<9)
                    {
                        textprintf_ex(buffer,font,880,650,makecol(255,0,0),makecol(2,2,2),"vous avez pas assez");
                        textprintf_ex(buffer,font,880,660,makecol(255,0,0),makecol(2,2,2),"de PA");
                        continue;
                    }

                if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etat!=1))
                {

                    if(rand()%100>10)
                    {
                        michel[nb].PV=michel[nb].PV-18;//le joueur adverse perd 10 PV
                        michel[joueurTour].PA=michel[joueurTour].PA-9;//le joueur adverse perd 6 PA
                        michel[nb].toucher = 30;
                        play_sample(epee,80,125,1003,0);

                        //sons des degats
                        if(michel[nb].classe == 1 && michel[nb].PV > 0)
                        {
                            play_sample(degatSorciere,200,125,1003,0);
                        }
                        else if(michel[nb].classe == 2 && michel[nb].PV > 0)
                        {
                            play_sample(degatSteve,200,125,1003,0);
                        }
                        else if (michel[nb].classe == 3 && michel[nb].PV > 0)
                        {
                            play_sample(degatSkeleton,200,125,1003,0);
                        }
                        else if (michel[nb].classe == 4 && michel[nb].PV > 0)
                        {
                            play_sample(degatZombie,1000,125,1003,0);
                        }
                        if(michel[nb].PV <= 0) // si le joueur meurt
                        {
                            play_sample(mort,200,125,1003,0);
                            classement[*joueurEnvie] = michel[nb].classe;
                            classement[nb_joueur] = (classement[nb_joueur])-1;
                            *joueurEnvie = *joueurEnvie -1;
                        }
                    }
                    else
                    {
                        play_sample(esquive,200,125,1003,0);
                    }
                    *etat=1;
                }
            }


        }
        for (b=michel[joueurTour].posx; b>michel[joueurTour].posx-300; b=b-50)
        {
            blit(blanc, buffer, 0,0,b,michel[joueurTour].posy, 50,50);
            if (michel[joueurTour].posx==b)
                continue;

            if (michel[nb].posx==b)
            {
                if (michel[joueurTour].PA<9)
                    {
                        textprintf_ex(buffer,font,880,650,makecol(255,0,0),makecol(2,2,2),"vous avez pas assez");
                        textprintf_ex(buffer,font,880,660,makecol(255,0,0),makecol(2,2,2),"de PA");
                        continue;
                    }

                if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etat!=1))
                {

                    if(rand()%100>10)
                    {
                        michel[nb].PV=michel[nb].PV-18;//le joueur adverse perd 10 PV
                        michel[joueurTour].PA=michel[joueurTour].PA-9;//le joueur adverse perd 6 PA
                        michel[nb].toucher = 30;
                        play_sample(epee,80,125,1003,0);

                        //sons des degats
                        if(michel[nb].classe == 1 && michel[nb].PV > 0)
                        {
                            play_sample(degatSorciere,200,125,1003,0);
                        }
                        else if(michel[nb].classe == 2 && michel[nb].PV > 0)
                        {
                            play_sample(degatSteve,200,125,1003,0);
                        }
                        else if (michel[nb].classe == 3 && michel[nb].PV > 0)
                        {
                            play_sample(degatSkeleton,200,125,1003,0);
                        }
                        else if (michel[nb].classe == 4 && michel[nb].PV > 0)
                        {
                            play_sample(degatZombie,1000,125,1003,0);
                        }
                        if(michel[nb].PV <= 0) // si le joueur meurt
                        {
                            play_sample(mort,200,125,1003,0);
                            classement[*joueurEnvie] = michel[nb].classe;
                            classement[nb_joueur] = (classement[nb_joueur])-1;
                            *joueurEnvie = *joueurEnvie -1;
                        }
                    }
                    else
                    {
                        play_sample(esquive,200,125,1003,0);
                    }
                    *etat=1;
                }
            }
        }
    }
}



