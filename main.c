#include "sous programme.h"

int main()
{

    allegro_init();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1300,700,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    menuDEBUT();
    menuFIN();


    return 0;
}
END_OF_MAIN();
