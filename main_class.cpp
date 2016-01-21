#include "main_class.h"

//--------------------------------------------
//default construcor
//by default we assume that the perfect size is
//1024 x 768
//--------------------------------------------

MainClass::MainClass() {

    quit_state = false;

    try {
        csdl_setup = new SDL(SDL_INIT_VIDEO | SDL_INIT_TIMER, &quit_state,"title",0,0,1024,768);
    }catch(InitError &e) {
        std::cerr << "Could not initialize SDL: " << e.what();
        quit_state = true;
    }


    background_image = nullptr;
    background_image = IMG_LoadTexture(csdl_setup->GetRenderer(), "images/grass.bmp");

    main_char_image = nullptr;
    main_char_image = IMG_LoadTexture(csdl_setup->GetRenderer(), "images/death_scythe.png");

    background_rect.x = 0;
    background_rect.y = 0;
    background_rect.w = 1024;
    background_rect.h = 768;

    main_char_rect.x = 300;
    main_char_rect.y = 250;
    main_char_rect.w = 40;
    main_char_rect.h = 65;


}

MainClass::MainClass(const bool flag, const char *title, const uint32_t pos_x, const uint32_t pos_y, const uint32_t w, const uint32_t h) {

    quit_state = flag;

    try {
        csdl_setup = new SDL(SDL_INIT_VIDEO | SDL_INIT_TIMER, &quit_state,title,pos_x,pos_y,w,h);
    }catch(InitError &e) {
        std::cerr << "Could not initialize SDL: " << e.what();
        quit_state = true;
    }

    background_image = nullptr;
    background_image = IMG_LoadTexture(csdl_setup->GetRenderer(), "images/grass.bmp");

    main_char_image = nullptr;
    main_char_image = IMG_LoadTexture(csdl_setup->GetRenderer(), "images/death_scythe.png");

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
    while (!quit_state && csdl_setup->GetMainEvent()-> type != SDL_QUIT) {

        SDL_PollEvent(csdl_setup->GetMainEvent());
        SDL_RenderClear(csdl_setup->GetRenderer());
        SDL_RenderCopy(csdl_setup->GetRenderer(),background_image,nullptr,&background_rect);
        SDL_RenderCopy(csdl_setup->GetRenderer(),main_char_image,nullptr, &main_char_rect); // to be front on the background
        SDL_RenderPresent(csdl_setup->GetRenderer());
    }
}

MainClass::~MainClass() {
    SDL_DestroyTexture(background_image);
    SDL_DestroyTexture(main_char_image);

}
