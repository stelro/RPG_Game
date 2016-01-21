#include "main_class.h"

#define WINDOW_POS_X 100
#define WINDOW_POS_Y 100
#define WINDOW_WIDTH_PX 1024
#define WINDOW_HEIGHT_PX 768

MainClass::MainClass() {
    quit_state = false;
    window = nullptr;
    window = SDL_CreateWindow("RPG",WINDOW_POS_X,
    WINDOW_POS_Y,
    WINDOW_WIDTH_PX,
    WINDOW_HEIGHT_PX,
    SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);

    if (window == nullptr) {
        std::cerr << "Could not create window: " << SDL_GetError();
        quit_state = true;
        return 1;
    }

    renderer = nullptr;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    main_event = new SDL_Evenet();

}

MainClass::MainClass(const bool flag, const string &title, const uint32_t pos_x, const uint32_t pos_y, const uint32_t w, const u_int32_t, const string &window_state) {

    quit_state = flag;
    window = nullptr;
    window = SDL_CreateWindow(title,pos_x,pos_y,w,h,window_state);

    if ( window == nullptr) {
        std::cerr << "Could not create window: " << SDL_GetError();
        quit_state = true;
        return 1;
    }

    renderer = nullptr;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    main_event = new SDL_Evenet();

}

void MainClass::GameLoop() {

}
