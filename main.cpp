#include <iostream>
#include <string>
#include <exception>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#define WINDOW_POS_X 100
#define WINDOW_POS_Y 100
#define WINDOW_WIDTH_PX 1024
#define WINDOW_HEIGHT_PX 768

class InitError : public std::exception {
public:
    InitError();
    InitError(const std::string&);
    virtual ~InitError() throw();
    virtual const char* what() const throw();
private:
    std::string msg;
};

InitError::InitError() :
    exception(), msg(SDL_GetError()) {}
InitError::InitError(const std::string &m) :
    exception(), msg(m) {}
InitError::~InitError() throw() {}
const char *InitError::what() const throw() {
    return msg.c_str();
}

class SDL {
public:
    SDL(Uint32 flags = 0) throw(InitError);
    virtual ~SDL();
};

SDL::SDL(Uint32 flags) throw(InitError) {
    if (SDL_Init(flags) != 0)
        throw InitError();
}

SDL::~SDL() {
    SDL_Quit();
}

int main(int argc, char **argv)
{
    bool quit_flag = false;

    try {
        SDL sdl(SDL_INIT_VIDEO|SDL_INIT_TIMER);
        return 0;
    }catch(const InitError &err) {
        std::cerr << "Error while initializing SDL: "
                  << err.what() << std::endl;
    }

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
    grass_rect.x = 10;
    grass_rect.y = 50;
    grass_rect.w = 250;
    grass_rect.h = 250;

    while (!quit_flag && main_event-> type != SDL_QUIT) {

        SDL_PollEvent(main_event);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,grass_image,nullptr,&grass_rect);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    delete main_event;

}
