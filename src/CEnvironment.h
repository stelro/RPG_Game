#ifndef GUARD_ENVIRONMENT_H
#define GUARD_ENVIRONMENT_H

#include <SDL.h>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "Trees.h"

class Environment {
public:
    Environment(const int screenWidth,const int screenHeight, float *CameraX, float *CameraY,SDL *passed_csdl_setup);
    ~Environment();
    void DrawBack();
    void DrawFront();
    void Update();
    void SaveToFile();
    void LoadFromFile();
    enum Modetype {
        Gameplay,
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
