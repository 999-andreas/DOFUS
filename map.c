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
        draw_sprite(buffer, skins[(michel[i].classe)-1], (michel[i].posx), (michel[i].posy));
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


void deplacement_case(t_joueur* michel, int maps[26][12],int nb_joueur,int joueurTour,int *bouger)
{
    int i = 0;
    int j = 0;

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
                    michel[joueurTour].posx = i*50;
                    (michel[joueurTour].PM)--;
                    deplace++;
                }
                // SI ON CLICK SUR LA CASE DE DROITE
                else if ( (i*50 <= michel[joueurTour].posx+50) && (michel[joueurTour].posx <= i*50-50) && ((j-1)*50 == michel[joueurTour].posy) && ((michel[joueurTour].PM) >= 0) && (*bouger != 3))
                {
                    michel[joueurTour].posx = i*50;
                    (michel[joueurTour].PM)--;
                    deplace++;
                }
                // SI ON CLICK SUR LA CASE AU DESSUS
                else if ( (j*50-50 <= michel[joueurTour].posy-50) && (michel[joueurTour].posy <= j*50) && (i*50 == michel[joueurTour].posx) && ((michel[joueurTour].PM) >= 0) && (*bouger != 3))
                {
                    michel[joueurTour].posy = j*50-50;
                    (michel[joueurTour].PM)--;
                    deplace++;
                }
                // SI ON CLICK SUR LA CASE D'EN BAS
                else if ( ( j*50 <= michel[joueurTour].posy+100) && (michel[joueurTour].posy <= j*50-100) && (i*50 == michel[joueurTour].posx) && ((michel[joueurTour].PM) >= 0) && (*bouger != 3))
                {
                    michel[joueurTour].posy = j*50-50;
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


void attaqueQuatrieme_SORT(t_joueur *michel, int joueurTour,BITMAP*orange,BITMAP*buffer, int nb_joueur, int* etat,int* etat2,int* etat3,int* etat4, int classement[nb_joueur+1],int *joueurEnvie)
{
        switch(michel[joueurTour].classe)
        {
        case 1:
            {
                attaque_poison(michel,joueurTour, nb_joueur, orange, buffer, etat3);
                break;
            }

        case 2:
            {
                attaque_epee_celeste(michel,joueurTour, nb_joueur, orange, buffer, etat4);
                break;
            }

        case 3:
            {
                sort_vol_vie(michel,joueurTour,orange,buffer, nb_joueur, etat,classement,joueurEnvie);
                break;
            }


        case 4:
            {
                attaque_zone(michel,joueurTour,orange,buffer, nb_joueur, etat2,classement,joueurEnvie);

                break;
            }
        }
}


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

                    if ((cliquer_zone(j*50,k*50, 50,50)==1) && (*etat !=1))
                    {
                        michel[joueurTour].PA -= 5;

                        *etat = 1;

                        if(rand()%100 >=10)
                        {
                            michel[i].toucher = 30;

                            printf("avant: %d\n",michel[i].PV);
                            michel[i].PV -=10;
                            michel[joueurTour].PV +=10;
                            printf("apres: %d\n",michel[i].PV);

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


                            if(michel[i].PV < 0)
                            {
                                play_sample(mort,200,125,1003,0);
                                classement[*joueurEnvie] = michel[i].classe;
                                classement[nb_joueur] = (classement[nb_joueur])-1;

                                //printf("JoueurEnvie %d et Classe MORTTTTTTTTTTTTT: %d\n",*joueurEnvie,michel[i].classe);
                                //printf("Classement[joueurTour] = %d\n",classement[*joueurEnvie]);

                                *joueurEnvie = *joueurEnvie -1;
                                //printf("JOUEUR ENVIE : %d\n",classement[nb_joueur+1]);
                            }
                            else  {}
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

void attaque_zone(t_joueur *michel, int joueurTour,BITMAP*orange,BITMAP*buffer, int nb_joueur, int* etat, int classement[nb_joueur+1],int *joueurEnvie)
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

    if(*etat!=1)
    {
        for (i=0; i<nb_joueur; i++)
        {
            for(j = (debutx); j <(finx); j++)
            {

                for(k = (debuty); k <(finy); k++)
                {

                    if(michel[i].posx == j*50 && michel[i].posy == k*50 && michel[i].PV > 0 )
                    {
                        if((michel[joueurTour].posx == j*50) && (michel[joueurTour].posy == k*50))
                            continue;

                        blit(orange, buffer, 0,0,j*50,k*50, 50,50);

                        michel[joueurTour].PA -= 2;

                        if(rand()%100>50)
                        {
                            michel[i].toucher = 30;

                            printf("avant: %d\n",michel[i].PV);
                            michel[i].PV -=20;
                            printf("apres: %d\n",michel[i].PV);

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


                            if(michel[i].PV < 0) // si le joueur meurt
                            {
                                play_sample(mort,200,125,1003,0);
                                classement[*joueurEnvie] = michel[i].classe;
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
        *etat = 1;
    }
}

void attaque_poison(t_joueur* michel, int joueurTour, int nb_joueur, BITMAP* blanc, BITMAP*buffer,int* etat)
{
    int nb,i,j,k,b;


    SAMPLE *degatSteve;
    SAMPLE *degatZombie;
    SAMPLE *degatSkeleton;
    SAMPLE *degatSorciere;
    SAMPLE *esquive;
    SAMPLE *mort;

    degatSteve = load_sample("degat_steve.wav");
    degatZombie = load_sample("degat_zombie.wav");
    degatSkeleton = load_sample("degat_skeleton.wav");
    degatSorciere = load_sample("degat_villagoie.wav");
    esquive = load_sample("esquive.wav");
    mort = load_sample("MORT.wav");

    for (nb=0; nb<nb_joueur; nb++)///parcourir le nombre de joueur
    {

        for (i=michel[joueurTour].posy; i<michel[joueurTour].posy+100; i=i+50)//parcour de la position en y+ jusqu'a posy+200
        {
            blit(blanc, buffer, 0,0,michel[joueurTour].posx,i, 50,50);//affichage du carre en y+

            if (michel[joueurTour].posy==i)//si le joueur actuelle a les meme position en y que i alors
                continue;//sort de la boucle

            if (michel[nb].posy==i)///si joueur adverse a les meme position en y que i
            {
                if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etat!=1))// si le joueur clic sur la zone et que etatepee != 1
                {
                   if (michel[joueurTour].PA<10)//si les PA du
                    {
                        continue;//sort de la boucle
                    }
                    if(rand()%100>50)
                    {
                         michel[nb].PV=michel[nb].PV-10;//le joueur adverse perd 10 PV
                        michel[joueurTour].PA=michel[joueurTour].PA-6;//le joueur adverse perd 6 PA
                        michel[nb].toucher = 30;

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
                        continue;
                    }
                    if(rand()%100>50)
                    {
                        michel[nb].PV=michel[nb].PV-10;//le joueur adverse perd 10 PV
                        michel[joueurTour].PA=michel[joueurTour].PA-6;//le joueur adverse perd 6 PA
                        michel[nb].toucher = 30;

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
                if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etat!=1))
                {
                    if (michel[joueurTour].PA<10)
                    {
                        continue;
                    }
                    if(rand()%100>50)
                    {
                         michel[nb].PV=michel[nb].PV-10;//le joueur adverse perd 10 PV
                        michel[joueurTour].PA=michel[joueurTour].PA-6;//le joueur adverse perd 6 PA
                        michel[nb].toucher = 30;

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
                if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etat!=1))
                {
                    if (michel[joueurTour].PA<10)
                    {
                        continue;
                    }
                    if(rand()%100>50)
                    {
                         michel[nb].PV=michel[nb].PV-10;//le joueur adverse perd 10 PV
                        michel[joueurTour].PA=michel[joueurTour].PA-6;//le joueur adverse perd 6 PA
                        michel[nb].toucher = 30;

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

void attaque_epee_celeste(t_joueur* michel, int joueurTour, int nb_joueur, BITMAP* blanc, BITMAP*buffer,int* etat)
{
    int nb,i,j,k,b;


    SAMPLE *degatSteve;
    SAMPLE *degatZombie;
    SAMPLE *degatSkeleton;
    SAMPLE *degatSorciere;
    SAMPLE *esquive;
    SAMPLE *mort;

    degatSteve = load_sample("degat_steve.wav");
    degatZombie = load_sample("degat_zombie.wav");
    degatSkeleton = load_sample("degat_skeleton.wav");
    degatSorciere = load_sample("degat_villagoie.wav");
    esquive = load_sample("esquive.wav");
    mort = load_sample("MORT.wav");

    for (nb=0; nb<nb_joueur; nb++)///parcourir le nombre de joueur
    {

        for (i=michel[joueurTour].posy; i<michel[joueurTour].posy+300; i=i+50)//parcour de la position en y+ jusqu'a posy+200
        {
            blit(blanc, buffer, 0,0,michel[joueurTour].posx,i, 50,50);//affichage du carre en y+

            if (michel[joueurTour].posy==i)//si le joueur actuelle a les meme position en y que i alors
                continue;//sort de la boucle

            if (michel[nb].posy==i)///si joueur adverse a les meme position en y que i
            {
                if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etat!=1))// si le joueur clic sur la zone et que etatepee != 1
                {
                   if (michel[joueurTour].PA<10)//si les PA du
                    {
                        continue;//sort de la boucle
                    }
                    if(rand()%100>50)
                    {
                         michel[nb].PV=michel[nb].PV-10;//le joueur adverse perd 10 PV
                        michel[joueurTour].PA=michel[joueurTour].PA-6;//le joueur adverse perd 6 PA
                        michel[nb].toucher = 30;

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
                if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etat!=1))
                {
                    if (michel[joueurTour].PA<10)
                    {
                        continue;
                    }
                    if(rand()%100>50)
                    {
                        michel[nb].PV=michel[nb].PV-10;//le joueur adverse perd 10 PV
                        michel[joueurTour].PA=michel[joueurTour].PA-6;//le joueur adverse perd 6 PA
                        michel[nb].toucher = 30;

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
                if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etat!=1))
                {
                    if (michel[joueurTour].PA<10)
                    {
                        continue;
                    }
                    if(rand()%100>50)
                    {
                         michel[nb].PV=michel[nb].PV-10;//le joueur adverse perd 10 PV
                        michel[joueurTour].PA=michel[joueurTour].PA-6;//le joueur adverse perd 6 PA
                        michel[nb].toucher = 30;

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
                if (cliquer_zone(michel[nb].posx,michel[nb].posy, 50,50)==1 && (*etat!=1))
                {
                    if (michel[joueurTour].PA<10)
                    {
                        continue;
                    }
                    if(rand()%100>50)
                    {
                         michel[nb].PV=michel[nb].PV-10;//le joueur adverse perd 10 PV
                        michel[joueurTour].PA=michel[joueurTour].PA-6;//le joueur adverse perd 6 PA
                        michel[nb].toucher = 30;

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





void classementTop(t_joueur *michel, int nb_joueur, int classement[nb_joueur+1],int joueurTour)
{
    BITMAP *podium;

    BITMAP *steveNormal;
    BITMAP *zombieNormal;
    BITMAP *sorciereNR;
    BITMAP *skeletteNormal;

    BITMAP *steveRoi;
    BITMAP *skeletteRoi;
    BITMAP *zombieRoi;

    SAMPLE *victoire;

    steveNormal = load_bitmap("images/steveNormal.bmp",NULL);
    zombieNormal = load_bitmap("images/zombieNormal.bmp",NULL);
    sorciereNR = load_bitmap("images/sorcierNormal.bmp",NULL);
    skeletteNormal = load_bitmap("images/skeletteNormal.bmp",NULL);

    steveRoi = load_bitmap("images/steveRoi.bmp",NULL);
    skeletteRoi = load_bitmap("images/skeletteRoi.bmp",NULL);
    zombieRoi = load_bitmap("images/zombieRoi.bmp",NULL);

    podium = load_bitmap("images/podium.bmp",NULL);

    victoire = load_sample("victoire.wav");
    play_sample(victoire,50,125,1003,5);
    time_t temps = time(NULL);

    while(time(NULL)-temps < 3000)
    {
    int i =0;
    for(i=0; i<3; i++)
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
    blit(podium,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
    destroy_sample(victoire);
}



