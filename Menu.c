#include "header.h"

void nbr_joueur(int i)
{

    BITMAP *joueur;
    BITMAP * page;

    BITMAP *sprite_transp;

    page=create_bitmap(1300,700);
    joueur=load_bitmap("joueur.bmp",NULL);

    //int choixJ=0; ///variable nombre de joueur

    sprite_transp=load_bitmap("rectangle.bmp",NULL);

    if (!sprite_transp)
    {
        allegro_message("pas pu trouver rectangle.bmp");
        exit(EXIT_FAILURE);
    }

    if (!joueur)// Vérification que l'image est bien chargée
    {
        allegro_message("pas pu trouver/charger mon_image.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    show_mouse(screen);

    blit(joueur,page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    blit(joueur,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

    while (i!=2 || i!=3 || i!=4)// Boucle interactive
    {
        blit(joueur,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        blit(joueur,page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);



        //textprintf_ex(screen,font,60,300,makecol(0,255,0),makecol(0,0,0),"%4d %4d",mouse_x,mouse_y);

        if (mouse_x>=152 && mouse_x<=305 && mouse_y>=373 && mouse_y<=485)
        {

            draw_sprite(page, sprite_transp, 117,344 );
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);


            if (mouse_b & 1 && mouse_x>=152 && mouse_x<=305 && mouse_y>=373 && mouse_y<=485)///boutton 2 joueurs
            {
                i=2;
                clear(joueur);
                clear(screen);
                clear(page);
                classeJ(i);
            }
        }


        if (mouse_x>=568 && mouse_x<=720 && mouse_y>=373 && mouse_y<=485)
        {
            draw_sprite(page, sprite_transp, 531,346 );
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

            if (mouse_b & 1 && mouse_x>=568 && mouse_x<=720 && mouse_y>=373 && mouse_y<=485)///boutton 3 joueurs
            {

                i=3;
                clear(joueur);
                clear(screen);
                clear(page);
                classeJ(i);
            }
        }

        if (mouse_x>=977 && mouse_x<=1128 && mouse_y>=373 && mouse_y<=485)
        {
            draw_sprite(page, sprite_transp, 938,346 );
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

            if (mouse_b & 1 && mouse_x>=977 && mouse_x<=1128 && mouse_y>=373 && mouse_y<=485)///boutton 4 joueurs
            {

                i=4;
                clear(joueur);
                clear(page);
                clear(screen);
                classeJ(i);
            }
        }
        rest(100);
    }
    rest(50);
}


void classeJ(int choixJ)
{

    BITMAP* bmp;
    BITMAP*Classss;
    BITMAP* rect;
    int tour=0;

    bmp=create_bitmap(1300,700);
    Classss=load_bitmap("classes.bmp",NULL);
    rect=load_bitmap("rectt.bmp",NULL);

    if (!Classss)// Vérification que l'image est bien chargée
    {
        allegro_message("pas pu trouver/charger Classe.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
     if (!rect)// Vérification que l'image est bien chargée
    {
        allegro_message("pas pu trouver/charger rectt.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    show_mouse(screen);

    blit(Classss,bmp, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    blit(Classss,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);


    t_joueur *J[choixJ];

    while(tour != choixJ)
    {
        textprintf_ex(Classss,font,60,300,makecol(0,255,0),makecol(0,0,0),"%4d %4d",mouse_x,mouse_y);
        blit(Classss,bmp, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        blit(Classss,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        printf("nbrrrrr : %d\n", choixJ);
        printf ("c'est au joueur %d de jouer \n", tour+1);

        if (mouse_x>=141 && mouse_x<=330 && mouse_y>=167 && mouse_y<=467)
        {
            draw_sprite(bmp, rect, 125,160 );
            blit(bmp,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if (mouse_b & 1 && mouse_x>=141 && mouse_x<=330 && mouse_y>=167 && mouse_y<=467)
            {
                tour=tour+1;
                rest(200);
            }
        }
        rest(200);


        /* if (mouse_b & 1 && mouse_x>=409 && mouse_x<=600 && mouse_y>=168 && mouse_y<=472)
         {
             printf("tour: %d \n",tour);
             tour=tour+1;
             rest(300);

         }*/

    }
}


void jeux()
{

    BITMAP* Classss;
    Classss=create_bitmap(1300,700);
    Classss=load_bitmap("paysage.bmp",NULL);

    if (!Classss)// Vérification que l'image est bien chargée
    {
        allegro_message("pas pu trouver/charger mon_image.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    show_mouse(screen);

    blit(Classss,screen,0,0,0,0, Classss->w, Classss->h); // Affichage de l'image sur l'écran
    rectfill(screen,550,650,600,700,makecol(255,0,0 ));
    while(!key[KEY_ESC])
    {

    }


}
