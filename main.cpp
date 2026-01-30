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

// srand(time(NULL));
// int b = rand() % 4;
// l->deplacement(b);
void update(Grille g)
{
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++)
    {
        if (g.grille_animaux[i]->type == 0)
        {
            bool V = (g.grille_animaux[i]->E > 50);
            g.grille_animaux[i]->E -= 10;
            g.grille_animaux[i]->age += 1;
            bool VM = (g.grille_animaux[i]->E <= 0 && g.grille_animaux[i]->age > 90);
            if (V)
            {
                g.grille_animaux[i]->reproduction();
            }
            if (VM)
            {
                free(g.grille_animaux[i]);
            }
            else
            {
                if (g.grille_herbe[i + 1] == 1)
                {
                    g.grille_animaux[i]->y += 1;
                    g.grille_animaux[i + 1] = g.grille_animaux[i];
                    Null_Entity a;
                    g.grille_animaux[i] = &a;
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
                else if (g.grille_herbe[i + GRID_SIZE] == 1)
                {
                    g.grille_animaux[i]->x += 1;
                    g.grille_animaux[i + GRID_SIZE] = g.grille_animaux[i];
                    Null_Entity a;
                    g.grille_animaux[i] = a;
                    manger_herbe(g.grille_animaux[i + GRID_SIZE]);
                }
                else if (g.grille_herbe[i - GRID_SIZE] == 1)
                {
                    g.grille_animaux[i]->x -= 1;
                    g.grille_animaux[i - GRID_SIZE] = g.grille_animaux[i];
                    Null_Entity a;
                    g.grille_animaux[i] = a;
                    manger_herbe(g.grille_animaux[i - GRID_SIZE]);
                }
                else
                {
                    g.deplacement(g.grille_animaux[i]);
                }
                if (V && g.grille_animaux[i]->type == 2)
                {
                    Mouton *pbm = constructeur_mouton(i / GRID_SIZE, i % GRID_SIZE, 20, 0);
                    g.grille_animaux[i] = pbm;
                }
            }
        }
    }
}