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
    ///BITMAP///

    BITMAP* bmp;
    BITMAP*Classss;
    BITMAP* rect;
    BITMAP* suivant;


    BITMAP* J1;
    BITMAP* J2;
    BITMAP* J3;
    BITMAP* J4;

    BITMAP* carac1;
    int tour=0;

    bmp=create_bitmap(1300,700); ///buffer
    Classss=load_bitmap("classes.bmp",NULL);
    rect=load_bitmap("rectt.bmp",NULL);
    suivant=load_bitmap("suivant.bmp",NULL);
    J1=load_bitmap("joueur1.bmp",NULL);
    J2=load_bitmap("joueur2.bmp",NULL);
    J3=load_bitmap("joueur3.bmp",NULL);
    J4=load_bitmap("joueur4.bmp",NULL);
    carac1=load_bitmap("carac1.bmp",NULL);

    if (!Classss)/// Vérification que l'image est bien chargée///
    {
        allegro_message("pas pu trouver/charger Classe.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!rect)/// Vérification que l'image est bien chargée///
    {
        allegro_message("pas pu trouver/charger rectt.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!suivant)/// Vérification que l'image est bien chargée///
    {
        allegro_message("pas pu trouver/charger suivant.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!J1)/// Vérification que l'image est bien chargée///
    {
        allegro_message("pas pu trouver/charger joueur1.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!J2)/// Vérification que l'image est bien chargée///
    {
        allegro_message("pas pu trouver/charger joueur2.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!J3)/// Vérification que l'image est bien chargée///
    {
        allegro_message("pas pu trouver/charger joueur3.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!J4)/// Vérification que l'image est bien chargée///
    {
        allegro_message("pas pu trouver/charger joueur4.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    if (!carac1)/// Vérification que l'image est bien chargée///
    {
        allegro_message("pas pu trouver/charger carac1.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    show_mouse(screen);

    blit(Classss,bmp, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    blit(Classss,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

    t_joueur J[choixJ];

    int classe1, classe2, classe3, classe4;

    while(tour != choixJ)
    {

        rest (100);
        textprintf_ex(Classss,font,60,300,makecol(0,255,0),makecol(0,0,0),"%4d %4d",mouse_x,mouse_y);
        blit(Classss,bmp, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        blit(Classss,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        printf("nbrrrrr : %d\n", choixJ);
        printf ("c'est au joueur %d de jouer \n", tour+1);

        if(mouse_x>=1014 && mouse_x<=1222 && mouse_y>=595 && mouse_y<=655)
        {
            draw_sprite(bmp, suivant, 1011,594 );
            blit(bmp,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        }

        if (tour == 0)
        {
            draw_sprite(screen,J1, 500,100 );
            blit(screen,font, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        }
        if (tour == 1)
        {
            draw_sprite(bmp, J2, 500,100 );
            blit(bmp,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        }

        if (tour == 2)
        {
            draw_sprite(bmp, J3, 500,100 );
            blit(bmp,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        }

        if (tour == 3)
        {
            draw_sprite(bmp, J4, 500,100 );
            blit(bmp,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        }

        ///CLASSE 1:  LA SORCIERE///

        if (mouse_x>=141 && mouse_x<=330 && mouse_y>=167 && mouse_y<=467)
        {
            draw_sprite(bmp, rect, 125,160 );
            draw_sprite(bmp, carac1, 20,500 );
            blit(bmp,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if (mouse_b & 1 && mouse_x>=141 && mouse_x<=330 && mouse_y>=167 && mouse_y<=467)
            {
                if (classe1!=1)
                {
                    J[tour].classe=1;
                    printf("la classe choisie pas le joueur %d est : %d \n", tour+1, J[tour].classe);
                    tour=tour+1;
                    classe1=1;
                }

            }
        }

        ///CLASSE 2: STEVE///

        if(mouse_x>=409 && mouse_x<=600 && mouse_y>=168 && mouse_y<=472)
        {
            draw_sprite(bmp, rect, 393,162 );
            blit(bmp,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if (mouse_b & 1 && mouse_x>=409 && mouse_x<=600 && mouse_y>=168 && mouse_y<=472)
            {
                if (classe2!=1)
                {
                    J[tour].classe=2;
                    printf("la classe choisie pas le joueur %d est : %d \n", tour+1, J[tour].classe);
                    tour=tour+1;
                    classe2=1;
                }

            }
        }

        ///CLASSE 3 : LE SQUELETTE///

        if(mouse_x>=687 && mouse_x<=876 && mouse_y>=168 && mouse_y<=472)
        {
            draw_sprite(bmp, rect, 670,162 );
            blit(bmp,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if (mouse_b & 1 && mouse_x>=687 && mouse_x<=876 && mouse_y>=168 && mouse_y<=472)
            {
                if (classe3!=1)
                {
                    J[tour].classe=3;
                    printf("la classe choisie pas le joueur %d est : %d \n", tour+1, J[tour].classe);
                    tour=tour+1;
                    classe3=1;
                }

            }
        }

        ///CLASSE 4 : LE ZOMBIE ///
        if(mouse_x>=963 && mouse_x<=1160 && mouse_y>=168 && mouse_y<=472)///coordonées du bouttons de la classe4
        {
            draw_sprite(bmp, rect, 945,162 );
            blit(bmp,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if (mouse_b & 1 && mouse_x>=963 && mouse_x<=1160 && mouse_y>=168 && mouse_y<=472)
            {
                if (classe4!=1)///condition pour que la classe sois prise par un seul joueur
                {
                    J[tour].classe=4;///classe 4 pour le joueur tour
                    printf("la classe choisie pas le joueur %d est : %d \n", tour+1, J[tour].classe);
                    tour=tour+1; ///incrémenation du joueur
                    classe4 = 1;

                }

            }
        }
        rest(200);///pause sinon ca va trop vite
    }

    int termine;

    while (termine!=1)///boucle pour le boutton suivant
    {
        blit(Classss,bmp, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        blit(Classss,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        if(mouse_x>=1014 && mouse_x<=1222 && mouse_y>=595 && mouse_y<=655)/// coordonées du boutton
        {
            draw_sprite(bmp, suivant, 1011,594 );
            blit(bmp,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if (mouse_b & 1 && mouse_x>=1014 && mouse_x<=1222 && mouse_y>=595 && mouse_y<=655)
            {
                termine=1;
                clear(screen);///efface l'écran

                ///efface les bitmaps///
                clear(Classss);
                clear(bmp);
            }
            rest(100);
        }
    }
    jeux();
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
