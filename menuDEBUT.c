#include "sous programme.h"

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
    image1 = load_bitmap("minecraft3.bmp",NULL);
    jouer = load_bitmap("jouer.bmp",NULL);
    revanche = load_bitmap("revanche.bmp",NULL);
    quitter = load_bitmap("quitter.bmp",NULL);
    viseur = load_bitmap("viseur.bmp",NULL);
    jouerred = load_bitmap("jouerrouge.bmp",NULL);
    revanchered = load_bitmap("revancherouge.bmp",NULL);
    quitterred = load_bitmap("quitterrouge.bmp",NULL);
    ouverture = load_sample("ouverture.wav");
    combat = load_sample("combat.wav");


    while (!key[KEY_ESC] && fin != 1)
    {
        play_sample(ouverture,100,125,1000,10000);
        blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
        blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        //clear_bitmap(doubleBuffer);
        if( mouse_x > 440 && mouse_x < 868 && mouse_y > 312 && mouse_y < 355)
        {
            draw_sprite(image1,jouerred,390,250);
            blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
            blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

            if(mouse_b&1)
            {
                stop_sample(ouverture);
                play_sample(combat,100,125,1000,10000);
                clear_bitmap(screen);
                // CONDITION POUR JOUER
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

                /* while(1)
                {
                   // CONDITION POUR REJOUER UNE PARTIE
                }*/
            }

        }
        else
        {
            draw_sprite(image1,revanche,390,300);
        }
             /*while(1)
             {
                  // CONDITION POUR LES TOP JOUEURS
             }

         }*/
        if( mouse_x > 440 && mouse_x < 868 && mouse_y > 412 && mouse_y < 455)
        {
            draw_sprite(image1,quitterred,390,350);
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
    image1 = load_bitmap("minecraft3.bmp",NULL);
    jouer = load_bitmap("jouer.bmp",NULL);
    quitter = load_bitmap("quitter.bmp",NULL);
    viseur = load_bitmap("viseur.bmp",NULL);
    jouerred = load_bitmap("jouerrouge.bmp",NULL);
    quitterred = load_bitmap("quitterrouge.bmp",NULL);
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

            if(mouse_b&1)
            {
                stop_sample(ouverture);
                play_sample(combat,75,125,1000,10000);
                clear_bitmap(screen);



                // CONDITION POUR JOUER
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
