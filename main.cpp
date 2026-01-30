#include "animaux.hpp"
#include "visuel.hpp"
#include "const.hpp"
#include <SDL.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main()
{
    // Générer la fenêtre graphique
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    if (!init(&window, &renderer))
    {
        return 1;
    }
    // Création des grilles du terrain et des animaux
    // Génération des animaux et de l'herbe
    // Ajout des animaux et de l'herbe dans les grilles
    bool running = false;
    while (running)
    {
        // Update()
        // augmenter les âges
        // générer de l'herbe aléatoirement avec la fonction renouvellement
        // Update MOUTONS :
        // déplacements (déplacement aléatoires + se déplacer vers l'herbe)
        // manger l'herbe et augmenter l'Energie
        // Se reproduire
        // Condition Mort
        // Update LOUP :
        // déplacements (déplacement aléatoires + se déplacer vers les moutons)
        // manger les moutons et augmenter l'Energie
        // Se reproduire
        // Condition Mort
        // render()
        // clear render
        // dessiner les MOUTONS, LOUPS
    }
    // fermer la fenêtre

    return 0;
}

void update(Loup *l; Grille)
{
    if ()
    {
        srand(time(NULL));
        int b = rand() % 4;
        l->deplacement(b);
    }
}
void update(Grille g)
{
    for (int i = 0; i < n * n; i++)
    {
        if (g.grille_animaux[i]->type == 0)
        {
            if (g.grille_herbe[i + 1] == 1)
            {
                g.grille_animaux[i]->y += 1;
                g.grille_animaux[i + 1] = g.grille_animaux[i];
                Null_Entity a;
                g.grille_animaux[i] = a;
                manger_herbe(g.grille_animaux[i + 1]);
            }
            else if (g.grille_herbe[i - 1] == 1)
            {
                g.grille_animaux[i]->y -= 1;
                g.grille_animaux[i - 1] = g.grille_animaux[i];
                Null_Entity a;
                g.grille_animaux[i] = a;
                manger_herbe(g.grille_animaux[i - 1]);
            }
            else if (g.grille_herbe[i + n] == 1)
            {
                g.grille_animaux[i]->x += 1;
                g.grille_animaux[i + n] = g.grille_animaux[i];
                Null_Entity a;
                g.grille_animaux[i] = a;
                manger_herbe(g.grille_animaux[i + n]);
            }
            else if (g.grille_herbe[i - n] == 1)
            {
                g.grille_animaux[i]->x -= 1;
                g.grille_animaux[i - n] = g.grille_animaux[i];
                Null_Entity a;
                g.grille_animaux[i] = a;
                manger_herbe(g.grille_animaux[i - n]);
            }
            else
            {   
                g.deplacement(g.grille_animaux[i]);
            }
            if ()
        }
    }
}