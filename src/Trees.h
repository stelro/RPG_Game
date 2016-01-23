#ifndef GUARD_TREES_H
#define GUARD_TREES_H

#include "CSprite.h"
#include "_sdl.h"

class Trees {
public:
    Trees(int x, int y,float *CameraX, float *CameraY,SDL *csdl_setup);
    ~Trees();
    void DrawCrown();
    void DrawTrunk();
private:
    CSprite *Crown;
    CSprite *Trunk;
};

#endif
