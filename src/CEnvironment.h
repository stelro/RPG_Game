#ifndef GUARD_ENVIRONMENT_H
#define GUARD_ENVIRONMENT_H

#include <SDL.h>
#include "Trees.h"
#include <vector>

class Environment {
public:
    Environment(const int screenWidth,const int screenHeight, float *CameraX, float *CameraY,SDL *passed_csdl_setup);
    ~Environment();
    void DrawBack();
    void DrawFront();
    void Update();

    enum Modetype {
        GamePlay,
        LevelCreation
    };

private:
    int Mode;
    bool one_press;
    SDL *csdl_setup;
    float *CameraX;
    float *CameraY;
    CSprite *background_img[4][7];
    std::vector<Trees*> trees;
};

#endif
