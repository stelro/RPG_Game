#include "main_class.h"

#define WINDOW_POS_X 100
#define WINDOW_POS_Y 100
#define WINDOW_WIDTH_PX 1024
#define WINDOW_HEIGHT_PX 768

//--------------------------------------------
//default construcor
//by default we assume that the perfect size is
//1024 x 768
//--------------------------------------------

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

    background_image = nullptr;
    background_image = IMG_LoadTexture(renderer, "images/grass.bmp");

    main_char_image = nullptr;
    main_char_image = IMG_LoadTexture(renderer, "images/death_scythe.png");

    background_rect.x = 0;
    background_rect.y = 0;
    background_rect.w = WINDOW_WIDTH_PX;
    background_rect.h = WINDOW_HEIGHT_PX;

    main_char_rect.x = 300;
    main_char_rect.y = 250;
    main_char_rect.w = 40;
    main_char_rect.h = 65;


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

    background_image = nullptr;
    background_image = IMG_LoadTexture(renderer, "images/grass.bmp");

    main_char_image = nullptr;
    main_char_image = IMG_LoadTexture(renderer, "images/death_scythe.png");

    background_rect.x = pos_x;
    background_rect.y = pos_y;
    background_rect.w = w;
    background_rect.h = h;

    main_char_rect.x = 300;
    main_char_rect.y = 250;
    main_char_rect.w = 40;
    main_char_rect.h = 65;

}

void MainClass::GameLoop() {
    while (!quit_flag && main_event-> type != SDL_QUIT) {

        SDL_PollEvent(main_event);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,grass_image,nullptr,&grass_rect);
        SDL_RenderCopy(renderer,bob_image,nullptr, &bob_rect); // to be front on the grass
        SDL_RenderPresent(renderer);
    }
}

MainClass::~MainClass() {
    SDL_DestroyTexture(background_image);
    SDL_DestroyTexture(main_char_image);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    delete main_event;
}
