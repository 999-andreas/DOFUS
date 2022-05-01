#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

int main()
{

    BITMAP *image;
    BITMAP *dofus;
    BITMAP *jouer;
    BITMAP *doubleBuffer;
    BITMAP *revanche;
    BITMAP *classement;
    BITMAP *quitter;
    BITMAP *viseur;
    BITMAP *image1;
    allegro_init();
    install_keyboard();
    install_mouse();
    show_mouse(screen);

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1300,700,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    int fin = 0;

    doubleBuffer = create_bitmap(SCREEN_W, SCREEN_H);
    image1 = load_bitmap("minecraft.bmp",NULL);
    dofus = load_bitmap("dofus.bmp",NULL);
    jouer = load_bitmap("jouer.bmp",NULL);
    revanche = load_bitmap("revanche.bmp",NULL);
    classement = load_bitmap("classement.bmp",NULL);
    quitter = load_bitmap("quitter.bmp",NULL);
    viseur = load_bitmap("viseur.bmp",NULL);

    while (!key[KEY_ESC] && fin != 1)
    {

    clear_bitmap(doubleBuffer);
    //textprintf_ex(screen,font,60,300,makecol(0,255,0),makecol(0,0,0),"%4d %4d",mouse_x,mouse_y);
    //rectfill(screen, mouse_x, mouse_y, mouse_x+5, mouse_y+5, makecol(255,0,0));
    //draw_sprite(image1,viseur,mouse_x,mouse_y);
    //clear_bitmap(doubleBuffer);
    draw_sprite(image1,dofus,450,0);
    draw_sprite(image1,jouer,255+250,175);
    draw_sprite(image1,revanche,255+250,258);
    draw_sprite(image1,classement,255+250,341);
    draw_sprite(image1,quitter,255+250,424);
    draw_sprite(doubleBuffer,viseur,mouse_x,mouse_y);
    //masked_blit(viseur,image1,mouse_x,mouse_y,mouse_x+20,mouse_y+20,SCREEN_W,SCREEN_H);
    blit(image1,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
    draw_sprite(doubleBuffer,viseur,mouse_x-15,mouse_y-5);
    blit(doubleBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    clear_bitmap(doubleBuffer);
    if(mouse_b&1 && mouse_x > 300+250 && mouse_x < 495+250 && mouse_y > 206 && mouse_y < 280)
    {
        clear_bitmap(screen);
        textprintf_ex(screen,font,100,200,makecol(255,255,0),makecol(0,0,0),"JOUER UNE PARTIE");
        /*while(1)
        {
             // CONDITION POUR JOUER
        }*/

    }
    else if(mouse_b&1 && mouse_x > 300+250 && mouse_x < 495+250 && mouse_y > 290 && mouse_y < 364)
    {
        clear_bitmap(screen);
        textprintf_ex(screen,font,100,200,makecol(255,255,0),makecol(0,0,0),"REVANCHE");
       /* while(1)
        {
             // CONDITION POUR REJOUER UNE PARTIE
        }*/

    }
    else if(mouse_b&1 && mouse_x > 300+250 && mouse_x < 495+250 && mouse_y > 375 && mouse_y < 448)
    {
        clear_bitmap(screen);
        textprintf_ex(screen,font,100,200,makecol(255,255,0),makecol(0,0,0),"CLASSEMENT DES TOP JOUEURS");
       /* while(1)
        {
             // CONDITION POUR LES TOP JOUEURS
        }*/

    }
    else if(mouse_b&1 && mouse_x > 300+250 && mouse_x < 495+250 && mouse_y > 455 && mouse_y < 533)
    {
        //clear_bitmap(screen);
        //textprintf_ex(screen,font,100,200,makecol(255,255,0),makecol(0,0,0),"QUITTEZ");
        fin = 1;

    }

    }

    return 0;
}
END_OF_MAIN();
