#include <iostream>
#include <string>
#include "_sdl.h"




        int main(int argc, char **argv)
        {

            try {

                SDL sdl(SDL_INIT_VIDEO|SDL_INIT_TIMER);

            

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
