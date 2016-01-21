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

     timeCheck = SDL_GetTicks();
     MouseX = 0;
     MouseY = 0;

}

double MainClass::GetDistance(int x1, int y1, int x2, int y2) {

    double DifferenceX = x1 - x2;
    double DifferenceY = y1 - y2;
    double distance = sqrt((DifferenceX * DifferenceX) + (DifferenceY * DifferenceY));

    return distance;
}

void MainClass::GameLoop() {
    while (!quit_state && csdl_setup->GetMainEvent()-> type != SDL_QUIT) {

        csdl_setup->SdlBegin();

        SDL_GetMouseState(&MouseX,&MouseY);

        background_img->Draw();
        main_char->Draw();





        if (timeCheck+5 < SDL_GetTicks()) {

            double distance = GetDistance(main_char->GetX(),main_char->GetY(),MouseX,MouseY);

            if (distance != 0) {

                if (main_char->GetX() > MouseX) {
                    main_char->SetX(main_char->GetX() - ((main_char->GetX() - MouseX) / distance ) * 1.5f );
                }
                if (main_char->GetX() < MouseX) {
                    main_char->SetX(main_char->GetX() - ((main_char->GetX() - MouseX) / distance ) * 1.5f);
                }
                if (main_char->GetY() > MouseY) {
                    main_char->SetY(main_char->GetY() - ((main_char->GetY() - MouseY) / distance ) * 1.5f);
                }
                if (main_char->GetY() < MouseY) {
                    main_char->SetY(main_char->GetY() - ((main_char->GetY() - MouseY) / distance ) * 1.5f);
                }
            }

            timeCheck = SDL_GetTicks();
        }

        csdl_setup->SdlEnd();
    }
}

MainClass::~MainClass() {

    delete main_char;
    delete background_img;
    delete csdl_setup;

}
