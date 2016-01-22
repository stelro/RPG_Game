#ifndef GUARD_MAINCHARACTER_H
#define GUARD_MAINCHARACTER_H

#include "CSprite.h"
#include <cmath>
#include "_sdl.h"

class MainCharacter {
public:
    MainCharacter(SDL *passed_sdl_setup, int *passed_MouseX, int *passed_MouseY);
    ~MainCharacter();
    void Update();
    void Draw();
    double GetDistance(const int x1, const int y1, const int x2, const int y2);
private:
    int MouseX;
    int MouseY;

    SDL* csdl_setup;

    CSprite *main_char;
    size_t timeCheck;

    bool follow;
    int follow_point_x;
    int follow_point_y;

    double distance;
    bool stopAnimation;
};

#endif
