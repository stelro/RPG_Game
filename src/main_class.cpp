#include "main_class.h"

//--------------------------------------------
//default construcor
//by default we assume that the perfect size is
//1024 x 768
//--------------------------------------------

MainClass::MainClass() {

    // quit_state = false;
    //
    // try {
    //     csdl_setup = new SDL(SDL_INIT_VIDEO | SDL_INIT_TIMER, &quit_state,"title",0,0,1024,768);
    // }catch(InitError &e) {
    //     std::cerr << "Could not initialize SDL: " << e.what();
    //     quit_state = true;
    // }
    //
    // background_img = new CSprite(csdl_setup->GetRenderer(), "images/grass.bmp",0,0,1024,768);
    //
    // main_char = new MainCharacter(csdl_setup, &MouseX, &MouseY);

    //TODO: to fix default constructor
}

MainClass::MainClass(const bool flag, const char *title, const int pos_x, const int pos_y, const int w, const int h)  {

    quit_state = flag;

    CameraX = 0;
    CameraY = 0;

    try {
        csdl_setup = new SDL(SDL_INIT_VIDEO | SDL_INIT_TIMER, &quit_state,title,pos_x,pos_y,w,h);
    }catch(InitError &e) {
        std::cerr << "Could not initialize SDL: " << e.what();
        quit_state = true;
    }

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 7; j++) {
            background_img[i][j] = new CSprite(csdl_setup->GetRenderer(), "images/grass.bmp",1024 * i,768 * j,1024,768, &CameraX, &CameraY);
        }
    }

     MouseX = 0;
     MouseY = 0;

     main_char = new MainCharacter(csdl_setup, &MouseX, &MouseY, &CameraX, &CameraY);

}



void MainClass::GameLoop() {
    while (!quit_state && csdl_setup->GetMainEvent()-> type != SDL_QUIT) {

        csdl_setup->SdlBegin();
        SDL_GetMouseState(&MouseX,&MouseY);
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 7; j++) {
                background_img[i][j]->Draw();
            }
        }
        main_char->Draw();
        main_char->Update();
        csdl_setup->SdlEnd();
    }
}

MainClass::~MainClass() {

    delete main_char;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 7; j++) {
            delete background_img[i][j];
        }
    }
    delete csdl_setup;

}
