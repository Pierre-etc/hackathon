#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "animaux.hpp"
#include "visuel.hpp"
#include "const.hpp"

int* i_to_xy(int i)
{
    int arr[2];
    arr[0] = i/10;
    arr[1] = i%10;
    return &arr[0];
}

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
    // Pour chaque EMPLACEMENT
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++)
    {
        int *position_grille = i_to_xy(i);
        int x = position_grille[0];
        int y = position_grille[1];
        Entity *entity = g.grille_animaux[i];

        // S'il y a un MOUTON à cet emplacement
        if(entity->type == 0)
        {
            Entity *mouton = entity;

            // S'il y a de l'herbe en bas du mouton
            if (y<GRID_SIZE-1 && g.grille_herbe[i + 1] == 1)
            {
                g.grille_animaux[i]->y += 1;
                g.grille_animaux[i + 1] = g.grille_animaux[i];
                Null_Entity a;
                g.grille_animaux[i] = &a;
                g.manger_herbe(g.grille_animaux[i + 1]);
            }
            // S'il y a de l'herbe en haut du mouton
            else if (y>0 && g.grille_herbe[i - 1] == 1)
            {
                g.grille_animaux[i]->y -= 1;
                g.grille_animaux[i - 1] = g.grille_animaux[i];
                Null_Entity a;
                g.grille_animaux[i] = &a;
                g.manger_herbe(g.grille_animaux[i - 1]);
            }
            // S'il y a de l'herbe à droite du mouton
            else if (x<GRID_SIZE-1 && g.grille_herbe[i + GRID_SIZE] == 1)
            {
                g.grille_animaux[i]->x += 1;
                g.grille_animaux[i + GRID_SIZE] = g.grille_animaux[i];
                Null_Entity a;
                g.grille_animaux[i] = &a;
                g.manger_herbe(g.grille_animaux[i + GRID_SIZE]);
            }
            // S'il y a de l'herbe à droite du mouton
            else if (x>0 && g.grille_herbe[i - GRID_SIZE] == 1)
            {
                g.grille_animaux[i]->x -= 1;
                g.grille_animaux[i - GRID_SIZE] = g.grille_animaux[i];
                Null_Entity a;
                g.grille_animaux[i] = &a;
                g.manger_herbe(g.grille_animaux[i - GRID_SIZE]);
            }
            else
            {   
                mouton->deplacement(0);
            }
        }
        // S'il y a un LOUP à cet emplacement
        if(entity->type == 1){

        }
    }
}

