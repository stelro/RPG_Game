#include "MainCharacter.h"

MainCharacter::MainCharacter(SDL *passed_sdl_setup, int *passed_MouseX, int *passed_MouseY, float *passed_CameraX, float *passed_CameraY) : PI(3.14159265359) {

    CameraX = passed_CameraX;
    CameraY = passed_CameraY;

    csdl_setup = passed_sdl_setup;
    MouseX = passed_MouseX;
    MouseY = passed_MouseY;

    main_char = new CSprite(csdl_setup->GetRenderer(), "images/leviathan.png", 300, 250, 70, 100, CameraX, CameraY,CollisionRect(300,130,70,100));

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
    main_char->DrawSteady();
}

void MainCharacter::UpdateAnimation() {

    //-----------------------------------------------------------------
    //this code above is about the caracter animation
    //this turging the carakter to the right direction
    //when the mouse direction changes
    //--------------------------
    //we get angle in radiance so
    //convert it to
    //degrees
    //---------------------------
    double angle = atan2(follow_point_y - *CameraY, follow_point_x - *CameraX);
    angle = angle * (180/PI) + 180;

    //std::cout << angle << std::endl;

    //if distance equals to 0 , stop playing
    //the animation, this is set when the
    //carakter is not runing

    if (!stopAnimation) {
        if (angle > 45 &&  angle <= 135) {
            //down
            if ( distance > 15)
                main_char->PlayAnimation(0,2,0,200);
            else
                main_char->PlayAnimation(1,1,0,200);
        }
        else if (angle > 135 && angle <= 225) {
            //left
            if ( distance > 15)
                main_char->PlayAnimation(0,2,1,200);
            else
                main_char->PlayAnimation(1,1,1,200);
        }
        else if (angle > 225 && angle <= 315) {
            //up
            if ( distance > 15)
                main_char->PlayAnimation(0,2,3,200);
            else
                main_char->PlayAnimation(1,1,3,200);
        }
        else if ((angle <= 360 && angle > 315) || (angle >= 0 && angle <= 45)) {
            //right
            if ( distance > 15)
                main_char->PlayAnimation(0,2,2,200);
            else
                main_char->PlayAnimation(1,1,2,200);

        }
    }


    //--------------------------------------------------------------------
}

void MainCharacter::UpdateControllers() {
    if (csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN ||
    csdl_setup->GetMainEvent()->type == SDL_MOUSEMOTION) {

        if(csdl_setup->GetMainEvent()->button.button == SDL_BUTTON_LEFT) {
            follow_point_x = *CameraX - *MouseX + 300;
            follow_point_y = *CameraY - *MouseY + 250;
            follow = true;
        }

    }

    if (timeCheck+10 < SDL_GetTicks() && follow) {

         distance = GetDistance(*CameraX,*CameraY,follow_point_x,follow_point_y);

        if (distance == 0)
            stopAnimation = true;
        else
            stopAnimation = false;

        if (distance > 15 ) {

            if (*CameraX != follow_point_x) {
                *CameraX = (*CameraX - ((*CameraX - follow_point_x) / distance ) * 1.5f );
            }
            if (*CameraY != follow_point_y) {
                *CameraY = (*CameraY - ((*CameraY - follow_point_y) / distance ) * 1.5f);
            }
        }
        else
            follow = false;

        timeCheck = SDL_GetTicks();
    }
}

void MainCharacter::Update() {
    /* keep UpdateAnimation method call before
    the UpdateControllers */

    UpdateAnimation();
    UpdateControllers();

}

double MainCharacter::GetDistance(int x1, int y1, int x2, int y2) {

    double DifferenceX = x1 - x2;
    double DifferenceY = y1 - y2;
    double distance = sqrt((DifferenceX * DifferenceX) + (DifferenceY * DifferenceY));

    return distance;
}
