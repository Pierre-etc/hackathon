#include "visuel.hpp"

using namespace cv;

using namespace std::chrono_literals;



bool init(SDL_Window **window, SDL_Renderer **renderer)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("Erreur SDL_Init: %s", SDL_GetError());
		return false;
	}

	*window = SDL_CreateWindow("Platypus Wars", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
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








void carre(SDL_Renderer *renderer, int x, int y, int cote, int r, int g, int b){
	SDL_Rect rect = {x,y,cote,cote};
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);
}



void affiche_mouton(SDL_Renderer *renderer, int x, int y){
	carre(renderer, x, y, 50, 255, 255, 255);
}

void affiche_herbe(SDL_Renderer *renderer, int x, int y){
	carre(renderer, x, y, 50, 0, 255, 0);
}




void pixel(SDL_Renderer *renderer, int x, int y, int r, int g, int b){
	carre(renderer, x, y, 1, r, g, b);
}

// on va faire une homothétie *100
void affiche_ornithorynque(SDL_Renderer *renderer, int position_x, int position_y){
	Mat mat = imread("perry100x100.png");
	cv::Size s = mat.size();
	int I = s.height;
	int J = s.width;
	for(int i = 0; i<I; ++i){
		for (int j = 0; j<J; ++j){
			cv::Vec3b rgb = mat.at<cv::Vec3b>(i, j);
			int b = rgb[0];
			int g = rgb[1];
			int r = rgb[2];
			pixel(renderer, 100*position_x + i, 100*position_y + j, r,g,b);
		}
	}
}



void affiche_image_100x100(SDL_Renderer *renderer, const char * image_path, int position_x, int position_y){
	SDL_Surface* surface = IMG_Load(image_path); 
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface); 
	SDL_FreeSurface(surface);
	SDL_Rect destination;
	destination.x = 100*position_x;
	destination.y = 100*position_y;
	destination.w = 100;
	destination.h = 100;

	SDL_RenderCopy(renderer, texture, NULL, &destination);
	SDL_RenderPresent(renderer);
	SDL_DestroyTexture(texture);
}




unsigned bounded_rand(unsigned range)
{
    for (unsigned x, r;;)
        if (x = rand(), r = x % range, x - r <= -range)
            return r;
}


template <typename T>
T minimum(T x, T y){
	if (x<y){
		return x;
	}
	return y;
}




int main(){

	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	bool bien_initialise = init(&window, &renderer);
	if (bien_initialise){
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // couleur noire (0, 0, 0), opaque (255)
	SDL_RenderClear(renderer); // On efface tout sous un voile noir opaque

	std::vector<const char *> paths = {"perry100x100.png", "perry_fluo100x100.png"};
	// const char * path = "perry100x100.png";
	// affiche_ornithorynque(renderer,2,2);
	for (int i = 1; i<100; i++){
		
		int x = bounded_rand(10);
		int y = bounded_rand(10);
		affiche_image_100x100(renderer, paths[i%2], x, y);
		long double tau = (1/sqrt(i));
		
		std::this_thread::sleep_for(std::chrono::duration<long double>(tau));
		//std::this_thread::sleep_for(1s);
	}
	
	
	
	cleanup(window, renderer);
	}
	else{
		std::cout << "error ! "<< std::endl;
	}
	

	
}
