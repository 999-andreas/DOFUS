#include "header.h"


///SOUS PROGRAMME CHOIX DU NOMBRE DE JOUEUR///

void nbr_joueur(BITMAP* son)//passage en parmètre la bitmap son pour la musique
{

    install_mouse();//install souris
    BITMAP *joueur;
    BITMAP * page;

    BITMAP *sprite_transp;
    BITMAP *viseur;

    page=create_bitmap(1300,700);
    joueur=load_bitmap("images/joueur.bmp",NULL);///load image joueur.bmp
    viseur=load_bitmap("images/viseur.bmp",NULL);

    int i=0;///variable du nombre de joueur

    sprite_transp=load_bitmap("images/rectangle.bmp",NULL);


    ///verification que chaque image charge bien///

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

    blit(joueur,page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);///affihe l'image joueur sur le buffer
    blit(joueur,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);///affiche l'image joueur sur le screen

    while (i!=2 || i!=3 || i!=4 )
    {// Boucle tanque i est différent de 2,3,4
        blit(joueur,page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        draw_sprite(page,viseur,mouse_x-15,mouse_y-5);///affiche le viseur de la souris sur la page


 ///boutton 2 joueurs///

        if (mouse_x>=152 && mouse_x<=305 && mouse_y>=373 && mouse_y<=485)///si la souris est entre ces coordonnées
        {

            draw_sprite(page, sprite_transp, 117,344 );///affiche le rectangle de selection sur la page
            draw_sprite(page,viseur,mouse_x-15,mouse_y-5);///affiche le viseur
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);///afficher tout sur le screen


            if (mouse_b & 1 && mouse_x>=152 && mouse_x<=305 && mouse_y>=373 && mouse_y<=485)///si on clic entre ces coordonnées
            {
                i=2;///i (nombre de joueur) égal
                clear(joueur);///afface la bitmap joueur
                clear(screen);///afface la bitmap screen
                clear(page);///afface la bitmap page
                classeJ(i,son);///appel du sous prog classeJ

            }
        }

     ///boutton 3 joueurs///

        if (mouse_x>=568 && mouse_x<=720 && mouse_y>=373 && mouse_y<=485)///meme chose pour les 3 joueurs
        {
            draw_sprite(page, sprite_transp, 531,346 );
            draw_sprite(page,viseur,mouse_x-15,mouse_y-5);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

            if (mouse_b & 1 && mouse_x>=568 && mouse_x<=720 && mouse_y>=373 && mouse_y<=485)
            {

                i=3;
                clear(joueur);
                clear(screen);
                clear(page);
                classeJ(i,son);
            }
        }

        ///boutton 4 joueurs///
        if (mouse_x>=977 && mouse_x<=1128 && mouse_y>=373 && mouse_y<=485)///meme chose pour les 4 joueurs
        {
            draw_sprite(page, sprite_transp, 938,346 );
            draw_sprite(page,viseur,mouse_x-15,mouse_y-5);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

            if (mouse_b & 1 && mouse_x>=977 && mouse_x<=1128 && mouse_y>=373 && mouse_y<=485)
            {

                i=4;
                clear(joueur);
                clear(page);
                clear(screen);
                classeJ(i,son);
            }
        }
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);///afficher la page sur le screen
    }
}


///SOUS PROGRAMME CHOIX DES CLASSE ////

void classeJ(int choixJ, BITMAP* son)//Passage en parametre le nombre de joueur choisie et la musique
{

    ///BITMAP///

    BITMAP* bmp;
    BITMAP*Classss;
    BITMAP* rect;
    BITMAP* suivant;


    ///bitmap affiche "joueur 1,2,3...

    BITMAP* J1;
    BITMAP* J2;
    BITMAP* J3;
    BITMAP* J4;

    /// BITMAP caractéristique de chaque classe

    BITMAP* carac1;
    BITMAP* carac2;
    BITMAP* carac3;
    BITMAP* carac4;

    ///Bitmap visieur de souris

    BITMAP*viseur;


    ///variable nombre de tour
    int tour=0;



    ///création ou chargement de chaque bitmap

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


    ///Verification que chaque image charge bien

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


    blit(Classss,bmp, 0, 0, 0, 0, SCREEN_W, SCREEN_H);///affichage de l'image des classss sur bmp
    blit(Classss,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);///affichage de la classe sur le screen

    t_joueur J[choixJ];///tableau de strcure t_joueur du choix joueur

    J[0].nbJoueur = choixJ;///stockage su nombre de joueur total
    int classe1, classe2, classe3, classe4;///variable de chaque classe pour pas prendre la meme classe

    while(tour != choixJ)///boucle tanque le nombre de tour est différent du nombre de joueur
    {
        blit(Classss,bmp, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        draw_sprite(bmp,viseur,mouse_x-15,mouse_y-5);
        printf("nbrrrrr : %d\n", choixJ);
        printf ("c'est au joueur %d de jouer \n", tour+1);

        if(mouse_x>=1014 && mouse_x<=1222 && mouse_y>=595 && mouse_y<=655)///bouton suivant
        {
            draw_sprite(bmp, suivant, 1011,594 );
            blit(bmp,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        }

        if (tour == 0)///affichage "joueur 1" quand tour = 0
        {
            draw_sprite(bmp,J1, 500,100 );
            draw_sprite(bmp,viseur,mouse_x-15,mouse_y-5);
        }
        if (tour == 1)///affichage "joueur 2" quand tour = 1
        {
            draw_sprite(bmp, J2, 500,100 );
            draw_sprite(bmp,viseur,mouse_x-15,mouse_y-5);
        }

        if (tour == 2)///affichage "joueur 3" quand tour = 2
        {
            draw_sprite(bmp, J3, 500,100 );
            draw_sprite(bmp,viseur,mouse_x-15,mouse_y-5);
        }

        if (tour == 3)///affichage "joueur 4" quand tour = 3
        {
            draw_sprite(bmp, J4, 500,100 );
            draw_sprite(bmp,viseur,mouse_x-15,mouse_y-5);
        }

        ///CLASSE 1:  LA SORCIERE///

        if (mouse_x>=141 && mouse_x<=330 && mouse_y>=167 && mouse_y<=467)///si la souris est entre ces coordonées
        {
            draw_sprite(bmp, rect, 125,160 );//affiche carrer de selection
            draw_sprite(bmp, carac1, 20,500 );//affiche les caractéristiques de la classe 1
            draw_sprite(bmp,viseur,mouse_x-15,mouse_y-5);//affiche du viseur

            if (mouse_b & 1 && mouse_x>=141 && mouse_x<=330 && mouse_y>=167 && mouse_y<=467)///si clic sur la classe 1
            {
                if (classe1!=1)///condition pour dire que la classe 1 est deja prise
                {
                    J[tour].classe=1; //stockage de la classe dans le tableau de structure tour = 1
                    printf("la classe choisie par le joueur %d est : %d \n", tour+1, J[tour].classe);
                    tour=tour+1;//incrémentation du tour
                    classe1=1;//condition d'arret
                }

            }
        }

        ///CLASSE 2: STEVE///

        if(mouse_x>=409 && mouse_x<=600 && mouse_y>=168 && mouse_y<=472)///meme chose pour la classe 2
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

        if(mouse_x>=687 && mouse_x<=876 && mouse_y>=168 && mouse_y<=472)///meme chose pour la classe 3
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
        ///meme chose pour la classe 4
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
        blit(bmp,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);///afficher le bmp sur le screen
    }///sort de la premier boucle while

    int termine;///variable pour la condition d'arret

    while (termine!=1)///boucle tanque le boutton suivant n'a pas était cliquer
    {
        blit(Classss,bmp, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        draw_sprite(bmp,viseur,mouse_x-15,mouse_y-5);

        if(mouse_x>=1014 && mouse_x<=1222 && mouse_y>=595 && mouse_y<=655)/// coordonées du boutton
        {
            draw_sprite(bmp, suivant, 1011,594 );
            blit(bmp,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if (mouse_b & 1 && mouse_x>=1014 && mouse_x<=1222 && mouse_y>=595 && mouse_y<=655)///si clic sur le boutton suivant
            {
                termine=1;///variable terminé = 1
                clear(screen);///efface l'écran

                ///efface les bitmaps///
                clear(Classss);
                clear(bmp);
            }

        }
        blit(bmp,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);///afficher le bmp sur le screen
    }
    jeux(J,son, choixJ);//appelle sur sous prog jeu pour arrivé sur le plateau
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

