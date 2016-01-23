#include "CEnvironment.h"

Environment::Environment(const int screenWidth,const int screenHeight, float *CameraX, float *CameraY,SDL *csdl_setup) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 7; j++) {
            background_img[i][j] = new CSprite(csdl_setup->GetRenderer(), "images/grass.bmp",screenWidth * i,screenHeight * j,screenWidth,screenHeight, CameraX, CameraY);
        }
    }
}

Environment::~Environment() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 7; j++) {
            delete background_img[i][j];
        }
    }
}

void Environment::DrawFront() {

}

void Environment::DrawBack() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 7; j++) {
            background_img[i][j]->Draw();
        }
    }
}
