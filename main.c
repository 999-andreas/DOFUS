#include "header.h"

int main()
{
    srand(time(NULL));

    setup_allegro();

    nbr_joueur(0);

    return 0;
}

END_OF_MAIN();

//faire un giga tableau pour les infos de chaque classe
//peut etre les infos de classe dans un fichier txt ?
//pour que le code soit plus lisible
//mettre des flammes comme obstacle, qui fond des degats
//faire marcher l'ecriture en plus gros
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
