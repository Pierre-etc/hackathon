#include "visuel.hpp"
#include <SDL.h>
#include "const.hpp"
#include <stdio.h>
#include <iostream>



bool init(SDL_Window **window, SDL_Renderer **renderer)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Erreur SDL_Init: %s", SDL_GetError());
        return false;
    }

    *window = SDL_CreateWindow("Space Invaders (SDL)", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!*window)
    {
        SDL_Log("Erreur SDL_CreateWindow: %s", SDL_GetError());
        SDL_Quit();
        return false;
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (!*renderer)
    {
        SDL_Log("Erreur SDL_CreateRenderer: %s", SDL_GetError());
        SDL_DestroyWindow(*window);
        SDL_Quit();
        return false;
    }

    return true;
}


#if 0

void handle_input(bool *running, const Uint8 *keys, Entity *player, bool *new_bullet_demand)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_KEYDOWN && event.key.repeat == 0 && event.key.keysym.sym == SDLK_SPACE) {
            *new_bullet_demand = true;
        }
        if (event.type == SDL_QUIT)
            *running = false;
    }

    player->vx = 0.0f;
    if (keys[SDL_SCANCODE_LEFT])
        player->vx = -PLAYER_SPEED;
    if (keys[SDL_SCANCODE_RIGHT])
        player->vx = PLAYER_SPEED;
}



void render(SDL_Renderer *renderer, GAME_STATE Game)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // couleur noire (0, 0, 0), opaque (255)
    SDL_RenderClear(renderer); // On efface tout sous un voile noir opaque

    for(int i=0; i<NB_ENTITY_MAX; i++){
        Entity *entity = Game.Entities[i];
        if (entity != NULL && entity->alive == true){
            // On definit un rectangle que SDL dessinera. Il contient les coordonnées, le width et height.
            SDL_Rect rect = {
                (int)entity->x, (int)entity->y,
                entity->w, entity->h
            };
            if (entity->type == 0)
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            if (entity->type == 1)
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            if (entity->type == 2)
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

            SDL_RenderFillRect(renderer, &rect);
        }
    }

    SDL_RenderPresent(renderer);
}

#endif



void cleanup(SDL_Window *window, SDL_Renderer *renderer)
{
    if (renderer)
        SDL_DestroyRenderer(renderer);
    if (window)
        SDL_DestroyWindow(window);
    SDL_Quit();
}



int main(){

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    bool bien_initialise = init(&window, &renderer);
    if (bien_initialise){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // couleur noire (0, 0, 0), opaque (255)
    SDL_RenderClear(renderer); // On efface tout sous un voile noir opaque

    SDL_Rect rect = { 10, 10, 50, 100
            };
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);

    cleanup(window, renderer);
    }
    else{
        std::cout << "error ! "<< std::endl;
    }
    

    
}
