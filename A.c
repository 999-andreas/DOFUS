
#include "header.h"



typedef struct point
    {
        int x;
        int y;

    }t_point;

    typedef struct cell
    {
        t_point parent;
        t_point actu;

        int estimation, distance_reelle, cout; // c'est des float normalement
    }t_case;

    int valide (int ligne, int col)
    {
        return (ligne >= 0) && (ligne < 12) && (col >= 0)&& (col < 26);
    }

    int distance(int x_depart, int y_depart, int x_arrivee, int y_arrivee)
    {
        return sqrt((x_depart-x_arrivee)*(x_depart-x_arrivee) + (y_depart-y_arrivee)*(y_depart-y_arrivee));
    }

    int deja_dans_la_liste(cell liste[26][12], cell x)
    {
        int i;
        int j;

        for(i = 0; i<26; i++)
        {
            for(j = 0; j<12; j++)
            {
                if((liste[i][j]).actu == x.actu)
                {
                    return 1;
                }
            }
        }
        return 0;
    }

void find_path(t_joueur* michel,int x_goal, int y_goal, int maps[26][12])
{
    cell open[26][12] = {0}; // case pas encore parcouru
    cell closed[26][12] = {0}; // case parcouru

    int estimation;
    int distance_reelle;
    int cout;

    //distance estimé entre depart et arrivé
    estimation  = distance(michel->)

    //distance reelle entre le depart et une case
    distance_reelle = 0;

    cout = estimation+distance_reelle;

    //---------------------------------------------------
    //boucle principale

    t_point arrive;
    t_point courant;

    courant.x = michel->posx;
    courant.y = michel->posy;

    arrive.x = x_goal;
    arrive.y = y_goal;

    //pas sur que ça marche ça mdr
    open[michel->posx][michel->posy].actu.x = michel->posx;
    open[michel->posx][michel->posy].actu.y = michel->posy;

    ajouter_liste_fermee(courant);
    ajout_cases_adjacentes(courant);

    while(!(courant.x == arrive.x) && (courant.y == arrive.y) /* et la liste open pas vide (faire une fonction pour ca)*/)
    {

        courant = meilleur_noeud(open);

        ajouter_liste_fermee(courant);

        ajouter_cases_adjacentes(courant);



    }
    if((courant.x == arrive.x) && (courant.y == arrive.y))
    {
        retrouver_chemin(); //pas sur de comment ca marche ca
        afficher_chemin();
    }
    else
        printf("pas de solution\n");

}
