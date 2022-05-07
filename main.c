#include <allegro.h>


int main()
{
    // Déclaration du pointeur sur BITMAP devant recevoir l'image
    BITMAP *image;
    BITMAP *buffer;
    BITMAP *image1;
    //int fin;

    // paramètres de l'élément à animer
    int posx,posy;    // coordonnées
    int tx,ty;        // taille (largeur et hauteur)
    int depx,depy;    // vecteur déplacement effectif en x et y
    //int x,y;//position plateau
    int casse;

    // Lancer allegro et le mode graphique
    allegro_init();
    install_keyboard();
    install_mouse();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1300,700,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    show_mouse(screen);



    // dessiner une zone EXIT en haut à gauche de l'écran
    //rectfill(screen,0,0,40,20,makecol(0,128,0 ));
    //textprintf_ex(screen,font,4,6,makecol(255,0,0),makecol(0,255,0),"EXIT");

    // init. variable de sortie boucle interactive
    //fin=0;

    // Chargement de l'image (l'allocation a lieu en même temps)
    image=load_bitmap("steve.bmp",NULL);
    if (!image)
    {
        allegro_message("pas pu trouver/charger steve.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    image1=load_bitmap("stevedep.bmp",NULL);
    if (!image)
    {
        allegro_message("pas pu trouver/charger stevedep.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }



    // Initialisation des paramètres de l'élément à animer

    // La taille est directement récupérée dans les champs w et h
    tx=image1->w;
    ty=image1->h;

    // Position initiale au centre
    posx=SCREEN_W/2-tx/2;
    posy=SCREEN_H/2-ty/2;
    //posx = 50;
    //posy =50;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);
    blit(image1,buffer,0,0,mouse_x,mouse_y,tx,ty);
    //blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

    /*if(mouse_x>0&&mouse_y>0&&mouse_x<50&&mouse_y<50)
    {
        posx=0;
        posy=0;
    }
    if(mouse_x>0&&mouse_x<50&&mouse_y>50&&mouse_y<100)
    {
        posx=0;
              posy=50;
    }

       if(mouse_b & 1)   {          // }
        if (casse==1)
            {
              posx=0;
              posy=0;


            }

        if (casse==2 )
            {
              posx=0;
              posy=50;


            }
        }*/


    // mouvements vers la droite et vers le bas
    // on pourrait initialiser aléatoirement ici...
    //depx=9;
    //depy=5;

    // Boucle d'animation (pas d'interaction)
    while (!key[KEY_ESC])
    {

        textprintf_ex(screen,font,60,300,makecol(0,255,0),makecol(0,0,0),"%4d %4d",mouse_x,mouse_y);
        // textprintf_ex(screen,font,60,500,makecol(0,255,0),makecol(0,0,0),"%4d %4d",posx,posy);
        // textprintf_ex(screen,font,60,100,makecol(0,255,0),makecol(0,0,0),"%4d %4d",tx,ty);


        /*if(mouse_b & 1){
         if(mouse_x>0&&mouse_y>0&&mouse_x<50&&mouse_y<50)
         {
             posx=0;
             posy=0;
         }
         if(mouse_x>0&&mouse_x<50&&mouse_y>50&&mouse_y<100)
         {
             posx=0;
             posy=50;
         }
         }
             blit(image1,screen,0,0,posx,posy,tx,ty);*/





        if (mouse_b & 1)
        {
            //  blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            clear_bitmap(buffer);
            blit(image1,buffer,0,0,mouse_x,mouse_y,tx,ty);
        }


         blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        //if (mouse_b&1){

        //  blit(image1,screen,0,0,posx,posy,tx,ty);


        // 4) ON FAIT UNE PETITE PAUSE à chaque fois sinon ça va trop vite...
        rest(20);
    }

    return 0;
}
END_OF_MAIN();

