#include "main_class.h"

//--------------------------------------------
//default construcor
//by default we assume that the perfect size is
//1024 x 768
//--------------------------------------------

MainClass::MainClass() : PI(3.14159265359) {

    quit_state = false;

    try {
        csdl_setup = new SDL(SDL_INIT_VIDEO | SDL_INIT_TIMER, &quit_state,"title",0,0,1024,768);
    }catch(InitError &e) {
        std::cerr << "Could not initialize SDL: " << e.what();
        quit_state = true;
    }

        background_img = new CSprite(csdl_setup->GetRenderer(), "images/grass.bmp",0,0,1024,768);
}

MainClass::MainClass(const bool flag, const char *title, const int pos_x, const int pos_y, const int w, const int h) : PI(3.14159265359) {

    quit_state = flag;

    try {
        csdl_setup = new SDL(SDL_INIT_VIDEO | SDL_INIT_TIMER, &quit_state,title,pos_x,pos_y,w,h);
    }catch(InitError &e) {
        std::cerr << "Could not initialize SDL: " << e.what();
        quit_state = true;
    }

    background_img = new CSprite(csdl_setup->GetRenderer(), "images/grass.bmp",0,0,1024,768);

     MouseX = 0;
     MouseY = 0;

}



void MainClass::GameLoop() {
    while (!quit_state && csdl_setup->GetMainEvent()-> type != SDL_QUIT) {

        csdl_setup->SdlBegin();
        SDL_GetMouseState(&MouseX,&MouseY);
        background_img->Draw();
        csdl_setup->SdlEnd();
    }
}

MainClass::~MainClass() {

    delete background_img;
    delete csdl_setup;

}
