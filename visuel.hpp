#pragma once

#include "const.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <opencv2/opencv.hpp>

#include <stdio.h>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>


using namespace cv;




bool init(SDL_Window **window, SDL_Renderer **renderer);




void cleanup(SDL_Window *window, SDL_Renderer *renderer);
void carre(SDL_Renderer *renderer, int x, int y, int cote, int r, int g, int b);
void pixel(SDL_Renderer *renderer, int x, int y, int r, int g, int b);

void affiche_ornithorynque(SDL_Renderer *renderer, int position_x, int position_y);
void affiche_image_100x100(SDL_Renderer *renderer, std::string & image_path, int position_x, int position_y);













