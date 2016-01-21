#include <iostream>
#include <string>
#include "_sdl.h"

#include <SDL_image.h>
#include <SDL_mixer.h>

#define WINDOW_POS_X 100
#define WINDOW_POS_Y 100
#define WINDOW_WIDTH_PX 1024
#define WINDOW_HEIGHT_PX 768

        int main(int argc, char **argv)
        {
            bool quit_flag = false;

            try {

                SDL sdl(SDL_INIT_VIDEO|SDL_INIT_TIMER);

                SDL_Window *window = nullptr;

                window = SDL_CreateWindow("RPG",WINDOW_POS_X,
                WINDOW_POS_Y,
                WINDOW_WIDTH_PX,
                WINDOW_HEIGHT_PX,
                SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
                if (window == nullptr) {
                    std::cerr << "Could not create window: " << SDL_GetError();
                    return 1;
                }

                SDL_Renderer *renderer = nullptr;
                renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

                SDL_Event* main_event = new SDL_Event();

                SDL_Texture* grass_image = nullptr;
                grass_image = IMG_LoadTexture(renderer, "images/grass.bmp");

                SDL_Rect grass_rect;
                grass_rect.x = 0;
                grass_rect.y = 0;
                grass_rect.w = WINDOW_WIDTH_PX;
                grass_rect.h = WINDOW_HEIGHT_PX;

                SDL_Texture *bob_image = nullptr;
                bob_image = IMG_LoadTexture(renderer, "images/death_scythe.png");

                SDL_Rect bob_rect;
                bob_rect.x = 300;
                bob_rect.y = 250;
                bob_rect.w = 40;
                bob_rect.h = 65;

                while (!quit_flag && main_event-> type != SDL_QUIT) {

                    SDL_PollEvent(main_event);
                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer,grass_image,nullptr,&grass_rect);
                    SDL_RenderCopy(renderer,bob_image,nullptr, &bob_rect); // to be front on the grass
                    SDL_RenderPresent(renderer);
                }

                SDL_DestroyWindow(window);
                SDL_DestroyRenderer(renderer);
                delete main_event;

            } catch(const InitError &err) {
                std::cerr << "Error while initializing SDL: "
                << err.what() << std::endl;
            }

            return 1;

        }
