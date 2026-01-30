#pragma once





bool init(SDL_Window **window, SDL_Renderer **renderer);




void cleanup(SDL_Window *window, SDL_Renderer *renderer);
void carre(SDL_Renderer *renderer, int x, int y, int cote, int r, int g, int b);
void pixel(SDL_Renderer *renderer, int x, int y, int r, int g, int b);

void affiche_ornithorynque(SDL_Renderer *renderer, int position_x, int position_y);














