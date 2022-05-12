#include "header.h"

void nbr_joueur(BITMAP* son)
{

    install_mouse();
    BITMAP *joueur;
    BITMAP * page;

    BITMAP *sprite_transp;
    BITMAP *viseur;

    page=create_bitmap(1300,700);
    joueur=load_bitmap("images/joueur.bmp",NULL);
    viseur=load_bitmap("images/viseur.bmp",NULL);

    int i=0;

    sprite_transp=load_bitmap("images/rectangle.bmp",NULL);

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
    if (!viseur)// Vérification que l'image est bien chargée
    {
        allegro_message("pas pu trouver/charger viseur.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    //show_mouse(screen);

    blit(joueur,page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    blit(joueur,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

    while (i!=2 || i!=3 || i!=4 )// Boucle interactive
    {
        blit(joueur,page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        draw_sprite(page,viseur,mouse_x-15,mouse_y-5);

        if (mouse_x>=152 && mouse_x<=305 && mouse_y>=373 && mouse_y<=485)
        {

            draw_sprite(page, sprite_transp, 117,344 );
            draw_sprite(page,viseur,mouse_x-15,mouse_y-5);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);


            if (mouse_b & 1 && mouse_x>=152 && mouse_x<=305 && mouse_y>=373 && mouse_y<=485)///boutton 2 joueurs
            {
                i=2;
                clear(joueur);
                clear(screen);
                clear(page);
                classeJ(i,son);

            }
        }


        if (mouse_x>=568 && mouse_x<=720 && mouse_y>=373 && mouse_y<=485)
        {
            draw_sprite(page, sprite_transp, 531,346 );
            draw_sprite(page,viseur,mouse_x-15,mouse_y-5);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

            if (mouse_b & 1 && mouse_x>=568 && mouse_x<=720 && mouse_y>=373 && mouse_y<=485)///boutton 3 joueurs
            {

                i=3;
                clear(joueur);
                clear(screen);
                clear(page);
                classeJ(i,son);
            }
        }

        if (mouse_x>=977 && mouse_x<=1128 && mouse_y>=373 && mouse_y<=485)
        {
            draw_sprite(page, sprite_transp, 938,346 );
            draw_sprite(page,viseur,mouse_x-15,mouse_y-5);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

            if (mouse_b & 1 && mouse_x>=977 && mouse_x<=1128 && mouse_y>=373 && mouse_y<=485)///boutton 4 joueurs
            {

                i=4;
                clear(joueur);
                clear(page);
                clear(screen);
                classeJ(i,son);
            }
        }
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
}


void classeJ(int choixJ, BITMAP* son)
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
    BITMAP* carac2;
    BITMAP* carac3;
    BITMAP* carac4;

    BITMAP*viseur;

    int tour=0;

    bmp=create_bitmap(1300,700); ///buffer
    Classss=load_bitmap("images/classes.bmp",NULL);
    rect=load_bitmap("images/rectt.bmp",NULL);
    suivant=load_bitmap("images/suivant.bmp",NULL);
    J1=load_bitmap("images/joueur1.bmp",NULL);
    J2=load_bitmap("images/joueur2.bmp",NULL);
    J3=load_bitmap("images/joueur3.bmp",NULL);
    J4=load_bitmap("images/joueur4.bmp",NULL);
    carac1=load_bitmap("images/carac1.bmp",NULL);
    carac2=load_bitmap("images/carac2.bmp",NULL);
    carac3=load_bitmap("images/carac3.bmp",NULL);
    carac4=load_bitmap("images/carac4.bmp",NULL);
    viseur=load_bitmap("images/viseur.bmp",NULL);

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
    if (!carac2)/// Vérification que l'image est bien chargée///
    {
        allegro_message("pas pu trouver/charger carac2.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!carac3)/// Vérification que l'image est bien chargée///
    {
        allegro_message("pas pu trouver/charger carac3.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!carac4)/// Vérification que l'image est bien chargée///
    {
        allegro_message("pas pu trouver/charger carac4.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!viseur)/// Vérification que l'image est bien chargée///
    {
        allegro_message("pas pu trouver/charger viseur.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    blit(Classss,bmp, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    blit(Classss,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

    t_joueur J[choixJ];

    int classe1, classe2, classe3, classe4;

    while(tour != choixJ)
    {
        blit(Classss,bmp, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        draw_sprite(bmp,viseur,mouse_x-15,mouse_y-5);
        printf("nbrrrrr : %d\n", choixJ);
        printf ("c'est au joueur %d de jouer \n", tour+1);

        if(mouse_x>=1014 && mouse_x<=1222 && mouse_y>=595 && mouse_y<=655)
        {
            draw_sprite(bmp, suivant, 1011,594 );
            blit(bmp,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        }

        if (tour == 0)
        {
            draw_sprite(bmp,J1, 500,100 );
            draw_sprite(bmp,viseur,mouse_x-15,mouse_y-5);
        }
        if (tour == 1)
        {
            draw_sprite(bmp, J2, 500,100 );
            draw_sprite(bmp,viseur,mouse_x-15,mouse_y-5);
        }

        if (tour == 2)
        {
            draw_sprite(bmp, J3, 500,100 );
            draw_sprite(bmp,viseur,mouse_x-15,mouse_y-5);
        }

        if (tour == 3)
        {
            draw_sprite(bmp, J4, 500,100 );
            draw_sprite(bmp,viseur,mouse_x-15,mouse_y-5);
        }

        ///CLASSE 1:  LA SORCIERE///

        if (mouse_x>=141 && mouse_x<=330 && mouse_y>=167 && mouse_y<=467)
        {
            draw_sprite(bmp, rect, 125,160 );
            draw_sprite(bmp, carac1, 20,500 );
            draw_sprite(bmp,viseur,mouse_x-15,mouse_y-5);

            if (mouse_b & 1 && mouse_x>=141 && mouse_x<=330 && mouse_y>=167 && mouse_y<=467)
            {
                if (classe1!=1)
                {
                    J[tour].classe=1;
                    printf("la classe choisie par le joueur %d est : %d \n", tour+1, J[tour].classe);
                    tour=tour+1;
                    classe1=1;
                }

            }
        }

        ///CLASSE 2: STEVE///

        if(mouse_x>=409 && mouse_x<=600 && mouse_y>=168 && mouse_y<=472)
        {
            draw_sprite(bmp, rect, 393,162 );
            draw_sprite(bmp, carac2, 20,500 );
            draw_sprite(bmp,viseur,mouse_x-15,mouse_y-5);

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
            draw_sprite(bmp, carac3, 20,500 );
            draw_sprite(bmp,viseur,mouse_x-15,mouse_y-5);

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
            draw_sprite(bmp, carac4, 20,500 );
            draw_sprite(bmp,viseur,mouse_x-15,mouse_y-5);

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
        blit(bmp,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }

    int termine;

    while (termine!=1)///boucle pour le boutton suivant
    {
        blit(Classss,bmp, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        draw_sprite(bmp,viseur,mouse_x-15,mouse_y-5);

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

        }
        blit(bmp,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
    jeux(J,son, choixJ);
}


void menuFIN()
{
    BITMAP *jouer;
    BITMAP *doubleBuffer;
    BITMAP *revanche;
    BITMAP *quitter;
    BITMAP *viseur;
    BITMAP *image1;
    BITMAP *jouerred;
    BITMAP *revanchered;
    BITMAP *quitterred;
    SAMPLE *ouverture;
    SAMPLE *combat;

    install_keyboard();
    install_mouse();
    if(install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL)!=0)
    {
        allegro_message("erreur");
    }

    int fin = 0;

    doubleBuffer = create_bitmap(SCREEN_W, SCREEN_H);
    image1 = load_bitmap("images/minecraft3.bmp",NULL);
    jouer = load_bitmap("images/jouer.bmp",NULL);
    revanche = load_bitmap("images/revanche.bmp",NULL);
    quitter = load_bitmap("images/quitter.bmp",NULL);
    viseur = load_bitmap("images/viseur.bmp",NULL);
    jouerred = load_bitmap("images/jouerrouge.bmp",NULL);
    revanchered = load_bitmap("images/revancherouge.bmp",NULL);
    quitterred = load_bitmap("images/quitterrouge.bmp",NULL);
    ouverture = load_sample("ouverture.wav");
    combat = load_sample("combat.wav");

    while (!key[KEY_ESC] && fin != 1)
    {
        play_sample(ouverture,100,125,1000,10000);
        blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
        blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        if( mouse_x > 440 && mouse_x < 868 && mouse_y > 312 && mouse_y < 355)
        {
            draw_sprite(image1,jouerred,390,250);
            blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
            blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

            if(mouse_b&1)
            {
                stop_sample(ouverture);
                play_sample(combat,75,125,1000,10000);
                clear_bitmap(screen);
                nbr_joueur(combat);
            }

        }
        else
        {
            draw_sprite(image1,jouer,390,250);
        }

        if( mouse_x > 440 && mouse_x <868  && mouse_y > 362 && mouse_y < 405)
        {
            draw_sprite(image1,revanchered,390,300);
            blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
            blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

            if(mouse_b&1)
            {
                // CONDITION POUR REJOUER
            }

        }
        else
        {
            draw_sprite(image1,revanche,390,300);
        }
        /*while(1)
        {
             // CONDITION POUR RELANCER LA PARTIE
        }*/
        if( mouse_x > 440 && mouse_x < 868 && mouse_y > 412 && mouse_y < 455)
        {
            draw_sprite(image1,quitterred,390,350);
            blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
            blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            if(mouse_b&1)
            {
                exit(1);
                fin = 1;
            }
        }
        else
        {
            draw_sprite(image1,quitter,390,350);
        }

    }
    remove_sound();

}


void menuDEBUT()
{

    BITMAP *jouer;
    BITMAP *doubleBuffer;
    BITMAP *quitter;
    BITMAP *viseur;
    BITMAP *image1;
    BITMAP *jouerred;
    BITMAP *quitterred;
    SAMPLE *ouverture;
    SAMPLE *combat;
    install_keyboard();
    install_mouse();
    if(install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL)!=0)
    {
        allegro_message("erreur");
    }

    int fin = 0;
    doubleBuffer = create_bitmap(SCREEN_W, SCREEN_H);
    image1 = load_bitmap("images/minecraft3.bmp",NULL);
    jouer = load_bitmap("images/jouer.bmp",NULL);
    quitter = load_bitmap("images/quitter.bmp",NULL);
    viseur = load_bitmap("images/viseur.bmp",NULL);
    jouerred = load_bitmap("images/jouerrouge.bmp",NULL);
    quitterred = load_bitmap("images/quitterrouge.bmp",NULL);
    ouverture = load_sample("ouverture.wav");
    combat = load_sample("combat.wav");

    while (fin != 1)
    {
        play_sample(ouverture,75,125,1000,100);
        draw_sprite(doubleBuffer,viseur,mouse_x,mouse_y);
        blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
        blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        if( mouse_x > 440 && mouse_x < 868 && mouse_y > 312 && mouse_y < 355)
        {
            draw_sprite(image1,jouerred,390,250);
            blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
            blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

            if(mouse_b&1) // JOUER
            {
                stop_sample(ouverture);
                play_sample(combat,75,125,1000,10000);
                clear_bitmap(screen);
                nbr_joueur(combat);
            }

        }
        else
        {
            draw_sprite(image1,jouer,390,250);
        }

        if( mouse_x > 440 && mouse_x <868  && mouse_y > 362 && mouse_y < 405)
        {
            draw_sprite(image1,quitterred,390,300);
            blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
            blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            if(mouse_b&1)
            {
                fin = 1;
            }
        }
        else
        {
            draw_sprite(image1,quitter,390,300);
        }

    }
    remove_sound();
}

