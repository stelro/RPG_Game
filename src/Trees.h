#ifndef GUARD_TREES_H
#define GUARD_TREES_H

#include "CSprite.h"
#include "_sdl.h"

class Trees {
public:
    Trees(int x, int y,float *passed_CameraX, float *passed_CameraY,SDL *csdl_setup);
    ~Trees();
    void DrawCrown();
    void DrawTrunk();
    int GetX() const;
    int GetY() const;
    CSprite *GetCrown();
    CSprite *GetTrunk();
private:
    int x;
    int y;
    CSprite *Crown;
    CSprite *Trunk;
    float *CameraX;
    float *CameraY;
};

#endif
