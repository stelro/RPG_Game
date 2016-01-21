#include "_sdl.h"

//TODO: default constructor

SDL::SDL(Uint32 flags, bool *quit_state,const char *title, const uint32_t pos_x, const uint32_t pos_y, const uint32_t w, const uint32_t h) throw(InitError) {

    if (SDL_Init(flags) != 0)
        throw InitError();

    window = nullptr;

    window = SDL_CreateWindow(title,pos_x,
    pos_y,
    w,
    h,
    SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);

    if (window == nullptr) {
        std::cerr << "Could not create window: " << SDL_GetError();
        *quit_state = true;
    }

    renderer = nullptr;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    main_event = new SDL_Event();
}

SDL_Renderer *SDL::GetRenderer() const {
    return renderer;
}

SDL_Event *SDL::GetMainEvent() const {
    return main_event;
}

SDL::~SDL() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    delete main_event;
    SDL_Quit();
}
