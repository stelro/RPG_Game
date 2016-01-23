#include "_sdl.h"


/* we use bool to pointer to change the quit state in the memory
so we can access the quit state from the whole program */

SDL::SDL(Uint32 flags, bool *quit_state,const char *title, const uint32_t pos_x, const uint32_t pos_y, const uint32_t w, const uint32_t h) throw(InitError) :
    window(nullptr), renderer(nullptr) {

    if (SDL_Init(flags) != 0)
        throw InitError();

    window = SDL_CreateWindow(title,pos_x,
    pos_y,
    w,
    h,
    SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);

    if (window == nullptr) {
        std::cerr << "Could not create window: " << SDL_GetError();
        *quit_state = true;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if ( renderer == nullptr) {
        std::cerr << "Could not create renderer: " << SDL_GetError();
        *quit_state = true;
    }

    main_event = new SDL_Event();
}

//copy constructor
SDL::SDL(const SDL &copy_sdl) {
    if (this != &copy_sdl) {

        delete main_event;
        main_event = nullptr;
        window = nullptr;
        renderer = nullptr;

        main_event = new SDL_Event();

        window = copy_sdl.window;
        renderer = copy_sdl.renderer;
        main_event = copy_sdl.main_event;

        if ( window == nullptr) {
            std::cerr << "Could not create window in copy constructor: " << SDL_GetError();
        }

        if ( renderer == nullptr) {
            std::cerr << "Could not create renderer in copy constructor: " << SDL_GetError();
        }
    }
}

SDL_Renderer *SDL::GetRenderer() const {
    return renderer;
}

SDL_Event *SDL::GetMainEvent() const {
    return main_event;
}

void SDL::SdlBegin() const {
    SDL_PollEvent(main_event);
    SDL_RenderClear(renderer);
}

void SDL::SdlEnd() const {
    SDL_RenderPresent(renderer);
}

SDL::~SDL() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    delete main_event;
    SDL_Quit();
}
