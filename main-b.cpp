#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

int main()
{
    bool quit = false;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = NULL;

    window = SDL_CreateWindow("RPG Game",100,100,1024,768,SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (window == NULL)
        return 1;

    SDL_Renderer* renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event* main_event = new SDL_Event();
    SDL_Texture* grass_image = NULL;
    grass_image = IMG_LoadTexture(renderer, "images/grass.bmp");

    SDL_Rect grass_rect;
    grass_rect.x = 10;
    grass_rect.y = 50;
    grass_rect.w = 250;
    grass_rect.h = 250;

    while (!quit && main_event-> type != SDL_QUIT) {

        SDL_PollEvent(main_event);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer,grass_image,NULL, &grass_rect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    delete main_event;

    return 0;
}
