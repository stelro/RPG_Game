#ifndef GUARD_MAIN_CLASS_H
#define GUARD_MAIN_CLASS_H

#include "_sdl.h"
#include "CSprite.h"
#include <cmath>

//TODO: copy constructor

class MainClass  {
public:
    MainClass();
    MainClass(const bool flag, const char *title, const int pos_x, const int pos_y, const int w, const int h);
    ~MainClass();
    void GameLoop();
    double GetDistance(const int x1, const int y1, const int x2, const int y2);
private:
    bool quit_state;
    SDL* csdl_setup;

    //-------------------------
    //Creating objects on the screen
    //-------------------------

    CSprite *background_img;
    CSprite *main_char;
    int MouseX;
    int MouseY;
    bool follow;
    int follow_point_x;
    int follow_point_y;
    size_t timeCheck;
};

#endif