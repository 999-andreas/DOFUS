#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

int main()
{

    BITMAP *image;
    BITMAP *dofus;
    BITMAP *doubleBuffer;
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
    while (!key[KEY_ESC])
    {

    clear_bitmap(doubleBuffer);
    draw_sprite(image,dofus,200,15);
    blit(image,doubleBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
    blit(image,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }

    return 0;
}
END_OF_MAIN();
