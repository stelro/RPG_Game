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

    main_char = new CSprite(csdl_setup->GetRenderer(), "images/death_scythe_ani.png", 100, 200, 50, 90);
    //----------------------------------
    //Set origin , set the half width and height
    //of the main character
    //----------------------------------
    main_char->SetOrigin(main_char->GetWidth() / 2.0f, main_char->GetHeight() / 2.0f);

     timeCheck = SDL_GetTicks();
     MouseX = 0;
     MouseY = 0;
     follow = false;

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

        main_char->PlayAnimation(0,0,1,5);

        if (csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN ||
        csdl_setup->GetMainEvent()->type == SDL_MOUSEMOTION) {

            if(csdl_setup->GetMainEvent()->button.button == SDL_BUTTON_LEFT) {
                follow_point_x = MouseX;
                follow_point_y = MouseY;
                follow = true;
            }

        }



        if (timeCheck+10 < SDL_GetTicks() && follow) {

            double distance = GetDistance(main_char->GetX(),main_char->GetY(),follow_point_x,follow_point_y);

            if (distance != 0) {

                if (main_char->GetX() != follow_point_x) {
                    main_char->SetX(main_char->GetX() - ((main_char->GetX() - follow_point_x) / distance ) * 1.5f );
                }
                if (main_char->GetY() != follow_point_y) {
                    main_char->SetY(main_char->GetY() - ((main_char->GetY() - follow_point_y) / distance ) * 1.5f);
                }
            }
            else
                follow = false;

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
