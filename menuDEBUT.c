#include "sous programme.h"

void menuFIN()
{
    BITMAP *dofus;
    BITMAP *jouer;
    BITMAP *doubleBuffer;
    BITMAP *revanche;
    BITMAP *quitter;
    BITMAP *viseur;
    BITMAP *image1;
    BITMAP *jouerred;
    BITMAP *revanchered;
    BITMAP *quitterred;

    install_keyboard();
    install_mouse();
    //show_mouse(screen);

    int fin = 0;

    doubleBuffer = create_bitmap(SCREEN_W, SCREEN_H);
    image1 = load_bitmap("minecraft.bmp",NULL);
    dofus = load_bitmap("dofus.bmp",NULL);
    jouer = load_bitmap("jouer.bmp",NULL);
    revanche = load_bitmap("revanche.bmp",NULL);
    quitter = load_bitmap("quitter.bmp",NULL);
    viseur = load_bitmap("viseur.bmp",NULL);
    jouerred = load_bitmap("jouerrouge.bmp",NULL);
    revanchered = load_bitmap("revancherouge.bmp",NULL);
    quitterred = load_bitmap("quitterrouge.bmp",NULL);

    while (!key[KEY_ESC] && fin != 1)
    {

    //clear_bitmap(doubleBuffer);
    //textprintf_ex(screen,font,60,300,makecol(0,255,0),makecol(0,0,0),"%4d %4d",mouse_x,mouse_y);
    //rectfill(screen, mouse_x, mouse_y, mouse_x+5, mouse_y+5, makecol(255,0,0));
    //draw_sprite(image1,viseur,mouse_x,mouse_y);
    //clear_bitmap(doubleBuffer);
    draw_sprite(image1,dofus,450,0);
    //draw_sprite(image1,jouer,505,210);
    //draw_sprite(image1,revanche,505,330);
    //draw_sprite(image1,classement,255+250,341);
    //draw_sprite(image1,quitter,505,450);
    draw_sprite(doubleBuffer,viseur,mouse_x,mouse_y);
    //masked_blit(viseur,image1,mouse_x,mouse_y,mouse_x+20,mouse_y+20,SCREEN_W,SCREEN_H);
    blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
    draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
    blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    //clear_bitmap(doubleBuffer);
    if( mouse_x > 550 && mouse_x < 750 && mouse_y > 246 && mouse_y < 318)
    {
        //clear_bitmap(screen);
        draw_sprite(image1,jouerred,505,210);
        blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
        blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        if(mouse_b&1)
        {
            textprintf_ex(screen,font,100,200,makecol(255,255,0),makecol(0,0,0),"JOUER UNE PARTIE");


        /*while(1)
        {
             // CONDITION POUR JOUER
        }*/
        }

    }
    else
    {
        draw_sprite(image1,jouer,505,210);
    }

     if( mouse_x > 550 && mouse_x < 750 && mouse_y > 370 && mouse_y < 436)
    {
        //clear_bitmap(screen);
        draw_sprite(image1,revanchered,505,330);
        blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
        blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        if(mouse_b&1)
        {
            textprintf_ex(screen,font,100,200,makecol(255,255,0),makecol(0,0,0),"REVANCHE");

            /* while(1)
           {
               // CONDITION POUR REJOUER UNE PARTIE
           }*/
        }

    }
    else
    {
        draw_sprite(image1,revanche,505,330);
    }
   /* else if(mouse_b&1 && mouse_x > 300+250 && mouse_x < 495+250 && mouse_y > 375 && mouse_y < 448)
    {
        clear_bitmap(screen);
        textprintf_ex(screen,font,100,200,makecol(255,255,0),makecol(0,0,0),"CLASSEMENT DES TOP JOUEURS");
        while(1)
        {
             // CONDITION POUR LES TOP JOUEURS
        }

    }*/
    if( mouse_x > 550 && mouse_x < 750 && mouse_y > 494 && mouse_y < 554)
    {
        draw_sprite(image1,quitterred,505,450);
        blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
        blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        if(mouse_b&1)
        {
            fin = 1;
        }
        //clear_bitmap(screen);
        //textprintf_ex(screen,font,100,200,makecol(255,255,0),makecol(0,0,0),"QUITTEZ");
    }
    else
    {
        draw_sprite(image1,quitter,505,450);
    }

    }

}


void menuDEBUT()
{

    BITMAP *image;
    BITMAP *dofus;
    BITMAP *jouer;
    BITMAP *doubleBuffer;
    BITMAP *quitter;
    BITMAP *viseur;
    BITMAP *image1;
    BITMAP *jouerred;
    BITMAP *quitterred;

    install_keyboard();
    install_mouse();
    //show_mouse(screen);

    // CHOIX DES JOUEURS INITIALISATION
    t_joueur Joueur[3];
    int play=0;

    int fin = 0;

    doubleBuffer = create_bitmap(SCREEN_W, SCREEN_H);
    image1 = load_bitmap("minecraft.bmp",NULL);
    dofus = load_bitmap("dofus.bmp",NULL);
    jouer = load_bitmap("jouer.bmp",NULL);
    quitter = load_bitmap("quitter.bmp",NULL);
    viseur = load_bitmap("viseur.bmp",NULL);
    jouerred = load_bitmap("jouerrouge.bmp",NULL);
    quitterred = load_bitmap("quitterrouge.bmp",NULL);

    while (!key[KEY_ESC] && fin != 1)
    {

    //clear_bitmap(doubleBuffer);
    //textprintf_ex(screen,font,60,300,makecol(0,255,0),makecol(0,0,0),"%4d %4d",mouse_x,mouse_y);
    //rectfill(screen, mouse_x, mouse_y, mouse_x+5, mouse_y+5, makecol(255,0,0));
    //draw_sprite(image1,viseur,mouse_x,mouse_y);
    //clear_bitmap(doubleBuffer);
    draw_sprite(image1,dofus,450,0);
    //draw_sprite(image1,jouer,505,250);
    //draw_sprite(image1,revanche,505,330);
    //draw_sprite(image1,quitter,505,370);
    draw_sprite(doubleBuffer,viseur,mouse_x,mouse_y);
    //masked_blit(viseur,image1,mouse_x,mouse_y,mouse_x+20,mouse_y+20,SCREEN_W,SCREEN_H);
    blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
    draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
    blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    //clear_bitmap(doubleBuffer);
    if( mouse_x > 550 && mouse_x < 750 && mouse_y > 285 && mouse_y < 355)
    {
        //clear_bitmap(screen);
        draw_sprite(image1,jouerred,505,250);
        blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
        blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        if(mouse_b&1)
        {
            clear_bitmap(screen);
            textprintf_ex(screen,font,100,200,makecol(255,255,0),makecol(0,0,0),"JOUER UNE PARTIE");

            for(int i=0;i<4;i++)
            {
                printf("Saisir un nom: ");
                scanf("%s",Joueur[i].joueur);
            }


        while(fin != 1 && Joueur[0].dernierENVIE != 1)
        {
            clear_bitmap(screen);
            if(play %4 == 0)
            {
                play = 0;
                //Joueur[0].dernierENVIE--;
            }
            textprintf_ex(screen,font,100,205,makecol(255,255,0),makecol(2,2,2),"Joueur: %s de jouer",Joueur[play].joueur);
            rest(300);
            play = play+1;

        }
             // CONDITION POUR JOUER
        }

    }
    else
    {
        draw_sprite(image1,jouer,505,250);
    }

   /*  if( mouse_x > 550 && mouse_x < 750 && mouse_y > 370 && mouse_y < 436)
    {
        //clear_bitmap(screen);
        draw_sprite(image1,revanchered,505,330);
        blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
        blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        if(mouse_b&1)
        {
            textprintf_ex(screen,font,100,200,makecol(255,255,0),makecol(0,0,0),"REVANCHE");

             while(1)
           {
               // CONDITION POUR REJOUER UNE PARTIE
           }
        }

    }
    else
    {
        draw_sprite(image1,revanche,505,330);
    }*/
    if( mouse_x > 550 && mouse_x < 750 && mouse_y > 405 && mouse_y < 480)
    {
        draw_sprite(image1,quitterred,505,370);
        blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
        blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        if(mouse_b&1)
        {
            fin = 1;
        }
        //clear_bitmap(screen);
        //textprintf_ex(screen,font,100,200,makecol(255,255,0),makecol(0,0,0),"QUITTEZ");
    }
    else
    {
        draw_sprite(image1,quitter,505,370);
    }

    }

}
