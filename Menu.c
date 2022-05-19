#include "header.h"


///SOUS PROGRAMME CHOIX DU NOMBRE DE JOUEUR///

void nbr_joueur(SAMPLE* son)//passage en parm�tre la bitmap son pour la musique
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

    if (!joueur)// V�rification que l'image est bien charg�e
    {
        allegro_message("pas pu trouver/charger mon_image.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!viseur)// V�rification que l'image est bien charg�e
    {
        allegro_message("pas pu trouver/charger viseur.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    //show_mouse(screen);

    blit(joueur,page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);///affihe l'image joueur sur le buffer
    blit(joueur,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);///affiche l'image joueur sur le screen

    while (i!=2 || i!=3 || i!=4 )
    {// Boucle tanque i est diff�rent de 2,3,4
        blit(joueur,page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        draw_sprite(page,viseur,mouse_x-15,mouse_y-5);///affiche le viseur de la souris sur la page


 ///boutton 2 joueurs///

        if (mouse_x>=152 && mouse_x<=305 && mouse_y>=373 && mouse_y<=485)///si la souris est entre ces coordonn�es
        {

            draw_sprite(page, sprite_transp, 117,344 );///affiche le rectangle de selection sur la page
            draw_sprite(page,viseur,mouse_x-15,mouse_y-5);///affiche le viseur
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);///afficher tout sur le screen


            if (mouse_b & 1 && mouse_x>=152 && mouse_x<=305 && mouse_y>=373 && mouse_y<=485)///si on clic entre ces coordonn�es
            {
                i=2;///i (nombre de joueur) �gal
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

void classeJ(int choixJ, SAMPLE* son)//Passage en parametre le nombre de joueur choisie et la musique
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

    /// BITMAP caract�ristique de chaque classe

    BITMAP* carac1;
    BITMAP* carac2;
    BITMAP* carac3;
    BITMAP* carac4;

    ///Bitmap visieur de souris

    BITMAP*viseur;


    ///variable nombre de tour
    int tour=0;



    ///cr�ation ou chargement de chaque bitmap

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

    if (!Classss)/// V�rification que l'image est bien charg�e///
    {
        allegro_message("pas pu trouver/charger Classe.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!rect)/// V�rification que l'image est bien charg�e///
    {
        allegro_message("pas pu trouver/charger rectt.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!suivant)/// V�rification que l'image est bien charg�e///
    {
        allegro_message("pas pu trouver/charger suivant.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!J1)/// V�rification que l'image est bien charg�e///
    {
        allegro_message("pas pu trouver/charger joueur1.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!J2)/// V�rification que l'image est bien charg�e///
    {
        allegro_message("pas pu trouver/charger joueur2.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!J3)/// V�rification que l'image est bien charg�e///
    {
        allegro_message("pas pu trouver/charger joueur3.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!J4)/// V�rification que l'image est bien charg�e///
    {
        allegro_message("pas pu trouver/charger joueur4.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    if (!carac1)/// V�rification que l'image est bien charg�e///
    {
        allegro_message("pas pu trouver/charger carac1.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!carac2)/// V�rification que l'image est bien charg�e///
    {
        allegro_message("pas pu trouver/charger carac2.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!carac3)/// V�rification que l'image est bien charg�e///
    {
        allegro_message("pas pu trouver/charger carac3.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!carac4)/// V�rification que l'image est bien charg�e///
    {
        allegro_message("pas pu trouver/charger carac4.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!viseur)/// V�rification que l'image est bien charg�e///
    {
        allegro_message("pas pu trouver/charger viseur.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }


    blit(Classss,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);///affichage de la classe sur le screen

    t_joueur J[choixJ];///tableau de strcure t_joueur du choix joueur

    J[0].nbJoueur = choixJ;///stockage su nombre de joueur total
    int classe1, classe2, classe3, classe4;///variable de chaque classe pour pas prendre la meme classe

    while(tour != choixJ)///boucle tanque le nombre de tour est diff�rent du nombre de joueur
    {
        blit(Classss,bmp, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        draw_sprite(bmp,viseur,mouse_x-15,mouse_y-5);

        if(mouse_x>=1014 && mouse_x<=1222 && mouse_y>=595 && mouse_y<=655)///bouton suivant
        {
            draw_sprite(bmp, suivant, 1011,594 );
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

        if (mouse_x>=141 && mouse_x<=330 && mouse_y>=167 && mouse_y<=467)///si la souris est entre ces coordon�es
        {
            draw_sprite(bmp, rect, 125,160 );//affiche carrer de selection
            draw_sprite(bmp, carac1, 20,500 );//affiche les caract�ristiques de la classe 1
            draw_sprite(bmp,viseur,mouse_x-15,mouse_y-5);//affiche du viseur

            if (mouse_b & 1 && mouse_x>=141 && mouse_x<=330 && mouse_y>=167 && mouse_y<=467)///si clic sur la classe 1
            {
                if (classe1!=1)///condition pour dire que la classe 1 est deja prise
                {
                    J[tour].classe=1; //stockage de la classe dans le tableau de structure tour = 1
                    tour=tour+1;//incr�mentation du tour
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
                    tour=tour+1;
                    classe3=1;
                }

            }
        }

        ///CLASSE 4 : LE ZOMBIE ///
        ///meme chose pour la classe 4
        if(mouse_x>=963 && mouse_x<=1160 && mouse_y>=168 && mouse_y<=472)///coordon�es du bouttons de la classe4
        {
            draw_sprite(bmp, rect, 945,162 );
            draw_sprite(bmp, carac4, 20,500 );
            draw_sprite(bmp,viseur,mouse_x-15,mouse_y-5);

            if (mouse_b & 1 && mouse_x>=963 && mouse_x<=1160 && mouse_y>=168 && mouse_y<=472)
            {
                if (classe4!=1)///condition pour que la classe sois prise par un seul joueur
                {
                    J[tour].classe=4;///classe 4 pour le joueur tour
                    tour=tour+1; ///incr�menation du joueur
                    classe4 = 1;

                }

            }

        }
        blit(bmp,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);///afficher le bmp sur le screen
    }///sort de la premier boucle while

    int termine;///variable pour la condition d'arret

    while (termine!=1)///boucle tanque le boutton suivant n'a pas �tait cliquer
    {
        blit(Classss,bmp, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        draw_sprite(bmp,viseur,mouse_x-15,mouse_y-5);

        if(mouse_x>=1014 && mouse_x<=1222 && mouse_y>=595 && mouse_y<=655)/// coordon�es du boutton
        {
            draw_sprite(bmp, suivant, 1011,594 );
            blit(bmp,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if (mouse_b & 1 && mouse_x>=1014 && mouse_x<=1222 && mouse_y>=595 && mouse_y<=655)///si clic sur le boutton suivant
            {
                termine=1;///variable termin� = 1
                clear(screen);///efface l'�cran

                ///efface les bitmaps///
                clear(Classss);
                clear(bmp);
            }

        }
        blit(bmp,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);///afficher le bmp sur le screen
    }
    jeux(J,son, choixJ);//appelle sur sous prog jeu pour arriv� sur le plateau
}


void menuFIN(t_joueur *michel,int nb_joueur)
{
    // DECLARATION DE TOUT LES BITMAP
    BITMAP *jouer;
    BITMAP *doubleBuffer;
    BITMAP *revanche;
    BITMAP *quitter;
    BITMAP *viseur;
    BITMAP *image1;
    BITMAP *jouerred;
    BITMAP *revanchered;
    BITMAP *quitterred;

    // DECLARATIOIN DES SAMPLE POUR LA MUSIQUE
    SAMPLE *menu;
    SAMPLE *combat;

    install_keyboard();
    install_mouse();
    if(install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL)!=0)
    {
        allegro_message("erreur");
    }

    int fin = 0;

    // CHARGEMENT DES BITMAP
    doubleBuffer = create_bitmap(SCREEN_W, SCREEN_H);
    image1 = load_bitmap("images/minecraft3.bmp",NULL);
    jouer = load_bitmap("images/jouer.bmp",NULL);
    revanche = load_bitmap("images/revanche.bmp",NULL);
    quitter = load_bitmap("images/quitter.bmp",NULL);
    viseur = load_bitmap("images/viseur.bmp",NULL);
    jouerred = load_bitmap("images/jouerrouge.bmp",NULL);
    revanchered = load_bitmap("images/revancherouge.bmp",NULL);
    quitterred = load_bitmap("images/quitterrouge.bmp",NULL);

    // CHARGEMENT DES MUSIQUES
    menu = load_sample("menu.wav");
    combat = load_sample("combat.wav");

    while (fin != 1) // CONDITION DE BOUCLE INFINIE
    {

        // LANCEMENT DE LA MUSIQUE DU MENU ET AFFICHAGE DE LA SOURIS
        play_sample(menu,100,125,1003,10000);
        blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
        blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        // SI ON PASSE PAR DESSUS LA CASE JOUER ALORS ON LE MET EN SURBRILLANCE
        if( mouse_x > 440 && mouse_x < 868 && mouse_y > 312 && mouse_y < 355)
        {
            draw_sprite(image1,jouerred,390,250);
            blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
            blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

            // SI ON CLICK SUR LA CASE JOUER
            if(mouse_b&1)
            {
                // ON ARRRETE LA MUSIQUE MENU ET ON LANCE CELUI DU JEUX
                stop_sample(menu);
                play_sample(combat,75,125,1003,10000);
                clear_bitmap(screen);
                nbr_joueur(combat);
            }

        }

        // SINON ON L'AFFICHE L'IMAGE QUI N'EST PAS EN SURBRILLANCE
        else
        {
            draw_sprite(image1,jouer,390,250);
        }


        // SI ON PASSE PAR DESSUS REJOUER ALORS ON L'AFFICHE EN SURBRILLANCE
        if( mouse_x > 440 && mouse_x <868  && mouse_y > 362 && mouse_y < 405)
        {
            draw_sprite(image1,revanchered,390,300);
            blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
            blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);


            // SI ON CLICK SUR JOUER
            if(mouse_b&1)
            {
                // ALORS ON STOP LA MUSIQUE MENU ET ON LANCE CELUI DU JEUX
                stop_sample(menu);
                play_sample(combat,75,125,1003,10000);
                clear_bitmap(screen);
                jeux(michel,combat,nb_joueur);
            }

        }

        // SINON ON AFFICHE L'IMAGE QUI N'EST PAS EN SURBRILLANCE
        else
        {
            draw_sprite(image1,revanche,390,300);
        }

        // SI ON PASSE PAR DESSUS QUITTER ALORS ON L'AFFICHE EN SURBRILLANCE
        if( mouse_x > 440 && mouse_x < 868 && mouse_y > 412 && mouse_y < 455)
        {
            // ON AFFICHE L'IMAGE ET LA SOURIS
            draw_sprite(image1,quitterred,390,350);
            blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
            blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

            // SI ON CLICK SUR QUITTER ALORS ON QUITTE TOUT LE PROGRAMME ET FIN DU JEUX
            if(mouse_b&1)
            {
                exit(1);
                fin = 1;
            }
        }

        // ON AFFICHE L'IMAGE QUITTER QUI N'EST PAS EN SURBRILLANCE
        else
        {
            draw_sprite(image1,quitter,390,350);
        }

    }

    remove_sound(); // ON ARRETE TOUT LES MUSIQUES

}


void menuDEBUT()
{
    // DECLARATION DE TOUTE LES BITMAP ET SAMPLE
    BITMAP *jouer;
    BITMAP *doubleBuffer;
    BITMAP *quitter;
    BITMAP *viseur;
    BITMAP *image1;
    BITMAP *jouerred;
    BITMAP *quitterred;
    SAMPLE *menu;
    SAMPLE *combat;
    install_keyboard();
    install_mouse();
    if(install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL)!=0)
    {
        allegro_message("erreur");
    }

    int fin = 0;

    // CHARGEMENT DES BITMAP
    doubleBuffer = create_bitmap(SCREEN_W, SCREEN_H);
    image1 = load_bitmap("images/minecraft3.bmp",NULL);
    jouer = load_bitmap("images/jouer.bmp",NULL);
    quitter = load_bitmap("images/quitter.bmp",NULL);
    viseur = load_bitmap("images/viseur.bmp",NULL);
    jouerred = load_bitmap("images/jouerrouge.bmp",NULL);
    quitterred = load_bitmap("images/quitterrouge.bmp",NULL);

    // CHARGEMENT DES MUSIQUES
    menu = load_sample("menu.wav");
    combat = load_sample("combat.wav");

    while (fin != 1)   // BOUCLE INFINIE TANT QUE ON NE CLICK PAS SUR FIN
    {
        // AFFICHAGE DU VISEUR DE LANCEMENT DE LA MUSIQUE DANS LE MENU
        play_sample(menu,100,125,1003,100);
        blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
        blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        // SI ON PASSE PAR DESSUS LA CASE JOUER ALORS ON MET EN SURBRILLANCE
        if( mouse_x > 440 && mouse_x < 868 && mouse_y > 312 && mouse_y < 355)
        {
            draw_sprite(image1,jouerred,390,250);
            blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
            blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

            if(mouse_b&1) // SI ON CLICK SUR JOUER ALORS LANCEMENT DE LA PARTIE ET STOP MUSIQUE DU MENU
            {
                stop_sample(menu);
                play_sample(combat,75,125,1003,10000);
                clear_bitmap(screen);
                nbr_joueur(combat);
            }

        // SINON ON AFFICHE L'IMAGE QUI N'EST PAS EN SURBRILLANCE
        }
        else
        {
            draw_sprite(image1,jouer,390,250);
        }


        // SI ON PASSE PAR DESSUS LA CASE QUUTTER ALORS ON MET EN SURBRILLANCE
        if( mouse_x > 440 && mouse_x <868  && mouse_y > 362 && mouse_y < 405)
        {
            draw_sprite(image1,quitterred,390,300);
            blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
            blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            if(mouse_b&1)  // SI ON CLICK SUR QUITTER ALORS FIN DU JEUX ALORS LA BOUCLE INFINIE
            {
                fin = 1;  // PERMET D'ARRETER LA BOUCLE INFINIE
            }
        }
        // SINON ON AFFICHE IMAGE QUI N'EST PAS EN SURBRILLANCE
        else
        {
            draw_sprite(image1,quitter,390,300);
        }

    }
    remove_sound();  // ON ARRETE TOUT LES MUSIQUES
}

