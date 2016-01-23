#include "MainCharacter.h"

MainCharacter::MainCharacter(SDL *passed_sdl_setup, int *passed_MouseX, int *passed_MouseY) : PI(3.14159265359) {

    csdl_setup = passed_sdl_setup;
    MouseX = passed_MouseX;
    MouseY = passed_MouseY;

    main_char = new CSprite(csdl_setup->GetRenderer(), "images/ryuk.png", 100, 200, 50, 80);

    //----------------------------------
    //Set origin , set the half width and height
    //of the main character
    //----------------------------------
    main_char->SetUpAnimation(4,4);
    main_char->SetOrigin(main_char->GetWidth() / 2.0f, main_char->GetHeight() / 2.0f);

    timeCheck = SDL_GetTicks();
    follow = false;
    distance = 0;
    stopAnimation = false;

}

MainCharacter::~MainCharacter() {
    delete main_char;
}

void MainCharacter::Draw() {
    main_char->Draw();
}

void MainCharacter::Update() {
    //-----------------------------------------------------------------
    //this code above is about the caracter animation
    //this turging the carakter to the right direction
    //when the mouse direction changes
    //--------------------------
    //we get angle in radiance so
    //convert it to
    //degrees
    //---------------------------
    double angle = atan2(follow_point_y - main_char->GetY(), follow_point_x - main_char->GetX());
    angle = angle * (180/PI) + 180;

    //std::cout << angle << std::endl;

    //if distance equals to 0 , stop playing
    //the animation, this is set when the
    //carakter is not runing

    if (!stopAnimation) {
        if (angle > 45 &&  angle <= 135) {
            //up
            if ( distance > 15)
                main_char->PlayAnimation(0,2,3,200);
            else
                main_char->PlayAnimation(1,1,3,200);
        }
        else if (angle > 135 && angle <= 225) {
            //right
            if ( distance > 15)
                main_char->PlayAnimation(0,2,2,200);
            else
                main_char->PlayAnimation(1,1,2,200);
        }
        else if (angle > 225 && angle <= 315) {
            //down
            if ( distance > 15)
                main_char->PlayAnimation(0,2,0,200);
            else
                main_char->PlayAnimation(1,1,0,200);
        }
        else if ((angle <= 360 && angle > 315) || (angle >= 0 && angle <= 45)) {
            //left
            if ( distance > 15)
                main_char->PlayAnimation(0,2,1,200);
            else
                main_char->PlayAnimation(1,1,1,200);
        }
    }


    //--------------------------------------------------------------------



    if (csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN ||
    csdl_setup->GetMainEvent()->type == SDL_MOUSEMOTION) {

        if(csdl_setup->GetMainEvent()->button.button == SDL_BUTTON_LEFT) {
            follow_point_x = *MouseX;
            follow_point_y = *MouseY;
            follow = true;
        }

    }



    if (timeCheck+10 < SDL_GetTicks() && follow) {

         distance = GetDistance(main_char->GetX(),main_char->GetY(),follow_point_x,follow_point_y);

        if (distance == 0)
            stopAnimation = true;
        else
            stopAnimation = false;

        if (distance > 15 ) {

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
}

double MainCharacter::GetDistance(int x1, int y1, int x2, int y2) {

    double DifferenceX = x1 - x2;
    double DifferenceY = y1 - y2;
    double distance = sqrt((DifferenceX * DifferenceX) + (DifferenceY * DifferenceY));

    return distance;
}
