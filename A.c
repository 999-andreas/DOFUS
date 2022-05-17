
#include "header.h"

//en fait je crois pas que je puisse mettre une structure dans une autre d'un coup
// il faut que je rajoute un indice d'ajout pour la liste fermée

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
}cell;


int distance(int x_depart, int y_depart, int x_arrivee, int y_arrivee)
{
    return sqrt((x_depart-x_arrivee)*(x_depart-x_arrivee) + (y_depart-y_arrivee)*(y_depart-y_arrivee));
}

int deja_dans_la_liste(cell liste[26][12], cell n) // il faut que j'ecrive une version pour la liste fermé
{
    int i;
    int j;

    for(i = 0; i<26; i++)
    {
        for(j = 0; j<12; j++)
        {
            if((liste[i][j].actu.x == n.actu.x)&&(liste[i][j].actu.y == n.actu.y))
            {
                return 1;
            }
        }
    }
    return 0;
}


void ajouter_cases_adjacentes(cell n, int maps[26][12], cell closed[26][12], cell open[26][12], t_point arrivee)
{

    for(int i= (n.actu.x)-1; i<(n.actu.x)+1; i++)
    {
        if((i<0) || (i>=26)) //en dehors du terrain
            continue;
        for(int j= (n.actu.y-1); j<(n.actu.y)+1; j++)
        {
            if((j<0) || (i>=12)) // en dehors du terrain
                continue;

            if(maps[i][j] == 2)
                continue;

            cell tempo;

            tempo.actu.x = i;
            tempo.actu.y = j;

            if(!deja_dans_la_liste(tempo, closed))
            {
                //calcul de l'estimation
                //calcul de la dsitance reelle
                //et du coup total

                tempo.estimation = distance(i,j,arrivee.x, arrivee.y);
                tempo.distance_reelle = (n.distance_reelle) + (distance(i,j,n.actu.x, n.actu.y));
                tempo.cout = tempo.distance_reelle + tempo.estimation;
                tempo.parent = n.actu;

                if(deja_dans_la_liste(tempo, open))
                {
                    //on compare les cout
                    if(tempo.cout<open[i][j].cout)
                    {
                        open[i][j] = tempo;
                    }

                    /// je comprend pas comment on accede au info dans les liste

                }
                else
                {
                    open[i][j] = tempo;
                }
            }
        }
    }
}

cell meilleur_noeud(cell liste[26][12]) // je crois qu'il faut que je fasse passer un cell en parametre pour recup le resultat
{
    int i;
    int j;
    cell tempo = liste[0][0];

    for(i=0;i<26;i++)
    {
        for(j=0; i<12;j++)
        {
            if(tempo.cout<liste[i][j].cout)
            {
                tempo = liste[i][j];
            }
        }
    }
    return tempo;
}

void ajouter_liste_fermee(cell n, cell closed[26][12], cell open[26][12])
{
    closed[n.actu.x-1][n.actu.y] = n;
    open[n.actu.x-1][n.actu.y] = 0; //ca je sais ca marche pas
}

void trouver_parent(cell closed[], cell tempo);
{

}

int retrouver_chemin(cell closed[],int indice_ajout, int chemin_final[100][2], t_joueur* michel)
{
    int i;
    t_point tempo = closed[indice_ajout-1];
    int longeur;

    while((closed[i].parent.x != michel->posx) &&(closed[i].parent.y != michel->posy) )
    {
        chemin_final[i-indice_ajout][0] = tempo.actu.x;
        chemin_final[i-indice_ajout][1] = tempo.actu.y;
        tempo = trouver_prochain(closed, tempo);
        longeur +=1;
    }
}


void find_path(t_joueur* michel,int x_goal, int y_goal, int maps[26][12])
{
    cell open[26][12] = {0}; // case pas encore parcouru
    cell closed[286] = {0}; // case parcouru

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


///---------------------------------------

f

if((michel[i].posx >= michel[joueurTour].posx) && (michel[i].posx-50 <= michel[joueurTour].posx-50))
