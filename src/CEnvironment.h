#ifndef GUARD_ENVIRONMENT_H
#define GUARD_ENVIRONMENT_H

#include <SDL.h>
#include "CSprite.h"
#include "_sdl.h"

class Environment {
public:
    Environment(const int screenWidth,const int screenHeight, float *CameraX, float *CameraY,SDL *csdl_setup);
    ~Environment();
    void DrawBack();
    void DrawFront();
private:
    CSprite *background_img[4][7];
};

#endif
