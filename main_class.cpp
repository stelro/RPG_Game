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

        background_img = new CSprite(csdl_setup->GetRenderer(), "images/grass.bmp",0,0,1024,768);
}

MainClass::MainClass(const bool flag, const char *title, const int pos_x, const int pos_y, const int w, const int h) {

    quit_state = flag;

    try {
        csdl_setup = new SDL(SDL_INIT_VIDEO | SDL_INIT_TIMER, &quit_state,title,pos_x,pos_y,w,h);
    }catch(InitError &e) {
        std::cerr << "Could not initialize SDL: " << e.what();
        quit_state = true;
    }

    background_img = new CSprite(csdl_setup->GetRenderer(), "images/grass.bmp",0,0,1024,768);

    main_char = new CSprite(csdl_setup->GetRenderer(), "images/death_scythe.png", 100, 200, 40, 65);

}

void MainClass::GameLoop() {
    while (!quit_state && csdl_setup->GetMainEvent()-> type != SDL_QUIT) {

        csdl_setup->SdlBegin();

        background_img->Draw();
        main_char->Draw();

        switch (csdl_setup->GetMainEvent()->type) {
        case SDL_KEYDOWN:

            switch(csdl_setup->GetMainEvent()->key.keysym.sym) {

            case SDLK_a:
                main_char->SetX(main_char->GetX() - 1);
                break;
            case SDLK_s:
                main_char->SetY(main_char->GetY() + 1);
                break;
            case SDLK_w:
                main_char->SetY(main_char->GetY() - 1);
                break;
            case SDLK_d:
                main_char->SetX(main_char->GetX() + 1);
                break;
            default:
                break;
            }

            break;
        default:
            break;
        }

        csdl_setup->SdlEnd();
    }
}

MainClass::~MainClass() {

    delete main_char;
    delete background_img;
    delete csdl_setup;

}
