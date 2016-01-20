#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

int main()
{
    bool quit = false;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = NULL;

    window = SDL_CreateWindow("RPG Game",100,100,600,400,SDL_WINDOW_SHOWN);

    if (window == NULL)
        return 1;

    SDL_Renderer* renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    

    while (!quit) {

    }

    return 0;
}
