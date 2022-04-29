#include "header.h"

void nbr_joueur()
{

    BITMAP *joueur;
    BITMAP * page;
    BITMAP * carre;

    page=create_bitmap(1300,700);
    carre=create_bitmap(1300,700);
    joueur=load_bitmap("joueur.bmp",NULL);

    int choixJ=0; ///variable nombre de joueur


    if (!joueur)// Vérification que l'image est bien chargée
    {
        allegro_message("pas pu trouver/charger mon_image.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    show_mouse(screen);

    blit(joueur,page,0,0,0,0, joueur->w, joueur->h);
    blit(page,screen,0,0,0,0, page->w, page->h);// Affichage de l'image sur l'écran


    while (choixJ!=2 || choixJ!=3 || choixJ!=4)// Boucle interactive
    {

        textprintf_ex(page,font,60,300,makecol(0,255,0),makecol(0,0,0),"%4d %4d",mouse_x,mouse_y);
        blit(page,screen,0,0,0,0, page->w, page->h);

        if (mouse_x>=152 && mouse_x<=305 && mouse_y>=373 && mouse_y<=485)
        {

            rect(page,152,373,310,490,makecol(255,0,0));

            if (mouse_b & 1 && mouse_x>=152 && mouse_x<=305 && mouse_y>=373 && mouse_y<=485)///boutton 2 joueurs
            {
                choixJ=2;
                clear(joueur);
                clear(screen);
                clear(page);
                classeJ(choixJ);
            }
        }


        if (mouse_b & 1 && mouse_x>=568 && mouse_x<=720 && mouse_y>=373 && mouse_y<=485)///boutton 3 joueurs
        {

            choixJ=3;
            clear(joueur);
            clear(screen);
            clear(page);
            classeJ(choixJ);

        }
        if (mouse_b & 1 && mouse_x>=977 && mouse_x<=1128 && mouse_y>=373 && mouse_y<=485)///boutton 4 joueurs
        {

            choixJ=4;
            clear(joueur);
            clear(page);
            clear(screen);
            classeJ(choixJ);

        }

    }
}


void classeJ(int choixJ)
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
