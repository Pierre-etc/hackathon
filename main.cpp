#include "animaux.hpp"
#include "visuel.hpp"
#include "const.hpp"
#include <SDL.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
srand(time(NULL));
int a = rand() % 4;



    
    
int main(){
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
    while (running){
        // Update()
            // augmenter les âges
            // générer de l'herbe aléatoirement
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

