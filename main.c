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
    allegro_init();
    install_keyboard();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    doubleBuffer = create_bitmap(SCREEN_W, SCREEN_H);
    image = load_bitmap("minecraft.bmp",NULL);
    dofus = load_bitmap("dofus.bmp",NULL);
    jouer = load_bitmap("jouer.bmp",NULL);
    revanche = load_bitmap("revanche.bmp",NULL);
    classement = load_bitmap("classement.bmp",NULL);
    quitter = load_bitmap("quitter.bmp",NULL);
    while (!key[KEY_ESC])
    {

    clear_bitmap(doubleBuffer);
    draw_sprite(image,dofus,200,0);
    draw_sprite(image,jouer,255,175);
    draw_sprite(image,revanche,255,258);
    draw_sprite(image,classement,255,341);
    draw_sprite(image,quitter,255,424);
    blit(image,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
    blit(image,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }

    return 0;
}
END_OF_MAIN();
