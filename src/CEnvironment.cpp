#include "CEnvironment.h"

Environment::Environment(const int screenWidth,const int screenHeight, float *passed_CameraX, float *passed_CameraY,SDL *passed_csdl_setup) {

    csdl_setup = passed_csdl_setup;

    CameraX = passed_CameraX;
    CameraY = passed_CameraY;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 7; j++) {
            background_img[i][j] = new CSprite(csdl_setup->GetRenderer(), "images/grass.bmp",screenWidth * i,screenHeight * j,screenWidth,screenHeight, CameraX, CameraY);
        }
    }

    Mode = GamePlay;

    one_press = false;

}

Environment::~Environment() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 7; j++) {
            delete background_img[i][j];
        }
    }

    for (auto &i : trees) {
        delete i;
    }

    trees.clear();
}

void Environment::Update() {

    if (Mode == LevelCreation) {
        if (csdl_setup->GetMainEvent()->type == SDL_KEYDOWN) {
            if (!one_press && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_e) {
                /* character offset, 300 and 250 */
                trees.push_back(new Trees(-*CameraX + 300,-*CameraY + 250,CameraX,CameraY,csdl_setup));
                one_press = true;
            }
        }

        if (csdl_setup->GetMainEvent()->type == SDL_KEYUP) {
            if ( one_press && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_e) {
                one_press = false;
            }
        }

    }
}

void Environment::DrawFront() {

    for (auto &i : trees) {
        i->DrawCrown();
    }
}

void Environment::DrawBack() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 7; j++) {
            background_img[i][j]->Draw();
        }
    }

    for (auto &i : trees) {
        i->DrawTrunk();
    }
}
